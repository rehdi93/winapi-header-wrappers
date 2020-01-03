#pragma once
#ifdef MessageBox
#   error "<windows.h> has already been included, possibly with undesired options."
#endif

#ifdef _MSC_VER
#   include <iso646.h>                  // Standard `and` etc. also with MSVC.
#endif

#ifndef _WIN32_WINNT
#   define _WIN32_WINNT     0x0600      // Windows Vista as earliest supported OS.
#endif
#undef WINVER
#define WINVER _WIN32_WINNT

#define IS_NARROW_WINAPI() \
    ("Define UTF8_WINAPI please.", sizeof(*GetCommandLine()) == 1)

#define IS_WIDE_WINAPI() \
    ("Define UNICODE please.", sizeof(*GetCommandLine()) > 1)

// UTF8_WINAPI is a custom macro for this file. UNICODE, _UNICODE and _MBCS are MS macros.
#if defined( UTF8_WINAPI) and defined( UNICODE )
#   error "Inconsistent encoding options, both UNICODE (UTF-16) and UTF8_WINAPI (UTF-8)."
#endif

#undef UNICODE
#undef _UNICODE
#ifdef UTF8_WINAPI
#   define _MBCS        // Mainly for 3rd party code that uses it for platform detection.
#else
#   define UNICODE
#   define _UNICODE     // Mainly for 3rd party code that uses it for platform detection.
#endif
#undef NOMINMAX
#define NOMINMAX
#undef STRICT
#define STRICT
#undef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
// After this an `#include <winsock2.h>` will actually include that header.

#include <windows.h>

inline auto winapi_h_assert_utf8_codepage()
    -> bool
{
    assert(( "The process codepage isn't UTF-8 (old Windows?).", GetACP() == 65001 ));
    return true;
}
