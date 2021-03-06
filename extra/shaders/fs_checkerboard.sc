$input v_normal, v_texcoord0

#include <bgfx_shader.sh>

uniform vec4 u_color;
uniform vec4 u_textureSize_cellSize;

void main()
{
	uint x = uint(v_texcoord0.z * u_textureSize_cellSize.x);
	uint y = uint(v_texcoord0.w * u_textureSize_cellSize.y);
	uint cellSize = uint(u_textureSize_cellSize.z);
	float scale = (x / cellSize % 2u) != (y / cellSize % 2u) ? 0.75 : 1.0;
	gl_FragColor = vec4(u_color.rgb * scale, u_color.a);
}
