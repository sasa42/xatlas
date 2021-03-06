static const uint8_t fs_material_gl[920] =
{
	0x46, 0x53, 0x48, 0x06, 0x91, 0xb0, 0x36, 0xc4, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x0a, 0x75, // FSH...6........u
	0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x6d, 0x61, 0x70, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x09, // _lightmap.......
	0x75, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x0a, // u_diffuse.......
	0x75, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, // u_emission......
	0x14, 0x75, 0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x44, 0x69, 0x72, 0x5f, 0x73, 0x68, 0x61, 0x64, // .u_lightDir_shad
	0x65, 0x54, 0x79, 0x70, 0x65, 0x02, 0x01, 0x00, 0x00, 0x01, 0x00, 0x38, 0x03, 0x00, 0x00, 0x69, // eType......8...i
	0x6e, 0x20, 0x76, 0x65, 0x63, 0x33, 0x20, 0x76, 0x5f, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x3b, // n vec3 v_normal;
	0x0a, 0x69, 0x6e, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, // .in vec4 v_texco
	0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, // ord0;.uniform sa
	0x6d, 0x70, 0x6c, 0x65, 0x72, 0x32, 0x44, 0x20, 0x75, 0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x6d, // mpler2D u_lightm
	0x61, 0x70, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x76, 0x65, 0x63, 0x34, // ap;.uniform vec4
	0x20, 0x75, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, //  u_diffuse;.unif
	0x6f, 0x72, 0x6d, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x75, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, // orm vec4 u_emiss
	0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x76, 0x65, 0x63, // ion;.uniform vec
	0x34, 0x20, 0x75, 0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x44, 0x69, 0x72, 0x5f, 0x73, 0x68, 0x61, // 4 u_lightDir_sha
	0x64, 0x65, 0x54, 0x79, 0x70, 0x65, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, // deType;.void mai
	0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x28, 0x75, 0x69, // n ().{.  if ((ui
	0x6e, 0x74, 0x28, 0x75, 0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x44, 0x69, 0x72, 0x5f, 0x73, 0x68, // nt(u_lightDir_sh
	0x61, 0x64, 0x65, 0x54, 0x79, 0x70, 0x65, 0x2e, 0x77, 0x29, 0x20, 0x3d, 0x3d, 0x20, 0x75, 0x69, // adeType.w) == ui
	0x6e, 0x74, 0x28, 0x30, 0x29, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76, 0x65, // nt(0))) {.    ve
	0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x20, // c4 tmpvar_1;.   
	0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, //  tmpvar_1.xyz = 
	0x28, 0x28, 0x75, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x2e, 0x78, 0x79, 0x7a, 0x20, // ((u_diffuse.xyz 
	0x2a, 0x20, 0x28, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x28, 0x64, 0x6f, 0x74, 0x20, 0x28, // * (.      (dot (
	0x76, 0x5f, 0x6e, 0x6f, 0x72, 0x6d, 0x61, 0x6c, 0x2c, 0x20, 0x75, 0x5f, 0x6c, 0x69, 0x67, 0x68, // v_normal, u_ligh
	0x74, 0x44, 0x69, 0x72, 0x5f, 0x73, 0x68, 0x61, 0x64, 0x65, 0x54, 0x79, 0x70, 0x65, 0x2e, 0x78, // tDir_shadeType.x
	0x79, 0x7a, 0x29, 0x20, 0x2a, 0x20, 0x30, 0x2e, 0x35, 0x29, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, // yz) * 0.5).     
	0x2b, 0x20, 0x30, 0x2e, 0x35, 0x29, 0x29, 0x20, 0x2b, 0x20, 0x75, 0x5f, 0x65, 0x6d, 0x69, 0x73, // + 0.5)) + u_emis
	0x73, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x79, 0x7a, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x74, // sion.xyz);.    t
	0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x75, 0x5f, 0x64, 0x69, // mpvar_1.w = u_di
	0x66, 0x66, 0x75, 0x73, 0x65, 0x2e, 0x77, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x67, 0x6c, 0x5f, // ffuse.w;.    gl_
	0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, // FragColor = tmpv
	0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x7d, 0x20, 0x65, 0x6c, 0x73, 0x65, 0x20, 0x7b, // ar_1;.  } else {
	0x0a, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x28, 0x28, 0x28, 0x75, 0x5f, 0x65, 0x6d, // .    if ((((u_em
	0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x20, 0x3e, 0x20, 0x30, 0x2e, 0x30, 0x29, 0x20, // ission.x > 0.0) 
	0x7c, 0x7c, 0x20, 0x28, 0x75, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2e, 0x79, // || (u_emission.y
	0x20, 0x3e, 0x20, 0x30, 0x2e, 0x30, 0x29, 0x29, 0x20, 0x7c, 0x7c, 0x20, 0x28, 0x75, 0x5f, 0x65, //  > 0.0)) || (u_e
	0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2e, 0x7a, 0x20, 0x3e, 0x20, 0x30, 0x2e, 0x30, 0x29, // mission.z > 0.0)
	0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, // )) {.      vec4 
	0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, // tmpvar_2;.      
	0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x31, 0x2e, 0x30, // tmpvar_2.w = 1.0
	0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, // ;.      tmpvar_2
	0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x75, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, // .xyz = u_emissio
	0x6e, 0x2e, 0x78, 0x79, 0x7a, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x67, 0x6c, 0x5f, // n.xyz;.      gl_
	0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, // FragColor = tmpv
	0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x20, 0x65, 0x6c, 0x73, 0x65, // ar_2;.    } else
	0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, //  {.      vec4 tm
	0x70, 0x76, 0x61, 0x72, 0x5f, 0x33, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x74, 0x6d, // pvar_3;.      tm
	0x70, 0x76, 0x61, 0x72, 0x5f, 0x33, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x28, 0x75, 0x5f, // pvar_3.xyz = (u_
	0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x2a, 0x20, 0x74, 0x65, // diffuse.xyz * te
	0x78, 0x74, 0x75, 0x72, 0x65, 0x20, 0x28, 0x75, 0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x6d, 0x61, // xture (u_lightma
	0x70, 0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x7a, // p, v_texcoord0.z
	0x77, 0x29, 0x2e, 0x78, 0x79, 0x7a, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x74, // w).xyz);.      t
	0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x33, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x75, 0x5f, 0x64, 0x69, // mpvar_3.w = u_di
	0x66, 0x66, 0x75, 0x73, 0x65, 0x2e, 0x77, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x67, // ffuse.w;.      g
	0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, // l_FragColor = tm
	0x70, 0x76, 0x61, 0x72, 0x5f, 0x33, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x3b, 0x0a, 0x20, // pvar_3;.    };. 
	0x20, 0x7d, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                                 //  };.}...
};
