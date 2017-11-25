#ifndef CNO_BUILD_H
#define CNO_BUILD_H

#define CNO_BUILD_NAME "DreamPuff"
#define CNO_BUILD_ORGANIZATION "Canosw"

#define CNO_BUILD_VERSION_MAJOR 0
#define CNO_BUILD_VERSION_MINOR 3
#define CNO_BUILD_VERSIOM_PATCH 3

#if !defined(CNO_BUILD_DATE)
#define CNO_BUILD_DATE __DATE__
#endif //!defined(CNO_BUILD_DATE)

#if !defined(CNO_BUILD_TIME)
#define CNO_BUILD_TIME __TIME__
#endif //!defined(CNO_BUILD_TIME)

#if !defined(CNO_BUILD_COMMIT)
#define CNO_BUILD_COMMIT GIT_COMMIT
#endif //!defined(CNO_BUILD_COMMIT)

#include "c_predefined.h"

/*#if !defined(CNO_IS_C99) 
#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 199901L
#define CNO_IS_C99 1
#else
#define CNO_IS_C99 0
#error "Not C99"
#endif //__STDC_VERSION__ >= 199901L
#endif //__STDC_VERSION__
#endif //!defined(CNO_IS_C99) */

#if !defined(CNO_BUILD_GOAL)
#if defined(CNO_BUILD_FOR_BINARY)
#define CNO_BUILD_GOAL "binary"
#elif defined(CNO_BUILD_FOR_LIBRARY)
#define CNO_BUILD_GOAL "library"
#else
#define CNO_BUILD_GOAL "binary"
#endif //defined(CNO_BUILD_FOR_BINARY)
#endif //!defined(CNO_BUILD_GOAL)

#if !defined(CNO_BUILD_ARCHITECTURE)
#define CNO_BUILD_ARCHITECTURE C_ARCHITECTURE
#endif //!defined(CNO_BUILD_ARCHITECTURE)

#if !defined(CNO_BUILD_SYSTEM)
#define CNO_BUILD_SYSTEM C_SYSTEM
#endif //!defined(CNO_BUILD_SYSTEM)

#if !defined(CNO_BUILD_COMPILER)
#define CNO_BUILD_COMPILER C_COMPILER
#endif //!defined(CNO_BUILD_COMPILER)

#if !defined(CNO_DEBUG)
#if defined(NDEBUG)
#define CNO_DEBUG 0
#else
#define CNO_DEBUG 1
#endif //defined(NDEBUG)
#endif //!defined(CNO_DEBUG)

#if !defined(CNO_DS)
#if C_SYSTEM_WINDOWS || C_SYSTEM_WINDOWSCE
#define CNO_DS "\\"
#else
#define CNO_DS "/"
#endif //C_SYSTEM_WINDOWS || C_SYSTEM_WINDOWSCE
#endif //!defined(CNO_DS)

#if !defined(CNO_ROOT)
#if C_SYSTEM_WINDOWS || C_SYSTEM_WINDOWSCE
#define CNO_ROOT "C:\\"
#else
#define CNO_ROOT "/"
#endif //C_SYSTEM_WINDOWS || C_SYSTEM_WINDOWSCE
#endif //!defined(CNO_ROOT)

#if !defined(CNO_BUFFER_MAXSIZE)
#define CNO_BUFFER_MAXSIZE 1024
#endif //!defined(CNO_BUFFER_MAXSIZE)

#if !defined(CNO_TYPEDEFS_SET)
typedef size_t cno_size_type;
typedef unsigned char cno_u8_type;
typedef signed char cno_s8_type;
typedef unsigned short cno_u16_type;
typedef signed short cno_s16_type;
typedef unsigned long cno_u32_type;
typedef signed long cno_s32_type;
typedef unsigned long long cno_u64_type;
typedef signed long long cno_s64_type;
typedef float cno_f32_type;
typedef double cno_f64_type;
typedef cno_u8_type* cno_buffer_type;
typedef unsigned char* cno_cstring_type;
typedef void* cno_utf8_type;
#if !defined(CNO_noop)
#define CNO_noop ((void)0)
#endif //!defined(CNO_noop)
#define CNO_TYPEDEFS_SET 1
#endif //!defined(CNO_TYPEDEFS_SET)

