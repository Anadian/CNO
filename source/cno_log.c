/**
*	@file source/cno_log.c
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
#include "cno_log.h"

#include "cno_string.h"
#include "cno_time.h"
#include "cno_filestream.h"
#include "cno_application.h"

#if CNO_HAVE_STRETCHY_BUFFER
#include "stretchy_buffer.h"
#endif /* CNO_HAVE_STRETCHY_BUFFER */

cno_u8_type CNO_Log_Init(){
	cno_u8_type _return = 0;
#if !defined(CNO_NO_GLOBAL_STATE)
	CNO_Log_Transport_type transport = {CNO_Log_Priority_Debug, CNO_Log_Type_File, {"cno.log", 0, 0}};
	sb_push(CNO_Transports_Global, transport);
	transport = {CNO_Log_Priority_Info, CNO_Log_Type_Stream, {CNO_Application.stderr, 1}};
	sb_push(CNO_Transports_Global, transport);
	_return = 1;
#else
	_return = 0;
#endif /* !defined(CNO_NO_GLOBAL_STATE) */
	return _return;
}
cno_u8_type CNO_Log(CNO_Transport_type *transports, cno_string_type process, cno_string_type file, cno_string_type function, CNO_Log_Priority_type priority, cno_string_type format, ...){
	cno_u8_type _return = 0;
	va_list arguments;
	cno_string_type message;
	cno_u8_type buffer[256];
	cno_size_type transport_index = 0;
	if(transports == NULL){
		transports = CNO_Transports_Global;
	}
	if(process == NULL){
		
	
}
cno_u8_type CNO_Log_Quit(){
	cno_u8_type _return = 0;
#if !defined(CNO_NO_GLOBAL_STATE)
	sb_free(CNO_Transports_Global);
	_return = 1;
#else
	_return = 0;
#endif /* !defined(CNO_NO_GLOBAL_STATE) */
	return _return;
}
