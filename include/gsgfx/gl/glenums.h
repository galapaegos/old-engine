#ifndef _glenums_h_
#define _glenums_h_

#include <GL/gl.h>

typedef int* GLsizeiptr;
typedef int* GLintptr;
typedef unsigned int GLhandleARB;
typedef char GLcharARB;
typedef char GLchar;

#ifndef GL_VERSION_1_2
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_RESCALE_NORMAL                 0x803A
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_LIGHT_MODEL_COLOR_CONTROL      0x81F8
#define GL_SINGLE_COLOR                   0x81F9
#define GL_SEPARATE_SPECULAR_COLOR        0x81FA
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_POINT_SIZE_RANGE       0x846D
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E
#endif

#ifndef GL_VERSION_1_3
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE          0x84E1
#define GL_MAX_TEXTURE_UNITS              0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX     0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX    0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX       0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX         0x84E6
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_MULTISAMPLE_BIT                0x20000000
#define GL_NORMAL_MAP                     0x8511
#define GL_REFLECTION_MAP                 0x8512
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_ALPHA               0x84E9
#define GL_COMPRESSED_LUMINANCE           0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA     0x84EB
#define GL_COMPRESSED_INTENSITY           0x84EC
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
#define GL_CLAMP_TO_BORDER_SGIS           0x812D
#define GL_COMBINE                        0x8570
#define GL_COMBINE_RGB                    0x8571
#define GL_COMBINE_ALPHA                  0x8572
#define GL_SOURCE0_RGB                    0x8580
#define GL_SOURCE1_RGB                    0x8581
#define GL_SOURCE2_RGB                    0x8582
#define GL_SOURCE0_ALPHA                  0x8588
#define GL_SOURCE1_ALPHA                  0x8589
#define GL_SOURCE2_ALPHA                  0x858A
#define GL_OPERAND0_RGB                   0x8590
#define GL_OPERAND1_RGB                   0x8591
#define GL_OPERAND2_RGB                   0x8592
#define GL_OPERAND0_ALPHA                 0x8598
#define GL_OPERAND1_ALPHA                 0x8599
#define GL_OPERAND2_ALPHA                 0x859A
#define GL_RGB_SCALE                      0x8573
#define GL_ADD_SIGNED                     0x8574
#define GL_INTERPOLATE                    0x8575
#define GL_SUBTRACT                       0x84E7
#define GL_CONSTANT                       0x8576
#define GL_PRIMARY_COLOR                  0x8577
#define GL_PREVIOUS                       0x8578
#define GL_DOT3_RGB                       0x86AE
#define GL_DOT3_RGBA                      0x86AF
#endif

#ifndef GL_VERSION_1_4
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_SIZE_MIN                 0x8126
#define GL_POINT_SIZE_MAX                 0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_POINT_DISTANCE_ATTENUATION     0x8129
#define GL_GENERATE_MIPMAP                0x8191
#define GL_GENERATE_MIPMAP_HINT           0x8192
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_FOG_COORDINATE_SOURCE          0x8450
#define GL_FOG_COORDINATE                 0x8451
#define GL_FRAGMENT_DEPTH                 0x8452
#define GL_CURRENT_FOG_COORDINATE         0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE      0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE    0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER   0x8456
#define GL_FOG_COORDINATE_ARRAY           0x8457
#define GL_COLOR_SUM                      0x8458
#define GL_CURRENT_SECONDARY_COLOR        0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE     0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE     0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE   0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER  0x845D
#define GL_SECONDARY_COLOR_ARRAY          0x845E
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_FILTER_CONTROL         0x8500
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_DEPTH_TEXTURE_MODE             0x884B
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_COMPARE_R_TO_TEXTURE           0x884E
#endif

#ifndef GL_VERSION_1_5
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING    0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING    0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING     0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING     0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING    0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_FOG_COORD_SOURCE               GL_FOG_COORDINATE_SOURCE
#define GL_FOG_COORD                      GL_FOG_COORDINATE
#define GL_CURRENT_FOG_COORD              GL_CURRENT_FOG_COORDINATE
#define GL_FOG_COORD_ARRAY_TYPE           GL_FOG_COORDINATE_ARRAY_TYPE
#define GL_FOG_COORD_ARRAY_STRIDE         GL_FOG_COORDINATE_ARRAY_STRIDE
#define GL_FOG_COORD_ARRAY_POINTER        GL_FOG_COORDINATE_ARRAY_POINTER
#define GL_FOG_COORD_ARRAY                GL_FOG_COORDINATE_ARRAY
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#define GL_SRC0_RGB                       GL_SOURCE0_RGB
#define GL_SRC1_RGB                       GL_SOURCE1_RGB
#define GL_SRC2_RGB                       GL_SOURCE2_RGB
#define GL_SRC0_ALPHA                     GL_SOURCE0_ALPHA
#define GL_SRC1_ALPHA                     GL_SOURCE1_ALPHA
#define GL_SRC2_ALPHA                     GL_SOURCE2_ALPHA
#endif

#ifndef GL_ARB_imaging
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#define GL_BLEND_COLOR                    0x8005
#define GL_FUNC_ADD                       0x8006
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
#define GL_BLEND_EQUATION                 0x8009
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_CONVOLUTION_1D                 0x8010
#define GL_CONVOLUTION_2D                 0x8011
#define GL_SEPARABLE_2D                   0x8012
#define GL_CONVOLUTION_BORDER_MODE        0x8013
#define GL_CONVOLUTION_FILTER_SCALE       0x8014
#define GL_CONVOLUTION_FILTER_BIAS        0x8015
#define GL_REDUCE                         0x8016
#define GL_CONVOLUTION_FORMAT             0x8017
#define GL_CONVOLUTION_WIDTH              0x8018
#define GL_CONVOLUTION_HEIGHT             0x8019
#define GL_MAX_CONVOLUTION_WIDTH          0x801A
#define GL_MAX_CONVOLUTION_HEIGHT         0x801B
#define GL_POST_CONVOLUTION_RED_SCALE     0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE   0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE    0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE   0x801F
#define GL_POST_CONVOLUTION_RED_BIAS      0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS    0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS     0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS    0x8023
#define GL_HISTOGRAM                      0x8024
#define GL_PROXY_HISTOGRAM                0x8025
#define GL_HISTOGRAM_WIDTH                0x8026
#define GL_HISTOGRAM_FORMAT               0x8027
#define GL_HISTOGRAM_RED_SIZE             0x8028
#define GL_HISTOGRAM_GREEN_SIZE           0x8029
#define GL_HISTOGRAM_BLUE_SIZE            0x802A
#define GL_HISTOGRAM_ALPHA_SIZE           0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE       0x802C
#define GL_HISTOGRAM_SINK                 0x802D
#define GL_MINMAX                         0x802E
#define GL_MINMAX_FORMAT                  0x802F
#define GL_MINMAX_SINK                    0x8030
#define GL_TABLE_TOO_LARGE                0x8031
#define GL_COLOR_MATRIX                   0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH       0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH   0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE    0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE  0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE   0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE  0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS     0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS   0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS    0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS   0x80BB
#define GL_COLOR_TABLE                    0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE   0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE  0x80D2
#define GL_PROXY_COLOR_TABLE              0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#define GL_COLOR_TABLE_SCALE              0x80D6
#define GL_COLOR_TABLE_BIAS               0x80D7
#define GL_COLOR_TABLE_FORMAT             0x80D8
#define GL_COLOR_TABLE_WIDTH              0x80D9
#define GL_COLOR_TABLE_RED_SIZE           0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE         0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE          0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE         0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE     0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE     0x80DF
#define GL_CONSTANT_BORDER                0x8151
#define GL_REPLICATE_BORDER               0x8153
#define GL_CONVOLUTION_BORDER_COLOR       0x8154
#endif

