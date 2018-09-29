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
	cno_u8_type condition1 = ((*dynamic_buffer).array != NULL);
	cno_u8_type condition2 = ((*dynamic_buffer).capacity > 0);
	/* _function */
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
* @param cno_size_type *bytes [out] A pointer to where the capacity will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountBytes_Unsafe( cno_size_type *bytes, CNO_DynamicBuffer_type *dynamic_buffer ){
	cno_u8_type _return = 1;
	/* Variables */
	/* _function */
	*bytes = ((*dynamic_buffer).capacity);
	_return = 0;
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_GetByte_Unsafe
* @brief Get the value of the byte in the given DynamicBuffer at the given address.
* @param cno_u8_type *byte [out] A pointer to where the byte's value will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param cno_size_type address [in] The address of the value to retrieve.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_GetByte_Unsafe( cno_u8_type *byte, CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8t\y condition1 = (address < ((*dynamic_buffer).capacity));
	/* _function */
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
* @param cno_size_type address [in] The address of the byte to be set.
* @param cno_u8_type value [in] The value to be set.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_SetByte_Unsafe( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_u8_type value ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = (address < ((*dynamic_buffer).capacity));
	/* _function */
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
* @param cno_size_type *count [out] A pointer to where the count will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param cno_u8_type value [in] The value to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountByte_Unsafe( cno_size_type *count, CNO_DynamicBuffer_type *dynamic_buffer, cno_u8_type value ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = NULL;
	cno_u8_type _function_return = 1;
	cno_size_type loop_index = 0;
	cno_size_type bytes = 0;
	cno_u8_type byte = 0;
	/* Arguments */
	/* _function */
	/* DynamicBuffer is good. */
	_function_return = CNO_DynamicBuffer_CountBytes_Unsafe( &bytes, dynamic_buffer );
	if( _function_return == 0 ){
		/* Got DynamicBuffer size. */
		for( loop_index = 0; loop_index < bytes; loop_index++ ){
			_function_return = CNO_DynamicBuffer_GetByte_Unsafe( &byte, dynamic_buffer, loop_index );
			if( _function_return == 0 ){
				/* Got byte value. */
				condition1 = (byte == value);
				if( condition1 ){
					/* Values matched. */
					(*count)++;
				}
			} else{
				/* Something went wrong; abort the loop. */
				loop_index = (bytes+1);
				_return = _function_return;
			}
		}
		condition1 = (loop_index == bytes);
		if( condition1 ){
			_return = 0;
		}
	} else{
		/* Couldn't get size of DynamicBuffer. */
		_return = _function_return;
	}
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_AddressByte_Unsafe
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
cno_u8_type CNO_DynamicBuffer_AddressByte_Unsafe( cno_size_type *address, CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type instance, cno_u8_type value ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = NULL;
	cno_size_type loop_index = 0;
	cno_size_type bytes = 0;
	cno_size_type count = 0;
	cno_size_type byte = 0;
	/* Arguments */
	cno_u8_type _function_return = CNO_DynamicBuffer_CountBytes_Unsafe( &bytes, dynamic_buffer );
	/* _function */
	if( _function_return == 0 ){
		/* Got buffer size. */
		for( loop_index = 0; loop_index < bytes; loop_index++ ){
			_function_return = CNO_DynamicBuffer_GetByte_Unsafe( &byte, dynamic_buffer, loop_index );
			if( _function_return == 0 ){
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
				_return += _function_return;
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
		_return = _function_return;
	}
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_AddBytes_Unsafe
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
cno_u8_type CNO_DynamicBuffer_AddBytes_Unsafe( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_size_type bytes, cno_u8_type value ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = NULL;
	cno_u8_type _function_return = 0;
	cno_size_type buffer_size = 0;
	cno_size_type loop_index = 0;
	/* _function */
	/* DynamicBuffer good. */
	_function_return = CNO_DynamicBuffer_CountBytes_Unsafe( &buffer_size, dynamic_buffer );
	if( _function_return == 0 ){
		/* Got buffer size. */
		condition1 = ( address <= buffer_size );
		if( condition1 ){
			/* Address is good. */
			_function_return = CNO_Memory_Reallocate( (void*)((*dynamic_buffer).array), (cno_size_type)((*dynamic_buffer).capacity + bytes) );
			if( _function_return == 0 ){
				/* Reallocation successful begin copying. */
				_function_return = CNO_Memory_Copy( (void*)((*dynamic_buffer).array + address + bytes), (void*)((*dynamic_buffer).array + address), bytes );
				if( _function_return == 0 ){
					/* Copy successful. */
					for( loop_index = 0; loop_index < (buffer_size + bytes); loop_index++ ){
						_function_return = CNO_DynamicBuffer_SetByte_Unsafe( dynamic_buffer, loop_index, value );
						if( _function_return != 0 ){
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
					_return = _function_return;
				}
			} else{
				/* Reallocationg failed. */
				_return = _function_return;
			}
		} else{ 
			/* Address out of range. */
			_return = 2;
		}
	} else{
		/* Couldn't get buffer size. */
		_return = _function_return;
	}
	/* Return */
	return _return;
}
/**
* @fn CNO_DynamicBuffer_RemoveBytes_Unsafe
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
cno_u8_type CNO_DynamicBuffer_RemoveBytes_Unsafe( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_size_type range ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = NULL;
	cno_size_type buffer_size = 0;
	cno_u8_type _function_return = 1;
	/* _function */
	_function_return = CNO_DynamicBuffer_CountBytes_Unsafe( &buffer_size, dynamic_buffer );
	if( _function_return == 0 ){
		/* Got buffer size. */
		condition1 = ( (address + range) < buffer_size );
		if( condition1 ){
			/* Range is valid. */
			_function_return = CNO_Memory_Copy( (void*)((*dynamic_buffer).array + address), (void*)((*dynamic_buffer).array + address + range), (buffer_size - address));
			if( _function_return == 0 ){
				/* Copy successful; time to reallocate. */
				_function_return = CNO_Memory_Reallocate( (void*)((*dynamic_buffer).array), (buffer_size - range) );
				if( _function_return == 0 ){
					/* Reallocation successful; set new capacity. */
					(*dynamic_buffer).capacity = (buffer_size - range);
					_return = 0;
				} else{
					/* Reallocation failed. */
					_return = _function_return;
				}
			} else{
				/* Copy failed. */
				_return = _function_return;
			}
		} else{
			/* Range invalid. */
			_return = 32;
		}
	} else{
		/* Couldn't get buffer size. */
		_return = _function_return;
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
	cno_u8_type _function_return = 1;
	/* Arguments */
	cno_u8_type condition1 = (dynamic_buffer == NULL);
	cno_u8_type condition2 = (capacity > 0);
	/* _function */
	if( condition2 ){
		/* Capacity valid. */
		if( condition1 ){
			/* Initialise a new buffer. */
			_function_return = CNO_Memory_Allocate( (void*)(new_buffer.array), sizeof(cno_u8_type), capacity );
			if( _function_return == 0 ){
				/* Allocation successful. */
				new_buffer.capacity = capacity;
				dynamic_buffer = new_buffer;
				_return = 0;
			} else{
				/* Allocation failed. */
				_return += (_function_return + 3);
			}
		} else{
			/* Try to reinitialise the existing buffer. */
			condition1 = ((*dynamic_buffer).array != NULL);
			condition2 = ((*dynamic_buffer).capacity > 0);
			/* Should be allocated. */
			if( condition1 && condition2 ){
				/* Looks good; trying to reset. */
				_function_return = CNO_Memory_Reallocate( (void*)((*dynamic_buffer).array), capacity );
				if( _function_return == 0 ){
					/* Reallocate successful. */
					(*dynamic_buffer).capacity = capacity;
					_return = 0;
				} else{
					/* Reallocate failed. */
					_return += (_function_return + 4);
				}
			} else{
				if( condition1 ){
					/* It's pretty messed up; trying to free it. */
					_function_return = CNO_Memory_Free( (void*)((*dynamic_buffer).array) ); 
					if( _function_return == 0 ){
						_return = 0;
					} else {
						_return += (_function_return += 5);
					}
				}
				/* Initialise a new buffer. */
				if( _return < 2 ){
					_function_return = CNO_Memory_Allocate( (void*)((*dynamic_buffer).array), sizeof(cno_u8_type), capacity );
					if( _function_return == 0 ){
						/* Allocation successful. */
						(*dynamic_buffer).capacity = capacity;
						_return = 0;
					} else{
						/* Allocation failed. */
						_return += (_function_return + 6);
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
	cno_u8_type condition1 = (dynamic_buffer != NULL);
	cno_u8_type condition2 = NULL;
	/* Arguments */
	if( condition1 ){
		/* _function */
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
* @param cno_size_type *bytes [out] A pointer to where the capacity will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountBytes( cno_size_type *bytes, CNO_DynamicBuffer_type *dynamic_buffer ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = (bytes != NULL);
	cno_u8_type condition2 = (dynamic_buffer != NULL);
	cno_u8_type _function_return = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* _function */
		_function_return = CNO_DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( _function_return == 0 ){
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
* @param cno_u8_type *byte [out] A pointer to where the byte's value will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param cno_size_type address [in] The address of the value to retrieve.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_GetByte( cno_u8_type *byte, CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = (byte != NULL);
	cno_u8_type condition2 = (dynamic_buffer != NULL);
	cno_u8_type _function_return = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* _function */
		_function_return = CNO_DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( _function_return == 0 ){
			/* DynamicBuffer good. */
			_function_return = CNO_DynamicBuffer_GetByte_Unsafe( byte, dynamic_buffer, address );
			if( _function_return == 0 ){
				/* Got byte. */
				_return = 0;
			} else{
				/* Didn't get byte. */
				_return = _function_return;
			}
		} else{
			/* DynamicBuffer is invlaid. */
			_return = _function_return;
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
* @param cno_size_type address [in] The address of the byte to be set.
* @param cno_u8_type value [in] The value to be set.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_SetByte( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_u8_type value ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = (dynamic_buffer != NULL);
	cno_u8_type _function_return = 1;
	/* Arguments */
	if( condition1 ){
		/* _function */
		_function_return = CNO_DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( _function_return == 0 ){
			/* DynamicBuffer good. */
			_function_return = CNO_DynamicBuffer_SetByte_Unsafe( dynamic_buffer, address, value );
			if( _function_return == 0 ){
				/* Set byte. */
				_return = 0;
			} else{
				/* Couldn't set byte. */
				_return = _function_return;
			}
		} else{
			/* DynamicBuffer invalid. */
			_return = _function_return;
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
* @param cno_size_type *count [out] A pointer to where the count will be stored.
* @param CNO_DynamicBuffer_type *dynamic_buffer [in] A pointer to the DynamicBuffer.
* @param cno_u8_type value [in] The value to be counted.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval >1 Failure.
*/
cno_u8_type CNO_DynamicBuffer_CountByte( cno_size_type *count, CNO_DynamicBuffer_type *dynamic_buffer, cno_u8_type value ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = (count != NULL);
	cno_u8_type condition2 = (dynamic_buffer != NULL);
	cno_u8_type _function_return = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* _function */
		_function_return = CNO_DynamicBuffer_IsGood( dynamic_buffer );
		if( _function_return == 0 ){
			_function_return = CNO_DynamicBuffer_CountByte_Unsafe( count, dynamic_buffer, value );
			if( _function_return == 0 ){
				/* Couted bytes successfully. */
				_return = 0;
			} else{
				/* Failed to enumerate instances of the given value. */
				_return = _function_return;
		} else{
			/* DynamicBuffer is not good. */
			_return = _function_return;
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
cno_u8_type CNO_DynamicBuffer_AddressByte( cno_size_type *address, CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type instance, cno_u8_type value ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = (address != NULL);
	cno_u8_type condition2 = (dynamic_buffer != NULL);
	cno_u8_type _function_return = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* Arguments valid. */
		/* _function */
		_function_return = CNO_DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( _function_return == 0 ){
			/* DynamicBuffer is good. */
			_function_return = CNO_DynamicBuffer_AddressByte_Unsafe( address, dynamic_buffer, instance, value );
			if( _function_return == 0 ){
				/* Successfully addressed the byte. */
				_return = 0;
			} else{
				/* Failed to address the byte. */
				_return = _function_return;
			}
		} else{
			/* DynamicBuffer is not good. */
			_return = _function_return;
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
* @param cno_size_type address [in] The addres at which the bytes should be inserted.
* @param cno_size_type bytes [in] The number of bytes to insert.
* @param cno_u8_type value [in] The value of each newly-inserted byte.
* @return cno_u8_type
* @retval 0 Success.
* @retval 1 Not supported.
* @retval 2 Invalid argument.
* @retval >2 Failure.
*/
cno_u8_type CNO_DynamicBuffer_AddBytes( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_size_type bytes, cno_u8_type value ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = ( dynamic_buffer != NULL );
	cno_u8_type condition2 = ( bytes > 0 );
	cno_u8_type _function_return = 0;
	/* Arguments */
	if( condition1 && condition2 ){
		/* Arguments good. */
		_function_return = CNO_DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( _function_return == 0 ){
			/* DynamicBuffer good. */
			_function_return = CNO_DynamicBuffer_AddBytes_Unsafe( dynamic_buffer, address, bytes, value );
			/* _function */
			if( _function_return == 0 ){
				/* Bytes added successfully. */
				_return = 0;
			} else{
				/* Error adding bytes. */
				_return = _function_return;
			}
		} else{
			/* DynamicBuffer not good. */
			_return = _function_return;
		}
	} else{
		/* Arguments invalid. */
		if( !condition1 ){
			/* DynamicBuffer pointer is NULL. */
			_return = 2;
		}
		if( !condition2 ){
			/* bytes is 0 */
			_return = 3;
		}
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_RemoveBytes( CNO_DynamicBuffer_type *dynamic_buffer, cno_size_type address, cno_size_type range ){
	cno_u8_type _return = 1;
	/* Variables */
	cno_u8_type condition1 = ( dynamic_buffer != NULL );
	cno_u8_type condition2 = ( range > 0 );
	cno_u8_type _function_return = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* Arguments good. */
		/* _function */
		_function_return = CNO_DynamicBuffer_IsGood_Unsafe( dynamic_buffer );
		if( _function_return == 0 ){
			/* DynamicBuffer is good. */
			_function_return = CNO_DynamicBuffer_RemoveBytes_Unsafe( dynamic_buffer, address, range );
			if( _function_return == 0 ){
				/* Removal successful. */
				_return = 0;
			} else{
				/* Removal failed. */
				_return = _function_return;
			}
		} else{
			/* DynamicBuffer is not good. */
			_return = _function_return;
		}
	} else{
		/* Arguments invalid. */
		if( !condition1 ){
			/* DynamicBuffer pointer is NULL. */
			_return = 2;
		}
		if( !condition2 ){
			/* range is 0. */
			_return = 3;
		}
	}
	/* Return */
	return _return;
}
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
cno_u8_type CNO_DynamicBuffer_Serialize( c\string\ty string, C\DynamicBuffer\ty *dynamic_buffer ){
	cno_u8_type _return = 1;
	/* Variables */
	c\u8\ty condition1 = ( string != NULL );
	c\u8\ty condition2 = ( dynamic_buffer != NULL );
	c\u8\ty f\r = 1;
	/* Arguments */
	if( condition1 && condition2 ){
		/* Arguments valid. */
		/* Function */
		f\r = C\DynamicBuffer_IsGood( dynamic_buffer );
		if( f\r == 0 ){
			/* DynamicBuffer is good. */
			f\r = C\DynamicBuffer_Serialize_Unsafe( string, dynamic_buffer );
			if( f\r == 0 ){
				/*


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
	cno_u8_type _function_return = 1;
	/* Arguments */
	cno_u8_type condition1 = (dynamic_buffer != NULL);
	if( condition1 ){
		/* _function */
		condition1 = ((*dynamic_buffer).array != NULL);
		if( condition1 ){
			/* Array should be ready to free. */
			_function_return = CNO_Memory_Free( (void*)((*dynamic_buffer).array) );
			if( _function_return == 0 ){
				/* Deallocation successful. */
				(*dynamic_buffer).array = NULL;
				(*dynamic_buffer).capacity = 0;
				_return = 0;
			} else{
				/* Deallocation failed. */
				_return += (_function_return + 4);
			}
		} else{
			/* Array is NULL. */
			_return += (_function_return + 3);
		}
	} else{
		/* Invalid dynamic_buffer. */
		_return = 2;
	}
	/* Return */
	return _return;
}

