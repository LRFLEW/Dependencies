#define PACKAGE_VERSION "1.2rc3"

#ifdef _WIN32

// Microsoft version of 'inline'
#define inline __inline

// In Visual Studio, _M_IX86_FP=1 means /arch:SSE was used, likewise
// _M_IX86_FP=2 means /arch:SSE2 was used.
// Also, enable both _USE_SSE and _USE_SSE2 if we're compiling for x86-64
#if _M_IX86_FP >= 1 || defined(_M_X64)
#define _USE_SSE
#endif

#if _M_IX86_FP >= 2 || defined(_M_X64)
#define _USE_SSE2
#endif

// Visual Studio support alloca(), but it always align variables to 16-bit
// boundary, while SSE need 128-bit alignment. So we disable alloca() when
// SSE is enabled.
#ifndef _USE_SSE
#  define USE_ALLOCA
#endif

#elif defined(__APPLE__) && defined(__MACH__)

// Use GCC/Clang macros to test for SSE
#ifdef __SSE__
#define _USE_SSE /**/
#endif

#ifdef __SSE2__
#define _USE_SSE2 /**/
#endif

#define VAR_ARRAYS /**/

#endif

// Default to floating point
#ifndef FIXED_POINT
#  define FLOATING_POINT
#  define USE_SMALLFT
#else
#  define USE_KISS_FFT
#endif

// We don't need visibility declared on Win32 (where it's compiled
// as a static library) or macOS (where it defaults to visible)
#define EXPORT
