filecommenttm(source/cno_log.c,)
#include "cno_log.h"

#include "cno_string.h"
#include "cno_time.h"
#include "cno_filestream.h"
#include "cno_application.h"

#if C\H\STRETCHY_BUFFER
#include "stretchy_buffer.h"
#endif /* C\H\STRETCHY_BUFFER */

c\u8\ty C\Log_Init(){
	c\u8\ty _return = 0;
#if !defined(CNO_NO_GLOBAL_STATE)
	C\Log_Transport\ty transport = {CNO_Log_Priority_Debug, CNO_Log_Type_File, {"cno.log", 0, 0}};
	sb_push(CNO_Transports_Global, transport);
	transport = {CNO_Log_Priority_Info, CNO_Log_Type_Stream, {CNO_Application.stderr, 1}};
	sb_push(CNO_Transports_Global, transport);
	_return = 1;
#else
	_return = 0;
#endif /* !defined(CNO_NO_GLOBAL_STATE) */
	return _return;
}
c\u8\ty C\Log(C\Transport\ty *transports, c\string\ty process, c\string\ty file, c\string\ty function, C\Log_Priority\ty priority, c\string\ty format, ...){
	c\u8\ty _return = 0;
	va_list arguments;
	c\string\ty message;
	c\u8\ty buffer[256];
	c\size\ty transport_index = 0;
	if(transports == NULL){
		transports = CNO_Transports_Global;
	}
	if(process == NULL){
		
	
}
c\u8\ty C\Log_Quit(){
	c\u8\ty _return = 0;
#if !defined(CNO_NO_GLOBAL_STATE)
	sb_free(CNO_Transports_Global);
	_return = 1;
#else
	_return = 0;
#endif /* !defined(CNO_NO_GLOBAL_STATE) */
	return _return;
}