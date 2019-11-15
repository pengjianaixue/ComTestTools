/**
 * @brief     Provides basic standard define includes macro define of export and import.
 * @file      istddef.h
 * @author    Jiecheng Huang
 * @version   1.0.0
 * @date      2016-09
 * @pre
 * @bug
 * @warning
 * @note      Copyright (C) 1995-2016 MCGS
 ***************************************************************************************/

#if !defined(__INTERFACE_STANDARD_DEFINE_H__)
#define __INTERFACE_STANDARD_DEFINE_H__

#ifdef __cplusplus
#   define _EXTERN_C_ extern "C"
#   define _DEFAULT(val) = val
#else
#   define _EXTERN_C_ extern
#   define _DEFAULT(val)
#endif

#if defined(_WINDOWS_) || defined(WIN32) || defined(_WIN32) || defined(WIN64)|| defined(_WIN64)
#define _CDECL __cdecl
#else
#define _CDECL
#endif

#define _APIDECL(return) _EXTERN_C_ return _CDECL

#ifdef SYMBOLS_EXPORT
#   if defined(_WINDOWS_) || defined(WIN32) || defined(_WIN32) || defined(WIN64)|| defined(_WIN64)
#       define _SYMBOL_EX_ __declspec(dllexport)
#       define _SYMBOL_IM_ __declspec(dllimport)
#       define _API(return) _EXTERN_C_ _SYMBOL_EX_ return _CDECL
#       define _APIIMPORT(return) _EXTERN_C_ _SYMBOL_IM_ return _CDECL
#   else
#       define _SYMBOL_IM_ __attribute__ ((dllimport))
#       if __GNUC__ >= 4
#           define _SYMBOL_EX_ __attribute__ ((visibility ("default")))
#           define _API(return) _EXTERN_C_ _SYMBOL_EX_ return _CDECL
#           define _APIIMPORT(return) _EXTERN_C_ _SYMBOL_IM_ return _CDECL
#       else
#           define _SYMBOL_EX_ __attribute__ ((dllexport))
#           define _API(return) _EXTERN_C_ _SYMBOL_EX_ return _CDECL
#           define _APIIMPORT(return) _EXTERN_C_ _SYMBOL_IM_ return _CDECL
        #endif
#   endif
#else
#   if defined(_WINDOWS_) || defined(WIN32) || defined(_WIN32) || defined(WIN64)|| defined(_WIN64)
#       define _SYMBOL_IM_ __declspec(dllimport)
#       define _SYMBOL_EX_ __declspec(dllexport)
#       define _API(return) _EXTERN_C_ _SYMBOL_IM_ return _CDECL
#       define _APIEXPORT(return) _EXTERN_C_ _SYMBOL_EX_ return _CDECL
#   else
#       define _SYMBOL_IM_ __attribute__ ((dllimport))
#       if __GNUC__ >= 4
#           define _SYMBOL_EX_ __attribute__ ((visibility ("default")))
#           define _API(return) _EXTERN_C_ _SYMBOL_IM_ return _CDECL
#           define _APIEXPORT(return) _EXTERN_C_ _SYMBOL_EX_ return _CDECL
#       else
#           define _SYMBOL_EX_ __attribute__ ((dllexport))
#           define _API(return) _EXTERN_C_ _SYMBOL_IM_ return _CDECL
#           define _APIEXPORT(return) _EXTERN_C_ _SYMBOL_EX_ return _CDECL
#       endif
#   endif
#endif

#include <stdint.h>
#include <stddef.h>

typedef enum {
    False = 0,
    True = 1
} bool_t;

#define ___void          //no parameter
#define ___in            //mandatory input parameter
#define ___in_opt        //optional input parameter
#define ___out           //mandatory output parameter
#define ___out_opt       //optional output parameter
#define ___in_out        //mandatory input/output parameter
#define ___in_out_opt    //optional input/output parameter

#endif // end of __INTERFACE_STANDARD_DEFINE_H__
