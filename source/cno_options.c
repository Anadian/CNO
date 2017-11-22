//cno_options.c
#include "cno_options.h"

#include "cno_build_info.h"

#if CNO_HAVE_STRING
#include <string.h> //strcpy, strcmp
#endif //CNO_HAVE_STRING
#if CNO_HAVE_STDIO
#include <stdio.h> //printf
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STDLIB
#include <stdlib.h> //exit, atoi
#endif //CNO_HAVE_STDLIB

cno_u8_type CNO_Options_Process(int argc, char *argv[]){
	cno_u8_type _return;
#if CNO_ALLOW_PRINTF
	cno_size_type i;
	for(i = 0; i < argc; i++){
		CNO_printf("%d: %s\n", i, argv[i]);
	}
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_OPTIONS == 1
	int gopt_argc;
	gopt_argc = gopt(argv, CNO_Options);
	if(gopt_argc > 0){
#if CNO_ALLOW_PRINTF
		CNO_printf("Non-option arguments: %d\n", gopt_argc);
#endif //CNO_ALLOW_PRINTF
	}
#if CNO_ALLOW_EXIT
	gopt_error("GOPT error:", CNO_Options);
#endif //CNO_ALLOW_EXIT
	_return = 1;
#else
	_return = 0;
#endif //CNO_ALLOW_OPTIONS
	return _return;
}
cno_cstring_type CNO_Options_Query(cno_cstring_type key, cno_u32_type *count){
	cno_size_type i;
	cno_size_type number_of_options = (sizeof(CNO_Options)/sizeof(CNO_Option_type));
	for(i = 0; i < number_of_options; i++){
		
