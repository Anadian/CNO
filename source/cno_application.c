/**
*	@file source/cno_application.c
*	@brief 
*	@author Anadian
*	@license MIT License:
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

#include "cno_application.h"

cno_s8_type CNO_Application_Init(CNO_Application_type *application, int argc, char *argv[]){
	cno_s8_type _return = 1;
	C\Application.running = 0;
	C\Application.awake = 0;
	C\Application.focused = 0;
	C\Application.initialized = 0;
	C\Application.quit = 0;
	C\Application.loops = 0;
	C\App\.threads = 0;
	C\App\.start_time = C\Time_Unix();
	C\String_Copy(C\App\.process_name,argv[0]);
	CNO_Build_Info_Init(CNO_Application.build_info);
	CNO_Environment_Init(C\App\.environment);