#ifndef GL_ARB_multitexture
#define GL_TEXTURE0_ARB                   0x84C0
#define GL_TEXTURE1_ARB                   0x84C1
#define GL_TEXTURE2_ARB                   0x84C2
#define GL_TEXTURE3_ARB                   0x84C3
#define GL_TEXTURE4_ARB                   0x84C4
#define GL_TEXTURE5_ARB                   0x84C5
#define GL_TEXTURE6_ARB                   0x84C6
#define GL_TEXTURE7_ARB                   0x84C7
#define GL_TEXTURE8_ARB                   0x84C8
#define GL_TEXTURE9_ARB                   0x84C9
#define GL_TEXTURE10_ARB                  0x84CA
#define GL_TEXTURE11_ARB                  0x84CB
#define GL_TEXTURE12_ARB                  0x84CC
#define GL_TEXTURE13_ARB                  0x84CD
#define GL_TEXTURE14_ARB                  0x84CE
#define GL_TEXTURE15_ARB                  0x84CF
#define GL_TEXTURE16_ARB                  0x84D0
#define GL_TEXTURE17_ARB                  0x84D1
#define GL_TEXTURE18_ARB                  0x84D2
#define GL_TEXTURE19_ARB                  0x84D3
#define GL_TEXTURE20_ARB                  0x84D4
#define GL_TEXTURE21_ARB                  0x84D5
#define GL_TEXTURE22_ARB                  0x84D6
#define GL_TEXTURE23_ARB                  0x84D7
#define GL_TEXTURE24_ARB                  0x84D8
#define GL_TEXTURE25_ARB                  0x84D9
#define GL_TEXTURE26_ARB                  0x84DA
#define GL_TEXTURE27_ARB                  0x84DB
#define GL_TEXTURE28_ARB                  0x84DC
#define GL_TEXTURE29_ARB                  0x84DD
#define GL_TEXTURE30_ARB                  0x84DE
#define GL_TEXTURE31_ARB                  0x84DF
#define GL_ACTIVE_TEXTURE_ARB             0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB      0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB          0x84E2
#endif

//GL_ARB_transpose_matrix
#ifndef GL_ARB_transpose_matrix
#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB   0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB     0x84E6
#endif

//WGL_ARB_buffer_region
#ifdef WIN32
#ifdef WGL_ARB_buffer_region
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB		0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB		0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB			0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB			0x00000008
#endif
#endif

#ifndef GL_ARB_multisample
#define GL_MULTISAMPLE_ARB                0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB   0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB        0x809F
#define GL_SAMPLE_COVERAGE_ARB            0x80A0
#define GL_SAMPLE_BUFFERS_ARB             0x80A8
#define GL_SAMPLES_ARB                    0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB      0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB     0x80AB
#define GL_MULTISAMPLE_BIT_ARB            0x20000000
#endif

#ifndef GL_ARB_texture_env_add
#endif

#ifndef GL_ARB_texture_cube_map
#define GL_NORMAL_MAP_ARB                 0x8511
#define GL_REFLECTION_MAP_ARB             0x8512
#define GL_TEXTURE_CUBE_MAP_ARB           0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB   0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB     0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB  0x851C
#endif

#ifdef WIN32
#ifndef WGL_ARB_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_ARB	0x2000
#define WGL_DRAW_TO_WINDOW_ARB			0x2001
#define WGL_DRAW_TO_BITMAP_ARB			0x2002
#define WGL_ACCELERATION_ARB			0x2003
#define WGL_NEED_PALETTE_ARB			0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB		0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB		0x2006
#define WGL_SWAP_METHOD_ARB				0x2007
#define WGL_NUMBER_OVERLAYS_ARB			0x2008
#define WGL_NUMBER_UNDERLAYS_ARB		0x2009
#define WGL_TRANSPARENT_ARB				0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB	0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB	0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB	0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB	0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB	0x203B
#define WGL_SHARE_DEPTH_ARB				0x200C
#define WGL_SHARE_STENCIL_ARB			0x200D
#define WGL_SHARE_ACCUM_ARB				0x200E
#define WGL_SUPPORT_GDI_ARB				0x200F
#define WGL_SUPPORT_OPENGL_ARB			0x2010
#define WGL_DOUBLE_BUFFER_ARB			0x2011
#define WGL_STEREO_ARB					0x2012
#define WGL_PIXEL_TYPE_ARB				0x2013
#define WGL_COLOR_BITS_ARB				0x2014
#define WGL_RED_BITS_ARB				0x2015
#define WGL_RED_SHIFT_ARB				0x2016
#define WGL_GREEN_BITS_ARB				0x2017
#define WGL_GREEN_SHIFT_ARB				0x2018
#define WGL_BLUE_BITS_ARB				0x2019
#define WGL_BLUE_SHIFT_ARB				0x201A
#define WGL_ALPHA_BITS_ARB				0x201B
#define WGL_ALPHA_SHIFT_ARB				0x201C
#define WGL_ACCUM_BITS_ARB				0x201D
#define WGL_ACCUM_RED_BITS_ARB			0x201E
#define WGL_ACCUM_GREEN_BITS_ARB		0x201F
#define WGL_ACCUM_BLUE_BITS_ARB			0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB		0x2021
#define WGL_DEPTH_BITS_ARB				0x2022
#define WGL_STENCIL_BITS_ARB			0x2023
#define WGL_AUX_BUFFERS_ARB				0x2024
#define WGL_NO_ACCELERATION_ARB			0x2025
#define WGL_GENERIC_ACCELERATION_ARB	0x2026
#define WGL_FULL_ACCELERATION_ARB		0x2027
#define WGL_SWAP_EXCHANGE_ARB			0x2028
#define WGL_SWAP_COPY_ARB				0x2029
#define WGL_SWAP_UNDEFINED_ARB			0x202A
#define WGL_TYPE_RGBA_ARB				0x202B
#define WGL_TYPE_COLORINDEX_ARB			0x202C
#endif
#endif

#ifdef WIN32
#ifndef WGL_ARB_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_ARB			0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB	0x2054
#endif
#endif

#ifdef WIN32
#ifndef WGL_ARB_pbuffer
DECLARE_HANDLE(HPBUFFERARB);
#define WGL_DRAW_TO_PBUFFER_ARB			0x202D
#define WGL_DRAW_TO_PBUFFER_ARB			0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB		0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB		0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB		0x2030
#define WGL_PBUFFER_LARGEST_ARB			0x2033
#define WGL_PBUFFER_WIDTH_ARB			0x2034
#define WGL_PBUFFER_HEIGHT_ARB			0x2035
#define WGL_PBUFFER_LOST_ARB			0x2036
#endif
#endif

#ifndef GL_ARB_texture_compression
#define GL_COMPRESSED_ALPHA_ARB           0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB       0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB 0x84EB
#define GL_COMPRESSED_INTENSITY_ARB       0x84EC
#define GL_COMPRESSED_RGB_ARB             0x84ED
#define GL_COMPRESSED_RGBA_ARB            0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB   0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB 0x86A0
#define GL_TEXTURE_COMPRESSED_ARB         0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB 0x86A3
#endif

#ifndef GL_ARB_texture_border_clamp
#define GL_CLAMP_TO_BORDER_ARB            0x812D
#endif

#ifndef GL_ARB_point_parameters
#define GL_POINT_SIZE_MIN_ARB             0x8126
#define GL_POINT_SIZE_MAX_ARB             0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB  0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB 0x8129
#endif

#ifndef GL_ARB_vertex_blend
#define GL_MAX_VERTEX_UNITS_ARB           0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB        0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB           0x86A6
#define GL_VERTEX_BLEND_ARB               0x86A7
#define GL_CURRENT_WEIGHT_ARB             0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB          0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB        0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB          0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB       0x86AC
#define GL_WEIGHT_ARRAY_ARB               0x86AD
#define GL_MODELVIEW0_ARB                 0x1700
#define GL_MODELVIEW1_ARB                 0x850A
#define GL_MODELVIEW2_ARB                 0x8722
#define GL_MODELVIEW3_ARB                 0x8723
#define GL_MODELVIEW4_ARB                 0x8724
#define GL_MODELVIEW5_ARB                 0x8725
#define GL_MODELVIEW6_ARB                 0x8726
#define GL_MODELVIEW7_ARB                 0x8727
#define GL_MODELVIEW8_ARB                 0x8728
#define GL_MODELVIEW9_ARB                 0x8729
#define GL_MODELVIEW10_ARB                0x872A
#define GL_MODELVIEW11_ARB                0x872B
#define GL_MODELVIEW12_ARB                0x872C
#define GL_MODELVIEW13_ARB                0x872D
#define GL_MODELVIEW14_ARB                0x872E
#define GL_MODELVIEW15_ARB                0x872F
#define GL_MODELVIEW16_ARB                0x8730
#define GL_MODELVIEW17_ARB                0x8731
#define GL_MODELVIEW18_ARB                0x8732
#define GL_MODELVIEW19_ARB                0x8733
#define GL_MODELVIEW20_ARB                0x8734
#define GL_MODELVIEW21_ARB                0x8735
#define GL_MODELVIEW22_ARB                0x8736
#define GL_MODELVIEW23_ARB                0x8737
#define GL_MODELVIEW24_ARB                0x8738
#define GL_MODELVIEW25_ARB                0x8739
#define GL_MODELVIEW26_ARB                0x873A
#define GL_MODELVIEW27_ARB                0x873B
#define GL_MODELVIEW28_ARB                0x873C
#define GL_MODELVIEW29_ARB                0x873D
#define GL_MODELVIEW30_ARB                0x873E
#define GL_MODELVIEW31_ARB                0x873F
#endif

