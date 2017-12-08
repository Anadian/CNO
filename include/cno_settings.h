//cno_settings.h

#ifndef CNO_SETTINGS_H
#define CNO_SETTINGS_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#if (CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX) && (!defined(CNO_SETTINGS_MATCH_VALIDATION_REGEX) || !defined(CNO_SETTINGS_MATCH_REGEX_NMATCH))
#define CNO_SETTINGS_MATCH_VALIDATION_REGEX ":([-0-9A-Za-z_ ]*)?:([0-9A-Za-z_]+)?:(([-0-9A-Za-z]+)(=([0-9A-Za-z]))?)?:(0|(([NIRBWAUFDnirbwaufd])[^!?=;]*([!?])(=(((\|)|(([-0-9A-Za-z_.\/\\ ]+)([!?])?)))+)?));"
#define CNO_SETTINGS_MATCH_REGEX_NMATCH 18
#endif //(CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX) && (!defined(CNO_SETTING_VALIDATION_REGEX) || !defined(CNO_SETTING_REGEX_NMATCH))
// Conversion regex: /{":([^:]*):([^:]*):([^:=]*)(=([A-Za-z]))?:([0NIRBWAUFD][!?]?)(=([^;]*))?;","(.*)"},/{CNO_Setting_Type_,"\1","\2",'\5',"\3",'\6',NULL,"\9",NULL,0,0,0,"\8"},/
// /^{":([0-9A-Za-z ]*)?:([0-9a-z_]*)?:(([-a-z]+)(=([0-9A-Za-z]))?)?:(([0-9A-Z])(([!?])(=(([0-9A-Za-z._\/-]+[!?]?)|\|)*)?)?);", ?"((\w*):)?(.*)"},?/{"\1","\2",'\6',"\4",CNO_Value_\8...,"\15","\16",NULL,0,NULL,NULL,"\9"},/
typedef enum CNO_Value_Type_enum{
	CNO_Value_Flag='0',
	CNO_Value_Natural='N',
	CNO_Value_Integer='I',
	CNO_Value_Real='R',
	CNO_Value_Boolean='B',
	CNO_Value_Word='W', //[A-Za-z0-9_]
	CNO_Value_ASCII='A',
	CNO_Value_UTF8='U',
	CNO_Value_File='F', //file/directory/url
	CNO_Value_Discrete='D'
} CNO_Value_Type\ty;
typedef struct CNO_Setting_struct {
	cno_cstring_type section;
	cno_cstring_type config_name;
	cno_u8_type option_key;
	cno_cstring_type option_name;
	CNO_Value_Type_type value_type;
	cno_cstring_type hint;
	cno_cstring_type description;
	cno_cstring_type argument;
	cno_u8_type hits;
	union{
		cno_u8_type value; //natural/boolean
		cno_s32_type value; //integer
		cno_f32_type value; //real
		cno_cstring_type value; //word/ascii/file/discrete
		cno_utf8_type value; //utf8
	};
	union{
		cno_u8_type default_value; //natural/boolean
		cno_s32_type default_value; //integer
		cno_f32_type default_value; //real
		cno_cstring_type default_value; //word/ascii/file/discrete
		cno_utf8_type default_value; //utf8
	};
	cno_cstring_type valid_values;
} CNO_Setting_type; //system defaults => user config => options => -C if specified
	
