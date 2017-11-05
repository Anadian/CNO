//cno_log.c

#include "cno_log.h"

#include "cno_string.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //sprintf, f*,
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_ERRNO
#include <errno.h> //errno
#endif //CNO_HAVE_ERRNO

cno_u8_type CNO_Log_OpenFile_private(cno_file_type *filehandle, CNO_Log_type *log);
cno_u8_type CNO_Log_CloseFile_private(CNO_Log_type *log);

cno_u8_type CNO_Log_Init(/*CNO_Log_type *log, CNO_Log_Priority_type verbosity, cno_u8_type colour, cno_u8_type stream, cno_cstring_type filename*/){
	cno_u8_type _return;
#if CNO_LOG_ENGINE == CNO_LOG_ENGINE_STDIO && !defined(CNO_NO_GLOBAL_STATE)
	CNO_Mutex_Lock(&CNO_Log_Mutex);
	cno_string_type time_string = CNO_Time_StringFromCurrent();
	CNO_String_Concatenate(&time_string, ".log");
	CNO_GlobalLog = {verbosity = 5, colour = 1, stream = 2, file = time_string, persist = 0,  overwrite = 0};
	
#else
	_return = 0;
#endif //CNO_LOG_ENGINE == CNO_LOG_ENGINE_STDIO && !defined(CNO_NO_GLOBAL_STATE)
	return _return;
}
	