#ifndef GL_ARB_matrix_palette
#define GL_MATRIX_PALETTE_ARB             0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB 0x8841
#define GL_MAX_PALETTE_MATRICES_ARB       0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB     0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB         0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB       0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB    0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB    0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB  0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB 0x8849
#endif

#ifndef GL_ARB_texture_env_combine
#define GL_COMBINE_ARB                    0x8570
#define GL_COMBINE_RGB_ARB                0x8571
#define GL_COMBINE_ALPHA_ARB              0x8572
#define GL_SOURCE0_RGB_ARB                0x8580
#define GL_SOURCE1_RGB_ARB                0x8581
#define GL_SOURCE2_RGB_ARB                0x8582
#define GL_SOURCE0_ALPHA_ARB              0x8588
#define GL_SOURCE1_ALPHA_ARB              0x8589
#define GL_SOURCE2_ALPHA_ARB              0x858A
#define GL_OPERAND0_RGB_ARB               0x8590
#define GL_OPERAND1_RGB_ARB               0x8591
#define GL_OPERAND2_RGB_ARB               0x8592
#define GL_OPERAND0_ALPHA_ARB             0x8598
#define GL_OPERAND1_ALPHA_ARB             0x8599
#define GL_OPERAND2_ALPHA_ARB             0x859A
#define GL_RGB_SCALE_ARB                  0x8573
#define GL_ADD_SIGNED_ARB                 0x8574
#define GL_INTERPOLATE_ARB                0x8575
#define GL_SUBTRACT_ARB                   0x84E7
#define GL_CONSTANT_ARB                   0x8576
#define GL_PRIMARY_COLOR_ARB              0x8577
#define GL_PREVIOUS_ARB                   0x8578
#endif

#ifndef GL_ARB_texture_env_crossbar
#endif

#ifndef GL_ARB_texture_env_dot3
#define GL_DOT3_RGB_ARB                   0x86AE
#define GL_DOT3_RGBA_ARB                  0x86AF
#endif

#ifndef GL_ARB_render_texture
#define WGL_BIND_TO_TEXTURE_RGB_ARB         0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB        0x2071
#define WGL_TEXTURE_FORMAT_ARB              0x2072
#define WGL_TEXTURE_TARGET_ARB              0x2073
#define WGL_MIPMAP_TEXTURE_ARB              0x2074
#define WGL_TEXTURE_RGB_ARB                 0x2075
#define WGL_TEXTURE_RGBA_ARB                0x2076
#define WGL_NO_TEXTURE_ARB                  0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB            0x2078
#define WGL_TEXTURE_1D_ARB                  0x2079
#define WGL_TEXTURE_2D_ARB                  0x207A
#define WGL_NO_TEXTURE_ARB                  0x2077
#define WGL_MIPMAP_LEVEL_ARB                0x207B
#define WGL_CUBE_MAP_FACE_ARB               0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB     0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB     0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB     0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB     0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB     0x2081 
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB     0x2082
#define WGL_FRONT_LEFT_ARB                  0x2083
#define WGL_FRONT_RIGHT_ARB                 0x2084
#define WGL_BACK_LEFT_ARB                   0x2085
#define WGL_BACK_RIGHT_ARB                  0x2086
#define WGL_AUX0_ARB                        0x2087 
#define WGL_AUX1_ARB                        0x2088 
#define WGL_AUX2_ARB                        0x2089 
#define WGL_AUX3_ARB                        0x208A 
#define WGL_AUX4_ARB                        0x208B 
#define WGL_AUX5_ARB                        0x208C 
#define WGL_AUX6_ARB                        0x208D
#define WGL_AUX7_ARB                        0x208E 
#define WGL_AUX8_ARB                        0x208F 
#define WGL_AUX9_ARB                        0x2090
#endif

#ifndef GL_ARB_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_ARB            0x8370
#endif

#ifndef GL_ARB_depth_texture
#define GL_DEPTH_COMPONENT16_ARB          0x81A5
#define GL_DEPTH_COMPONENT24_ARB          0x81A6
#define GL_DEPTH_COMPONENT32_ARB          0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB         0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB         0x884B
#endif

#ifndef GL_ARB_shadow
#define GL_TEXTURE_COMPARE_MODE_ARB       0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB       0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB       0x884E
#endif

#ifndef GL_ARB_shadow_ambient
#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB 0x80BF
#endif

#ifndef GL_ARB_window_pos
#endif

#ifndef GL_ARB_vertex_program
#define GL_COLOR_SUM_ARB                  0x8458
#define GL_VERTEX_PROGRAM_ARB             0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB   0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB   0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB      0x8626
#define GL_PROGRAM_LENGTH_ARB             0x8627
#define GL_PROGRAM_STRING_ARB             0x8628
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB 0x862E
#define GL_MAX_PROGRAM_MATRICES_ARB       0x862F
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB 0x8640
#define GL_CURRENT_MATRIX_ARB             0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB  0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB    0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB 0x8645
#define GL_PROGRAM_ERROR_POSITION_ARB     0x864B
#define GL_PROGRAM_BINDING_ARB            0x8677
#define GL_MAX_VERTEX_ATTRIBS_ARB         0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB 0x886A
#define GL_PROGRAM_ERROR_STRING_ARB       0x8874
#define GL_PROGRAM_FORMAT_ASCII_ARB       0x8875
#define GL_PROGRAM_FORMAT_ARB             0x8876
#define GL_PROGRAM_INSTRUCTIONS_ARB       0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB   0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB 0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB        0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB    0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB 0x88A7
#define GL_PROGRAM_PARAMETERS_ARB         0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB     0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB  0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB 0x88AB
#define GL_PROGRAM_ATTRIBS_ARB            0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB        0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB     0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB 0x88AF
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB  0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB 0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB 0x88B3
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB 0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB 0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB 0x88B6
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB   0x88B7
#define GL_MATRIX0_ARB                    0x88C0
#define GL_MATRIX1_ARB                    0x88C1
#define GL_MATRIX2_ARB                    0x88C2
#define GL_MATRIX3_ARB                    0x88C3
#define GL_MATRIX4_ARB                    0x88C4
#define GL_MATRIX5_ARB                    0x88C5
#define GL_MATRIX6_ARB                    0x88C6
#define GL_MATRIX7_ARB                    0x88C7
#define GL_MATRIX8_ARB                    0x88C8
#define GL_MATRIX9_ARB                    0x88C9
#define GL_MATRIX10_ARB                   0x88CA
#define GL_MATRIX11_ARB                   0x88CB
#define GL_MATRIX12_ARB                   0x88CC
#define GL_MATRIX13_ARB                   0x88CD
#define GL_MATRIX14_ARB                   0x88CE
#define GL_MATRIX15_ARB                   0x88CF
#define GL_MATRIX16_ARB                   0x88D0
#define GL_MATRIX17_ARB                   0x88D1
#define GL_MATRIX18_ARB                   0x88D2
#define GL_MATRIX19_ARB                   0x88D3
#define GL_MATRIX20_ARB                   0x88D4
#define GL_MATRIX21_ARB                   0x88D5
#define GL_MATRIX22_ARB                   0x88D6
#define GL_MATRIX23_ARB                   0x88D7
#define GL_MATRIX24_ARB                   0x88D8
#define GL_MATRIX25_ARB                   0x88D9
#define GL_MATRIX26_ARB                   0x88DA
#define GL_MATRIX27_ARB                   0x88DB
#define GL_MATRIX28_ARB                   0x88DC
#define GL_MATRIX29_ARB                   0x88DD
#define GL_MATRIX30_ARB                   0x88DE
#define GL_MATRIX31_ARB                   0x88DF
#endif

#ifndef GL_ARB_fragment_program
#define GL_FRAGMENT_PROGRAM_ARB           0x8804
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB   0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB   0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB   0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB 0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB 0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB 0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB 0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB 0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB 0x8810
#define GL_MAX_TEXTURE_COORDS_ARB         0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB    0x8872
#endif

