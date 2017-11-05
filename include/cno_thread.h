//cno_thread.h

#ifndef CNO_THREAD_H
#define CNO_THREAD_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_ALLOW_THREADS && CNO_HAVE_SDL2
#include <SDL2/SDL_thread.h>

typedef SDL_Thread* cno_thread_type;
typedef int cno_threadfunction_type;
#endif //CNO_ALLOW_THREADS && CNO_HAVE_SDL2

cno_u8_type CNO_Thread_Create(cno_thread_type *thread, cno_threadfunction_type function, cno_cstring_type name);
cno_u8_type CNO_Thread_Wait(cno_thread_type *thread);
cno_u8_type CNO_Thread_Destroy(cno_thread_type *thread);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_THREAD_H
