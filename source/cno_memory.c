/**
*	@file cno_memory.c
*	@brief Dynamic memory functions
*	@author Anadian
*	@license MIT License:
	Copyright 2018 Canosw
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

/* CSI(CNO_HAVE_STDLIB,<stdlib.h>) */
#if CNO_HAVE_STDLIB
#include <stdlib.h>
#endif /* CNO_HAVE_STDLIB */

/**
* @fn CNO_Memory_Allocate
* @brief Allocate and zero a dynamic block of memory.
* @param void *output_pointer [out] The pointer to the newly allocate memory block.
* @param cno_size_type size [in] The size of each block.
* @param cno_size_type capacity [in] The count of blocks to allocate.
* @pre CNO_HAVE_STDLIB
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_Memory_Allocate(void *output_pointer, cno_size_type size, cno_size_type capacity){
	cno_u8_type _return = 0;
	/* Variables */
	
#if CNO_HAVE_STDLIB

	if( size == 0 ){
		size = sizeof(cno_u8_type);
		_return += 2;
	}
	if( capacity == 0 ){
		capacity = 256;
		_return += 3;
	}
	if( output_pointer == NULL ){
		output_pointer = calloc(capacity, size);
		if( output_pointer == NULL ){
			_return += 8;
		}
	} else{
		free(output_pointer);
		_return += 4;
		output_pointer = calloc(capacity, size);
		if( output_pointer == NULL ){
			_return += 9;
		}
	}
#else
	_return += 1;
#endif /* CNO_HAVE_STDLIB */
	/* Return */
	return _return;
}

/**
* @fn CNO_Memory_Reallocate
* @brief Reallocate a, previously-allocated, dynamic-memory block to a new size.
* @param void *pointer [out] The pointer to the memory block to be reallocated.
* @param cno_size_type capacity [in] The new capacity of the reallocated memory.
* @pre CNO_HAVE_STDLIB
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_Memory_Reallocate( void *pointer, cno_size_type capacity){
	cno_u8_type _return = 0;
	/* Variables */
#if CNO_HAVE_STDLIB
	void *realloc_return = NULL;
	if( capacity > 0 ){
		if( pointer != NULL ){
			realloc_return = realloc(pointer, capacity);
			if( realloc_return != NULL ){
				pointer = realloc_return;
			} else{
				free(pointer);
				free(realloc_return);
				_return += 8;
			}
		} else{
			_return += 4;
		}
	} else{
		_return += 2;
	}		
#else
	_return += 1;
#endif /* CNO_HAVE_STDLIB */
	/* Return */
	return _return;
}

/**
* @fn CNO_Memory_Free
* @brief Free (deallocate) a, previously-allocated, memory block and set the pointer to NULL.
* @param void *pointer [out] Pointer to the memory block to be freed.
* @pre CNO_HAVE_STDLIB
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_Memory_Free( void *pointer){
	cno_u8_type _return = 0;
	/* Variables */

#if CNO_HAVE_STDLIB
	if( pointer != NULL ){
		free(pointer);
	} else{
		_return += 2;
	}
#else
	_return += 1;
#endif /* CNO_HAVE_STDLIB */
	/* Return */
	return _return;
}
