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
	cno_u8_type *array;
	cno_size_type capacity;
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
* @param cno_size_type *bytes [out] A pointer to where the capacity will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountBytes( cno_size_type *bytes, CNO_DynamicBuffer_type *dynamic_buffer );
/**
* @fn CNO_DynamicBuffer_GetByte
* @brief Get the value of the byte in the given DynamicBuffer at the given address.
* @param cno_u8_type *byte [out] A pointer to where the byte's value will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param cno_size_type address [in] The address of the value to retrieve.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_GetByte( cno_u8_type *byte, CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address );
/**
* @fn CNO_DynamicBuffer_SetByte
* @brief Set the value of the byte in the given DynamicBuffer at the given address.
* @param CNO_DynamicBuffer_type *dynamic_buffer [out] A pointer to the DynamicBuffer.
* @param cno_size_type address [in] The address of the byte to be set.
* @param cno_u8_type value [in] The value to be set.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_SetByte( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_u8_type value );
/**
* @fn CNO_DynamicBuffer_CountByte
* @brief Count how many times the given value occurs in the given DynamicBuffer.
* @param cno_size_type *count [out] A pointer to where the count will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param cno_u8_type value [in] The value to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountByte( cno_size_type *count, CNO_DynamicBuffer_type *dynamic_buffer, cno_u8_type value );
/**
* @fn CNO_DynamicBuffer_AddressByte
* @brief Gets the address of the given instance of the given value in the given DynamicBuffer.
* @param cno_size_type *address [out] A pointer to where the address will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param cno_size_type instance [in] The instance of the value to be addressed.
* @param cno_u8_type value [in] The value to be addressed.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval >2 Failure.
*/
cno_u8_type CNO_DynamicBuffer_AddressByte( cno_size_type *address, CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type instance, cno_u8_type value );
/**
* @fn CNO_DynamicBuffer_AddBytes
* @brief Adds a gven number of bytes with the given valu to the address given in the given DynamicBuffer.
* @param CNO_DynamicBuffer_type *dynamic_buffer [out] A pointer to the DynamicBuffer to be modified.
* @param cno_size_type address [in] The addres at which the bytes should be inserted.
* @param cno_size_type bytes [in] The number of bytes to insert.
* @param cno_u8_type value [in] The value of each newly-inserted byte.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval >2 Failure.
*/
cno_u8_type CNO_DynamicBuffer_AddBytes( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_size_type bytes, cno_u8_type value );
/**
* @fn CNO_DynamicBuffer_RemoveBytes
* @brief Removes a range of bytes from a DynamicBuffer.
* @param CNO_DynamicBuffer_type *dynamic_buffer [out] A pointer to the DynamicBuffer to modify.
* @param cno_size_type address [in] The start of the removal range.
* @param cno_size_type range [in] The length of the removal range.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval >2 Failure.
*/
cno_u8_type CNO_DynamicBuffer_RemoveBytes( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_size_type range );
/*DynamicBuffer_InsertBuffer
DynamicBuffer_ExtractBuffer
DynamicBuffer_GetBuffer
DynamicBuffer_SetBuffer
DynamicBuffer_CountBuffer
DynamicBuffer_AddressBuffer
DynamicBuffer_Copy
DynamicBuffer_FromFileStream
DynamicBuffer_FromJSONValue*/
/**
* @fn CNO_DynamicBuffer_Serialize
* @brief Serialize a dynamic buffer to a string.
* @param c\string\ty string [out] The output string.
* @param C\DynamicBuffer\ty *dynamic_buffer [in] A pointer to the DynamicBuffer to serialize.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval >2 Failure.
*/
cno_u8_type CNO_DynamicBuffer_Serialize( c\string\ty string, C\DynamicBuffer\ty *dynamic_buffer );
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
