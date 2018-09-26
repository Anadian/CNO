/**
*	@file cno_buffer.h
*	@brief Declaration for memory-safe dynamic buffers.
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

#if !defined(CNO_BUFFER_H)
#define CNO_BUFFER_H

#if defined(__cplusplus)
extern "C"{
#endif /* defined(__cplusplus) */

typedef struct CNO_DynamicBuffer_struct {
	c\u8\ty *array;
	c\size\ty capacity;
} CNO_DynamicBuffer_type;

/**
* @fn CNO_DynamicBuffer_Create
* @brief Create, initialise, and zero a new DynamicBuffer with a specified size.
* @param CNO_DynamicBuffer_type *dynamic_buffer [out] A pointer to the DynamicBuffer to be created.
* @param cno_size_type capacity [in] The number of bytes the buffer should be a able to hold.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_Create( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type capacity );
/**
* @fn CNO_DynamicBuffer_IsGood
* @brief Checks if a DynamicBuffer is okay.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval 4 Array invalid.
* @retval 8 Capacity invalid.
*/
cno_u8_type CNO_DynamicBuffer_IsGood( CNO_DynamicBuffer_type *dynamic_buffer );
/**
* @fn CNO_DynamicBuffer_CountBytes
* @brief Return the number of bytes currently allocated: the capacity.
* @param c\size\ty *bytes [out] A pointer to where the capacity will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountBytes( c\size\ty *bytes, CNO_DynamicBuffer_type *dynamic_buffer );
/**
* @fn CNO_DynamicBuffer_GetByte
* @brief Get the value of the byte in the given DynamicBuffer at the given address.
* @param c\u8\ty *byte [out] A pointer to where the byte's value will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param c\size\ty address [in] The address of the value to retrieve.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_GetByte( c\u8\ty *byte, CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address );
/**
* @fn CNO_DynamicBuffer_SetByte
* @brief Set the value of the byte in the given DynamicBuffer at the given address.
* @param CNO_DynamicBuffer_type *dynamic_buffer [out] A pointer to the DynamicBuffer.
* @param c\size\ty address [in] The address of the byte to be set.
* @param c\u8\ty value [in] The value to be set.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_SetByte( CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address, c\u8\ty value );
/**
* @fn CNO_DynamicBuffer_CountByte
* @brief Count how many times the given value occurs in the given DynamicBuffer.
* @param c\size\ty *count [out] A pointer to where the count will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param c\u8\ty value [in] The value to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountByte( c\size\ty *count, CNO_DynamicBuffer_type *dynamic_buffer, c\u8\ty value );
/**
* @fn CNO_DynamicBuffer_AddressByte
* @brief Gets the address of the given instance of the given value in the given DynamicBuffer.
* @param c\size\ty *address [out] A pointer to where the address will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param c\size\ty instance [in] The instance of the value to be addressed.
* @param c\u8\ty value [in] The value to be addressed.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval >2 Failure.
*/
cno_u8_type CNO_DynamicBuffer_AddressByte( c\size\ty *address, CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty instance, c\u8\ty value );
/**
* @fn CNO_DynamicBuffer_AddBytes
* @brief Adds a gven number of bytes with the given valu to the address given in the given DynamicBuffer.
* @param CNO_DynamicBuffer_type *dynamic_buffer [out] A pointer to the DynamicBuffer to be modified.
* @param c\size\ty address [in] The addres at which the bytes should be inserted.
* @param c\size\ty bytes [in] The number of bytes to insert.
* @param c\u8\ty value [in] The value of each newly-inserted byte.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval >2 Failure.
*/
cno_u8_type CNO_DynamicBuffer_AddBytes( CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address, c\size\ty bytes, c\u8\ty value );
DynamicBuffer_RemoveBytes
DynamicBuffer_InsertBuffer
DynamicBuffer_ExtractBuffer
DynamicBuffer_GetBuffer
DynamicBuffer_SetBuffer
DynamicBuffer_CountBuffer
DynamicBuffer_AddressBuffer
DynamicBuffer_Copy
DynamicBuffer_FromFileStream
DynamicBuffer_FromJSONValue
/**
* @fn CNO_DynamicBuffer_Destroy
* @brief Destroy a previously created DynamicBuffer.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer to be destroyed.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_Destroy( CNO_DynamicBuffer_type *dynamic_buffer );

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* !defined(CNO_BUFFER_H) */
