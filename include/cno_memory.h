/**
*	@file cno_memory.h
*	@brief Dynamic memory routines.
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

#if !defined(CNO_MEMORY_H)
#define CNO_MEMORY_H

#if defined(__cplusplus)
extern "C"{
#endif /* defined(__cplusplus) */

#include "cno_build.h"


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
cno_u8_type CNO_Memory_Allocate( void *output_pointer, cno_size_type size, cno_size_type capacity ){
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
cno_u8_type CNO_Memory_Reallocate( void *pointer, cno_size_type capacity );
/**
* @fn CNO_Memory_Copy
* @brief Copies one portion of memory to another.
* @param void *output_buffer [out] A pointer to the memory buffer to copy to.
* @param void *input_buffer [in] A pointer the memory buffer to copy from.
* @param c\size\ty bytes [in] The number of bytes to copy.
* @pre C\H\STDLIB required
* @pre C\H\STRING required
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval >2 Failure.
*/
cno_u8_type CNO_Memory_Copy( void *output_buffer, void *input_buffer, c\size\ty bytes );
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
cno_u8_type CNO_Memory_Free( void *pointer );


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* !defined(CNO_MEMORY_H) */
