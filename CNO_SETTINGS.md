## Regular Expressions

#if (CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX) && (!defined(CNO_SETTINGS_MATCH_VALIDATION_REGEX) || !defined(CNO_SETTINGS_MATCH_REGEX_NMATCH))
#define CNO_SETTINGS_MATCH_VALIDATION_REGEX ":([-0-9A-Za-z_ ]*)?:([0-9A-Za-z_]+)?:(([-0-9A-Za-z]+)(=([0-9A-Za-z]))?)?:(0|(([NIRBWAUFDnirbwaufd])[^!?=;]*([!?])(=(((\|)|(([-0-9A-Za-z_.\/\\ ]+)([!?])?)))+)?));"
#define CNO_SETTINGS_MATCH_REGEX_NMATCH 18
#endif //(CNO_SETTINGS_MATCH_ENGINE == CNO_SETTINGS_MATCH_ENGINE_REGEX) && (!defined(CNO_SETTING_VALIDATION_REGEX) || !defined(CNO_SETTING_REGEX_NMATCH))
// Conversion regex: /{":([^:]*):([^:]*):([^:=]*)(=([A-Za-z]))?:([0NIRBWAUFD][!?]?)(=([^;]*))?;","(.*)"},/{CNO_Setting_Type_,"\1","\2",'\5',"\3",'\6',NULL,"\9",NULL,0,0,0,"\8"},/

## Tiers
/*tier 1 ;
tier 2 :
tier 3 =
tier 4 | :[-0-9A-Za-z_ ]:[0-9A-Za-z_]:[-0-9A-Za-z]=[0-9A-Za-z]:[0-9A-Za-z!?]=[-0-9A-Za-z!?_ ];

number 0-?
true,on,enabled,yes=1
false,off,disabled,no=0
file/directory
string,subset,ascii,utf8,discrete,fd
:input:controller engine::D!=none|sdl-joystick!|sdl-controller|xinput|libusb|libgamepad||Engine:Define which backend API (engine), if any, to use for reading joystick/gamepad/controller input.|sdl-joystick:
:debug:verbosity:verbose=v:N?=3!|5?|0-5;*/

## Types
```
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
} CNO_Value_Type\t;
```

## Format
:[SECTION]:[CONFIG NAME]:[OPTION NAME](=<OPTION CHARACTER>):<TYPE>([! or ?](=<DEFAULT VALUE>!(|<DEFAULT ARGUMENT>?)(|<RANGE or a|list|of|values>))); [DESCRIPTION]<\n or \r>

```
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
//{":debug:file::B!=true!|false;","Boolean: Enable logging to a file."},
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
```