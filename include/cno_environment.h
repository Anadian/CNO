//cno_environment.h

#ifndef CNO_ENVIRONMENT_H
#define CNO_ENVIRONMENT_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

typedef struct C\Environment_WhereAmI\s{
	c\u8\ty executable_path[256];
	c\u8\ty module_path[256];
} C\Environment_WhereAmI\ty;
typedef struct C\Environment_SDL2\s{
	c\u8\ty base_path[256];
	c\u8\ty pref_path[256];
} C\Environment_SDL2\ty;
typedef struct C\Environment_XDG\s{
	c\u8\ty data_home[256]; /*~/.local/share*/
	c\u8\ty config_home[256]; /*~/.config*/
	c\u8\ty data_directories[CNO_BUFFER_MAXSIZE]; /*/usr/local/share/:/usr/share/*/
	c\u8\ty config_directories[CNO_BUFFER_MAXSIZE]; /*/etc/config*/
	c\u8\ty cache_home[256]; /*~/.cache*/
	c\u8\ty runtime_directory[CNO_BUFFER_MAXSIZE]; /*~/Shared*/
} C\Environment_XDG\ty;

typedef struct CNO_Environment_struct {
	cno_u8_type username[256];
	cno_u8_type hostname[256];
	cno_u8_type pwd[256];
	cno_u8_type home[256];
	C\Environment_WheraAmI\ty whereami;
	C\Environment_SDL2\ty sdl2;
	C\Environment_XDG\ty xdg;
	cno_u8_type ipv4_address[256];
	c\u8\ty ipv6_address[256];
} CNO_Environment_type;

cno_u8_type CNO_Environment_Init();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_ENVIRONMENT_H
