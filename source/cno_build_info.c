//cno_build_info.c

#include "cno_build_info.h"

#include "cno_build.h"
#include "cno_string.h"

#if CNO_HAVE_STDIO
#include <stdio.h>//sprintf
#endif //CNO_HAVE_STDIO

#if CNO_HAVE_SDL2
#include <SDL2/SDL_version.h>
#if CNO_HAVE_SDL2_IMAGE
#include <SDL2/SDL_image.h>
#endif /* CNO_HAVE_SDL2_IMAGE */
/* CSI(CNO_HAVE_SDL2_TTF,SDL2/SDL_ttf.h) */
#if CNO_HAVE_SDL2_TTF
#include <SDL2/SDL_ttf.h>
#endif /* CNO_HAVE_SDL2_TTF */
/* CSI(CNO_HAVE_SDL2_MIXER,SDL2/SDL_mixer.h) */
#if CNO_HAVE_SDL2_MIXER
#include <SDL2/SDL_mixer.h>
#endif /* CNO_HAVE_SDL2_MIXER */
#endif /* CNO_HAVE_SDL2 */


cno_u8_type CNO_Build_Info_Create(CNO_Build_Info_type *build_info){
	cno_u8_type _return = 0;
#if CNO_HAVE_STDIO
	sprintf((*build_info).build_string, "%s-%d-%d-%d %s-%s-%s-%s-%s", CNO_BUILD_NAME, CNO_BUILD_VERSION_MAJOR, CNO_BUILD_VERSION_MINOR, CNO_BUILD_VERSION_PATCH, CNO_BUILD_GOAL, CNO_BUILD_ARCHITECTURE, CNO_BUILD_SYSTEM, CNO_BUILD_COMPILER, CNO_BUILD_COMMIT);
#endif /* CNO_HAVE_STDIO */
	return _return;
}
