//cno_options.h

#ifndef CNO_OPTIONS_H
#define CNO_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#include "cno_build.h"

#if CNO_ALLOW_OPTIONS == 1
#include "gopt.h"
typedef struct option CNO_Option_type;
CNO_Option_type CNO_Options = {
	{'V',"version",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Display version information.
	{'h',"help",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Display this help text.
	{'a',"all",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Acknowledge invisible files
	{'A',"audio",(GOPT_ARGUMENT_OPTIONAL),0,NULL},//Boolean: Use ANSI/xterm text colouring.
	//{'b',"about-background",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Display information about background process.
	//{'B',"start-background",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Start background process (daemon).
	{'c',"configuration",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Print configuration information and exit.
	{'C',"configfile",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//File: Use the given file for configuration.
	//{'f',"force",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Harness an energy which flows through the universe in order to do things without asking the user for permission.
	{'F',"fail",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Don't take rejection so easily: exit at the first sign of something being wrong.
	{'g',"gui",(GOPT_ARGUMENT_OPTIONAL),0,NULL},//Opens a window; good for letting the air out.
	{'G',"global-colours",(GOPT_ARGUMENT_OPTIONAL),0,NULL},//Use global terminal colour system.
	//{'i',"interactive",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Offloads all the hard decision making onto the user.
	{'I',"input",(GOPT_ARGUMENT_REQUIRED),0,NULL},//File: Uses the given file instead of STDIN.
	//{'k',"stop-background",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Politely stop the background process (daemon).
	//{'K',"kill-background",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Forcefully terminate the background process (daemon); in essence: kill it!
	//{'l',"long",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//
	{'L',"link",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//Link a dynamic (.so) library; continues even if linking is unsuccessful.
	{'n',"dryrun",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Describe what this software would do, and what files it would change, without actually doing or changing anything.
	{'N',"newdefaults",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Create new default files.
	{'O',"output",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//File: Tells the program to \'put out\' to the given file: whatever that means.
	//{'p',"preprocess",(GOPTARGUMENT_FORBIDDEN),0,NULL},//But where's postprocess?
	{'P',"prefix",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//Directory: Adds the given directory to the list of directories which contain directories, each containing list of directories to be searched to find files which list where to find the directories containing the needed files.
	{'q',"quiet",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//... please.
	//{'r',"recursive",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Search directories recursively.
	{'R',"require",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//Link a dynamic (.so) library; exits if linking is unsuccessful.
	{'s',"silence",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Tells the software to shut up! Doubly redundant since \'-v 0\' and \'-q\' both get the same result.
	{'S',"source",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//File:Reluctantly obeys the orders contained in the given file.
	{'t',"test",(GOPTARGUMENT_FORBIDDEN),0,NULL},//Run automated test.
	{'u',"user",(GOPT_ARGUMENT_REQUIRED),0,NULL},//Username: Exempli gratia: local user -> \'luser\'.
	{'U',"update",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Breaks things.
	{'x',"execute",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//Command: Kills the given commanding officer.
	//{'X',"exact",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//Whaaaa?: Does something VERY specific: we just don't know what.
	//{'y',"yes",(GOPT_ARGUMENT_FORBIDDEN),0,NULL},//Impersonates Jim Carrey's character in the movie Yes Man.
	{'d',"debug",(GOPT_ARGUMENT_OPTIONAL),0,NULL},//Boolean: Enable debugging.
	{'v',"verbose",(GOPTARGUMENT_OPTIONAL),0,NULL},//Number: Sets debug verbosity to the given unsigned integer: 0 being silent; 5 being maximum logging. Defaults to 3, if omitted, and 5, if specified without an argument.
	{'o',"stdout",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//Stream: stdout, stderr, FILE, or /dev/null: oh, so many choices.
	{'e',"error",(GOPT_ARGUMENT_REQUIRED|GOPT_ARGUMENT_NO_HYPHEN),0,NULL},//Stream: Redirect stderr to the given stream; exempli gratia, STDOUT or a the name of a file.
	{0,NULL,GOPT_LAST,0,NULL}
};
#endif //CNO_ALLOW_OPTIONS

cno_u8_type CNO_Options_Init();
cno_s8_type CNO_Options_Process(int argc, char *argv[]);
cno\cstring_type CNO_Options_Query(cno_cstring_type key, cno_u32_type *count);
cno_u8_type CNO_Options_Quit();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_OPTIONS_H
