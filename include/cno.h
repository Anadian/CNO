//cno.h

#ifndef CNO_BUILDSYSTEM_H
#define CNO_BUILDSYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "cno_build.h"
//cno_string
//cno_time
//cno_json
//cno_filesystem:
//	cno_stream
//	cno_buffer
//	cno_directory
//	cno_archive
//cno_buildinfo
//cno_options
//cno_middleware
//cno_environment //config regex
//cno_thread
//cno_mutex
//cno_log

cno_u8_type CNO_Init();
cno_u8_type CNO_Quit();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //CNO_BUILDSYSTEM_H
