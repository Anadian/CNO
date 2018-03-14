/**
*	@file source/test.c
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

#include "cno_build.h"
#include "cno_string.h"
#include "cno_filestream.h"
#include "cno_time.h"
#include "cno_environment.h"

/* CSI(CNO_HAVE_STDIO,<stdio.h>) */
#if CNO_HAVE_STDIO
#include <stdio.h>
#endif /* CNO_HAVE_STDIO */

int main(int argc, char *argv[]){
	cno_unixtime_type unix_time;
	cno_calendartime_type calendar_time;
	cno_u8_type time_string[64];
	cno_filestream_type filestream;
	CNO_FileStream_AppendPlus(&filestream, "test.log");
	CNO_fprintf(stderr, "Yo.\n");
	CNO_Time_Unix(&unix_time);
	CNO_fprintf(stderr, "Yo.\n");
	CNO_Time_CalendarFromUnix(&calendar_time, unix_time);
	CNO_fprintf(stderr, "Yo. %d\n", calendar_time);
	CNO_Time_StringFromCalendar(&time_string, calendar_time);
	CNO_fprintf(stderr, "Yo. %s\n", time_string);
	CNO_fprintf(filestream, "Time is %s\n", time_string);
	CNO_String_Concatenate(&time_string,"yo.");
	CNO_fprintf(stderr, "time_string: %s\n", time_string);
	CNO_Environment_Test();
	CNO_FileStream_Sync(&filestream);
	CNO_FileStream_Close(&filestream);
	return 0;
}