/* Static Dependencies */
/* Standard */
#define CNO_HAVE_STDIO 1
#define CNO_HAVE_STDLIB 1
#define CNO_HAVE_STRING 1
#define CNO_HAVE_MATH 1
#define CNO_HAVE_TIME 1
#define CNO_HAVE_STDARG 1
#define CNO_HAVE_ERRNO 1
#define CNO_HAVE_ASSERT 1
/* Unix */
#define CNO_HAVE_UNISTD 1
#define CNO_HAVE_UUID 1
#define CNO_HAVE_PTHREAD 0
/* Bundled */
#define CNO_HAVE_WHEREAMI 1
#define CNO_HAVE_GOPT 1
#define CNO_HAVE_PARSON 1
#define CNO_HAVE_TINYFILES 1
#define CNO_HAVE_UTF8 1
#define CNO_HAVE_STRETCHYBUFFER 1
#define CNO_HAVE_TINYFILEDIALOGS 0
#define CNO_HAVE_SDS 0
/* External */
#define CNO_HAVE_SDL2 1
#define CNO_HAVE_ARCHIVE 1
#define CNO_HAVE_PCRE 0
#define CNO_HAVE_USB 0
#define CNO_HAVE_GAMEPAD 0
/* SDL */
#if CNO_HAVE_SDL2
#define CNO_HAVE_SDL2_IMAGE 1
#define CNO_HAVE_SDL2_MIXER 1
#define CNO_HAVE_SDL2_TTF 1
#define CNO_HAVE_SDL2_NET 1
#endif /* CNO_HAVE_SDL2 */

#define CNO_DEVICE_UNKNOWN 0
#define CNO_DEVICE_DESKTOP 1
#define CNO_DEVICE_MIXED 2
#define CNO_DEVICE_MOBILE 3
#define CNO_DEVICE_CLOSEDSYSTEM 4
#if !defined(CNO_DEVICE)
#define CNO_DEVICE CNO_DEVICE_DESKTOP
#endif //!defined(CNO_DEVICE)

//cno_settings
#define CNO_MATCH_ENGINE_NONE 0
#define CNO_MATCH_ENGINE_OTHER 1
#define CNO_MATCH_ENGINE_STDLIB 2
#if !defined(CNO_MATCH_ENGINE)
#if CNO_HAVE_STDLIB
#define CNO_MATCH_ENGINE CNO_MATCH_ENGINE_STDLIB
#else
#define CNO_MATCH_ENGINE CNO_MATCH_ENGINE_NONE
#endif //[CNO_HAVE]
#endif //!defined(CNO_MATCH_ENGINE)

//cno_string
#define CNO_STRING_ENGINE_NONE 0
#define CNO_STRING_ENGINE_OTHER 1
#define CNO_STRING_ENGINE_STRING 2
#define CNO_STRING_ENGINE_UTF8 3
#define CNO_STRING_ENGINE_SDS 4
#if !defined(CNO_STRING_ENGINE)
#if CNO_HAVE_UTF8
#define CNO_STRING_ENGINE CNO_STRING_ENGINE_UTF8
#elif CNO_HAVE_STRING
#define CNO_STRING_ENGINE CNO_STRING_ENGINE_STRING
#else
#define CNO_STRING_ENGINE CNO_STRING_ENGINE_NONE
#endif //CNO_HAVE_UTF8
#endif //!defined(CNO_STRING_ENGINE)

//cno_time
#define CNO_TIME_ENGINE_NONE 0
#define CNO_TIME_ENGINE_OTHER 1
#define CNO_TIME_ENGINE_TIME 2
#define CNO_TIME_ENGINE_SDL2 3
#if !defined(CNO_TIME_ENGINE)
#if CNO_HAVE_SDL2
#define CNO_TIME_ENGINE CNO_TIME_ENGINE_SDL2
#elif CNO_HAVE_TIME
#define CNO_TIME_ENGINE CNO_TIME_ENGINE_TIME
#else
#define CNO_TIME_ENGINE CNO_TIME_ENGINE_NONE
#endif //CNO_HAVE_SDL2
#endif //!defined(CNO_TIME_ENGINE)

//cno_assertion
#define CNO_ASSERTION_ENGINE_NONE 0
#define CNO_ASSERTION_ENGINE_OTHER 1
#define CNO_ASSERTION_ENGINE_ASSERT 2
#define CNO_ASSERTION_ENGINE_SDL2 3
#if !defined(CNO_ASSERTION_ENGINE)
#if CNO_HAVE_SDL2
#define CNO_ASSERTION_ENGINE CNO_ASSERTION_ENGINE_SDL2
#elif CNO_HAVE_ASSERT
#define CNO_ASSERTION_ENGINE CNO_ASSERTION_ENGINE_ASSERT
#else
#define CNO_ASSERION_ENGINE CNO_ASSERTION_ENGINE_NONE
#endif //CNO_HAVE_SDL2
#endif //!defined(CNO_ASSERTION_ENGINE)

