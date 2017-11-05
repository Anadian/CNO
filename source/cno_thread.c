//cno_thread.c

#include "cno_thread.h"

#if CNO_HAVE_STDIO
#include <stdio.h> // fprintf
#endif //CNO_HAVE_STDIO

#if CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2
#include <SDL2/SDL_error.h>
#endif //CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2

cno_u8_type CNO_Thread_Create(cno_thread_type thread, cno_threadfunction_type function, cno_cstring_type name){
	cno_u8_type _return;
#if (CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2)
	thread = SDL_CreateThread(function, name, NULL);
	if(thread != NULL) _return = 1;
	else{
		_return = 0;
		CNO_fprintf(stderr, "SDL_CreateThread error: %s", SDL_GetError());
	}
#else
	_return = 0;
#endif //(CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2)
	return _return;
}
cno_u8_type CNO_Thread_Wait(cno_thread_type thread){
	cno_u8_type _return;
#if (CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2)
	cno_threadfunction_type threadfunction_return;
	SDL_WaitThread(thread, &threadfunction_return);
	CNO_fprintf(stderr, "Thread returned with %d", threadfunction_return);
	_return = 1;
#else
	_return = 0;
#endif //(CNO_THREAD_ENGINE == CNO_THREAD_ENGINE_SDL2)
	return _return;
}
