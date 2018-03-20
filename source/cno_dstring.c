/**
*	@file cno_dstring.c
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

CSI(C\H\STDLIB,<stdlib.h>)

#include "cno_string.h"

c\u8\ty C\DString_Create(C\DString\ty *dstring, c\size\ty capacity){
	c\u8\ty _return = 0;
	if((*dstring).capacity > 0 && (*dstring).array != NULL){
		_return++;
	}
	(*dstring).length = 0;
	if(capacity == NULL){
		(*dstring).capacity = 256;
	} else{
		(*dstring).capacity = capacity;
	}
	(*dstring).array = calloc((*dstring).capacity, sizeof(unsigned char));
	if((*dstring).array == NULL){
		_return++;
	}
	return _return;
}

C\DString\ty *C\DString_Create_Raw(c\size\ty capacity){
	C\DString\ty *_return;
	c\u8\ty dstring_create_return = 1;
	C\DString\ty *dstring_pointer = C\DSTRING_DEFAULT;

	dstring_create_return = C\DString_Create(dstring_pointer, 256);
	if((dstring_create_return == 0) && ((*dstring).array != NULL)){
		_return = dstring_pointer;
	}else if((dstring_create_return != 0) || ((*dstring).array == NULL)){
		_return = NULL;
	}
	return _return;
}

c\u8\ty C\DString_Copy(C\DString\ty *target_dstring, C\DString\ty *source_dstring){
	c\u8\ty _return = 0;
	c\u8\ty condition1 = 0;
	c\u8\ty condition2 = 0;

	condition1 = (target_string != NULL);
	condition2 = (source_string != NULL);
	if( condition1 && condition2 ){
		condition1 = ((*source_string).capacity > 0);
		condition2 = ((*source_string).array != NULL);
		if( condition1 && condition2 ){
			if( 

c\u8\ty C\DString_Destroy(C\DString\ty *dstring){
	c\u8\ty _return = 0;
	if( ((*dstring).capacity > 0) && ((*dstring).array != NULL) ){
		(*dstring).length = 0;
		(*dstring).capacity = 0;
		free((*dstring).array);
		(*dstring).array = NULL;
	} else{
		_return++;
	}
	return _return;
}