//cno_regular_expressions: no regex on msvc
//CDM(

//cno_directories
#define CNO_DIRECTORY_ENGINE_NONE 0
#define CNO_DIRECTORY_ENGINE_OTHER 1
#define CNO_DIRECTORY_ENGINE_GLOB 2
#define CNO_DIRECTORY_ENGINE_DIRENT 3
#define CNO_DIRECTORY_ENGINE_TINYFILES 4
#if !defined(CNO_DIRECTORY_ENGINE)
#if CNO_HAVE_TINYFILES
#define CNO_DIRECTORY_ENGINE CNO_DIRECTORY_ENGINE_TINYFILES
#else
#define CNO_DIRECTORY_ENGINE CNO_DIRECTORY_ENGINE_NONE
#endif //CNO_HAVE_TINYFILES
#endif //!defined(CNO_DIRECTORY_ENGINE)

//cno_test
#define CNO_TEST_ENGINE_NONE 0
#define CNO_TEST_ENGINE_OTHER 1
#define CNO_TEST_ENGINE_INTERNAL 2
#if !defined(CNO_TEST_ENGINE)
#if CNO_HAVE_INTERNAL
#define CNO_TEST_ENGINE CNO_TEST_ENGINE_INTERNAL
#else
#define CNO_TEST_ENGINE CNO_TEST_ENGINE_NONE
#endif //CNO_HAVE_MUNIT
#endif //!defined(CNO_TEST_ENGINE)

//cno_json
//CDM(CNO_ALLOW_JSON,1)
#if !defined(CNO_ALLOW_JSON) //p
#define CNO_ALLOW_JSON 1 //p
#endif //!defined(CNO_ALLOW_JSON) //p

//cno_settings: no options on msvc
//CDM(CNO_ALLOW_OPTIONS,1)
#if !defined(CNO_ALLOW_OPTIONS) //p
#define CNO_ALLOW_OPTIONS 1 //p
#endif //!defined(CNO_ALLOW_OPTIONS) //p

//cno_settings
#if !defined(CNO_ALLOW_CONFIG)
#if CNO_ALLOW_JSON == 1
#define CNO_ALLOW_CONFIG 1
#else
#define CNO_ALLOW_CONFIG 0
#endif //CNO_ALLOW_JSON == 1
#endif //!defined(CNO_ALLOW_CONFIG)

//cno_log
#if !defined(CNO_ALLOW_LOG)
#define CNO_ALLOW_LOG 1
#endif //!defined(CNO_ALLOW_LOG)

#define CNO_MIDDLEWARE_ENGINE_NONE 0
#define CNO_MIDDLEWARE_ENGINE_OTHER 1
#define CNO_MIDDLEWARE_ENGINE_SDL2 2
#if !defined(CNO_MIDDLEWARE_ENGINE)
#if CNO_HAVE_SDL2
#define CNO_MIDDLEWARE_ENGINE CNO_MIDDLEWARE_ENGINE_SDL2
#else
#define CNO_MIDDLEWARE_ENGINE CNO_MIDDLEWARE_ENGINE_NONE
#endif //CNO_HAVE_SDL2
#endif //!defined(CNO_MIDDLEWARE_ENGINE)

#define CNO_ALLOW_THREADS 1

#if CNO_HAVE_STDIO
#define CNO_ALLOW_PRINTF 1
#endif //CNO_HAVE_STDIO

#if CNO_HAVE_STDLIB
#define CNO_ALLOW_EXIT 1
#endif //CNO_HAVE_STDLIB

#if CNO_HAVE_PARSON
#define cno_jsonvalue_type JSON_Value*
#define cno_jsonobject_type JSON_Object*
#define cno_jsonarray_type JSON_Array*
#endif //CNO_HAVE_PARSON

#if CNO_HAVE_TINYFILES
#define cno_directory_type tfDIR
#define cno_tinyfile_type tfFILE
#endif //CNO_HAVE_TINYFILES

#if CNO_HAVE_UTHASH
#define cno_hashhandle UT_hash_handle hh
#endif //CNO_HAVE_UTHASH

