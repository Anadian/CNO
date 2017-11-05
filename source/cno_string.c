/**
*	@file source/cno_string.c
*	@author Anadian
*	@copyright MIT License:
	Copyright 2017 Canosw
	Permission is hereby granted, free of charge, to any person obtaining a copy of this 
software and associated documentation files (the "Software"), to deal in the Software 
without restriction, including without limitation the rights to use, copy, modify, 
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
permit persons to whom the Software is furnished to do so, subject to the following 
conditions:
	The above copyright notice and this permission notice shall be included in all copies 
or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "cno_string.h"

#if CNO_HAVE_UTF8
#include "utf8.h"
#elif CNO_HAVE_STRING
#include <string.h>
#endif //CNO_HAVE_UTF8

cno_u8_type CNO_String_Concatenate(cno_string_type *destination, cno_string_type source){
	cno_u8_type _return = 0;
#if CNO_HAVE_UTF8
	utf8cat((*destination), source);
	_return = 1;
#elif CNO_HAVE_STRING
	strcat((*destination), source);
	_return = 1;
#else
	_return = 0;
#endif //CNO_HAVE_UTF8
	return _return;
}
cno_u8_type CNO_String_Copy(cno_string_type *destination, cno_string_type source){
	cno_u8_type _return = 0;
#if CNO_HAVE_UTF8
	utf8cpy((*destination), source);
	_return = 1;
#elif CNO_HAVE_STRING
	strcpy((*destination), source);
	_return = 1;
#else
	_return = 0;
#endif //CNO_HAVE_UTF8
	return _return;
}
cno_u8_type CNO_String_Length(cno_size_type *length, cno_string_type string){
	cno_u8_type _return = 0;
#if CNO_HAVE_UTF8
	*length = utf8len(string);
	_return = 1;
#elif CNO_HAVE_STRING
	*length = strlen(string);
	_return = 1;
#else
	*length = 0;
	_return = 0;
#endif //CNO_HAVE_UTF8
	return _return;
}
cno_u8_type CNO_String_Compare(cno_s32_type *result, cno_string_type string1, cno_string_type string2){
	cno_u8_type _return = 0;
#if CNO_HAVE_UTF8
	*result = utf8cmp(string1, string2);
	_return = 1;
#elif CNO_HAVE_STRING
	*result = strcmp(string1, string2);
	_return = 1;
#else
	*result = 0
	_return = 0;
#endif //CNO_HAVE_UTF8
	return _return;
}
cno_u8_type CNO_String_Match(cno_string_type string1, cno_string_type string2){
	cno_u8_type _return = 0;
	cno_s32_type compare_result = 0;
	if(CNO_String_Compare(&compare_result, string1, string2)){
		if(compare_result == 0){
			_return = 1;
		} else{
			_return = 0;
		}
	} else{
		fprintf(CNO_STDERR, "Error: Couldn't compare strings '%s' and '%s'. (HAVE_STRING: %d HAVE_UTF8: %d)\n", string1, string2, CNO_HAVE_STRING, CNO_HAVE_UTF8);
		_return = 0;
	}
	return _return;
}
