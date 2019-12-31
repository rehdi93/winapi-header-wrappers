#pragma once

#ifndef _WIN32_WINNT
#   define _WIN32_WINNT     0x0600      // Windows Vista
#endif
#undef WINVER
#define WINVER _WIN32_WINNT

#if defined( _MBCS ) and (defined( UNICODE ) or defined( _UNICODE ))
#   error "Inconsistent encoding specs, both Unicode (UTF-16) and MBCS (UTF-8)."
#endif

#undef UNICODE
#undef _UNICODE
#ifndef _MBCS           // _MBCS can be used for new-in-Windows-10 UTF-8 GUI apps.
#   define UNICODE
#   define _UNICODE     // Mainly for 3rd party code that uses it for platform detection.
#endif
#undef NOMINMAX
#define NOMINMAX
#undef STRICT
#define STRICT
#undef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN

#undef _WINSOCKAPI_
#define _WINSOCKAPI_
#include <windows.h>
//#include <winsock2.h>
