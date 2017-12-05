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

cno_u8_type CNO_Time_Unix(cno_unixtime_type *unix_time);
cno_u8_type CNO_Time_Clock(cno_clocktime_type *clock_time);
cno_u8_type CNO_Time_CalendarFromUnix(cno_calendartime_type *calendar_time, cno_unixtime_type unix_time);
cno_u8_type CNO_Time_StringFromCalendar(cno_string_type *string, cno_calendartime_type calendar_time);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_TIME_H
