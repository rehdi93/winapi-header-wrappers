#pragma once
#include <assert.h>

#undef UTF8_WINAPI
#define UTF8_WINAPI
#include "windows-h.hpp"

inline const bool winapi_h_utf8_assertion_dummy = winapi_h_assert_utf8_codepage();
