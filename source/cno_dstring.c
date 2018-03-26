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

/**
* @fn C\DString_Calloc
* @brief Allocates and zeros a new DString.
* @param C\DString\ty *dstring [out] A pointer to the DString to initialise.
* @param c\size\ty size [in] The number of bytes to allocate for the new DString; defaults to 256 if NULL.
* @return c\u8\ty
* @retval 0 Success
* @retval 1 Not supported
* @retval 2 Invalid arguments
* @retval 3 (*dstring).array isn't NULL.
* @retval 4 calloc returned NULL.
*/
c\u8\ty C\DString_Calloc(C\DString\ty *dstring, c\size\ty size){
	c\u8\ty _return = 0;
#if C\H\STDLIB
	if( dstring != NULL ){
		if( size == NULL ){
			size = 256;
		}
		if( (*dstring).array == NULL ){
			(*dstring).array = calloc(size, sizeof(c\u8\ty));
			if( (*dstring).array != NULL ){
				(*dstring).capacity = size;
				(*dstring).length = 0;
			} else{
				_return += 4;
				(*dstring).capacity = 0;
			}
		} else{
			_return += 3;
		}	
	} else{
		_return += 2;
	}
#else /* C\H\STDLIB */
	_return += 1;
#endif /* C\H\STDLIB */
	return _return;
}
c\u8\ty C\DString_Realloc(C\DString\ty *dstring, c\size\ty size

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

c\u8\ty C\DString_CreateFromCString( C\DString\ty *dstring, c\string\ty *string ){
	c\u8\ty _return = 0;
	c\size\ty string_length = 0;
	void *new_pointer = NULL;

	c\u8\ty condition1 = (dstring != NULL);
	c\u8\ty condition2 = (string != NULL);
	
	if( condition1 && condition2 ){ /* arguments valid */
		condition1 = ((*dstring).capacity == 0);
		condition2 = ((*dstring).array == NULL);
		if( condition1 && condition2 ){ /* dstring blank */
			string_length = utf8size( (void*)string );
			(*dstring).capacity = string_length;
			(*dstring).array = utf8dup( (void*)string );
			(*dstring).length = utf8len( (void*)((*dstring).array) );
		} else{
			string_length = utf8( (void*)string );
			(*dstring).capacity = string_length;
			new_pointer = realloc( (*dstring).array, ((*dstring).capacity * sizeof(c\u8\ty)) );
			(*dstring)
			if( new_pointer != NULL ){
				
				
			
	} else{
		_return += 1;
	}


c\u8\ty C\DString_Copy(C\DString\ty *target_dstring, C\DString\ty *source_dstring){
	c\u8\ty _return = 0;
	c\u8\ty condition1 = 0;
	c\u8\ty condition2 = 0;
	void *new_pointer = NULL;

	condition1 = (target_dstring != NULL);
	condition2 = (source_dstring != NULL);
	if( condition1 && condition2 ){
		condition1 = ((*source_dstring).capacity > 0);
		condition2 = ((*source_dstring).array != NULL);
		if( condition1 && condition2 ){
			condition1 = ((*target_dstring).capacity > 0);
			condition2 = ((*target_dstring).array != NULL);
			if( condition1 && condition2 ){ /* target_dstring initialised */
				new_pointer = realloc( (*target_dstring).array, ((*source_dstring).capacity * sizeof(c\u8\ty)) );
				if( new_pointer != NULL ){
					(*dstring).array = (c\u8\ty*)new_pointer;
					(*target_dstring).capacity = (*source_dstring).capacity;
					utf8cpy( (void*)((*target_dstring).array), (void*)((*source_dstring).array) ); 
					(*target_dstring).length = utf8len( (void*)((*target_dstring).array) );
				} else{
					_return += 8;
				}
			} else if( condition1 ){
				new_pointer = utf8dup( (void*)((*source_dstring).array) );
				if( new_pointer != 0 ){
					(*target_dstring).array = (c\u8\ty*)new_pointer;
					(*target_dstring).capacity = (*source_dstring).capacity;
					(*target_dstring).length = utf8len( (*target_dstring) );
				} else{
					_return += 16;
				}
			} else {
				_return += 4;
			}
		} else{
			_return += 2;
		}
	} else{
		_return += 1;
	}

	return _return;
}

c\u8\ty C\DString_Destroy(C\DString\ty *dstring){
	c\u8\ty _return = 0;
	if( ((*dstring).capacity > 0) && ((*dstring).array != NULL) ){
		(*dstring).length = 0;
		(*dstring).capacity = 0;
		free((*dstring).array);
		(*dstring).array = NULL;
	} else{
		_return += 1;
	}
	return _return;
}