#ifndef GL_ARB_vertex_buffer_object
#define GL_BUFFER_SIZE_ARB                0x8764
#define GL_BUFFER_USAGE_ARB               0x8765
#define GL_ARRAY_BUFFER_ARB               0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB       0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB       0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB 0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB 0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB 0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB 0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB 0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB 0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB 0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB 0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB 0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB 0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB 0x889F
#define GL_READ_ONLY_ARB                  0x88B8
#define GL_WRITE_ONLY_ARB                 0x88B9
#define GL_READ_WRITE_ARB                 0x88BA
#define GL_BUFFER_ACCESS_ARB              0x88BB
#define GL_BUFFER_MAPPED_ARB              0x88BC
#define GL_BUFFER_MAP_POINTER_ARB         0x88BD
#define GL_STREAM_DRAW_ARB                0x88E0
#define GL_STREAM_READ_ARB                0x88E1
#define GL_STREAM_COPY_ARB                0x88E2
#define GL_STATIC_DRAW_ARB                0x88E4
#define GL_STATIC_READ_ARB                0x88E5
#define GL_STATIC_COPY_ARB                0x88E6
#define GL_DYNAMIC_DRAW_ARB               0x88E8
#define GL_DYNAMIC_READ_ARB               0x88E9
#define GL_DYNAMIC_COPY_ARB               0x88EA
#endif

#ifndef GL_ARB_occlusion_query
#define GL_QUERY_COUNTER_BITS_ARB         0x8864
#define GL_CURRENT_QUERY_ARB              0x8865
#define GL_QUERY_RESULT_ARB               0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB     0x8867
#define GL_SAMPLES_PASSED_ARB             0x8914
#endif

#ifndef GL_ARB_shader_objects
#define GL_PROGRAM_OBJECT_ARB             0x8B40
#define GL_SHADER_OBJECT_ARB              0x8B48
#define GL_OBJECT_TYPE_ARB                0x8B4E
#define GL_OBJECT_SUBTYPE_ARB             0x8B4F
#define GL_FLOAT_VEC2_ARB                 0x8B50
#define GL_FLOAT_VEC3_ARB                 0x8B51
#define GL_FLOAT_VEC4_ARB                 0x8B52
#define GL_INT_VEC2_ARB                   0x8B53
#define GL_INT_VEC3_ARB                   0x8B54
#define GL_INT_VEC4_ARB                   0x8B55
#define GL_BOOL_ARB                       0x8B56
#define GL_BOOL_VEC2_ARB                  0x8B57
#define GL_BOOL_VEC3_ARB                  0x8B58
#define GL_BOOL_VEC4_ARB                  0x8B59
#define GL_FLOAT_MAT2_ARB                 0x8B5A
#define GL_FLOAT_MAT3_ARB                 0x8B5B
#define GL_FLOAT_MAT4_ARB                 0x8B5C
#define GL_OBJECT_DELETE_STATUS_ARB       0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB      0x8B81
#define GL_OBJECT_LINK_STATUS_ARB         0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB     0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB     0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB    0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB     0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB 0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB 0x8B88
#endif

#ifndef GL_ARB_vertex_shader
#define GL_VERTEX_SHADER_ARB              0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB 0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB         0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB 0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB   0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB 0x8B8A
#endif

#ifndef GL_ARB_fragment_shader
#define GL_FRAGMENT_SHADER_ARB            0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB 0x8B49
#endif

#ifndef GL_ARB_shading_language_100
#define SHADING_LANGUAGE_VERSION_ARB		0x8B8C
#endif

#ifndef GL_ARB_texture_non_power_of_two
#endif

#ifndef GL_ARB_point_sprite
#define GL_POINT_SPRITE_ARB               0x8861
#define GL_COORD_REPLACE_ARB              0x8862
#endif

#ifndef GL_ARB_fragment_program_shadow
#endif

#ifndef GL_ARB_draw_buffers
#define GL_MAX_DRAW_BUFFERS_ARB                    0x8824
#define GL_DRAW_BUFFER0_ARB                        0x8825
#define GL_DRAW_BUFFER1_ARB                        0x8826
#define GL_DRAW_BUFFER2_ARB                        0x8827
#define GL_DRAW_BUFFER3_ARB                        0x8828
#define GL_DRAW_BUFFER4_ARB                        0x8829
#define GL_DRAW_BUFFER5_ARB                        0x882A
#define GL_DRAW_BUFFER6_ARB                        0x882B
#define GL_DRAW_BUFFER7_ARB                        0x882C
#define GL_DRAW_BUFFER8_ARB                        0x882D
#define GL_DRAW_BUFFER9_ARB                        0x882E
#define GL_DRAW_BUFFER10_ARB                       0x882F
#define GL_DRAW_BUFFER11_ARB                       0x8830
#define GL_DRAW_BUFFER12_ARB                       0x8831
#define GL_DRAW_BUFFER13_ARB                       0x8832
#define GL_DRAW_BUFFER14_ARB                       0x8833
#define GL_DRAW_BUFFER15_ARB                       0x8834
#endif

#ifndef GL_ARB_texture_rect
#define GL_TEXTURE_RECTANGLE_ARB            0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB    0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB      0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB   0x84F8
#define GL_SAMPLER_2D_RECT_ARB              0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB       0x8B64
#endif

#ifndef GL_ARB_color_buffer_float
#define GL_RGBA_FLOAT_MODE_ARB                     0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB                  0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB                0x891B
#define GL_CLAMP_READ_COLOR_ARB                    0x891C
#define GL_FIXED_ONLY_ARB                          0x891D
#define WGL_TYPE_RGBA_FLOAT_ARB                 0x21A0
#define GLX_RGBA_FLOAT_TYPE                     0x20B9
#define GLX_RGBA_FLOAT_BIT                      0x00000004
#endif

#ifndef GL_ARB_half_float_pixel
#define GL_HALF_FLOAT_ARB                                0x140B
#endif

#ifndef GL_ARB_texture_float
#define TEXTURE_RED_TYPE_ARB             0x8C10
#define TEXTURE_GREEN_TYPE_ARB           0x8C11
#define TEXTURE_BLUE_TYPE_ARB            0x8C12
#define TEXTURE_ALPHA_TYPE_ARB           0x8C13
#define TEXTURE_LUMINANCE_TYPE_ARB       0x8C14
#define TEXTURE_INTENSITY_TYPE_ARB       0x8C15
#define TEXTURE_DEPTH_TYPE_ARB           0x8C16
#define UNSIGNED_NORMALIZED_ARB          0x8C17
#define RGBA32F_ARB                      0x8814
#define RGB32F_ARB                       0x8815
#define ALPHA32F_ARB                     0x8816
#define INTENSITY32F_ARB                 0x8817
#define LUMINANCE32F_ARB                 0x8818
#define LUMINANCE_ALPHA32F_ARB           0x8819
#define RGBA16F_ARB                      0x881A
#define RGB16F_ARB                       0x881B
#define ALPHA16F_ARB                     0x881C
#define INTENSITY16F_ARB                 0x881D
#define LUMINANCE16F_ARB                 0x881E
#define LUMINANCE_ALPHA16F_ARB           0x881F
#endif

#ifndef GL_ARB_pixel_buffer_object 
#define GL_PIXEL_PACK_BUFFER_ARB                        0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB                      0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB                0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB              0x88EF
#endif

//Extensions!
#ifndef GL_EXT_abgr
#define GL_ABGR_EXT                     0x8000
#endif

#ifndef GL_EXT_blend_color
#define GL_CONSTANT_COLOR_EXT               0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT     0x8002
#define GL_CONSTANT_ALPHA_EXT               0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT     0x8004
#define GL_BLEND_COLOR_EXT                  0x8005
#endif

#ifndef GL_EXT_polygon_offset
#define POLYGON_OFFSET_EXT               0x8037
#define POLYGON_OFFSET_FACTOR_EXT        0x8038
#define POLYGON_OFFSET_BIAS_EXT          0x8039
#endif

