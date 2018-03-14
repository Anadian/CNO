//cno_environment.c

#include "cno_environment.h"

#include "cno_build.h"
#include "cno_string.h"

#if CNO_HAVE_STDLIB
#include <stdlib.h> //getenv
#endif //CNO_HAVE_STDLIB

#if CNO_HAVE_WHEREAMI
#include "whereami.h"
#endif // CNO_HAVE_WHEREAMI

#if CNO_HAVE_SDL2
#include "SDL2/SDL.h"
# endif //CNO_HAVE_SDL2

#if CNO_HAVE_PARSON
#include "parson.h"
#endif //CNO_HAVE_PARSON

/* CSI(CNO_HAVE_STDIO,<stdio.h>) */
#if CNO_HAVE_STDIO
#include <stdio.h>
#endif /* CNO_HAVE_STDIO */

cno_u8_type CNO_Environment_Standard_Init(CNO_Environment_Standard_type *environment_standard){
	cno_u8_type _return = 0;
#if CNO_HAVE_STDLIB
	if(getenv("USER") != NULL) CNO_String_Copy(((*environment_standard).username),getenv("USER"));
	else if(getenv("USERNAME") != NULL) CNO_String_Copy(((*environment_standard).username),getenv("USERNAME"));
	else if(getenv("LOGNAME") != NULL) CNO_String_Copy(((*environment_standard).username),getenv("LOGNAME"));
	if(getenv("HOSTNAME") != NULL) CNO_String_Copy(((*environment_standard).hostname),getenv("HOSTNAME"));
	if(getenv("PWD") != NULL) CNO_String_Copy(((*environment_standard).pwd),getenv("PWD"));
	if(getenv("HOME") != NULL) CNO_String_Copy(((*environment_standard).home),getenv("HOME"));
	_return = 1;
#endif //CNO_HAVE_STDLIB
	return _return;
}

cno_u8_type CNO_Environment_WhereAmI_Init(CNO_Environment_WhereAmI_type *environment_whereami){
	cno_u8_type _return = 0;
#if CNO_HAVE_WHEREAMI
	wai_getExecutablePath(&((*environment_whereami).executable_path), sizeof((*environment_whereami).executable_path), NULL);
	wai_getModulePath(&((*environment_whereami).module_path), sizeof((*environment_whereami).module_path), NULL);
	_return = 1;
#endif //CNO_HAVE_WHEREAMI
	return _return;
}

cno_u8_type CNO_Environment_SDL2_Init(CNO_Environment_SDL2_type *environment_sdl2){
	cno_u8_type _return = 0;
#if CNO_HAVE_SDL2
	cno_string_type sdl2_base_path = SDL_GetBasePath();
	cno_string_type sdl2_pref_path = SDL_GetPrefPath(CNO_BUILD_ORGANIZATION, CNO_BUILD_NAME);
	
	CNO_String_Copy(&((*environment_sdl2).base_path), sdl2_base_path);
	CNO_String_Copy(&((*environment_sdl2).pref_path), sdl2_pref_path);

	SDL_free(sdl2_pref_path);
	SDL_free(sdl2_base_path);
	
	_return = 1;
#endif //CNO_HAVE_SDL2
	return _return;
}

cno_u8_type CNO_Environment_XDG_Init(CNO_Environment_XDG_type *environment_xdg){
	cno_u8_type _return = 0;
#if CNO_HAVE_STDLIB
	if(getenv("XDG_DATA_HOME") != NULL) CNO_String_Copy(&((*environment_xdg).data_home), getenv("XDG_DATA_HOME"));
	else CNO_String_Copy(&((*environment_xdg).data_home), "~/.local/share");
	if(getenv("XDG_CONFIG_HOME") != NULL) CNO_String_Copy(&((*environment_xdg).config_home), getenv("XDG_CONFIG_HOME"));
	else CNO_String_Copy(&((*environment_xdg).config_home), "~/.config");
	if(getenv("XDG_DATA_DIRS") != NULL) CNO_String_Copy(&((*environment_xdg).data_directories), getenv("XDG_DATA_DIRS"));
	else CNO_String_Copy(&((*environment_xdg).data_directories), "/usr/local/share/:/usr/share/");
	if(getenv("XDG_CONFIG_DIRS") != NULL) CNO_String_Copy(&((*environment_xdg).config_directories), getenv("XDG_CONFIG_DIRS"));
	else CNO_String_Copy(&((*environment_xdg).config_directories), "/etc/config");
	if(getenv("XDG_CACHE_HOME") != NULL) CNO_String_Copy(&((*environment_xdg).cache_home), getenv("XDG_CACHE_HOME"));
	else CNO_String_Copy(&((*environment_xdg).cache_home), "~/.cache");
	if(getenv("XDG_RUNTIME_DIR") != NULL) CNO_String_Copy(&((*environment_xdg).runtime_directory), getenv("XDG_RUNTIME_DIR"));
	else CNO_String_Copy(&((*environment_xdg).runtime_directory), "~/Shared");
	_return = 1;
#endif //CNO_HAVE_STDLIB
	return _return;
}

