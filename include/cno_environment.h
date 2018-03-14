//cno_environment.h

#ifndef CNO_ENVIRONMENT_H
#define CNO_ENVIRONMENT_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

/* CSI(CNO_HAVE_PARSON,"parson.h") */
#if CNO_HAVE_PARSON
#include "parson.h"
#endif /* CNO_HAVE_PARSON */

typedef struct CNO_Environment_Standard_struct{
	cno_u8_type username[256];
	cno_u8_type hostname[256];
	cno_u8_type pwd[256];
	cno_u8_type home[256];
} CNO_Environment_Standard_type;
typedef struct CNO_Environment_WhereAmI_struct{
	cno_u8_type executable_path[256];
	cno_u8_type module_path[256];
} CNO_Environment_WhereAmI_type;
typedef struct CNO_Environment_SDL2_struct{
	cno_u8_type base_path[256];
	cno_u8_type pref_path[256];
} CNO_Environment_SDL2_type;
typedef struct CNO_Environment_XDG_struct{
	cno_u8_type data_home[256]; /*~/.local/share*/
	cno_u8_type config_home[256]; /*~/.config*/
	cno_u8_type data_directories[CNO_BUFFER_MAXSIZE]; /*/usr/local/share/:/usr/share/*/
	cno_u8_type config_directories[CNO_BUFFER_MAXSIZE]; /*/etc/config*/
	cno_u8_type cache_home[256]; /*~/.cache*/
	cno_u8_type runtime_directory[CNO_BUFFER_MAXSIZE]; /*~/Shared*/
} CNO_Environment_XDG_type;
typedef struct CNO_Environment_Network_struct{
	cno_u8_type ipv4_address[256];
	cno_u8_type ipv6_address[256];
} CNO_Environment_Network_type;

typedef struct CNO_Environment_struct {
	CNO_Environment_Standard_type standard;
	CNO_Environment_WhereAmI_type whereami;
	CNO_Environment_SDL2_type sdl2;
	CNO_Environment_XDG_type xdg;
	CNO_Environment_Network_type network;
} CNO_Environment_type;

cno_u8_type CNO_Environment_Standard_Init(CNO_Environment_Standard_type *environment_standard);
cno_u8_type CNO_Environment_WhereAmI_Init(CNO_Environment_WhereAmI_type *environment_whereami);
cno_u8_type CNO_Environment_SDL2_Init(CNO_Environment_SDL2_type *environment_sdl2);
cno_u8_type CNO_Environment_XDG_Init(CNO_Environment_XDG_type *environment_xdg);

cno_u8_type CNO_Environment_Init(CNO_Environment_type *environment);
cno_u8_type CNO_Environment_ToJSON(JSON_Value *json_value, CNO_Environment_type *environment);
cno_u8_type CNO_Environment_Test();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_ENVIRONMENT_H
