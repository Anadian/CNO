//cno_file.c

#include "cno_filestream.h"

#if CNO_HAVE_STDIO
#include <stdio.h> //f*
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_ERRNO
#include <errno.h> //errno
#if CNO_HAVE_STRING
#include <string.h> //strerror
#endif //CNO_HAVE_STRING
#endif //CNO_HAVE_ERRNO

cno_u8_type CNO_FileStream_Open(cno_filestream_type *file, cno_cstring_type mode, cno_string_type filename){
	cno_u8_type _return;
#if CNO_HAVE_STDIO
	FILE* filehandle;
	filehandle = fopen(filename, mode);
	if(filehandle != NULL){
		_return = 1;
		*file = filehandle;
	} else{
		_return = 0;
		//cno_u8_type message_buffer[CNO_BUFFER_MAXSIZE];
#if CNO_HAVE_ERRNO && CNO_HAVE_STRING
		fprintf(stderr, "Error: Couldn't open file '%s': (mode: '%s' errno: %d description: '%s')\n", filename, mode, errno, strerror(errno));
#elif CNO_HAVE_ERRNO
		fprintf(stderr, "Error: Couldn't open file '%s': (mode: '%s' errno: %d)\n", filename, mode, errno);
#else
		fprintf(stderr, "Error: Couldn't open file '%s': (mode: '%s')\n", filename, mode);
#endif //CNO_HAVE_ERRNO && CNO_HAVE_STRING
	}
#else
	_return = 0;
#endif //CNO_HAVE_STDIO
	return _return;
}
cno_u8_type CNO_FileStream_Sync(cno_filestream_type *file){
	cno_u8_type _return;
#if CNO_HAVE_STDIO
	int fflsuh_return;
	fflush_return = fflush(*file);
	if(fflush_return == 0){
		_return = 1;
	} else{
		_return = 0;
	}
#else
	_return = 0;
#endif //CNO_HAVE_STDIO
	return _return;
}		
cno_u8_type CNO_FileStream_Close(cno_filestream_type *file){
	cno_u8_type _return;
#if CNO_HAVE_STDIO
	int fclose_return;
	fclose_return = fclose(*file);
	if(fclose_return == 0){
		_return = 1;
	} else{
		_return = 0;
	}
#else
	_return = 0;
#endif //CNO_HAVE_STDIO
	return _return;
}
	