/*
tier 1 ;
tier 2 :
tier 3 =
tier 4 | :[-0-9A-Za-z_ ]:[0-9A-Za-z_]:[-0-9A-Za-z]=[0-9A-Za-z]:[0-9A-Za-z!?]=[-0-9A-Za-z!?_ ];

number 0-?
true,on,enabled,yes=1
false,off,disabled,no=0
file/directory
string,subset,ascii,utf8,discrete,fd
input:controller engine:D!=none|sdl-joystick!|sdl-controller|xinput|libusb|libgamepad||Engine:Define which backend API (engine), if any, to use for reading joystick/gamepad/controller input.|sdl-joystick:
debug:verbosity|verbose=v:N?=3!|5?|0-5

{":::version=V:0;","Display version information."},
{":::help=h:0;","Display this help text."},
{":::all=a:0;","Acknowledge invisible files"},
{":::about-background=b:0;","Display information about background process."},
{":::start-background=B:0;","Start background process (daemon)."},
{":::configuration=c:0;","Print configuration information and exit."},
{":::configfile=C:F!;","File: Use the given file for configuration."},
{":::exit=E:0;","Disable premature exiting such as after display help or version information."},
{":::force=f:0;","Harness an energy which flows through the universe in order to do things without asking the user for permission."},
{":::fail=F:0;","Don't take rejection so easily: exit at the first sign of something being wrong."},
{":::global-colours=G:B!;","Use global terminal colour system."},
{":::stdin=i:0;","Read input from stdin instead of the input file."},
{":::input=I:F!;","File: Uses the given file instead of stdin."},
{":::stop-background=k:0;","Politely stop the background process (daemon)."},
{":::kill-background=K:0;","Forcefully terminate the background process (daemon); in essence: kill it!"},
{":::link=L:F!;", "Link a dynamic (.so) library; continues even if linking is unsuccessful."},
{":::message=m:U!;", "Pass the given message to the background daemon."},
{":::noop=n:0;","Describe what this software would do, and what files it would change, without actually doing or changing anything."},
{":::newdefaults=N:0;","Create new default files."},
{":::output=O:F!;","File: Tells the program to \"put out\" to the given file: whatever that means."},
{":::pipe=p:0;","But where's postprocess?"},
{":::prefix=P:F!;","Directory: Adds the given directory to the list of directories which contain directories, each containing list of directories to be searched to find files which list where to find the directories containing the needed files."},
{":::quiet=q:0;","... please."},
{":::query=Q:U!;","UTF8 query string:"},
{":::repl=r:0;", "Activate repl mode."},
{":::require=R:F!;", "Link a dynamic (.so) library; exits if linking is unsuccessful."},
{":::silent=s:0;","Tells the software to shut up! Doubly redundant since \"-v 0\" and \"-q\" both get the same result."},
{":::source=S:F!;","File:Reluctantly obeys the orders contained in the given file."},
{":::test=t:0;","Run automated test."},
{":::text=T:F!;","Load text from the given file; useful for changing languages."},
{":::user=u:W!;","Username: Exempli gratia: local user -> \"luser\"."},
{":::update=U:0;","Breaks things."},
{":::execute=x:D!;","Command: Kills the given commanding officer."},
{":::exact=X:D!;","Whaaaa?: Does something VERY specific: we just don't know what."},
{":::yes=y:0;","Impersonates Jim Carrey's character in the movie Yes Man."},
{":audio:enabled:audio=A:B!=true!|false;","Boolean: Enable audio."},
{":audio:channels::N!=2!|0-32;","Number: Max number of audio channels to use."},
{":audio:samplerate::N!=48000!|0-160_000;","Number: The sample rate, specified in Hz, to use for audio playback. 8000, 11025, 16000, 22050, 32000, 441000, 48000, or 96000 recommended."},
{":debug:enabled:debug=d:B?=true?|false!;","Boolean: Enable debugging."},
{":debug:verbosity:verbose=v:N?=3!|5?|0-5;""Number: Sets debug verbosity to the given unsigned integer: 0 being silent; 5 being maximum logging. Defaults to 3, if omitted, and 5, if specified without an argument."},
{":debug:standard_output:stdout=o:F!=stdout!;","Stream: stdout, stderr, FILE, or /dev/null: oh, so many choices."},
{":debug:standard_error:stderr=e:F!=stderr!;","Stream: Redirect stderr to the given stream; exempli gratia, STDOUT or a the name of a file."},
{":debug:file::B!=true!|false;","Boolean: Enable logging to a file."},
{":debug:log_filename:log=l:F!=cno.log!;","File: Name of the file to be used for logging."},
{"::dialogs::B!=true!|false;","Boolean: Sets whether to allow using external file dialogs."},
{"::environment::B!=true!|false;","Boolean: Sets whether to look for environment variables while initialising."},
{":input:keyboard_mode::D!=scancode!|keycode|text;","String: Sets the keyboard mode; in essence, how this software interprets keyboard input."}, //scancode, keycode, text
{":input:text_mode::D!=software|hardware!;","String: Sets whether to use the OS-defined (\"hardware\") keyboard or an internal, virtual (\"software\") keyboard for text input."}, //software, hardware
{":input:mouse_relative_motion::B!=true!|false;","Boolean: Accept the mouse's relative motion as an input source?"},
{":input:mouse_buttons::B!=true!|false;","Boolean: Accept mouse button events as an input source?"},
{":input:mouse_wheel::B!=true|false!;","Boolean: Accept mouse wheel events as a valid input source?"},
{":input:controller_engine::D!=none|sdl-joystick!|sdl-controller|xinput|libusb|libgamepad;","String: |sdl-joystick: Use SDL\'s native joystick engine; works well with joysticks of all shapes and size"}, //none, sdl-joystick, sdl-controller, xinput, libusb, libgamepad
{":input:joystick_buttons::B!=true!|false;","Boolean: Sets whether to accept joystick button events as an input source."},
{":input:joystick_axis::B!=true!|false;","Boolean: Sets whether to accept joystick axis/analog events as a valid input source."},
{":input:joystick_hat::B!=true!|false;","Boolean: Sets whether to accept joystick hat/pad events as a valid input source."},
{":input:joystick_ball::B!=true!|false;","Boolean: Set whether to accept joystick ball events as an input source."},
{":input:joystick_axis_deadzone::N!=800!|0-32_767;","Number: Sets the dead zone for all joysticks' axes; in essence, it's the minimum, absolute value an axis must possess (read) in to be used as an event."},
{":input:joystick_axis_peak::N!=32_000!|0-32_767;","Number: Sets the peak for joysticks' axes; in essence, the value that should be considered max when reading an axis event."},
{":input:touch_mode::D!=mouse!|touch;","String: Sets whether touch events should be interpreted has mouse clicks/motion or handled separately."}, //mouse, touch
{"::net::B!=true!|false;","Boolean: Enable networking functionality."},
{":sdl2:sdl2_enabled::B!=true!|false;","Boolean: Allow the use of SDL2 for video/threads/input-backend API."},
{":sdl2:sdl2_ttf_enabled::B!=true!|false;","Boolean: Use, SDL2-extension, SDL2_TTF for font rendering."},
{":sdl2:sdl2_gfx_enabled::B!=true|false!;","Boolean: Allow the use, SDL2-extension, SDL2_GFX for software rendering of primitives and graphical effects."},
{":sdl2:sdl2_net_enabled::B!=true!|false;","Boolean: Allow use of, SDL2-extension, SDL2_net for network functionality."},
{":sdl2 image:enabled::B!=true!|false;","Boolean: Use, SDL2-extension, SDL2_Image for image loading."},
{":sdl2 image:jpg::B!=true|false!;","Boolean: Allow SDL2_Image to load JPEG files."},
{":sdl2 image:png::B!=true!|false;","Boolean: Allow SDL2_Image to load PNG files."},
{":sdl2 image:tif::B!=true|false!;","Boolean: Allow SDL2_Image to load TIF files."},
{":sdl2 mixer:enabled::B!=true!|false;","Boolean: Use, SDL2-extension, SDL2_Mixer for audio."},
{":sdl2 mixer:flac::B!=true|false!;","Boolean: Allow SDL2_Mixer to load FLAC audio files."},
{":sdl2 mixer:mod::B!=true|false!;","Boolean: Allow SDL2_Mixer to load MOD audio files."},
{":sdl2 mixer:mp3::B!=true|false!;","Boolean: Allow SDL2_Mixer to load MP3 audio files."},
{":sdl2 mixer:ogg::B!=true!|false;","Boolean: Allow SDL2_Mixer to load OGG audio files."},
{":threads:enabled::B!=true!|false;","Boolean: Allow the use of multithreading."},
{":threads:max_threads::N!=8!|0-8;","Number: Sets the maximum number of threads."},
{":threads:logic::B!=true!|false;","Boolean: Conduct logic on its own thread."},
{":threads:fileio::B!=true!|false;","Boolean: Conduct file IO on its own thread."},
{":threads:network::B!=true!|false;","Boolean: Conduct networking on its own thread."},
{":video:enabled:gui=g:B!=true!|false;","Boolean: Enable video. (Opens a window; good for letting the air out.)"},
{":video:save_screenshot_bmp::B!=true|false!;","Boolean: Save screenshots as bitmap image files."},
{":video:save_screenshot_png::B!=true!|false;","Boolean: Save screenshots as PNG image files."},
{":video:driver::N!=0!|0-8;","Number: Use the video driver, corresponding to the given number, for all video rendering."},
{":video:display::N!=0!|0-8;","Number: Prefer the display, corresponding to give number, for creating windows and rendering fullscreen."},
{":video:displaymode::N!=0!|0-16;","Number: Derive resolution, colour depth, and fullscreen rules from the display-mode which corresponds to the given number."},
{":video:x_offset::I!=0!|-32787-32787;","Integer: The x position of the window in pixels."},
{":video:y_offset::I!=0!|-32787-32787;","Integer: The y position of the window in pixels."},
{":video:width::N!=640!|0-65_535;","Number: The width (horizontal size) of the window in pixels."},
{":video:height::N!=480!|0-65_535;","Number: The height (vertical size) of the window in pixels."},
{":video:bits_per_pixel::N!=32!|0-32;","Number: The colour depth of window/display in bits per pixel; not to be confused with bytes per pixel."},
{":video:exclusive_fullscreen::B!=true|false!;","Boolean: Whether to prefer exclusive (\"real\") fullscreen (changing the desktop display mode to rendering resolution) over windowed/borderless (\"fake\") fullscreen."},
{":video:framerate::N!=0!|0-120;","Number: How many times the render area should be refreshed (re-rendered) in a second (hertz); also commonly known as frames per second (FPS) or refresh rate. 0 will disable frame limiting altogether allowing the screen to be rendered as many times-a-second as it can (unlimited frames per second)."},
{":video:resizable::B!=true!|false;","Boolean: Allows windows to be resized but pulling on their edge."},
{":video:borderless::B!=true|false!;","Boolean: Makes windows borderless, essentially, removing the titlebar and the close/minimize buttons, showing only the rendering area."},
{":video:disable_screensaver::B!=true!|false;","Boolean: Explicitly disable any screensavers while application has focus; useful if you using sdl-joystick."},
{":video:software_bitmaps::B!=true|false!;","Boolean: Store images (bitmaps) in a software format (on CPU/RAM) as opposed to the default hardware format (GPU/vRAM)."},
//{":video:software_effects::B!=true|false!;","Boolean: Render graphical effects on the CPU (software style) as opposed to the, default, GPU (hardware-accelerated rendering)."},
{":video:software_render::B!=true|false!;","Boolean: Store the render buffer in RAM (software-style CPU blitting) as opposed to the default, hardware-accelerated, texture format."},
{":directories:portable::B!=true!|false;","Boolean: Only use directory containing this executable/binary for storing and retrieving data: portable-style ./; as opposed to unix-style: /usr/local/* and ~/*."},
{":directories:engine_data::F!=./engine!;","Directory: The directory, in which, the engine data can be found."},
{":directories:user_data::F!=./data!;","Directory: The directory, in which, user data should be saved."}
*/