#ifndef GL_EXT_texture
#define ALPHA4_EXT                       0x803B
#define ALPHA8_EXT                       0x803C
#define ALPHA12_EXT                      0x803D
#define ALPHA16_EXT                      0x803E
#define LUMINANCE4_EXT                   0x803F
#define LUMINANCE8_EXT                   0x8040
#define LUMINANCE12_EXT                  0x8041
#define LUMINANCE16_EXT                  0x8042
#define LUMINANCE4_ALPHA4_EXT            0x8043
#define LUMINANCE6_ALPHA2_EXT            0x8044
#define LUMINANCE8_ALPHA8_EXT            0x8045
#define LUMINANCE12_ALPHA4_EXT           0x8046
#define LUMINANCE12_ALPHA12_EXT          0x8047
#define LUMINANCE16_ALPHA16_EXT          0x8048
#define INTENSITY_EXT                    0x8049
#define INTENSITY4_EXT                   0x804A
#define INTENSITY8_EXT                   0x804B
#define INTENSITY12_EXT                  0x804C
#define INTENSITY16_EXT                  0x804D
#define RGB2_EXT                         0x804E
#define RGB4_EXT                         0x804F
#define RGB5_EXT                         0x8050
#define RGB8_EXT                         0x8051
#define RGB10_EXT                        0x8052
#define RGB12_EXT                        0x8053
#define RGB16_EXT                        0x8054
#define RGBA2_EXT                        0x8055
#define RGBA4_EXT                        0x8056
#define RGB5_A1_EXT                      0x8057
#define RGBA8_EXT                        0x8058
#define RGB10_A2_EXT                     0x8059
#define RGBA12_EXT                       0x805A
#define RGBA16_EXT                       0x805B
#define TEXTURE_RED_SIZE_EXT             0x805C
#define TEXTURE_GREEN_SIZE_EXT           0x805D
#define TEXTURE_BLUE_SIZE_EXT            0x805E
#define TEXTURE_ALPHA_SIZE_EXT           0x805F
#define TEXTURE_LUMINANCE_SIZE_EXT       0x8060
#define TEXTURE_INTENSITY_SIZE_EXT       0x8061
#define REPLACE_EXT                      0x8062
#define PROXY_TEXTURE_1D_EXT             0x8063
#define PROXY_TEXTURE_2D_EXT             0x8064
#endif

#ifndef GL_EXT_texture3D
#define PACK_SKIP_IMAGES_EXT             0x806B
#define PACK_IMAGE_HEIGHT_EXT            0x806C
#define UNPACK_SKIP_IMAGES_EXT           0x806D
#define UNPACK_IMAGE_HEIGHT_EXT          0x806E
#define TEXTURE_3D_EXT                   0x806F
#define PROXY_TEXTURE_3D_EXT             0x8070
#define TEXTURE_DEPTH_EXT                0x8071
#define TEXTURE_WRAP_R_EXT               0x8072
#define MAX_3D_TEXTURE_SIZE_EXT          0x8073
#endif

#ifndef GL_EXT_convolution
#define CONVOLUTION_1D_EXT               0x8010
#define CONVOLUTION_2D_EXT               0x8011
#define SEPARABLE_2D_EXT                 0x8012
#define CONVOLUTION_BORDER_MODE_EXT      0x8013
#define CONVOLUTION_FILTER_SCALE_EXT     0x8014
#define CONVOLUTION_FILTER_BIAS_EXT      0x8015
#define REDUCE_EXT                       0x8016
#define CONVOLUTION_FORMAT_EXT           0x8017
#define CONVOLUTION_WIDTH_EXT            0x8018
#define CONVOLUTION_HEIGHT_EXT           0x8019
#define MAX_CONVOLUTION_WIDTH_EXT        0x801A
#define MAX_CONVOLUTION_HEIGHT_EXT       0x801B
#define POST_CONVOLUTION_RED_SCALE_EXT   0x801C
#define POST_CONVOLUTION_GREEN_SCALE_EXT 0x801D
#define POST_CONVOLUTION_BLUE_SCALE_EXT  0x801E
#define POST_CONVOLUTION_ALPHA_SCALE_EXT 0x801F
#define POST_CONVOLUTION_RED_BIAS_EXT    0x8020
#define POST_CONVOLUTION_GREEN_BIAS_EXT  0x8021
#define POST_CONVOLUTION_BLUE_BIAS_EXT   0x8022
#define POST_CONVOLUTION_ALPHA_BIAS_EXT  0x8023
#endif

#ifndef GL_EXT_color_matrix
#define COLOR_MATRIX_SGI		 	0x80B1
#define COLOR_MATRIX_STACK_DEPTH_SGI		0x80B2
#define MAX_COLOR_MATRIX_STACK_DEPTH_SGI	0x80B3
#define POST_COLOR_MATRIX_RED_SCALE_SGI		0x80B4
#define POST_COLOR_MATRIX_GREEN_SCALE_SGI	0x80B5
#define POST_COLOR_MATRIX_BLUE_SCALE_SGI	0x80B6
#define POST_COLOR_MATRIX_ALPHA_SCALE_SGI	0x80B7
#define POST_COLOR_MATRIX_RED_BIAS_SGI		0x80B8
#define POST_COLOR_MATRIX_GREEN_BIAS_SGI	0x80B9
#define POST_COLOR_MATRIX_BLUE_BIAS_SGI		0x80BA
#define POST_COLOR_MATRIX_ALPHA_BIAS_SGI	0x80BB
#endif

#ifndef GL_SGIS_pixel_texture
#define PIXEL_TEXTURE_SGIS                      = 0x8353
#define PIXEL_FRAGMENT_RGB_SOURCE_SGIS          = 0x8354
#define PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS        = 0x8355
#define PIXEL_GROUP_COLOR_SGIS                  = 0x8356
#endif

#ifndef GL_SGIX_pixel_texture
#define PIXEL_TEX_GEN_SGIX                      = 0x8139
#define PIXEL_TEX_GEN_MODE_SGIX                 = 0x832B
#endif

#ifndef GL_SGIS_texture4d
#endif

#ifndef GL_EXT_cmyka
#define CMYK_EXT		0x800C
#define CMYKA_EXT		0x800D
#define PACK_CMYK_HINT_EXT	0x800E
#define UNPACK_CMYK_HINT_EXT	0x800F
#endif

#ifndef GL_EXT_texture_object
#define TEXTURE_PRIORITY_EXT		0x8066
#define TEXTURE_RESIDENT_EXT		0x8067
#define TEXTURE_1D_BINDING_EXT		0x8068
#define TEXTURE_2D_BINDING_EXT		0x8069
#define TEXTURE_3D_BINDING_EXT		0x806A
#endif

#ifndef GL_EXT_packed_pixels
#define UNSIGNED_BYTE_3_3_2_EXT		0x8032
#define UNSIGNED_SHORT_4_4_4_4_EXT	0x8033
#define UNSIGNED_SHORT_5_5_5_1_EXT	0x8034
#define UNSIGNED_INT_8_8_8_8_EXT	0x8035
#define UNSIGNED_INT_10_10_10_2_EXT	0x8036
#endif

#ifndef GL_SGIS_texture_lod
#define TEXTURE_MIN_LOD_SGIS		0x813A
#define TEXTURE_MAX_LOD_SGIS		0x813B
#define TEXTURE_BASE_LEVEL_SGIS		0x813C
#define TEXTURE_MAX_LEVEL_SGIS		0x813D
#endif

#ifndef GL_EXT_rescale_normal
#endif

#ifndef GL_EXT_visual_info
#define GLX_X_VISUAL_TYPE_EXT		0x22
#define GLX_TRANSPARENT_TYPE_EXT	0x23
#define GLX_TRANSPARENT_INDEX_VALUE_EXT	0x24
#define GLX_TRANSPARENT_RED_VALUE_EXT	0x25
#define GLX_TRANSPARENT_GREEN_VALUE_EXT	0x26
#define GLX_TRANSPARENT_BLUE_VALUE_EXT	0x27
#define GLX_TRANSPARENT_ALPHA_VALUE_EXT	0x28
#define GLX_TRUE_COLOR_EXT		0x8002
#define GLX_DIRECT_COLOR_EXT		0x8003
#define GLX_PSEUDO_COLOR_EXT		0x8004
#define GLX_STATIC_COLOR_EXT		0x8005
#define GLX_GRAY_SCALE_EXT		0x8006
#define GLX_STATIC_GRAY_EXT		0x8007
#define GLX_NONE_EXT			0x8000
#define GLX_TRANSPARENT_RGB_EXT		0x8008
#define GLX_TRANSPARENT_INDEX_EXT	0x8009
#endif

