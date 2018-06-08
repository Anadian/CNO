/**
*	@file cno_dstring.h
*	@brief Dynamic, memory-safe strings for ANSI C
*	@author Anadian
*	@license MIT License:
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

#if !defined(CNO_DSTRING_H)
#define CNO_DSTRING_H

#if defined(__cplusplus)
extern "C"{
#endif /* defined(__cplusplus) */

#include "cno_build.h"
#include "cno_string.h"

typedef struct CNO_DString\s{
	c\size\ty length;
	c\size\ty capacity;
	c\u8\ty *array;
} C\DString\ty;

#define CNO_DSTRING_DEFAULT {0,0,NULL}

c\u8\ty C\DString_Create(C\DString\ty *dstring, c\size\ty capacity);
C\DString\ty *C\DString_Create_Raw(c\size\ty capacity);

c\u8\ty C\DString_CreateFromCString(C\DString\ty *dstring, c\string\ty *string);
C\DString\ty *C\DString_CreateFromCString_Raw(c\string\ty string);

c\u8\ty C\DString_Copy(C\DString\ty *target_dstring, C\DString\ty *source_dstring);

c\u8\ty C\DString_Insert(C\DString\ty *output_dstring, C\DString\ty *original_dstring, c\s32\ty insert_position, C\DString\ty *input_dstring);
C\DString\ty *C\DString_Insert_Raw(C\DString\ty *original_dstring, c\s32\ty insert_position, C\DString\ty *input_dstring);
c\u8\ty C\DString_Isolate(C\DString\ty *output_dstring, C\DString\ty *original_dstring, c\s32\ty start_position, c\s32\ty substring_length);
C\DString\ty *C\DString_Isolate_Raw(C\DString\ty *original_dstring, c\s32\ty start_position, c\s32\ty substring_length);
c\u8\ty C\DString_Remove(C\DString\ty *output_dstring, C\DString\ty *original_dstring, c\s32\ty start_position, c\s32\ty substring_length);
C\DString\ty *C\DString_Remove_Raw(C\DString\ty *original_dstring, c\s32\ty start_position, c\s32\ty substring_length);

c\u8\ty C\DString_Prepend(C\DString\ty *output_dstring, C\DString\ty *input_dstring);
c\u8\ty C\DString_Append(C\DString\ty *output_dstring, C\DString\ty *input_dstring);
c\u8\ty C\DString_Concatenate(C\DString\ty *output_dstring, C\DString\ty *first_input_dstring, C\DString\ty *second_input_dstring);
C\DString\ty *C\DString_Concatenate_Raw(C\DString\ty *first_input_dstring, C\DString\ty *second_input_dstring);

c\u8\ty C\DString_Compare(c\s32\ty *result, C\DString\ty *first_dstring, C\DString\ty *second_dstring);
c\s32\ty C\DString_Compare_Raw(C\DString\ty *first_dstring, C\DString\ty *second_dstring);

c\u8\ty C\DString_Match(C\DString\ty *first_dstring, C\DString\ty *second_dstring);

c\s8\ty C\DString_IsSet(C\DString\ty *dstring, C\DString\ty *set_dstring);
c\u8\ty C\DString_StripSet(C\DString\ty *dstring, C\DString\ty *set_dstring);
C\DString\ty *C\DString_StripSet_Raw(C\DString\ty *set_dstring);
c\u8\ty C\DString_PreserveSet(C\DString\ty *dstring, C\DString\ty *set_dstring);
C\DString\ty *C\DString_PreserveSet_Raw(C\DString\ty *set_dstring);

c\u8\ty C\DString_Find(c\s32\ty *occurence_position, C\DString\ty *input_dstring, c\s32\ty relative_index);
c\u8\ty C\DString_Replace(C\DString\ty *dstring, C\DString\ty *match_dstring, C\DString\ty *replacement_dstring, c\s32\ty relative_index);
c\u8\ty C\DString_ReplaceAll(C\DString\ty *dstring, C\DString\ty *match_dstring, C\DString\ty *replacement_dstring);

c\u8\ty C\DString_Bytes(c\size\ty *bytes, C\DString\ty *dstring);
c\size\ty C\DString_Bytes_Raw(C\DString\ty *dstring);
c\u8\ty C\DString_Characters(c\u32\ty *characters, C\DString\ty *dstring;
c\u32\ty C\DString_Characters_Raw(C\DString\ty *dstring);

c\u8\ty C\DString_ToCString(c\string\ty *cstring, C\DString\ty *dstring);
c\string\ty C\DString_ToCString_Raw(C\DString\ty *dstring);

c\u8\ty C\DString_Destroy(C\DString\ty *dstring);


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* !defined(CNO_DSTRING_H) */
