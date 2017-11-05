//cno_time.h: Time retrieval functions

#ifndef CNO_TIME_H
#define CNO_TIME_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"
#include "cno_string.h"

#if CNO_HAVE_TIME
#include <time.h>
typedef time_t cno_unixtime_type;
typedef clock_t cno_clocktime_type;
typedef struct tm cno_calendartime_type;
#endif //CNO_HAVE_TIME

cno_unixtime_type CNO_Time_Unix();
cno_clocktime_type CNO_Time_CLock();
cno_calendartime_type CNO_Time_CalendarFromUnix(cno_unixtime_type unix_time);
cno_string_type CNO_Time_StringFromCalendar(cno_calendartime_type calendar_time);
#define CNO_Time_CalendarFromCurrent() CNO_Time_CalendarFromUnix(CNO_Time_Unix())
#define CNO_Time_StringFromUnix(unixtime) CNO_Time_StringFromCalendar(CNO_Time_CalendarFromUnix(unixtime))
#define CNO_Time_StringFromCurrent() CNO_Time_StringFromCalendar(CNO_Time_CalendarFromUnix(CNO_Time_Unix()))

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_TIME_H