#ifndef GL_EXT_vertex_array
#define VERTEX_ARRAY_EXT               0x8074
#define NORMAL_ARRAY_EXT               0x8075
#define COLOR_ARRAY_EXT                0x8076
#define INDEX_ARRAY_EXT                0x8077
#define TEXTURE_COORD_ARRAY_EXT        0x8078
#define EDGE_FLAG_ARRAY_EXT            0x8079
#define DOUBLE_EXT                     0x140A
#define VERTEX_ARRAY_SIZE_EXT          0x807A
#define VERTEX_ARRAY_TYPE_EXT          0x807B
#define VERTEX_ARRAY_STRIDE_EXT        0x807C
#define VERTEX_ARRAY_COUNT_EXT         0x807D
#define NORMAL_ARRAY_TYPE_EXT          0x807E
#define NORMAL_ARRAY_STRIDE_EXT        0x807F
#define NORMAL_ARRAY_COUNT_EXT         0x8080
#define COLOR_ARRAY_SIZE_EXT           0x8081
#define COLOR_ARRAY_TYPE_EXT           0x8082
#define COLOR_ARRAY_STRIDE_EXT         0x8083
#define COLOR_ARRAY_COUNT_EXT          0x8084
#define INDEX_ARRAY_TYPE_EXT           0x8085
#define INDEX_ARRAY_STRIDE_EXT         0x8086
#define INDEX_ARRAY_COUNT_EXT          0x8087
#define TEXTURE_COORD_ARRAY_SIZE_EXT   0x8088
#define TEXTURE_COORD_ARRAY_TYPE_EXT   0x8089
#define TEXTURE_COORD_ARRAY_STRIDE_EXT 0x808A
#define TEXTURE_COORD_ARRAY_COUNT_EXT  0x808B
#define EDGE_FLAG_ARRAY_STRIDE_EXT     0x808C
#define EDGE_FLAG_ARRAY_COUNT_EXT      0x808D
#define VERTEX_ARRAY_POINTER_EXT       0x808E
#define NORMAL_ARRAY_POINTER_EXT       0x808F
#define COLOR_ARRAY_POINTER_EXT        0x8090
#define INDEX_ARRAY_POINTER_EXT        0x8091
#define TEXTURE_COORD_ARRAY_POINTER_EXT 0x8092
#define EDGE_FLAG_ARRAY_POINTER_EXT    0x8093
#endif

#ifndef GL_SGIS_generate_mipmap
#define GENERATE_MIPMAP_SGIS		0x8191
#define GENERATE_MIPMAP_HINT_SGIS	0x8192
#endif

#ifndef GL_SGIS_texture_edge_clamp
#define CLAMP_TO_EDGE_SGIS		0x812F
#endif

#ifndef GL_SGIS_texture_border_clamp
#define CLAMP_TO_BORDER_SGIS		0x812D
#endif

#ifndef GL_EXT_blend_minmax
#define FUNC_ADD_EXT                     0x8006
#define MIN_EXT                          0x8007
#define MAX_EXT                          0x8008
#define BLEND_EQUATION_EXT               0x8009
#endif

#ifndef GL_EXT_blend_subtract
#define FUNC_SUBTRACT_EXT                0x800A
#define FUNC_REVERSE_SUBTRACT_EXT        0x800B
#endif

#ifndef GLX_EXT_visual_rating
#define GLX_VISUAL_CAVEAT_EXT		0x20
#define GLX_NONE_EXT			0x8000
#define GLX_SLOW_VISUAL_EXT		0x8001
#define GLX_NON_CONFORMANT_VISUAL_EXT	0x800D
#endif

#ifndef GL_SGIX_interlace
#define INTERLACE_SGIX				0x8094
#endif

#ifndef GLX_EXT_import_context
#define GLX_SHARE_CONTEXT_EXT		0x800A
#define GLX_VISUAL_ID_EXT			0x800B
#define GLX_SCREEN_EXT			0x800C
#endif

#ifndef GLX_SGIX_fbconfig
#define GLX_DRAWABLE_TYPE_SGIX		0x8010
#define GLX_RENDER_TYPE_SGIX		0x8011
#define GLX_X_RENDERABLE_SGIX		0x8012
#define GLX_FBCONFIG_ID_SGIX		0x8013
#define GLX_SCREEN_EXT			0x800C
#define GLX_WINDOW_BIT_SGIX		0x00000001
#define GLX_PIXMAP_BIT_SGIX		0x00000002
#define GLX_RGBA_BIT_SGIX		0x00000001
#define GLX_COLOR_INDEX_BIT_SGIX	0x00000002
#define GLX_RGBA_TYPE_SGIX		0x8014
#define GLX_COLOR_INDEX_TYPE_SGIX	0x8015
#endif

#ifndef GLX_SGIX_pbuffer
#define GLX_MAX_PBUFFER_WIDTH_SGIX		0x8016
#define GLX_MAX_PBUFFER_HEIGHT_SGIX		0x8017
#define GLX_MAX_PBUFFER_PIXELS_SGIX		0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX		0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX		0x801A
#define GLX_PBUFFER_BIT_SGIX			0x00000004
#define GLX_PRESERVED_CONTENTS_SGIX		0x801B
#define GLX_LARGEST_PBUFFER_SGIX		0x801C
#define GLX_WIDTH_SGIX 				0x801D
#define GLX_HEIGHT_SGIX				0x801E
#define GLX_EVENT_MASK_SGIX			0x801F
#define GLX_BUFFER_CLOBBER_MASK_SGIX  		0x08000000
#define GLX_DAMAGED_SGIX 			0x8020
#define GLX_SAVED_SGIX				0x8021
#define GLX_WINDOW_SGIX				0x8022
#define GLX_PBUFFER_SGIX			0x8023
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX		0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX		0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX		0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX		0x00000008
#define GLX_AUX_BUFFERS_BIT_SGIX		0x00000010
#define GLX_DEPTH_BUFFER_BIT_SGIX		0x00000020
#define GLX_STENCIL_BUFFER_BIT_SGIX		0x00000040
#define GLX_ACCUM_BUFFER_BIT_SGIX		0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX		0x00000100
#endif

#ifndef GL_SGIS_texture_select
#endif

#ifndef GL_SGIX_texture_multi_buffer
#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX		0x812E
#endif

#ifndef GL_EXT_point_parameters
#define GL_POINT_SIZE_MIN_EXT		   0x8126
#define GL_POINT_SIZE_MAX_EXT		   0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT   0x8128
#define GL_DISTANCE_ATTENUATION_EXT	   0x8129
#endif

#ifndef GL_SGIX_texture_scale_bias
#define POST_TEXTURE_FILTER_BIAS_SGIX		0x8179
#define POST_TEXTURE_FILTER_SCALE_SGIX		0x817A
#define POST_TEXTURE_FILTER_BIAS_RANGE_SGIX	0x817B
#define POST_TEXTURE_FILTER_SCALE_RANGE_SGIX	0x817C
#endif

#ifndef GL_SGIX_depth_texture
#define DEPTH_COMPONENT16_SGIX 		0x81A5
#define DEPTH_COMPONENT24_SGIX		0x81A6
#define DEPTH_COMPONENT32_SGIX		0x81A7
#endif

#ifndef GL_SGIS_fog_func
#define FOG_FUNC_SGIS                           = 0x812A
#define FOG_FUNC_POINTS_SGIS                    = 0x812B
#define MAX_FOG_FUNC_POINTS_SGIS                = 0x812C
#define FOG_FUNC_SGIS                           = 0x812A
#endif

#ifndef GL_SGIX_fog_offset
#define GL_FOG_OFFSET_SGIX		0x8198
#define GL_FOG_OFFSET_VALUE_SGIX	0x8199
#endif

#ifndef GLU_EXT_object_space_tess
#define OBJECT_PARAMETRIC_ERROR_EXT                       100208 
#define OBJECT_PATH_LENGTH_EXT                            100209
#endif

#ifndef GL_PGI_vertex_hints
#define VERTEX_DATA_HINT_PGI               107050
#define VERTEX_CONSISTENT_HINT_PGI         107051
#define MATERIAL_SIDE_HINT_PGI             107052
#define MAX_VERTEX_HINT_PGI                107053
#define COLOR3_BIT_PGI                  0x00010000
#define COLOR4_BIT_PGI                  0x00020000
#define EDGEFLAG_BIT_PGI                0x00040000
#define INDEX_BIT_PGI                   0x00080000
#define MAT_AMBIENT_BIT_PGI             0x00100000
#define MAT_AMBIENT_AND_DIFFUSE_BIT_PGI 0x00200000
#define MAT_DIFFUSE_BIT_PGI             0x00400000
#define MAT_EMISSION_BIT_PGI            0x00800000
#define MAT_COLOR_INDEXES_BIT_PGI       0x01000000
#define MAT_SHININESS_BIT_PGI           0x02000000
#define MAT_SPECULAR_BIT_PGI            0x04000000
#define NORMAL_BIT_PGI                  0x08000000
#define TEXCOORD1_BIT_PGI               0x10000000
#define TEXCOORD2_BIT_PGI               0x20000000
#define TEXCOORD3_BIT_PGI               0x40000000
#define TEXCOORD4_BIT_PGI               0x80000000
#define VERTEX23_BIT_PGI                0x00000004
#define VERTEX4_BIT_PGI                 0x00000008
#endif

