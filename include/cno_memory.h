/**
*	@file CNO_MEMORY_H
*	@brief Dynamic memory routines.
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

#if !defined(CNO_MEMORY_H)
#define CNO_MEMORY_H

#if defined(__cplusplus)
extern "C"{
#endif /* defined(__cplusplus) */

#include "cno_build.h"


c\u8\ty C\Memory_Allocate(void *destination_pointer, c\size\ty size, c\size\ty capacity);
c\u8\ty C\Memory_Reallocate(void *destination_pointer, c\size\ty size, c\size\ty capacity);
c\u8\ty C\Memory_Free(void *memory_pointer);


#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* !defined(CNO_MEMORY_H) */