cno_u8_type CNO_Environment_Init(CNO_Environment_type *environment){
	cno_u8_type _return = 0;
	cno_u8_type standard_init_return = CNO_Environment_Standard_Init(&((*environment).standard));
	cno_u8_type whereami_init_return = CNO_Environment_WhereAmI_Init(&((*environment).whereami));
	cno_u8_type sdl2_init_return = CNO_Environment_SDL2_Init(&((*environment).sdl2));
	cno_u8_type xdg_init_return = CNO_Environment_XDG_Init(&((*environment).xdg));
	if( (standard_init_return == 1) && (whereami_init_return == 1) && (sdl2_init_return == 1) && (xdg_init_return == 1) ) _return = 1;
	return _return;
}

cno_u8_type CNO_Environment_ToJSON(JSON_Value *json_value, CNO_Environment_type *environment){
	cno_u8_type _return = 0;
#if CNO_HAVE_PARSON
	JSON_Object *environment_object = json_value_get_object(json_value);

	JSON_Value *standard_value = json_value_init_object();
	JSON_Object *standard_object = json_value_get_object(standard_value);
	JSON_Status set_username_return = json_object_set_string(standard_object, "username", (*environment).standard.username);
	JSON_Status set_hostname_return = json_object_set_string(standard_object, "hostname", (*environment).standard.hostname);
	JSON_Status set_pwd_return = json_object_set_string(standard_object, "pwd", (*environment).standard.pwd);
	JSON_Status set_home_return = json_object_set_string(standard_object, "home", (*environment).standard.home);
	JSON_Status set_standard_return = json_object_set_value(environment_object, "standard", standard_value);
	json_value_free(standard_value);

	JSON_Value *whereami_value = json_value_init_object();
	JSON_Object *whereami_object = json_value_get_object(whereami_value);
	JSON_Status set_executable_path_return = json_object_set_string(whereami_object, "executable_path", (*environment).whereami.executable_path);
	JSON_Status set_module_path_return = json_object_set_string(whereami_object, "module_path", (*environment).whereami.module_path);
	JSON_Status set_whereami_return = json_object_set_value(environment_object, "whereami", whereami_value);
	json_value_free(whereami_value);

	JSON_Value *sdl2_value = json_value_init_object();
	JSON_Object *sdl2_object = json_value_get_object(sdl2_value);
	JSON_Status set_base_path_return = json_object_set_string(sdl2_object, "base_path", (*environment).sdl2.base_path);
	JSON_Status set_pref_path_return = json_object_set_string(sdl2_object, "pref_path", (*environment).sdl2.pref_path);
	JSON_Status set_sdl2_return = json_object_set_value(environment_object, "sdl2", sdl2_value);
	json_value_free(sdl2_value);

	JSON_Value *xdg_value = json_value_init_object();
	JSON_Object *xdg_object = json_value_get_object(xdg_value);
	JSON_Status set_data_home_return = json_object_set_string(xdg_object, "data_home", (*environment).xdg.data_home);
	JSON_Status set_config_home_return = json_object_set_string(xdg_object, "config_home", (*environment).xdg.config_home);
	JSON_Status set_data_directories_return = json_object_set_string(xdg_object, "data_directories", (*environment).xdg.data_directories);
	JSON_Status set_config_directories_return = json_object_set_string(xdg_object, "config_directories", (*environment).xdg.config_directories);
	JSON_Status set_cache_home_return = json_object_set_string(xdg_object, "cache_home", (*environment).xdg.cache_home);
	JSON_Status set_runtime_directory_return = json_object_set_string(xdg_object, "runtime_directory", (*environment).xdg.runtime_directory);
	JSON_Status set_xdg_return = json_object_set_value(environment_object, "xdg", xdg_value);
	json_value_free(xdg_value);

	if( (set_standard_return == JSONSuccess) && (set_whereami_return == JSONSuccess) && (set_sdl2_return == JSONSuccess) && (set_xdg_return == JSONSuccess) ) _return = 1;
#endif /* CNO_HAVE_PARSON */
	return _return;
}

cno_u8_type CNO_Environment_Test(){
	cno_u8_type _return = 0;
	CNO_Environment_type *environment;
	CNO_Environment_Init(environment);
#if CNO_HAVE_PARSON
	JSON_Value *json_value = json_value_init_object();
	cno_u8_type environment_tojson_return = CNO_Environment_ToJSON(json_value,environment);
	cno_string_type json_string = json_serialize_to_string(json_value);
	CNO_fprintf(stderr,json_string);
	json_free_serialized_string(json_string);
	json_value_free(json_value);
	if(environment_tojson_return == 1) _return = 1;
#endif /* CNO_HAVE_PARSON */
	return _return;
}
