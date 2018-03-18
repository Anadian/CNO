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
	CNO_fprintf(stderr,"%s\n", __func__);
#if CNO_HAVE_STDLIB
	(*environment_standard).username = string_init();
	if(getenv("USER") != NULL) CNO_String_Copy((*envronment_standard).username,getenv("USER"));
	else if(getenv("USERNAME") != NULL) CNO_String_Copy(&buffer,getenv("USERNAME"));
	else if(getenv("LOGNAME") != NULL) CNO_String_Copy(&buffer,getenv("LOGNAME"));
	buffer = &((*environment_standard).hostname);
	if(getenv("HOSTNAME") != NULL) CNO_String_Copy(&buffer,getenv("HOSTNAME"));
	buffer = &((*environment_standard).pwd);
	if(getenv("PWD") != NULL) CNO_String_Copy(&buffer,getenv("PWD"));
	buffer = &((*environment_standard).home);
	if(getenv("HOME") != NULL) CNO_String_Copy(&buffer,getenv("HOME"));
	CNO_fprintf(stderr, "%s\n", *buffer);
	_return = 1;
#endif //CNO_HAVE_STDLIB
	CNO_fprintf(stderr,"%s: %d\n", __func__, _return);
	return _return;
}

cno_u8_type CNO_Environment_WhereAmI_Init(CNO_Environment_WhereAmI_type *environment_whereami){
	cno_u8_type _return = 0;
	CNO_fprintf(stderr, "%s\n", __func__);
#if CNO_HAVE_WHEREAMI
	cno_string_type *buffer = &((*environment_whereami).executable_path);
	cno_u8_type length = 0;
	length = wai_getExecutablePath(NULL, 0, NULL);
	CNO_fprintf(stderr, "length: %d\n", length);
	cno_u8_type wai_buffer[length + 1];
	wai_getExecutablePath(wai_buffer, sizeof(wai_buffer), NULL);
	wai_buffer[length] = '\0';
	CNO_fprintf(stderr, "wai_buffer: %s\n", wai_buffer);
	cno_string_type *wai_pointer = wai_buffer;
	CNO_String_Copy(&buffer, wai_pointer);
	CNO_fprintf(stderr, "%s\n", (*environment_whereami).executable_path);
	buffer = &((*environment_whereami).module_path);
	wai_getModulePath(buffer, sizeof((*environment_whereami).module_path), NULL);
	_return = 1;
#endif //CNO_HAVE_WHEREAMI
	CNO_fprintf(stderr, "%s returned: %d\n", __func__, _return);
	return _return;
}

cno_u8_type CNO_Environment_SDL2_Init(CNO_Environment_SDL2_type *environment_sdl2){
	cno_u8_type _return = 0;
	CNO_fprintf(stderr, "%s\n", __func__);
#if CNO_HAVE_SDL2
	cno_string_type sdl2_base_path = SDL_GetBasePath();
	cno_string_type sdl2_pref_path = SDL_GetPrefPath(CNO_BUILD_ORGANIZATION, CNO_BUILD_NAME);
	
	cno_string_type *buffer = &((*environment_sdl2).base_path);
	CNO_String_Copy(&buffer, sdl2_base_path);
	buffer = &((*environment_sdl2).base_path);
	CNO_String_Copy(&buffer, sdl2_pref_path);

	SDL_free(sdl2_pref_path);
	SDL_free(sdl2_base_path);
	
	_return = 1;
#endif //CNO_HAVE_SDL2
	CNO_fprintf(stderr, "%s returned: %d\n", __func__, _return);
	return _return;
}

cno_u8_type CNO_Environment_XDG_Init(CNO_Environment_XDG_type *environment_xdg){
	cno_u8_type _return = 0;
	CNO_fprintf(stderr, "%s\n", __func__);
#if CNO_HAVE_STDLIB
	cno_string_type *buffer = &((*environment_xdg).data_home);
	if(getenv("XDG_DATA_HOME") != NULL) CNO_String_Copy(&buffer, getenv("XDG_DATA_HOME"));
	else CNO_String_Copy(&buffer, "~/.local/share");
	buffer = &((*environment_xdg).config_home);
	if(getenv("XDG_CONFIG_HOME") != NULL) CNO_String_Copy(&buffer, getenv("XDG_CONFIG_HOME"));
	else CNO_String_Copy(&buffer, "~/.config");
	buffer = &((*environment_xdg).data_directories);
	if(getenv("XDG_DATA_DIRS") != NULL) CNO_String_Copy(&buffer, getenv("XDG_DATA_DIRS"));
	else CNO_String_Copy(&buffer, "/usr/local/share/:/usr/share/");
	buffer = &((*environment_xdg).config_directories);
	if(getenv("XDG_CONFIG_DIRS") != NULL) CNO_String_Copy(&buffer, getenv("XDG_CONFIG_DIRS"));
	else CNO_String_Copy(&buffer, "/etc/config");
	buffer = &((*environment_xdg).cache_home);
	if(getenv("XDG_CACHE_HOME") != NULL) CNO_String_Copy(&buffer, getenv("XDG_CACHE_HOME"));
	else CNO_String_Copy(&buffer, "~/.cache");
	buffer = &((*environment_xdg).runtime_directory);
	if(getenv("XDG_RUNTIME_DIR") != NULL) CNO_String_Copy(&buffer, getenv("XDG_RUNTIME_DIR"));
	else CNO_String_Copy(&buffer, "~/Shared");
	_return = 1;
#endif //CNO_HAVE_STDLIB
	CNO_fprintf(stderr, "%s returned: %d\n", __func__, _return);
	return _return;
}

cno_u8_type CNO_Environment_Init(CNO_Environment_type *environment){
	cno_u8_type _return = 0;
	CNO_fprintf(stderr, "CNO_Environment_Init\n");
	cno_u8_type standard_init_return = CNO_Environment_Standard_Init(&((*environment).standard));
	cno_u8_type whereami_init_return = CNO_Environment_WhereAmI_Init(&((*environment).whereami));
	CNO_fprintf(stderr, "%s: Passed WhereAmI\n", __func__);
	cno_u8_type sdl2_init_return = CNO_Environment_SDL2_Init(&((*environment).sdl2));
	cno_u8_type xdg_init_return = CNO_Environment_XDG_Init(&((*environment).xdg));
	if( (standard_init_return == 1) && (whereami_init_return == 1) && (sdl2_init_return == 1) && (xdg_init_return == 1) ) _return = 1;
	CNO_fprintf(stderr, "CNO_Environment_Init returned: %d\n", _return);
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
	CNO_fprintf(stderr,"CET\n");
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
