#pragma once

#ifndef _WIN32_WINNT
#   define _WIN32_WINNT     0x0600      // Windows Vista
#endif
#undef WINVER
#define WINVER _WIN32_WINNT

#undef UNICODE
#define UNICODE
#undef _UNICODE
#define _UNICODE            // Mainly for 3rd party code that uses it for platform detection.
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
