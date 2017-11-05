//cno_time.c: Time retieval functions

#include "cno_time.h"

#if CNO_HAVE_TIME
#include <time.h> //time, gmtime, strftime
#endif //CNO_HAVE_TIME

cno_unixtime_type CNO_Time_Unix(){
#if CNO_HAVE_TIME
	return time(NULL);
#endif //CNO_HAVE_TIME
	return 0;
}
cno_clocktime_type CNO_Time_Clock(){
#if CNO_HAVE_TIME
	return clock(NULL);
#endif //CNO_HAVE_TIME
	return 0;
}
cno_calendartime_type CNO_Time_CalendarFromUnix(cno_unixtime_type unix_time){
#if CNO_HAVE_TIME
	return gmtime(unix_time);
#endif //CNO_HAVE_TIME
	return 0;
}
cno_string_type CNO_Time_StringFromCalendar(cno_calendartime_type calendar_time){
#if CNO_HAVE_TIME
	cno_u8_type buffer[64];
	strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", calendar_time);
	return buffer;
#endif //CNO_HAVE_TIME
	return 0;
}
