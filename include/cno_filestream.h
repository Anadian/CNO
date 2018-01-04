/**
*	@file cno_filestream.h
*	@brief Abstractions over C's native stdio file stream functions.
*	@author Anadian
*	@copyright MIT License
*/

#ifndef CNO_FILESTREAM_H
#define CNO_FILESTREAM_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#include "cno_string.h"

/* CSI(CNO_HAVE_STDIO,<stdio.h>) */
#if CNO_HAVE_STDIO
#include <stdio.h>
#endif /* CNO_HAVE_STDIO */

#if !defined(cno_filestream_type)
#define cno_filestream_type FILE* //cno_file_type is a macro not a typedef
#endif //cno_filestream_type

//Types:
//streams stdio.h
//buffers stdlib.h malloc and free
//directories parson and tinyfiles
//archives libarchive

cno_u8_type CNO_FileStream_Open(cno_filestream_type *file, cno_cstring_type mode, cno_string_type filename);
#define CNO_FileStream_Read(file,filename) CNO_FileStream_Open(file, "rb", filename);
#define CNO_FileStream_ReadPlus(file,filename) CNO_FileStream_Open(file, "r+b", filename);
#define CNO_FileStream_Write(file,filename) CNO_FileStream_Open(file, "wb", filename);
#define CNO_FileStream_WritePlus(file,filename) CNO_FileStream_Open(file, "w+b", filename);
#define CNO_FileStream_Append(file,filename) CNO_FileStream_Open(file, "ab", filename);
#define CNO_FileStream_AppendPlus(file,filename) CNO_FileStream_Open(file, "a+b", filename);
cno_u8_type CNO_FileStream_Sync(cno_filestream_type *file);
cno_u8_type CNO_FileStream_Close(cno_filestream_type *file);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_FILESTREAM_H