{"","",'V',"version",CNO_Value_0...,"","Display version information.",NULL,0,NULL,NULL,""},
{"","",'h',"help",CNO_Value_0...,"","Display this help text.",NULL,0,NULL,NULL,""},
{"","",'a',"all",CNO_Value_0...,"","Acknowledge invisible files",NULL,0,NULL,NULL,""},
{"","",'b',"about-background",CNO_Value_0...,"","Display information about background process.",NULL,0,NULL,NULL,""},
{"","",'B',"start-background",CNO_Value_0...,"","Start background process (daemon).",NULL,0,NULL,NULL,""},
{"","",'c',"configuration",CNO_Value_0...,"","Print configuration information and exit.",NULL,0,NULL,NULL,""},
{"","",'C',"configfile",CNO_Value_F...,"File"," Use the given file for configuration.",NULL,0,NULL,NULL,"!"},
{"","",'E',"exit",CNO_Value_0...,"","Disable premature exiting such as after display help or version information.",NULL,0,NULL,NULL,""},
{"","",'f',"force",CNO_Value_0...,"","Harness an energy which flows through the universe in order to do things without asking the user for permission.",NULL,0,NULL,NULL,""},
{"","",'F',"fail",CNO_Value_0...,"","Don't take rejection so easily: exit at the first sign of something being wrong.",NULL,0,NULL,NULL,""},
{"","",'G',"global-colours",CNO_Value_B...,"","Use global terminal colour system.",NULL,0,NULL,NULL,"!"},
{"","",'i',"stdin",CNO_Value_0...,"","Read input from stdin instead of the input file.",NULL,0,NULL,NULL,""},
{"","",'I',"input",CNO_Value_F...,"File"," Uses the given file instead of stdin.",NULL,0,NULL,NULL,"!"},
{"","",'k',"stop-background",CNO_Value_0...,"","Politely stop the background process (daemon).",NULL,0,NULL,NULL,""},
{"","",'K',"kill-background",CNO_Value_0...,"","Forcefully terminate the background process (daemon); in essence: kill it!",NULL,0,NULL,NULL,""},
{"","",'L',"link",CNO_Value_F...,"","Link a dynamic (.so) library; continues even if linking is unsuccessful.",NULL,0,NULL,NULL,"!"},
{"","",'m',"message",CNO_Value_U...,"","Pass the given message to the background daemon.",NULL,0,NULL,NULL,"!"},
{"","",'n',"noop",CNO_Value_0...,"","Describe what this software would do, and what files it would change, without actually doing or changing anything.",NULL,0,NULL,NULL,""},
{"","",'N',"newdefaults",CNO_Value_0...,"","Create new default files.",NULL,0,NULL,NULL,""},
{"","",'O',"output",CNO_Value_F...,"File"," Tells the program to \"put out\" to the given file: whatever that means.",NULL,0,NULL,NULL,"!"},
{"","",'p',"pipe",CNO_Value_0...,"","But where's postprocess?",NULL,0,NULL,NULL,""},
{"","",'P',"prefix",CNO_Value_F...,"Directory"," Adds the given directory to the list of directories which contain directories, each containing list of directories to be searched to find files which list where to find the directories containing the needed files.",NULL,0,NULL,NULL,"!"},
{"","",'q',"quiet",CNO_Value_0...,"","... please.",NULL,0,NULL,NULL,""},
{"","",'Q',"query",CNO_Value_U...,"","UTF8 query string:",NULL,0,NULL,NULL,"!"},
{"","",'r',"repl",CNO_Value_0...,"","Activate repl mode.",NULL,0,NULL,NULL,""},
{"","",'R',"require",CNO_Value_F...,"","Link a dynamic (.so) library; exits if linking is unsuccessful.",NULL,0,NULL,NULL,"!"},
{"","",'s',"silent",CNO_Value_0...,"","Tells the software to shut up! Doubly redundant since \"-v 0\" and \"-q\" both get the same result.",NULL,0,NULL,NULL,""},
{"","",'S',"source",CNO_Value_F...,"File","Reluctantly obeys the orders contained in the given file.",NULL,0,NULL,NULL,"!"},
{"","",'t',"test",CNO_Value_0...,"","Run automated test.",NULL,0,NULL,NULL,""},
{"","",'T',"text",CNO_Value_F...,"","Load text from the given file; useful for changing languages.",NULL,0,NULL,NULL,"!"},
{"","",'u',"user",CNO_Value_W...,"Username"," Exempli gratia: local user -> \"luser\".",NULL,0,NULL,NULL,"!"},
{"","",'U',"update",CNO_Value_0...,"","Breaks things.",NULL,0,NULL,NULL,""},
{"","",'x',"execute",CNO_Value_D...,"Command"," Kills the given commanding officer.",NULL,0,NULL,NULL,"!"},
{"","",'X',"exact",CNO_Value_D...,"","Whaaaa?: Does something VERY specific: we just don't know what.",NULL,0,NULL,NULL,"!"},
{"","",'y',"yes",CNO_Value_0...,"","Impersonates Jim Carrey's character in the movie Yes Man.",NULL,0,NULL,NULL,""},
{"audio","enabled",'A',"audio",CNO_Value_B...,"Boolean"," Enable audio.",NULL,0,NULL,NULL,"!=true!|false"},
{"audio","channels",'',"",CNO_Value_N...,"Number"," Max number of audio channels to use.",NULL,0,NULL,NULL,"!=2!|0-32"},
{"audio","samplerate",'',"",CNO_Value_N...,"Number"," The sample rate, specified in Hz, to use for audio playback. 8000, 11025, 16000, 22050, 32000, 441000, 48000, or 96000 recommended.",NULL,0,NULL,NULL,"!=48000!|0-160_000"},
{"debug","enabled",'d',"debug",CNO_Value_B...,"Boolean"," Enable debugging.",NULL,0,NULL,NULL,"?=true?|false!"},
{":debug:verbosity:verbose=v:N?=3!|5?|0-5;""Number: Sets debug verbosity to the given unsigned integer: 0 being silent; 5 being maximum logging. Defaults to 3, if omitted, and 5, if specified without an argument."},
{"debug","standard_output",'o',"stdout",CNO_Value_F...,"Stream"," stdout, stderr, FILE, or /dev/null: oh, so many choices.",NULL,0,NULL,NULL,"!=stdout!"},
{"debug","standard_error",'e',"stderr",CNO_Value_F...,"Stream"," Redirect stderr to the given stream; exempli gratia, STDOUT or a the name of a file.",NULL,0,NULL,NULL,"!=stderr!"},
{"debug","file",'',"",CNO_Value_B...,"Boolean"," Enable logging to a file.",NULL,0,NULL,NULL,"!=true!|false"},
{"debug","log_filename",'l',"log",CNO_Value_F...,"File"," Name of the file to be used for logging.",NULL,0,NULL,NULL,"!=cno.log!"},
{"","dialogs",'',"",CNO_Value_B...,"Boolean"," Sets whether to allow using external file dialogs.",NULL,0,NULL,NULL,"!=true!|false"},
{"","environment",'',"",CNO_Value_B...,"Boolean"," Sets whether to look for environment variables while initialising.",NULL,0,NULL,NULL,"!=true!|false"},
{"input","keyboard_mode",'',"",CNO_Value_D...,"String"," Sets the keyboard mode; in essence, how this software interprets keyboard input.",NULL,0,NULL,NULL,"!=scancode!|keycode|text"}, //scancode, keycode, text
{"input","text_mode",'',"",CNO_Value_D...,"String"," Sets whether to use the OS-defined (\"hardware\") keyboard or an internal, virtual (\"software\") keyboard for text input.",NULL,0,NULL,NULL,"!=software|hardware!"}, //software, hardware
{"input","mouse_relative_motion",'',"",CNO_Value_B...,"Boolean"," Accept the mouse's relative motion as an input source?",NULL,0,NULL,NULL,"!=true!|false"},
{"input","mouse_buttons",'',"",CNO_Value_B...,"Boolean"," Accept mouse button events as an input source?",NULL,0,NULL,NULL,"!=true!|false"},
{"input","mouse_wheel",'',"",CNO_Value_B...,"Boolean"," Accept mouse wheel events as a valid input source?",NULL,0,NULL,NULL,"!=true|false!"},
{"input","controller_engine",'',"",CNO_Value_D...,"String"," |sdl-joystick: Use SDL\'s native joystick engine; works well with joysticks of all shapes and size",NULL,0,NULL,NULL,"!=none|sdl-joystick!|sdl-controller|xinput|libusb|libgamepad"}, //none, sdl-joystick, sdl-controller, xinput, libusb, libgamepad
{"input","joystick_buttons",'',"",CNO_Value_B...,"Boolean"," Sets whether to accept joystick button events as an input source.",NULL,0,NULL,NULL,"!=true!|false"},
{"input","joystick_axis",'',"",CNO_Value_B...,"Boolean"," Sets whether to accept joystick axis/analog events as a valid input source.",NULL,0,NULL,NULL,"!=true!|false"},
{"input","joystick_hat",'',"",CNO_Value_B...,"Boolean"," Sets whether to accept joystick hat/pad events as a valid input source.",NULL,0,NULL,NULL,"!=true!|false"},
{"input","joystick_ball",'',"",CNO_Value_B...,"Boolean"," Set whether to accept joystick ball events as an input source.",NULL,0,NULL,NULL,"!=true!|false"},
{"input","joystick_axis_deadzone",'',"",CNO_Value_N...,"Number"," Sets the dead zone for all joysticks' axes; in essence, it's the minimum, absolute value an axis must possess (read) in to be used as an event.",NULL,0,NULL,NULL,"!=800!|0-32_767"},
{"input","joystick_axis_peak",'',"",CNO_Value_N...,"Number"," Sets the peak for joysticks' axes; in essence, the value that should be considered max when reading an axis event.",NULL,0,NULL,NULL,"!=32_000!|0-32_767"},
{"input","touch_mode",'',"",CNO_Value_D...,"String"," Sets whether touch events should be interpreted has mouse clicks/motion or handled separately.",NULL,0,NULL,NULL,"!=mouse!|touch"}, //mouse, touch
{"","net",'',"",CNO_Value_B...,"Boolean"," Enable networking functionality.",NULL,0,NULL,NULL,"!=true!|false"},
{"sdl2","sdl2_enabled",'',"",CNO_Value_B...,"Boolean"," Allow the use of SDL2 for video/threads/input-backend API.",NULL,0,NULL,NULL,"!=true!|false"},
{"sdl2","sdl2_ttf_enabled",'',"",CNO_Value_B...,"Boolean"," Use, SDL2-extension, SDL2_TTF for font rendering.",NULL,0,NULL,NULL,"!=true!|false"},
{"sdl2","sdl2_gfx_enabled",'',"",CNO_Value_B...,"Boolean"," Allow the use, SDL2-extension, SDL2_GFX for software rendering of primitives and graphical effects.",NULL,0,NULL,NULL,"!=true|false!"},
{"sdl2","sdl2_net_enabled",'',"",CNO_Value_B...,"Boolean"," Allow use of, SDL2-extension, SDL2_net for network functionality.",NULL,0,NULL,NULL,"!=true!|false"},
{"sdl2 image","enabled",'',"",CNO_Value_B...,"Boolean"," Use, SDL2-extension, SDL2_Image for image loading.",NULL,0,NULL,NULL,"!=true!|false"},
{"sdl2 image","jpg",'',"",CNO_Value_B...,"Boolean"," Allow SDL2_Image to load JPEG files.",NULL,0,NULL,NULL,"!=true|false!"},
{"sdl2 image","png",'',"",CNO_Value_B...,"Boolean"," Allow SDL2_Image to load PNG files.",NULL,0,NULL,NULL,"!=true!|false"},
{"sdl2 image","tif",'',"",CNO_Value_B...,"Boolean"," Allow SDL2_Image to load TIF files.",NULL,0,NULL,NULL,"!=true|false!"},
{"sdl2 mixer","enabled",'',"",CNO_Value_B...,"Boolean"," Use, SDL2-extension, SDL2_Mixer for audio.",NULL,0,NULL,NULL,"!=true!|false"},
{"sdl2 mixer","flac",'',"",CNO_Value_B...,"Boolean"," Allow SDL2_Mixer to load FLAC audio files.",NULL,0,NULL,NULL,"!=true|false!"},
{"sdl2 mixer","mod",'',"",CNO_Value_B...,"Boolean"," Allow SDL2_Mixer to load MOD audio files.",NULL,0,NULL,NULL,"!=true|false!"},
{"sdl2 mixer","mp3",'',"",CNO_Value_B...,"Boolean"," Allow SDL2_Mixer to load MP3 audio files.",NULL,0,NULL,NULL,"!=true|false!"},
{"sdl2 mixer","ogg",'',"",CNO_Value_B...,"Boolean"," Allow SDL2_Mixer to load OGG audio files.",NULL,0,NULL,NULL,"!=true!|false"},
{"threads","enabled",'',"",CNO_Value_B...,"Boolean"," Allow the use of multithreading.",NULL,0,NULL,NULL,"!=true!|false"},
{"threads","max_threads",'',"",CNO_Value_N...,"Number"," Sets the maximum number of threads.",NULL,0,NULL,NULL,"!=8!|0-8"},
{"threads","logic",'',"",CNO_Value_B...,"Boolean"," Conduct logic on its own thread.",NULL,0,NULL,NULL,"!=true!|false"},
{"threads","fileio",'',"",CNO_Value_B...,"Boolean"," Conduct file IO on its own thread.",NULL,0,NULL,NULL,"!=true!|false"},
{"threads","network",'',"",CNO_Value_B...,"Boolean"," Conduct networking on its own thread.",NULL,0,NULL,NULL,"!=true!|false"},
{"video","enabled",'g',"gui",CNO_Value_B...,"Boolean"," Enable video. (Opens a window; good for letting the air out.)",NULL,0,NULL,NULL,"!=true!|false"},
{"video","save_screenshot_bmp",'',"",CNO_Value_B...,"Boolean"," Save screenshots as bitmap image files.",NULL,0,NULL,NULL,"!=true|false!"},
{"video","save_screenshot_png",'',"",CNO_Value_B...,"Boolean"," Save screenshots as PNG image files.",NULL,0,NULL,NULL,"!=true!|false"},
{"video","driver",'',"",CNO_Value_N...,"Number"," Use the video driver, corresponding to the given number, for all video rendering.",NULL,0,NULL,NULL,"!=0!|0-8"},
{"video","display",'',"",CNO_Value_N...,"Number"," Prefer the display, corresponding to give number, for creating windows and rendering fullscreen.",NULL,0,NULL,NULL,"!=0!|0-8"},
{"video","displaymode",'',"",CNO_Value_N...,"Number"," Derive resolution, colour depth, and fullscreen rules from the display-mode which corresponds to the given number.",NULL,0,NULL,NULL,"!=0!|0-16"},
{"video","x_offset",'',"",CNO_Value_I...,"Integer"," The x position of the window in pixels.",NULL,0,NULL,NULL,"!=0!|-32787-32787"},
{"video","y_offset",'',"",CNO_Value_I...,"Integer"," The y position of the window in pixels.",NULL,0,NULL,NULL,"!=0!|-32787-32787"},
{"video","width",'',"",CNO_Value_N...,"Number"," The width (horizontal size) of the window in pixels.",NULL,0,NULL,NULL,"!=640!|0-65_535"},
{"video","height",'',"",CNO_Value_N...,"Number"," The height (vertical size) of the window in pixels.",NULL,0,NULL,NULL,"!=480!|0-65_535"},
{"video","bits_per_pixel",'',"",CNO_Value_N...,"Number"," The colour depth of window/display in bits per pixel; not to be confused with bytes per pixel.",NULL,0,NULL,NULL,"!=32!|0-32"},
{"video","exclusive_fullscreen",'',"",CNO_Value_B...,"Boolean"," Whether to prefer exclusive (\"real\") fullscreen (changing the desktop display mode to rendering resolution) over windowed/borderless (\"fake\") fullscreen.",NULL,0,NULL,NULL,"!=true|false!"},
{"video","framerate",'',"",CNO_Value_N...,"Number"," How many times the render area should be refreshed (re-rendered) in a second (hertz); also commonly known as frames per second (FPS) or refresh rate. 0 will disable frame limiting altogether allowing the screen to be rendered as many times-a-second as it can (unlimited frames per second).",NULL,0,NULL,NULL,"!=0!|0-120"},
{"video","resizable",'',"",CNO_Value_B...,"Boolean"," Allows windows to be resized but pulling on their edge.",NULL,0,NULL,NULL,"!=true!|false"},
{"video","borderless",'',"",CNO_Value_B...,"Boolean"," Makes windows borderless, essentially, removing the titlebar and the close/minimize buttons, showing only the rendering area.",NULL,0,NULL,NULL,"!=true|false!"},
{"video","disable_screensaver",'',"",CNO_Value_B...,"Boolean"," Explicitly disable any screensavers while application has focus; useful if you using sdl-joystick.",NULL,0,NULL,NULL,"!=true!|false"},
{"video","software_bitmaps",'',"",CNO_Value_B...,"Boolean"," Store images (bitmaps) in a software format (on CPU/RAM) as opposed to the default hardware format (GPU/vRAM).",NULL,0,NULL,NULL,"!=true|false!"},
{"video","software_render",'',"",CNO_Value_B...,"Boolean"," Store the render buffer in RAM (software-style CPU blitting) as opposed to the default, hardware-accelerated, texture format.",NULL,0,NULL,NULL,"!=true|false!"},
{"directories","portable",'',"",CNO_Value_B...,"Boolean"," Only use directory containing this executable/binary for storing and retrieving data: portable-style ./; as opposed to unix-style: /usr/local/* and ~/*.",NULL,0,NULL,NULL,"!=true!|false"},
{"directories","engine_data",'',"",CNO_Value_F...,"Directory"," The directory, in which, the engine data can be found.",NULL,0,NULL,NULL,"!=./engine!"},
{"directories","user_data",'',"",CNO_Value_F...,"Directory"," The directory, in which, user data should be saved.",NULL,0,NULL,NULL,"!=./data!"},

cno_u8_type CNO_Settings_Init(CNO_Setting_type *settings);

cno_u8_type CNO_Settings_Default(CNO_Settings_type *settings);
cno_u8_type CNO_Settings_GetOpt(CNO_Settings_type *settings, int argc, char *argv[]);
cno_u8_type CNO_Settings_Save(CNO_Settings_type *settings, cno_cstring_type filename);
cno_u8_type CNO_Settings_Load(CNO_Settings_type *settings, cno_cstring_type filename);

cno_u8_type CNO_Settings_Quit(CNO_Setting_type *settings);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CNO_SETTINGS_H
