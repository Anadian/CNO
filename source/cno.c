#include "cno.h"

#include "cno_build_info.h"
#include "cno_options.h"
#include "cno_middleware.h"
#include "cno_environment.h"
#include "cno_config.h"
#include "cno_thread.h"
#include "cno_log.h"

cno_u8_type CNO_Init(int argc, char *argv[]){
	cno_u8_type _return;
	cno_u8_type cno_build_info_init_return = CNO_Build_Info_Init();
	cno_u8_type cno_options_process_return = CNO_Options_Process(argc, argv);
	cno_u8_type cno_middleware_init_return = CNO_Middleware_Init();
	cno_u8_type cno_environment_init_return = CNO_Environment_Init();
	return (CNO_Build_Info_Init() && CNO_Environment_Init());
}
cno_u8_type CNO_Quit(){
	return 0;
}
