/**
*	@file include/cno_application.h
*	@brief Globals pertaining to the application's state.
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

#ifndef CNO_APPLICATION_H
#define CNO_APPLICATION_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"
#include "cno_string.h"
#include "cno_time.h"
#include "cno_filestream.h"
#include "cno_build_info.h"
#include "cno_environment.h"
#include "cno_mutex.h"

typedef struct CNO_Application_struct{
	cno_u8_type running;
	cno_u8_type awake;
	cno_u8_type focused;
	cno_u8_type initialized;
	cno_u8_type quit;
	cno_u32_type loops;
	cno_u8_type threads;
	cno_unixtime_type start_time;
	cno_u8_type process_name[64];
	CNO_Build_Info_type build_info;
	CNO_Evironment_type evironment;
	CNO_Settings_type settings;
	cno_filestream_type stdout;
	cno_filestream_type stderr;
	c\u8\ty middleware_initialized;
	c\u8\ty middleware_quit;
	CNO_Mutex_type mutex;
} CNO_Application_type;

cno_u8_type CNO_Application_Init();
c\u8\ty C\App\_Create(C\App\\ty *application, int argc, char *argv[]);
c\u8\ty C\App\_Destroy(C\App\\ty *application);
cno_u8_type CNO_Application_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_APPLICATION_H
