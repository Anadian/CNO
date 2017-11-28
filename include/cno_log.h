//cno_log.h

#ifndef CNO_LOG_H
#define CNO_LOG_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

// #if !defined(CNO_LOG_ENGINE)
// #define CNO_LOG_ENGINE CNO_LOG_ENGINE_NONE
// #endif //!defined(CNO_SETTINGS_LOG_ENGINE)
// 
// #if CNO_LOG_ENGINE == CNO_LOG_ENGINE_ORIGINAL
// #if CNO_HAVE_STDARG
// #include <stdarg.h>
// typedef va_list cno_va_list_type;
// #endif //CNO_HAVE_STDARG
// 
// #define cno_log(priority, ...) (priority <= CNO_LowLevelConfig.debug.verbosity)?(CNO_GlobalLog(__func__, __VA_ARGS__)):(CNO_noop)
// 
// cno_u8_type CNO_GlobalLog(cno_cstring_type function, cno_cstring_type format, ...);
// cno_u8_type CNO_SpecificLog(cno_cstring_type filename, cno_cstring_type function, cno_cstring_type format, ...);
// cno_u8_type CNO_NewGlobalLog();
// 
// #elif CNO_LOG_ENGINE == CNO_LOG_ENGINE_LOGH
// #include "log.h"
// 
// #define cno_log(...) CNO_noop
// #define cno_log_debug(...) log_debug(__VA_ARGS__)
// #define cno_log_info(...) log_info(__VA_ARGS__)
// #define cno_log_warn(...) log_warn(__VA_ARGS__)
// #define cno_log_error(...) log_error(__VA_ARGS__)
// #else
// #define cno_log(...) CNO_noop
// #define cno_log_debug(...) CNO_noop
// #define cno_log_info(...) CNO_noop
// #define cno_log_warn(...) CNO_noop
// #define cno_log_error(...) CNO_noop
// #endif //CNO_LOG_ENGINE

#if CNO_HAVE_STDARG
#include <stdarg.h>
#endif //CNO_HAVE_STDARG
#if CNO_HAVE_UNISTD
#include <unistd.h> //isatty
#endif //CNO_HAVE_UNISTD

#include "cno_time.h"
#include "cno_mutex.h"

//\033[<STYLE>;<COLOUR>m	Start foreground format
//\033[<BACKGROUND>m		Start background format
//\x1B[0m 	Reset to plain/normal.
//<STYLE>:
//0 normal
//1 bold
//2 dim
//3 italics
//4 underline
//5 blinking
//6 ???
//7 White on colour background
//8 Invisible
//<COLOUR>:
//30 black
//31 red
//32 green
//33 yellow
//34 blue
//35 magenta
//36 cyan
//37 white
//<BACKGROUND>:
//40 white background
//41 red bg
//42 green bg
//43 yellow bg
//44 blue bg
//45 magenta bg
//46 cyan bg
//47 white bg

#include "cno_string.h"

typedef enum CNO_Log_Priority_enum{
	CNO_Log_Priority_None=0,
	CNO_Log_Priority_Error=1, //Red
	CNO_Log_Priority_Warn=2, //Yellow
	CNO_Log_Priority_Note=3, //Magenta
	CNO_Log_Priority_Info=4, //Blue
	CNO_Log_Priority_Debug=5 //Green
} CNO_Log_Priority_type; //cyan?
typedef enum CNO_Log_Type_enum{
	CNO_Log_Type_None=0,
	CNO_Log_Type_File=1,
	CNO_Log_Type_Stream=2,
	CNO_Log_Type_Buffer=3
} CNO_Log_Type_type;
typedef struct CNO_Log_File_struct{
	cno_string_type name;
	cno_u8_type persist; /* Keep file open. */
	cno_u8_type overwrite; /* Overwrite file if it already exists, otherwise append */
} CNO_Log_File_type;
typedef struct CNO_Log_Stream_struct{
	cno_filestream_type stream;
	cno_u8_type colour;
} CNO_Log_Stream_type;
typedef struct CNO_Log_Buffer_struct{
	cno_u8_type *pointer;
	cno_u16_type offset;
	cno_u16_type length;
} CNO_Log_Buffer_type;

typedef struct CNO_Transport_struct{
	CNO_Log_Priority_type priority;
	CNO_Log_Type_type type;
	union{
		CNO_Log_File_type file;
		CNO_Log_Stream_type stream;
		CNO_Log_Buffer_type buffer;
	}
} CNO_Transport_type;

#if !defined(CNO_NO_GLOBAL_STATE)
CNO_Transport_type *CNO_Transports_Global = NULL;
//CDM(CNO_Log_Transport_Add_Global,CNO_Log_Transport_Add(CNO_Transports_Global, __VA_ARGS__))
#if !defined(CNO_Log_Transport_Add_Global) //p
#define CNO_Log_Transport_Add_Global(...) CNO_Log_Transport_Add(CNO_Transports_Global, __VA_ARGS__) //p
#endif //!defined(CNO_Log_Transport_Add_Global) //p
cno_mutex_type CNO_GlobalLog_Mutex;
#endif /*!defined(CNO_NO_GLOBAL_STATE)*/

//[bold] Error: [dim] file (line): [normal] function (time unix/clock): message (errno: strerror | other error messages)
cno_u8_type CNO_Log_Init();
/*cno_u8_type CNO_Log_Transport_AddGlobal(CNO_Transport_type transport);
cno_u8_type CNO_Log_Transport_ClearGlobal();
cno_u8_type CNO_Log_Global(cno_string_type process, cno_string_type file, cno_string_type function, CNO_Log_Priority_type priority, cno_string_type format, ...);*/
cno_u8_type CNO_Log_Transport_Add(CNO_Transport_type *transports, CNO_Transport_type transport);
cno_u8_type CNO_Log_Transport_Clear(CNO_Transport_type *transports);
cno_u8_type CNO_Log(CNO_Transport_type *transports, cno_string_type process, cno_cstring_type file, cno_cstring_type function, CNO_Log_Priority_type priority, cno_cstring_type format, ...);
cno_u8_type CNO_Log_Test();
cno_u8_type CNO_Log_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_LOG_H
