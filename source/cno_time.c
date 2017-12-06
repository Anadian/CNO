//cno_time.c: Time retieval functions

#include "cno_time.h"

#if CNO_HAVE_TIME
#include <time.h> //time, gmtime, strftime
#endif //CNO_HAVE_TIME

/* CSI(CNO_HAVE_STDIO,<stdio.h>) */
#if CNO_HAVE_STDIO
#include <stdio.h>
#endif /* CNO_HAVE_STDIO */

cno_u8_type CNO_Time_Unix(cno_unixtime_type *unix_time){
	cno_u8_type _return = 0;
#if CNO_HAVE_TIME
	*unix_time = time(NULL);
	_return = 1;
#endif //CNO_HAVE_TIME
	return _return;
}
cno_u8_type CNO_Time_Clock(cno_clocktime_type *clock_time){
	cno_u8_type _return = 0;
#if CNO_HAVE_TIME
	*clock_time = clock();
	_return = 1;
#endif //CNO_HAVE_TIME
	return _return;
}
cno_u8_type CNO_Time_CalendarFromUnix(cno_calendartime_type *calendar_time, cno_unixtime_type unix_time){
	cno_u8_type _return = 0;
#if CNO_HAVE_TIME
	*calendar_time = *(gmtime(&unix_time));
	_return = 1;
#endif //CNO_HAVE_TIME
	return _return;
}
cno_u8_type CNO_Time_StringFromCalendar(cno_string_type *string, cno_calendartime_type calendar_time){
	cno_u8_type _return = 0;
	//CNO_fprintf(stderr, "%s %d\n", string, calendar_time);
#if CNO_HAVE_TIME
	cno_u8_type buffer[64];
	strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", &calendar_time);
	//CNO_fprintf(stderr, "Yo. %s\n", buffer);
	CNO_String_Copy(string, buffer);
	_return = 1;
#endif //CNO_HAVE_TIME
	return _return;
}
