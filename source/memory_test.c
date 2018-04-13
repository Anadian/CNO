/**
*	@file memory_test.c
*	@brief Test CNO_Memory.
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

#include "cno_build.h"
#include "cno_string.h"
#include "cno_time.h"
#include "cno_filestream.h"
#include "cno_memory.h"

CSI(C\H\STDIO,<stdio.h>)

int main(int argc, char *argcv[]){
	c\u8\ty _return = 0;
	c\u8\ty func_return = 0;
	c\u8\ty *pointer_a = NULL;
	c\filestream\ty file;
	CNO_FileStream_WritePlus(&file,"debug.log");
	fprintf(file,"Stream open successful.\n");
	CNO_Memory_Allocate(pointer_a, sizeof(c\u8\ty), 256);

