//cno_environment.c

#include "cno_environment.h"

#include "cno_build.h"
#include "cno_string.h"

#if CNO_HAVE_STDLIB
#include <stdlib.h> //getenv
#endif //CNO_HAVE_STDLIB

#if CNO_HAVE_WHEREAMI
#include "whereami.h"
#endif // CNO_HAVE_WHEREAMI

#if CNO_HAVE_STDIO
#include <stdio.h>
#endif //CNO_HAVE_STDIO

cno_u8_type CNO_Environment_Init(CNO_Environment_type *environment){
#if CNO_HAVE_STDLIB
	if(getenv("USER") != NULL) CNO_String_Copy(&((*environment).username),getenv("USER"));
	else if(getenv("USERNAME") != NULL) CNO_String_Copy(&((*environment).username),getenv("USERNAME"));
	else if(getenv("LOGNAME") != NULL) CNO_String_Copy(&((*environment).username),getenv("LOGNAME"));
	if(getenv("HOSTNAME") != NULL) CNO_String_Copy(&((*environment).hostname),getenv("HOSTNAME"));
	if(getenv("PWD") != NULL) CNO_String_Copy(&((*environment).pwd),getenv("PWD"));
	if(getenv("HOME") != NULL) CNO_String_Copy(&((*environment).home),getenv("HOME"));
#if CNO_HAVE_WHEREAMI
	wai_getExecutablePath(&((*environment).whereami), sizeof((*environment).whereami), NULL);
#endif //CNO_HAVE_WHEREAMI
	return 1;
#else
	return 0;
#endif //CNO_HAVE_STDLIB
}
