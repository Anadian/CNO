/**
*	@file cno_middleware.c
*	@brief Function definitions for initialising and quitting any middleware (such as SDL2).
*	@author Anadian
*	@copyright MIT License
	Copyright 2017 Canosw
	Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the "Software"), to deal in the Software 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
permit persons to whom the Software is furnished to do so, subject to the following 
conditions:
	The above copyright notice and this permission notice shall be included in all copies 
or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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
	
