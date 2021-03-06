/*
xatlas
https://github.com/jpcy/xatlas
Copyright (c) 2018 Jonathan Young

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once
#include <bx/bx.h>
#include <bx/math.h>
#include <bgfx/bgfx.h>
#include <objzero/objzero.h>

constexpr bgfx::ViewId kModelView = 0;
constexpr bgfx::ViewId kGuiView = 1;
constexpr bgfx::ViewId kFirstFreeView = 2;

struct AABB
{
	AABB() : min(FLT_MAX, FLT_MAX, FLT_MAX), max(-FLT_MAX, -FLT_MAX, -FLT_MAX) {}

	void addPoint(bx::Vec3 v)
	{
		min.x = bx::min(min.x, v.x);
		min.y = bx::min(min.y, v.y);
		min.z = bx::min(min.z, v.z);
		max.x = bx::max(max.x, v.x);
		max.y = bx::max(max.y, v.y);
		max.z = bx::max(max.z, v.z);
	}

	void getCorners(bx::Vec3 *corners) const
	{
		const bx::Vec3 aabb[] = { min, max };
		for (int i = 0; i < 8; i++) {
			corners[i].x = aabb[i & 1].x;
			corners[i].y = aabb[(i >> 1) & 1].y;
			corners[i].z = aabb[(i >> 2) & 1].z;
		}
	}

	bx::Vec3 min;
	bx::Vec3 max;
};

void atlasInit();
void atlasShutdown();
void atlasDestroy();
void atlasGenerate();
void atlasFinalize();
void atlasRenderCharts(const float *modelMatrix);
void atlasShowGuiOptions();
void atlasShowGuiWindow(int progressDots);
uint32_t atlasGetWidth();
uint32_t atlasGetHeight();
bgfx::VertexBufferHandle atlasGetChartBoundaryVb();
bgfx::VertexBufferHandle atlasGetVb();
bgfx::IndexBufferHandle atlasGetIb();
bool atlasIsNotGenerated();
bool atlasIsReady();

void bakeInit();
void bakeShutdown();
void bakeExecute();
void bakeFrame(uint32_t bgfxFrame);
void bakeClear();
void bakeShowGuiOptions();
void bakeShowGuiWindow();
bgfx::TextureHandle bakeGetLightmap();
bool bakeIsIdle();

void guiInit();
void guiShutdown();
void guiResize(int width, int height);
void guiRunFrame(float deltaTime);
void guiRender();
void guiImageMagnifierTooltip(ImTextureID texture, ImVec2 cursorPos, ImVec2 textureSize);

struct ModelVertex
{
	bx::Vec3 pos;
	bx::Vec3 normal;
	float texcoord[4];
	static bgfx::VertexDecl decl;

	static void init()
	{
		decl.begin()
			.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
			.add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float)
			.add(bgfx::Attrib::TexCoord0, 4, bgfx::AttribType::Float)
			.end();
		assert(decl.getStride() == sizeof(ModelVertex));
	}
};

void modelInit();
void modelShutdown();
void modelFinalize();
void modelOpenDialog();
void modelDestroy();
void modelSetMaterialUniforms(const objzMaterial *mat);
void modelRender(const float *view, const float *projection);
void modelShowGuiOptions();
void modelShowGuiWindow(int progressDots);
AABB modelGetAABB();
const objzModel *modelGetData();
bx::Vec3 modelGetCentroid();
bgfx::ShaderHandle modelGet_vs_position();
bgfx::ShaderHandle modelGet_vs_model();
bool modelIsLoaded();

enum class ShadeMode
{
	Flat,
	Charts,
	Lightmap
};

enum class WireframeMode
{
	Charts,
	Triangles
};

struct Options
{
	bool gui = true;
	bool wireframe = true;
	ShadeMode shadeMode = ShadeMode::Flat;
	WireframeMode wireframeMode = WireframeMode::Triangles;
};

extern Options g_options;
struct GLFWwindow;
extern GLFWwindow *g_window;

void randomRGB(uint8_t *color);
void setErrorMessage(const char *format, ...);
void resetCamera();

enum class ShaderId
{
	fs_atomicCounterClear,
	fs_checkerboard,
	fs_color,
	fs_gui,
	fs_lightmapAverage,
	fs_lightmapClear,
	fs_material,
	fs_rayBundleClear,
	fs_rayBundleIntegrate,
	fs_rayBundleWrite,
	vs_gui,
	vs_model,
	vs_position
};

bgfx::ShaderHandle loadShader(ShaderId id);

#ifdef _MSC_VER
#define STRNCPY(_dest, _destSize, _src) strncpy_s(_dest, _destSize, _src, (_destSize) - 1)
#else
#define STRNCPY(_dest, _destSize, _src) strncpy(_dest, _src, (_destSize) - 1)
#endif

#define WINDOW_TITLE "xatlas viewer"