/* CNO_Functions */
#ifndef CNO_printf
#if CNO_HAVE_STDIO && CNO_ALLOW_PRINTF
#define CNO_printf(...) printf(__VA_ARGS__);
#else
#define CNO_printf(...) CNO_noop
#endif //CNO_HAVE_STDIO && CNO_ALLOW_PRINTF
#endif //CNO_printf
#ifndef CNO_sprintf
#if CNO_HAVE_STDIO
#define CNO_sprintf(...) sprintf(__VA_ARGS__);
#else
#define CNO_sprintf(...) CNO_noop
#endif //CNO_HAVE_STDIO
#endif //CNO_sprintf
#ifndef CNO_fopen
#if CNO_HAVE_STDIO
#define CNO_fopen(...) fopen(__VA_ARGS__)
#else
#define CNO_fopen(...) CNO_Noop
#endif //CNO_HAVE_STDIO
#endif //CNO_fopen
#ifndef CNO_fclose
#if CNO_HAVE_STDIO
#define CNO_fclose(...) fclose(__VA_ARGS__)
#else
#define CNO_fclose(...) CNO_noop
#endif //CNO_HAVE_STDIO
#endif //CNO_fclose
#ifndef CNO_fputs
#if CNO_HAVE_STDIO
#define CNO_fputs(...) fputs(__VA_ARGS__)
#else
#define CNO_fputs(...) CNO_noop
#endif //CNO_HAVE_STDIO
#endif //CNO_fputs
#if !defined(CNO_fprintf)
#if CNO_HAVE_STDIO
#define CNO_fprintf(...) fprintf(__VA_ARGS__)
#else
#define CNO_fprintf(...) CNO_noop
#endif //CNO_HAVE_STDIO
#endif //!defined(CNO_fprintf)

#ifndef CNO_exit
#if CNO_HAVE_STDLIB && CNO_ALLOW_EXIT
#define CNO_exit(...) exit(__VA_ARGS__)
#else
#define CNO_exit CNO_noop
#endif //CNO_HAVE_STDLIB && CNO_ALLOW_EXIT
#endif //CNO_exit
#ifndef CNO_atoi
#if CNO_HAVE_STDLIB
#define CNO_atoi(...) atoi(__VA_ARGS__)
#else
#define CNO_atoi(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_atoi
#ifndef CNO_getenv
#if CNO_HAVE_STDLIB
#define CNO_getenv(...) getenv(__VA_ARGS__)
#else
#define CNO_getenv(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_getenv
#ifndef CNO_malloc
#if CNO_HAVE_STDLIB
#define CNO_malloc(...) malloc(__VA_ARGS__)
#else
#define CNO_malloc(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_malloc
#ifndef CNO_calloc
#if CNO_HAVE_STDLIB
#define CNO_calloc(...) calloc(__VA_ARGS__)
#else
#define CNO_calloc(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_calloc
#ifndef CNO_realloc
#if CNO_HAVE_STDLIB
#define CNO_realloc(...) realloc(__VA_ARGS__)
#else
#define CNO_realloc(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_realloc
#ifndef CNO_free
#if CNO_HAVE_STDLIB
#define CNO_free(...) free(__VA_ARGS__)
#else
#define CNO_free(...) CNO_noop
#endif //CNO_HAVE_STDLIB
#endif //CNO_free

#ifndef CNO_strcpy
#if CNO_HAVE_STRING
#define CNO_strcpy(...) strcpy(__VA_ARGS__)
#else
#define CNO_strcpy(...) CNO_noop
#endif //CNO_HAVE_STRING
#endif //CNO_strcpy
#ifndef CNO_strcat
#if CNO_HAVE_STRING
#define CNO_strcat(...) strcat(__VA_ARGS__)
#else
#define CNO_strcat(...) CNO_noop
#endif //CNO_HAVE_STRING
#endif //CNO_strcat
#ifndef CNO_strlen
#if CNO_HAVE_STRING
#define CNO_strlen(...) strlen(__VA_ARGS__)
#else
#define CNO_strlen(...) CNO_noop
#endif //CNO_HAVE_STRING
#ifndef CNO_strncat
#if CNO_HAVE_STRING
#define CNO_strncat(...) strncat(__VA_ARGS__)
#else
#define CNO_strncat(...) CNO_noop
#endif //CNO_HAVE_STRING
#endif //CNO_strncat
#endif //CNO_strlen
#ifndef CNO_strcmp
#if CNO_HAVE_STRING
#define CNO_strcmp(...) strcmp(__VA_ARGS__)
#else
#define CNO_strcmp(...) CNO_noop
#endif //CNO_HAVE_STRING
#endif //CNO_strcmp

