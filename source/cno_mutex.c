//CNO_Mutex.c

#include "CNO_Mutex.h"

#if CNO_HAVE_STDIO
#include <stdio.h>
#endif //CNO_HAVE_STDIO

#if CNO_HAVE_SDL2
#include <SDL2/SDL_error.h>
#endif //CNO_HAVE_SDL2

cno_u8_type CNO_Mutex_Create(CNO_Mutex_type *mutex){
	cno_u8_type _return;
#if CNO_ALLOW_THREADS && CNO_HAVE_SDL2
	*mutex = SDL_CreateMutex();
	if(*mutex != NULL) _return = 1;
	else{
		_return = 0;
		CNO_fprintf(stderr, "SDL_CreateMutex error: %s\n", SDL_GetError());
	}
#else
	_return = 0;
#endif //CNO_ALLOW_THREADS && CNO_HAVE_SDL2
	return _return;
}
cno_u8_type CNO_Mutex_Lock(CNO_Mutex_type *mutex){
	cno_u8_type _return;
#if CNO_ALLOW_THREADS && CNO_HAVE_SDL2
	if(SDL_LockMutex(*mutex) == 0) _return = 1;
	else{
		_return = 0;
		CNO_fprintf(stderr, "SDL_LockMutex error: %s\n", SDL_GetError());
	}
#else
	_return = 0;
#endif //CNO_ALLOW_THREADS && CNO_HAVE_SDL2
	return _return;
}
cno_u8_type CNO_Mutex_Unlock(CNO_Mutex_type *mutex){
	cno_u8_type _return;
#if CNO_ALLOW_THREADS && CNO_HAVE_SDL2
	if(SDL_UnlockMutex(*mutex) == 0) _return = 1;
	else{
		_return = 0;
		CNO_fprintf(stderr, "SDL_UnlockMutex error: %s\n", SDL_GetError());
	}
#else
	_return = 0;
#endif //CNO_ALLOW_THREADS && CNO_HAVE_SDL2
	return _return;
}
cno_u8_type CNO_Mutex_Destroy(CNO_Mutex_type *mutex){
	cno_u8_type _return;
#if CNO_ALLOW_THREADS && CNO_HAVE_SDL2
	if(CNO_Mutex_Unlock(*mutex) == 1){
		SDL_DestroyMutex(*mutex);
		_return = 1;
	} else _return = 0;
#else
	_return = 0;
#endif //CNO_ALLOW_THREADS && CNO_HAVE_SDL2
	return _return;
}
