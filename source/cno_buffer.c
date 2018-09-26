/**
*	@file cno_buffer.c
*	@brief Definitions for memory-safe dynamic buffers.
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
/* Internal */
#include "cno_buffer.h"
#include "cno_memory.h"

/**
* @fn CNO_DynamicBuffer_IsGood_Unsafe
* @brief Checks if a DynamicBuffer is okay.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval 4 Array invalid.
* @retval 8 Capacity invalid.
*/
cno_u8_type CNO_DynamicBuffer_IsGood_Unsafe( CNO_DynamicBuffer_type *dynamic_buffer ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = ((*dynamic_buffer).array != NULL);
	c\u8\ty condition2 = ((*dynamic_buffer).capacity > 0);
	/* Function */
	if( condition1 && condition2 ){
		_return = 0;
	}
	if( !condition1 ){
		_return += 4;
	}
	if( !condition2 ){
		_return += 8;
	}
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_CountBytes_Unsafe
* @brief Return the number of bytes currently allocated: the capacity.
* @param c\size\ty *bytes [out] A pointer to where the capacity will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountBytes_Unsafe( c\size\ty *bytes, CNO_DynamicBuffer_type *dynamic_buffer ){
	cno_u8_type _return = 1;
	/* Variables */
	/* Function */
	*bytes = ((*dynamic_buffer).capacity);
	_return = 0;
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_GetByte_Unsafe
* @brief Get the value of the byte in the given DynamicBuffer at the given address.
* @param c\u8\ty *byte [out] A pointer to where the byte's value will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param c\size\ty address [in] The address of the value to retrieve.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_GetByte_Unsafe( c\u8\ty *byte, CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8t\y condition1 = (address < ((*dynamic_buffer).capacity));
	/* Function */
	if( condition1 ){
		/* Address in range. */
		*byte = ((*dynamic_buffer).array[address]);
		_return = 0;
	} else{
		/* Address out of range. */
		_return = 16
	}
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_SetByte_Unsafe
* @brief Set the value of the byte in the given DynamicBuffer at the given address.
* @param CNO_DynamicBuffer_type *dynamic_buffer [out] A pointer to the DynamicBuffer.
* @param c\size\ty address [in] The address of the byte to be set.
* @param c\u8\ty value [in] The value to be set.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_SetByte_Unsafe( CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address, c\u8\ty value ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = (address < ((*dynamic_buffer).capacity));
	/* Function */
	/* DynamicBuffer good. */
	if( condition1 ){
		/* Address in range. */
		(*dynamic_buffer).array[address] = value;
		_return = 0;
	} else{
		/* Address not in range. */
		_return = 16;
	}
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_CountByte_Unsafe
* @brief Count how many times the given value occurs in the given DynamicBuffer.
* @param c\size\ty *count [out] A pointer to where the count will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param c\u8\ty value [in] The value to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountByte_Unsafe( c\size\ty *count, CNO_DynamicBuffer_type *dynamic_buffer, c\u8\ty value ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = NULL;
	c\u8\ty function_return = 1;
	c\size\ty loop_index = 0;
	c\size\ty bytes = 0;
	c\u8\ty byte = 0;
	/* Arguments */
	/* Function */
	/* DynamicBuffer is good. */
	function_return = CNO_DynamicBuffer_CountBytes_Unsafe( &bytes, dynamic_buffer );
	if( function_return == 0 ){
		/* Got DynamicBuffer size. */
		for( loop_index = 0; loop_index < bytes; loop_index++ ){
			function_return = CNO_DynamicBuffer_GetByte_Unsafe( &byte, dynamic_buffer, loop_index );
			if( function_return == 0 ){
				/* Got byte value. */
				condition1 = (byte == value);
				if( condition1 ){
					/* Values matched. */
					(*count)++;
				}
			} else{
				/* Something went wrong; abort the loop. */
				loop_index = (bytes+1);
				_return = function_return;
			}
		}
		condition1 = (loop_index == bytes);
		if( condition1 ){
			_return = 0;
		}
	} else{
		/* Couldn't get size of DynamicBuffer. */
		_return = function_return;
	}
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_AddressByte_Unsafe
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
cno_u8_type CNO_DynamicBuffer_AddressByte_Unsafe( c\size\ty *address, CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty instance, c\u8\ty value ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = NULL;
	c\size\ty loop_index = 0;
	c\size\ty bytes = 0;
	c\size\ty count = 0;
	c\size\ty byte = 0;
	/* Arguments */
	c\u8\ty f\r = CNO_DynamicBuffer_CountBytes_Unsafe( &bytes, dynamic_buffer );
	/* Function */
	if( f\r == 0 ){
		/* Got buffer size. */
		for( loop_index = 0; loop_index < bytes; loop_index++ ){
			f\r = CNO_DynamicBuffer_GetByte_Unsafe( &byte, dynamic_buffer, loop_index );
			if( f\r == 0 ){
				/* Got byte. */
				condition1 = ( byte == value );
				if( condition1 ){
					/* Byte is value. */
					condition1 = ( count == instance );
					if( condition1 ){
						/* Is the address we're looking for. */
						*address = loop_index;
						loop_index = bytes;
						_return = 0;
					} else{
						/* Not the address but we'll keep looking. */
						count++;
					}
				} /* else Byte is not relevant to our search. */
			} else{
				/* Couldn't get byte; abort loop. */
				loop_index = ( bytes + 1 );
				_return += f\r;
			}
		}
		if( loop_index == bytes ){
			/* Loop terminated normally. */
			_return = 0;
		} else{
			/* Loop ended due to an error. */
			_return += 32;
		}
	} else{
		/* Couldn't get buffer size. */
		_return = f\r;
	}
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_AddBytes_Unsafe
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
cno_u8_type CNO_DynamicBuffer_AddBytes_Unsafe( CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address, c\size\ty bytes, c\u8\ty value ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = NULL;
	c\u8\ty f\r = 0;
	c\size\ty buffer_size = 0;
	c\size\ty loop_index = 0;
	/* Function */
	/* DynamicBuffer good. */
	f\r = C\DynamicBuffer_CountBytes_Unsafe( &buffer_size, dynamic_buffer );
	if( f\r == 0 ){
		/* Got buffer size. */
		condition1 = ( address <= buffer_size );
		if( condition1 ){
			/* Address is good. */
			f\r = CNO_Memory_Reallocate( (void*)((*dynamic_buffer).array), (c\size\ty)((*dynamic_buffer).capacity + bytes) );
			if( f\r == 0 ){
				/* Reallocation successful begin copying. */
				f\r = C\Memory_Copy( (void*)((*dynamic_buffer).array + address + bytes), (void*)((*dynamic_buffer).array + address), bytes );
				if( f\r == 0 ){
					/* Copy successful. */
					for( loop_index = 0; loop_index < (buffer_size + bytes); loop_index++ ){
						f\r = C\DynamicBuffer_SetByte_Unsafe( dynamic_buffer, loop_index, value );
						if( f\r != 0 ){
							/* Something went wrong; abort loop. */
							loop_index = (buffer_size + bytes + 1);
						}
					}
					if( loop_index == (buffer_size + bytes) ){
						/* All good. */
						(*dynamic_buffer).capacity += bytes;
						_return = 0;
					} else{
						/* Loop exited abruptly. */
						_return = 16;
					}
				} else{
					/* 	Memory copy failed. */
					_return = f\r;
				}
			} else{
				/* Reallocationg failed. */
				_return = f\r;
			}
		} else{ 
			/* Address out of range. */
			_return = 2;
		}
	} else{
		/* Couldn't get buffer size. */
		_return = f\r;
	}
	/* Return */
	return _return;
}

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
cno_u8_type CNO_DynamicBuffer_Create( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type capacity ){
	cno_u8_type _return = 1;
	/* Variables */
	CNO_DynamicBuffer_type new_buffer = NULL;
	c\u8\ty function_return = 1;
	/* Arguments */
	c\u8\ty condition1 = (dynamic_buffer == NULL);
	c\u8\ty condition2 = (capacity > 0);
	/* Function */
	if( condition2 ){
		/* Capacity valid. */
		if( condition1 ){
			/* Initialise a new buffer. */
			function_return = CNO_Memory_Allocate( (void*)(new_buffer.array), sizeof(c\u8\ty), capacity );
			if( function_return == 0 ){
				/* Allocation successful. */
				new_buffer.capacity = capacity;
				dynamic_buffer = new_buffer;
				_return = 0;
			} else{
				/* Allocation failed. */
				_return += (function_return + 3);
			}
		} else{
			/* Try to reinitialise the existing buffer. */
			condition1 = ((*dynamic_buffer).array != NULL);
			condition2 = ((*dynamic_buffer).capacity > 0);
			/* Should be allocated. */
			if( condition1 && condition2 ){
				/* Looks good; trying to reset. */
				function_return = CNO_Memory_Reallocate( (void*)((*dynamic_buffer).array), capacity );
				if( function_return == 0 ){
					/* Reallocate successful. */
					(*dynamic_buffer).capacity = capacity;
					_return = 0;
				} else{
					/* Reallocate failed. */
					_return += (function_return + 4);
				}
			} else{
				if( condition1 ){
					/* It's pretty messed up; trying to free it. */
					function_return = CNO_Memory_Free( (void*)((*dynamic_buffer).array) ); 
					if( function_return == 0 ){
						_return = 0;
					} else {
						_return += (function_return += 5);
					}
				}
				/* Initialise a new buffer. */
				if( _return < 2 ){
					function_return = CNO_Memory_Allocate( (void*)((*dynamic_buffer).array), sizeof(c\u8\ty), capacity );
					if( function_return == 0 ){
						/* Allocation successful. */
						(*dynamic_buffer).capacity = capacity;
						_return = 0;
					} else{
						/* Allocation failed. */
						_return += (function_return + 6);
					}
				}
			}
		}
	} else{
		/* Invalid capacity. */
		_return += 2;
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_IsGood( CNO_DynamicBuffer_type *dynamic_buffer ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = (dynamic_buffer != NULL);
	c\u8\ty condition2 = NULL;
	/* Arguments */
	if( condition1 ){
		/* Function */
		/* Argument valid. */
		condition1 = ((*dynamic_buffer).array != NULL);
		condition2 = ((*dynamic_buffer).capacity > 0);
		if( condition1 && condition2 ){
			/* DynamicBuffer is good. */
			_return = 0;
		} else{	
			if( condition1 ){
				/* Array invalid. */
				_return += 4;
			}
			if( condition2 ){
				/* Capacity invalid. */
				_return += 8;
			}
		}
	} else{
		/* Argument invalid. */
		_return = 2;
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_CountBytes( c\size\ty *bytes, CNO_DynamicBuffer_type *dynamic_buffer ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = (bytes != NULL);
	c\u8\ty condition2 = (dynamic_buffer != NULL);
	c\u8\ty f\r = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* Function */
		f\r = C\DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( f\r == 0 ){
			/* All good; we can return the capacity. */
			*bytes = ((*dynamic_buffer).capacity);
			_return = 0;
		} else{
			if( !condition1 ){
				/* Array is null. */
				_return += 4;
			}
			if( !condition2 ){
				/* Capacity is 0. */
				_return += 5;
			}
		}
	} else{
		if( !condition1 ){
			/* bytes is NULL. */
			_return += 2;
		}
		if( !condition2 ){
			/* dynamic_buffer is NULL. */
			_return += 3;
		}
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_GetByte( c\u8\ty *byte, CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = (byte != NULL);
	c\u8\ty condition2 = (dynamic_buffer != NULL);
	c\u8\ty function_return = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* Function */
		function_return = CNO_DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( function_return == 0 ){
			/* DynamicBuffer good. */
			function_return = CNO_DynamicBuffer_GetByte_Unsafe( byte, dynamic_buffer, address );
			if( function_return == 0 ){
				/* Got byte. */
				_return = 0;
			} else{
				/* Didn't get byte. */
				_return = function_return;
			}
		} else{
			/* DynamicBuffer is invlaid. */
			_return = function_return;
		}
	} else{
		/* Invalid arguments. */
		if( !condition1 ){
			/* Invalid byte pointer. */
			_return = 2;
		}
		if( !condition2 ){
			/* Invalid DynamicBuffer pointer. */
			_return = 3;
		}
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_SetByte( CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address, c\u8\ty value ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = (dynamic_buffer != NULL);
	c\u8\ty function_return = 1;
	/* Arguments */
	if( condition1 ){
		/* Function */
		function_return = CNO_DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( function_return == 0 ){
			/* DynamicBuffer good. */
			function_return = CNO_DynamicBuffer_SetByte_Unsafe( dynamic_buffer, address, value );
			if( function_return == 0 ){
				/* Set byte. */
				_return = 0;
			} else{
				/* Couldn't set byte. */
				_return = function_return;
			}
		} else{
			/* DynamicBuffer invalid. */
			_return = function_return;
		}
	} else{
		/* Arguments invalid. */
		/* DynamicBuffer pointer is NULL. */
		_return = 2;
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_CountByte( c\size\ty *count, CNO_DynamicBuffer_type *dynamic_buffer, c\u8\ty value ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = (count != NULL);
	c\u8\ty condition2 = (dynamic_buffer != NULL);
	c\u8\ty function_return = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* Function */
		function_return = CNO_DynamicBuffer_IsGood( dynamic_buffer );
		if( function_return == 0 ){
			function_return = C\DynamicBuffer_CountByte_Unsafe( count, dynamic_buffer, value );
			if( function_return == 0 ){
				/* Couted bytes successfully. */
				_return = 0;
			} else{
				/* Failed to enumerate instances of the given value. */
				_return = f\r;
		} else{
			/* DynamicBuffer is not good. */
			_return = function_return;
		}
	} else{
		/* Arguments invalid. */
		if( !condition1 ){
			/* Count pointer is NULL. */
			_return = 2;
		}
		if( !condition2 ){
			/* DynamicBuffer pointer is NULL. */
			_return = 3;
		}
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_AddressByte( c\size\ty *address, CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty instance, c\u8\ty value ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = (address != NULL);
	c\u8\ty condition2 = (dynamic_buffer != NULL);
	c\u8\ty f\r = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* Arguments valid. */
		/* Function */
		f\r = C\DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( f\r == 0 ){
			/* DynamicBuffer is good. */
			f\r = C\DynamicBuffer_AddressByte_Unsafe( address, dynamic_buffer, instance, value );
			if( f\r == 0 ){
				/* Successfully addressed the byte. */
				_return = 0;
			} else{
				/* Failed to address the byte. */
				_return = f\r;
			}
		} else{
			/* DynamicBuffer is not good. */
			_return = f\r;
		}
	} else{
		/* Arguments invalid. */
		if( !condition1 ){
			/* Address pointer is NULL. */
			_return += 2;
		}
		if( !condition2 ){
			/* DynamicBuffer pointer is NULL. */
			_return += 3;
		}
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_AddBytes( CNO_DynamicBuffer_type *dynamic_buffer, c\size\ty address, c\size\ty bytes, c\u8\ty value ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = ( dynamic_buffer != NULL );
	c\u8\ty f\r = 0;
	c\size\ty buffer_size = 0;
	/* Arguments */
	if( condition1 ){
		/* Arguments good. */
		f\r = C\DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( f\r == 0 ){
			/* DynamicBuffer good. */
			f\r = C\DynamicBuffer_CountBytes_Unsafe( &buffer_size, dynamic_buffer );
			if( f\r == 0 ){
				/* Got buffer size. */
				

	/* Function */


	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_Destroy
* @brief Destroy a previously created DynamicBuffer.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer to be destroyed.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_Destroy( CNO_DynamicBuffer_type *dynamic_buffer ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty function_return = 1;
	/* Arguments */
	c\u8\ty condition1 = (dynamic_buffer != NULL);
	if( condition1 ){
		/* Function */
		condition1 = ((*dynamic_buffer).array != NULL);
		if( condition1 ){
			/* Array should be ready to free. */
			function_return = CNO_Memory_Free( (void*)((*dynamic_buffer).array) );
			if( function_return == 0 ){
				/* Deallocation successful. */
				(*dynamic_buffer).array = NULL;
				(*dynamic_buffer).capacity = 0;
				_return = 0;
			} else{
				/* Deallocation failed. */
				_return += (function_return + 4);
			}
		} else{
			/* Array is NULL. */
			_return += (function_return + 3);
		}
	} else{
		/* Invalid dynamic_buffer. */
		_return = 2;
	}
	/* Return */
	return _return;
}

