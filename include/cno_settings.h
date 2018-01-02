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

typedef struct CNO_Settings_struct{
} CNO_Settings_type; //system defaults => user config => options => -C if specified
/*  */	CS\Byte\ty dialogs;
/*  */	CS\Byte\ty environment;
/* input */	CS\Word\ty keyboard_mode; //scancode, keycode, text
/* input */	CS\Word\ty text_mode; //software, hardware
/* input */	CS\Byte\ty mouse_relative_motion;
/* input */	CS\Byte\ty mouse_buttons;
/* input */	CS\Byte\ty mouse_wheel;
/* input */	CS\Word\ty controller_engine; //none, sdl-joystick, sdl-controller, xinput, libusb, libgamepad
/* input */	CS\Byte\ty joystick_buttons;
/* input */	CS\Byte\ty joystick_axis;
/* input */	CS\Byte\ty joystick_hat;
/* input */	CS\Byte\ty joystick_ball;
/* input */	CS\Byte\ty joystick_axis_deadzone;
/* input */	CS\Byte\ty joystick_axis_peak;
/* input */	CS\Word\ty touch_mode; //mouse, touch
/*  */	CS\Byte\ty net;
/* sdl2 */	CS\Byte\ty sdl2_enabled;
/* sdl2 */	CS\Byte\ty sdl2_ttf_enabled;
/* sdl2 */	CS\Byte\ty sdl2_gfx_enabled;
/* sdl2 */	CS\Byte\ty sdl2_net_enabled;
/* sdl2 image */	CS\Byte\ty enabled;
/* sdl2 image */	CS\Byte\ty jpg;
/* sdl2 image */	CS\Byte\ty png;
/* sdl2 image */	CS\Byte\ty tif;
/* sdl2 mixer */	CS\Byte\ty enabled;
/* sdl2 mixer */	CS\Byte\ty flac;
/* sdl2 mixer */	CS\Byte\ty mod;
/* sdl2 mixer */	CS\Byte\ty mp3;
/* sdl2 mixer */	CS\Byte\ty ogg;
/* threads */	CS\Byte\ty enabled;
/* threads */	CS\Byte\ty max_threads;
/* threads */	CS\Byte\ty logic;
/* threads */	CS\Byte\ty fileio;
/* threads */	CS\Byte\ty network;
/* video */	CS\Byte\ty enabled;
/* video */	CS\Byte\ty save_screenshot_bmp;
/* video */	CS\Byte\ty save_screenshot_png;
/* video */	CS\Byte\ty driver;
/* video */	CS\Byte\ty display;
/* video */	CS\Byte\ty displaymode;
/* video */	CS\Integer\ty x_offset;
/* video */	CS\Integer\ty y_offset;
/* video */	CS\Byte\ty width;
/* video */	CS\Byte\ty height;
/* video */	CS\Byte\ty bits_per_pixel;
/* video */	CS\Byte\ty exclusive_fullscreen;
/* video */	CS\Byte\ty framerate;
/* video */	CS\Byte\ty resizable;
/* video */	CS\Byte\ty borderless;
/* video */	CS\Byte\ty disable_screensaver;
/* video */	CS\Byte\ty software_bitmaps;
//{":video:software_effects::B!=true|false!;","Boolean: Render graphical effects on the CPU (software style) as opposed to the, default, GPU (hardware-accelerated rendering)."},
/* video */	CS\Byte\ty software_render;
/* directories */	CS\Byte\ty portable;
/* directories */	CS\String\ty engine_data;
/* directories */	CS\String\ty user_data;
*/

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
