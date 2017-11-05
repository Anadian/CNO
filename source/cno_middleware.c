/**
*	@file cno_middleware.c
*	@brief Function definitions for initialising and quitting any middleware (such as SDL2).
*	@author Anadian
*	@copyright MIT License
*/
#include "cno_middleware.h"

#if CNO_ALLOW_OPTIONS
#include "cno_options.h"
#define CNO_MIDDLEWARE_OPTIONS CNO_Options
#else
#define CNO_MIDDLEWARE_OPTIONS CNO_noop
#endif //CNO_ALLOW_OPTIONS

cno_u8_type CNO_Middleware_Init(){
	cno_u8_type _return;
#if CNO_HAVE_SDL2
	if(CNO_MIDDLEWARE_OPTIONS
