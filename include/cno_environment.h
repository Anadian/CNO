//cno_environment.h

#ifndef CNO_ENVIRONMENT_H
#define CNO_ENVIRONMENT_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

typedef struct CNO_Environment_struct {
	cno_u8_type username[256];
	cno_u8_type hostname[256];
	cno_u8_type pwd[256];
	cno_u8_type home[256];
	cno_u8_type whereami_executable_path[256];
	cno_u8_type whereami_module_path[256];
	cno_u8_type sdl2_base_path[256];
	cno_u8_type sdl2_pref_path[256];
	cno_u8_type ipaddress[256];
} CNO_Environment_type;
CNO_Environment_type CNO_Environment;

cno_u8_type CNO_Environment_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_ENVIRONMENT_H