#ifndef GL_PGI_misc_hints
#define PREFER_DOUBLEBUFFER_HINT_PGI        107000
#define STRICT_DEPTHFUNC_HINT_PGI           107030
#define STRICT_LIGHTING_HINT_PGI            107031
#define STRICT_SCISSOR_HINT_PGI             107032
#define FULL_STIPPLE_HINT_PGI               107033
#define NATIVE_GRAPHICS_BEGIN_HINT_PGI      107011
#define NATIVE_GRAPHICS_END_HINT_PGI        107012
#define CONSERVE_MEMORY_HINT_PGI            107005
#define RECLAIM_MEMORY_HINT_PGI             107006
#define ALWAYS_FAST_HINT_PGI                107020
#define ALWAYS_SOFT_HINT_PGI                107021
#define ALLOW_DRAW_OBJ_HINT_PGI             107022
#define ALLOW_DRAW_WIN_HINT_PGI             107023
#define ALLOW_DRAW_FRG_HINT_PGI             107024
#define ALLOW_DRAW_MEM_HINT_PGI             107025
#define CLIP_NEAR_HINT_PGI                  107040
#define CLIP_FAR_HINT_PGI                   107041
#define WIDE_LINE_HINT_PGI                  107042
#define BACK_NORMALS_HINT_PGI               107043
#define GL_NATIVE_GRAPHICS_HANDLE_PGI       107010
#endif

#ifndef GL_EXT_paletted_texture
#define COLOR_INDEX1_EXT                0x80E2
#define COLOR_INDEX2_EXT                0x80E3
#define COLOR_INDEX4_EXT                0x80E4
#define COLOR_INDEX8_EXT                0x80E5
#define COLOR_INDEX12_EXT               0x80E6
#define COLOR_INDEX16_EXT               0x80E7
#define COLOR_TABLE_FORMAT_EXT          0x80D8
#define COLOR_TABLE_WIDTH_EXT           0x80D9
#define COLOR_TABLE_RED_SIZE_EXT        0x80DA
#define COLOR_TABLE_GREEN_SIZE_EXT      0x80DB
#define COLOR_TABLE_BLUE_SIZE_EXT       0x80DC
#define COLOR_TABLE_ALPHA_SIZE_EXT      0x80DD
#define COLOR_TABLE_LUMINANCE_SIZE_EXT  0x80DE
#define COLOR_TABLE_INTENSITY_SIZE_EXT  0x80DF
#define TEXTURE_INDEX_SIZE_EXT          0x80ED
#define TEXTURE_1D                      0x0DE0
#define TEXTURE_2D                      0x0DE1
#define TEXTURE_3D_EXT                  0x806F
#define TEXTURE_CUBE_MAP_ARB            0x8513
#define PROXY_TEXTURE_1D                0x8063
#define PROXY_TEXTURE_2D                0x8064
#define PROXY_TEXTURE_3D_EXT            0x8070
#define PROXY_TEXTURE_CUBE_MAP_ARB      0x851B
#define TEXTURE_1D                      0x0DE0
#define TEXTURE_2D                      0x0DE1
#define TEXTURE_3D_EXT                  0x806F
#define TEXTURE_CUBE_MAP_ARB            0x8513
#endif

#ifndef GL_EXT_clip_volume_hint
#define CLIP_VOLUME_CLIPPING_HINT_EXT	0x80F0
#endif

#ifndef GL_SGIX_list_priority
#endif

#ifndef GL_SGIX_ir_instrument1
#endif

#ifndef GLX_SGIX_video_resize
#endif

#ifndef GL_SGIX_texture_lod_bias
#endif

#ifndef GLU_SGI_filter4_parameters
#endif

#ifndef GLX_SGIX_dm_buffer
#endif

#ifndef GL_SGIX_shadow_ambient
#endif

#ifndef GLX_SGIX_swap_group
#endif

#ifndef GLX_SGIX_swap_barrier
#endif

#ifndef GL_EXT_index_texture
#endif

#ifndef GL_EXT_index_material
#endif

#ifndef GL_EXT_index_func
#endif

#ifndef GL_EXT_index_array_formats
#endif

#ifndef GL_EXT_compiled_vertex_array
#endif

#ifndef GL_EXT_cull_vertex
#endif

#ifndef GLU_EXT_nurbs_tessellator
#endif

#ifndef GL_SGIX_ycrcb
#endif

#ifndef GL_EXT_fragment_lighting
#endif

#ifndef GL_IBM_rasterpos_clip
#endif

#ifndef GL_HP_texture_lighting
#endif

#ifndef GL_EXT_draw_range_elements
#endif

#ifndef GL_WIN_phong_shading
#endif

#ifndef GL_WIN_specular_fog
#endif

#ifndef GLX_SGIS_color_range
#endif

#ifndef GL_SGIS_color_range
#endif

#ifndef GL_EXT_light_texture
#endif

#ifndef GL_SGIX_blend_alpha_minmax
#endif

#ifndef GL_EXT_scene_marker
#endif

#ifndef GLX_EXT_scene_marker
#endif

#ifndef GL_SGIX_pixel_texture_bits
#endif

#ifndef GL_EXT_bgra
#endif

#ifndef GL_SGIX_async
#endif

#ifndef GL_SGIX_async_pixel
#endif

#ifndef GL_SGIX_async_histogram
#endif

#ifndef GL_INTEL_texture_scissor
#endif

#ifndef GL_INTEL_parallel_arrays
#endif

#ifndef GL_HP_occlusion_test
#endif

#ifndef GL_EXT_pixel_transform
#endif

#ifndef GL_EXT_pixel_transform_color_table
#endif

#ifndef GL_EXT_shared_texture_palette
#endif

#ifndef GLX_SGIS_blended_overlay
#endif

#ifndef GL_EXT_separate_specular_color
#endif

#ifndef GL_EXT_secondary_color
#endif

#ifndef GL_EXT_texture_env
#endif

#ifndef GL_EXT_texture_perturb_normal
#endif

#ifndef GL_EXT_multi_draw_arrays
#endif

#ifndef GL_SUN_multi_draw_arrays
#endif

#ifndef GL_EXT_fog_coord
#endif

#ifndef GL_REND_screen_coordinates
#endif

#ifndef GL_EXT_coordinate_frame
#endif

#ifndef GL_EXT_texture_env_combine
#endif

#ifndef GL_APPLE_specular_vector
#endif

#ifndef GL_APPLE_transform_hint
#endif

#ifndef GL_SUNX_constant_data
#endif

#ifndef GL_SUN_global_alpha
#endif

#ifndef GL_SUN_triangle_list
#endif

#ifndef GL_SUN_vertex
#endif

#ifndef WGL_EXT_display_color_table
#endif

#ifndef WGL_EXT_extensions_string
#endif

#ifndef WGL_EXT_make_current_read
#endif

#ifndef WGL_EXT_pixel_format
#endif

#ifndef WGL_EXT_pbuffer
#endif

#ifndef WGL_EXT_swap_control
#endif

#ifndef GL_EXT_blend_func_separate
#endif

#ifndef GL_INGR_color_clamp
#endif

#ifndef GL_INGR_interlace_read
#endif

#ifndef GL_EXT_stencil_wrap
#endif

#ifndef WGL_EXT_depth_float
#endif

#ifndef GL_EXT_422_pixels
#endif

#ifndef GL_NV_texgen_reflection
#endif

#ifndef GL_SGIX_texture_range
#endif

#ifndef GL_SUN_convolution_border_modes
#endif

#ifndef GLX_SUN_get_transparent_index
#endif

#ifndef GL_EXT_texture_env_add
#endif

#ifndef GL_EXT_texture_lod_bias
#endif

#ifndef GL_EXT_texture_filter_anisotropic
#endif

#ifndef GL_EXT_vertex_weighting
#endif

#ifndef GL_NV_light_max_exponent
#endif

#ifndef GL_NV_vertex_array_range
#endif

#ifndef GL_NV_register_combiners
#endif

#ifndef GL_NV_fog_distance
#endif

#ifndef GL_NV_texgen_emboss
#endif

