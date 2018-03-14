/**
*	@file cno_json.h
*	@brief CNO JSON abstraction: provided by Parson
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
#ifndef CNO_JSON_H
#define CNO_JSON_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

/* CSI(CNO_HAVE_PARSON,"parson.h") */
#if CNO_HAVE_PARSON
#include "parson.h"
#endif /* CNO_HAVE_PARSON */

typedef json_value

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_JSON_H
