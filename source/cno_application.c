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

cno_u8_type CNO_Application_Create(application_type *application, int argc, char *argv[]){
	cno_u8_type _return = 0;
	application->running = 0;
	application->awake = 0;
	application->focused = 0;
	application->initialized = 0;
	application->quit = 0;
	application->loops = 0;
	application->threads = 0;
	CNO_Time_Unix(&(*(application).start_time));
	CNO_String_Copy(&(*(application).process_name),argv[0]);
	CNO_Build_Info_Create(&(*(application).build_info));
	CNO_Environment_Create(&(*(application).environment));
	CNO_Options_Create(&(*(application).options), argc, argv);