#ifndef GL_NV_blend_square
#endif

#ifndef GL_NV_texture_env_combine4
#endif

#ifndef GL_MESA_resize_buffers
#endif

#ifndef GL_MESA_window_pos
#endif

#ifndef GL_EXT_texture_compression_s3tc
#endif

#ifndef GL_IBM_cull_vertex
#endif

#ifndef GL_IBM_multimode_draw_arrays
#endif

#ifndef GL_IBM_vertex_array_lists
#endif

#ifndef GL_3DFX_texture_compression_FXT1
#endif

#ifndef GL_3DFX_multisample
#endif

#ifndef GL_3DFX_tbuffer
#endif

#ifndef WGL_EXT_multisample
#endif

#ifndef GL_EXT_multisample
#endif

#ifndef GL_SGIX_vertex_preclip
#endif

#ifndef GL_SGIX_vertex_preclip_hint
#endif

#ifndef GL_SGIX_resample
#endif

#ifndef GL_SGIS_texture_color_mask
#endif

#ifndef GLX_MESA_copy_sub_buffer
#endif

#ifndef GLX_MESA_pixmap_colormap
#endif

#ifndef GLX_MESA_release_buffers
#endif

#ifndef GLX_MESA_set_3dfx_mode
#endif

#ifndef GL_EXT_texture_env_dot3
#endif

#ifndef GL_ATI_texture_mirror_once
#endif

#ifndef GL_NV_fence
#endif

#ifndef GL_IBM_static_data
#endif

#ifndef GL_IBM_texture_mirrored_repeat
#endif

#ifndef GL_NV_evaluators
#endif

#ifndef GL_NV_packed_depth_stencil
#endif

#ifndef GL_NV_register_combiners2
#endif

#ifndef GL_NV_texture_compression_vtc
#endif

#ifndef GL_NV_texture_rectangle
#endif

#ifndef GL_NV_texture_shader
#endif

#ifndef GL_NV_texture_shader2
#endif

#ifndef GL_NV_vertex_array_range2
#endif

#ifndef GL_NV_vertex_program
#endif

#ifndef GLX_SGIX_visual_select_group
#endif

#ifndef GL_SGIX_texture_coordinate_clamp
#endif

#ifndef GLX_OML_swap_method
#endif

#ifndef GLX_OML_sync_control
#endif

#ifndef GL_OML_interlace
#endif

#ifndef GL_OML_subsample
#endif

#ifndef GL_OML_resample
#endif

#ifndef WGL_OML_sync_control
#endif

#ifndef GL_NV_copy_depth_to_color
#endif

#ifndef GL_ATI_envmap_bumpmap
#endif

#ifndef GL_ATI_fragment_shader
#endif

#ifndef GL_ATI_pn_triangles
#endif

#ifndef GL_ATI_vertex_array_object
#endif

#ifndef GL_EXT_vertex_shader
#endif

#ifndef GL_ATI_vertex_streams
#endif

#ifndef WGL_I3D_digital_video_control
#endif

#ifndef WGL_I3D_gamma
#endif

#ifndef WGL_I3D_genlock
#endif

#ifndef WGL_I3D_image_buffer
#endif

#ifndef WGL_I3D_swap_frame_lock
#endif

#ifndef WGL_I3D_swap_frame_usage
#endif

#ifndef GL_ATI_element_array
#endif

#ifndef GL_SUN_mesh_array
#endif

#ifndef GL_SUN_slice_accum
#endif

#ifndef GL_NV_multisample_filter_hint
#endif

#ifndef GL_NV_depth_clamp
#endif

#ifndef GL_NV_occlusion_query
#endif

#ifndef GL_NV_point_sprite
#endif

#ifndef WGL_NV_render_depth_texture
#endif

#ifndef WGL_NV_render_texture_rectangle
#endif

#ifndef GL_NV_texture_shader3
#endif

#ifndef GL_NV_vertex_program1_1
#endif

#ifndef GL_EXT_shadow_funcs
#endif

#ifndef GL_EXT_stencil_two_side
#endif

#ifndef GL_ATI_text_fragment_shader
#endif

#ifndef GL_APPLE_client_storage
#endif

#ifndef GL_APPLE_element_array
#endif

#ifndef GL_APPLE_fence
#endif

#ifndef GL_APPLE_vertex_array_object
#endif

#ifndef GL_APPLE_vertex_array_range
#endif

#ifndef GL_APPLE_ycbcr_422
#endif

#ifndef GL_S3_s3tc
#endif

#ifndef GL_ATI_draw_buffers
#endif

#ifndef WGL_ATI_pixel_format_float
#endif

#ifndef GL_ATI_texture_env_combine3
#endif

#ifndef GL_ATI_texture_float
#endif

#ifndef GL_NV_float_buffer
#endif

#ifndef WGL_NV_float_buffer
#endif

#ifndef GL_NV_fragment_program
#endif

#ifndef GL_NV_half_float
#endif

#ifndef GL_NV_pixel_data_range
#endif

#ifndef GL_NV_primitive_restart
#endif

#ifndef GL_NV_texture_expand_normal
#endif

#ifndef GL_NV_vertex_program2
#endif

#ifndef GL_ATI_map_object_buffer
#endif

#ifndef GL_ATI_separate_stencil
#endif

#ifndef GL_ATI_vertex_attrib_array_object
#endif

#ifndef GL_OES_byte_coordinates
#endif

#ifndef GL_OES_fixed_point
#endif

#ifndef GL_OES_single_precision
#endif

#ifndef GL_OES_compressed_paletted_texture
#endif

#ifndef GL_OES_read_format
#endif

#ifndef GL_OES_query_matrix
#endif

#ifndef GL_EXT_depth_bounds_test
#endif

#ifndef GL_EXT_texture_mirror_clamp
#endif

#ifndef GL_EXT_blend_equation_separate
#endif

#ifndef GL_MESA_pack_invert
#endif

#ifndef GL_MESA_ycbcr_texture
#endif

#ifndef GL_EXT_pixel_buffer_object
#endif

#ifndef GL_NV_fragment_program_option
#endif

#ifndef GL_NV_fragment_program2
#endif

#ifndef GL_NV_vertex_program2_option
#endif

#ifndef GL_NV_vertex_program3
#endif

#ifndef GLX_SGIX_hyperpipe
#endif

#ifndef GLX_MESA_agp_offset
#endif

#ifndef GL_EXT_texture_compression_dxt1
#endif

#ifndef GL_EXT_framebuffer_object
#define GL_FRAMEBUFFER_EXT                     0x8D40
#define GL_RENDERBUFFER_EXT                    0x8D41
#define GL_STENCIL_INDEX1_EXT                  0x8D46
#define GL_STENCIL_INDEX4_EXT                  0x8D47
#define GL_STENCIL_INDEX8_EXT                  0x8D48
#define GL_STENCIL_INDEX16_EXT                 0x8D49
#define GL_RENDERBUFFER_WIDTH_EXT              0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT             0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT    0x8D44
#define GL_RENDERBUFFER_RED_SIZE_EXT           0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT         0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT          0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT         0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT         0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT       0x8D55
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT            0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT            0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT          0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT  0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT     0x8CD4
#define GL_COLOR_ATTACHMENT0_EXT                0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT                0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT                0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT                0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT                0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT                0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT                0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT                0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT                0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT                0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT               0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT               0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT               0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT               0x8CED
#define GL_COLOR_ATTACHMENT14_EXT               0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT               0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT                 0x8D00
#define GL_STENCIL_ATTACHMENT_EXT               0x8D20
#define GL_FRAMEBUFFER_COMPLETE_EXT                          0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT             0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT     0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT             0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT                0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT            0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT            0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT                       0x8CDD
#define GL_FRAMEBUFFER_BINDING_EXT             0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT            0x8CA7
#define GL_MAX_COLOR_ATTACHMENTS_EXT           0x8CDF
#define GL_MAX_RENDERBUFFER_SIZE_EXT           0x84E8
#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT   0x0506
#endif

#ifndef GL_GREMEDY_string_marker
#endif

#ifndef GL_EXT_packed_depth_stencil
#endif

#ifndef WGL_3DL_stereo_control
#endif

#ifndef GL_EXT_stencil_clear_tag
#endif

#ifndef GL_EXT_texture_sRGB
#endif

#ifndef GL_EXT_framebuffer_blit
#endif

#ifndef GL_EXT_framebuffer_multisample
#endif

#ifndef GL_MESAX_texture_stack
#endif

#endif
