//cno_environment.h

#ifndef CNO_ENVIRONMENT_H
#define CNO_ENVIRONMENT_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#include "cno_string.h"

/* CSI(CNO_HAVE_PARSON,"parson.h") */
#if CNO_HAVE_PARSON
#include "parson.h"
#endif /* CNO_HAVE_PARSON */

typedef struct CNO_Environment_Standard_struct{
	string_t *username;
	string_t *hostname;
	string_t *pwd;
	string_t * home;
} CNO_Environment_Standard_type;
typedef struct CNO_Environment_WhereAmI_struct{
	string_t *executable_path;
	string_t *module_path;
} CNO_Environment_WhereAmI_type;
typedef struct CNO_Environment_SDL2_struct{
	string_t *base_path;
	string_t *pref_path;
} CNO_Environment_SDL2_type;
typedef struct CNO_Environment_XDG_struct{
	string_t *data_home; /*~/.local/share*/
	string_t *config_home; /*~/.config*/
	string_t *data_directories; /*/usr/local/share/:/usr/share/*/
	string_t *config_directories; /*/etc/config*/
	string_t *cache_home; /*~/.cache*/
	string_t *runtime_directory; /*~/Shared*/
} CNO_Environment_XDG_type;
typedef struct CNO_Environment_Network_struct{
	string_t *ipv4_address;
	string_t *ipv6_address;
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
