/*
xatlas
https://github.com/jpcy/xatlas
Copyright (c) 2018 Jonathan Young

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include "viewer.h"

struct
{
	bgfx::VertexDecl vertexDecl;
	bgfx::TextureHandle font;
	bgfx::ProgramHandle program;
	bgfx::UniformHandle u_texture;
}
s_gui;

void guiInit()
{
	bgfx::setViewMode(kGuiView, bgfx::ViewMode::Sequential);
	bgfx::setViewRect(kGuiView, 0, 0, bgfx::BackbufferRatio::Equal);
	ImGui::CreateContext();
	int w, h;
	glfwGetWindowSize(g_window, &w, &h);
	ImGui::GetStyle().Colors[ImGuiCol_WindowBg].w = 0.9f;
	ImGuiIO &io = ImGui::GetIO();
	io.DisplaySize.x = (float)w;
	io.DisplaySize.y = (float)h;
	io.IniFilename = nullptr;
	io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
	io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
	io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
	io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
	io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
	io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
	io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
	io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
	io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
	io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
	io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
	io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
	io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
	io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;
	// font
	int fontWidth, fontHeight;
	uint8_t *fontData;
	io.Fonts->GetTexDataAsRGBA32(&fontData, &fontWidth, &fontHeight);
	s_gui.font = bgfx::createTexture2D((uint16_t)fontWidth, (uint16_t)fontHeight, false, 0, bgfx::TextureFormat::RGBA8, 0, bgfx::makeRef(fontData, fontWidth * fontHeight * 4));
	io.Fonts->TexID = (ImTextureID)(intptr_t)s_gui.font.idx;
	// ImDrawVert vertex decl
	s_gui.vertexDecl
		.begin()
		.add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
		.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
		.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
		.end();
	// shader program
	s_gui.u_texture = bgfx::createUniform("u_texture", bgfx::UniformType::Sampler);
	bgfx::ShaderHandle vertex = loadShader(ShaderId::vs_gui);
	bgfx::ShaderHandle fragment = loadShader(ShaderId::fs_gui);
	s_gui.program = bgfx::createProgram(vertex, fragment, true);
}

void guiShutdown()
{
	ImGui::DestroyContext();
	bgfx::destroy(s_gui.font);
	bgfx::destroy(s_gui.u_texture);
	bgfx::destroy(s_gui.program);
}

void guiResize(int width, int height)
{
	ImGuiIO &io = ImGui::GetIO();
	io.DisplaySize.x = (float)width;
	io.DisplaySize.y = (float)height;
	bgfx::setViewRect(kGuiView, 0, 0, bgfx::BackbufferRatio::Equal);
}

void guiRunFrame(float deltaTime)
{
	ImGuiIO &io = ImGui::GetIO();
	io.DeltaTime = deltaTime;
	if (glfwGetInputMode(g_window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL) {
		double x, y;
		glfwGetCursorPos(g_window, &x, &y);
		io.MousePos.x = (float)x;
		io.MousePos.y = (float)y;
	}
	else
		io.MousePos.x = io.MousePos.y = -1.0f;
}

void guiRender()
{
	ImGui::Render();
	ImDrawData *drawData = ImGui::GetDrawData();
	if (drawData->CmdListsCount == 0)
		return;
	ImGuiIO &io = ImGui::GetIO();
	float projection[16];
	bx::mtxOrtho(projection, 0, io.DisplaySize.x, io.DisplaySize.y, 0, 0, 1, 0, bgfx::getCaps()->homogeneousDepth);
	bgfx::setViewTransform(kGuiView, nullptr, projection);
	for (int n = 0; n < drawData->CmdListsCount; n++) {
		const ImDrawList* cmd_list = drawData->CmdLists[n];
		bgfx::TransientVertexBuffer tvb;
		bgfx::TransientIndexBuffer tib;
		if (!bgfx::allocTransientBuffers(&tvb, s_gui.vertexDecl, cmd_list->VtxBuffer.Size, &tib, cmd_list->IdxBuffer.Size))
			return;
		assert(sizeof(ImDrawVert) == s_gui.vertexDecl.getStride());
		memcpy(tvb.data, cmd_list->VtxBuffer.Data, tvb.size);
		assert(sizeof(ImDrawIdx) == sizeof(uint16_t));
		memcpy(tib.data, cmd_list->IdxBuffer.Data, tib.size);
		uint32_t firstIndex = 0;
		for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
			const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
			if (pcmd->UserCallback)
				pcmd->UserCallback(cmd_list, pcmd);
			else {
				bgfx::setScissor((uint16_t)pcmd->ClipRect.x, (uint16_t)pcmd->ClipRect.y, uint16_t(pcmd->ClipRect.z - pcmd->ClipRect.x), uint16_t(pcmd->ClipRect.w - pcmd->ClipRect.y));
				bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_BLEND_ALPHA);
				bgfx::TextureHandle texture;
				texture.idx = (uint16_t)(intptr_t)pcmd->TextureId;
				bgfx::setTexture(0, s_gui.u_texture, texture);
				bgfx::setIndexBuffer(&tib, firstIndex, pcmd->ElemCount);
				bgfx::setVertexBuffer(0, &tvb);
				bgfx::submit(kGuiView, s_gui.program);
			}
			firstIndex += pcmd->ElemCount;
		}
	}
}

void guiImageMagnifierTooltip(ImTextureID texture, ImVec2 cursorPos, ImVec2 textureSize)
{
	ImGuiIO &io = ImGui::GetIO();
	const ImVec2 imageSize(ImGui::GetItemRectSize());
	const ImVec2 imageToTex(textureSize.x / imageSize.x, textureSize.y / imageSize.y);
	const float magnifiedSize = 200.0f;
	const ImVec2 uv0 = ImVec2((io.MousePos.x - cursorPos.x) * imageToTex.x - magnifiedSize * 0.5f, (io.MousePos.y - cursorPos.y) * imageToTex.y - magnifiedSize * 0.5f);
	const ImVec2 uv1 = ImVec2(uv0.x + magnifiedSize, uv0.y + magnifiedSize);
	ImGui::BeginTooltip();
	ImGui::Image(texture, ImVec2(magnifiedSize, magnifiedSize), ImVec2(uv0.x / textureSize.x, uv0.y / textureSize.y), ImVec2(uv1.x / textureSize.x, uv1.y / textureSize.y));
	ImGui::EndTooltip();
}
