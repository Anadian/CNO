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

c\u8\ty C\DString_Destroy(C\DString\ty *dstring){
	c\u8\ty _return = 0;

