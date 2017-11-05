//cno_mutex.h

#ifndef CNO_MUTEX_H
#define CNO_MUTEX_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_ALLOW_THREADS && CNO_HAVE_SDL2
#include <SDL2/SDL_mutex.h>
typedef SDL_mutex* CNO_Mutex_type;
#else
typedef void CNO_Mutex_type;
#endif //CNO_ALLOW_THREADS && CNO_HAVE_SDL2

cno_u8_type CNO_Mutex_Create(CNO_Mutex_type *mutex);
cno_u8_type CNO_Mutex_Lock(CNO_Mutex_type *mutex);
cno_u8_type CNO_Mutex_Unlock(CNO_Mutex_type *mutex);
cno_u8_type CNO_Mutex_Destroy(CNO_Mutex_type *mutex);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_MUTEX_H