#ifndef CNO_abs
#if CNO_HAVE_MATH
#define CNO_abs(...) abs(__VA_ARGS__)
#else
#define CNO_abs(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_abs
#ifndef CNO_pow
#if CNO_HAVE_MATH
#define CNO_pow(...) pow(__VA_ARGS__)
#else
#define CNO_pow(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_pow
#ifndef CNO_sqrt
#if CNO_HAVE_MATH
#define CNO_sqrt(...) sqrt(__VA_ARGS__)
#else
#define CNO_sqrt(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_sqrt
#ifndef CNO_sin
#if CNO_HAVE_MATH
#define CNO_sin(...) sin(__VA_ARGS__)
#else
#define CNO_sin(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_sin
#ifndef CNO_cos
#if CNO_HAVE_MATH
#define CNO_cos(...) cos(__VA_ARGS__)
#else
#define CNO_cos(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_cos
#ifndef CNO_tan
#if CNO_HAVE_MATH
#define CNO_tan(...) tan(__VA_ARGS__)
#else
#define CNO_tan(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_tan
#ifndef CNO_asin
#if CNO_HAVE_MATH
#define CNO_asin(...) asin(__VA_ARGS__)
#else
#define CNO_asin(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_asin
#ifndef CNO_acos
#if CNO_HAVE_MATH
#define CNO_acos(...) acos(__VA_ARGS__)
#else
#define CNO_acos(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_acos
#ifndef CNO_atan
#if CNO_HAVE_MATH
#define CNO_atan(...) atan(__VA_ARGS__)
#else
#define CNO_atan(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_atan
#ifndef CNO_ceil
#if CNO_HAVE_MATH
#define CNO_ceil(...) ceil(__VA_ARGS__)
#else
#define CNO_ceil(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_ceil
#ifndef CNO_floor
#if CNO_HAVE_MATH
#define CNO_floor(...) floor(__VA_ARGS__)
#else
#define CNO_floor(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_floor
#ifndef CNO_round
#if CNO_HAVE_MATH
#define CNO_round(...) round(__VA_ARGS__)
#else
#define CNO_round(...) CNO_noop
#endif //CNO_HAVE_MATH
#endif //CNO_round

#ifndef CNO_time
#if CNO_HAVE_TIME
#define CNO_time(...) time(__VA_ARGS__)
#else
#define CNO_time(...) CNO_noop
#endif //CNO_HAVE_TIME
#endif //CNO_time
#ifndef CNO_gmtime
#if CNO_HAVE_TIME
#define CNO_gmtime(...) gmtime(__VA_ARGS__)
#else
#define CNO_gmtime(...) CNO_noop
#endif //CNO_HAVE_TIME
#endif //CNO_gmtime
#ifndef CNO_strftime
#if CNO_HAVE_TIME
#define CNO_strftime(...) strftime(__VA_ARGS__)
#else
#define CNO_strftime(...) CNO_noop
#endif //CNO_HAVE_TIME
#endif //CNO_strftime

#ifndef CNO_va_start
#if CNO_HAVE_STDARG
#define CNO_va_start(...) va_start(__VA_ARGS__)
#else
#define CNO_va_start(...) CNO_noop
#endif //CNO_HAVE_STDARG
#endif //CNO_va_start
#ifndef CNO_va_arg
#if CNO_HAVE_STDARG
#define CNO_va_arg(...) va_arg(__VA_ARGS__)
#else
#define CNO_va_arg(...) CNO_noop
#endif //CNO_HAVE_STDARG
#endif //CNO_va_arg
#ifndef CNO_va_end
#if CNO_HAVE_STDARG
#define CNO_va_end(...) va_end(__VA_ARGS__)
#else
#define CNO_va_end(...) CNO_noop
#endif //CNO_HAVE_STDARG
#endif //CNO_va_end

#ifndef CNO_uuid_generate
#if CNO_HAVE_UUID
#define CNO_uuid_generate(...) uuid_generate(__VA_ARGS__)
#else
#define CNO_HAVE_UUID CNO_noop
#endif //CNO_uuid_UUID
#endif //CNO_uuid_generate
#ifndef cno_uuid_type
#define cno_uuid_type uuid_t
#endif //cno_uuid_type

#endif //CNO_BUILD_H
