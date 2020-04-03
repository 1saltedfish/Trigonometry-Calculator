//
// MATLAB Compiler: 7.1 (R2019b)
// Date: Thu Apr  2 18:14:23 2020
// Arguments: "-B""macro_default""-W""cpplib:tanm""-T""link:lib""tanm.m""-C"
//

#ifndef tanm_h
#define tanm_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_tanm_C_API 
#define LIB_tanm_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_tanm_C_API 
bool MW_CALL_CONV tanmInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_tanm_C_API 
bool MW_CALL_CONV tanmInitialize(void);

extern LIB_tanm_C_API 
void MW_CALL_CONV tanmTerminate(void);

extern LIB_tanm_C_API 
void MW_CALL_CONV tanmPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_tanm_C_API 
bool MW_CALL_CONV mlxTanm(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_tanm
#define PUBLIC_tanm_CPP_API __declspec(dllexport)
#else
#define PUBLIC_tanm_CPP_API __declspec(dllimport)
#endif

#define LIB_tanm_CPP_API PUBLIC_tanm_CPP_API

#else

#if !defined(LIB_tanm_CPP_API)
#if defined(LIB_tanm_C_API)
#define LIB_tanm_CPP_API LIB_tanm_C_API
#else
#define LIB_tanm_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_tanm_CPP_API void MW_CALL_CONV tanm(int nargout, mwArray& output, const mwArray& input);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
