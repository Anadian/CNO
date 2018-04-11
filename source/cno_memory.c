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

CSI(C\H\STDLIB,<stdlib.h>)

/**
* @fn CNO_Memory_Allocate
* @brief Private function for reallocating DString.
* @param void *output_pointer [out] The pointer to the newly allocate memory block.
* @param c\size\ty size [in] The size of each block.
* @param c\size\ty capacity [in] The count of blocks to allocate.
* @pre C\H\STDLIB
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_Memory_Allocate(void *output_pointer, c\size\ty size, c\size\ty capacity){
	cno_u8_type _return = 0;
	/* Variables */
	
#if C\H\STDLIB
	if( size == 0 ){
		size = sizeof(c\u8\ty);
		_return += 2;
	}
	if( capacity == 0 ){
		capacity = 256;
		_return += 3;
	}
	if( output_pointer == NULL ){
		output_pointer = calloc(capacity,size);
		if( output_pointer == NULL ){
			_return += 8;
		}
	}
#else
	_return += 1;
#endif /* C\H\STDLIB */
	/* Return */
	return _return;
}
