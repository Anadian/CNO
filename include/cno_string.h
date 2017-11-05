/**
*	@file cno_string.h
*	@brief A wrapper around standard and non-standard string library functions.
*	@author Anadian
*	@copyright MIT License
*/
#ifndef CNO_STRING_H
#define CNO_STRING_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

#if CNO_HAVE_UTF8
typedef cno_utf8_type cno_string_type;
#elif CNO_HAVE_STRING
typedef cno_cstring_type cno_string_type;
#endif //CNO_HAVE_STRING

cno_u8_type CNO_String_Compare(cno_s32_type *result, cno_string_type string1, cno_string_type string2);
cno_u8_type CNO_String_Concatenate(cno_string_type *destination, cno_string_type source);
cno_u8_type CNO_String_Copy(cno_string_type *destination, cno_string_type source);
cno_u8_type CNO_String_Length(cno_size_type *length, cno_string_type string);
cno_u8_type CNO_String_Match(cno_u8_type *result, cno_string_type string1, cno_string_type string2);

#define CNO_strcat(...) CNO_String_Concatenate(__VA_ARGS__)
#define CNO_strcpy(...) CNO_String_Copy(__VA_ARGS__)
#define CNO_strlen(...) CNO_String_Length(__VA_ARGS__)

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_STRING_H
