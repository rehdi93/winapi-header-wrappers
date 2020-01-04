#pragma once
#undef UTF8_WINAPI
#define UTF8_WINAPI
#include "windows-h.hpp"

namespace uuid_0985060C_1AAD_453C_B3F9_A2E543F4CF1E {
    struct Winapi_envelope
    {
        Winapi_envelope()
        {
            static const bool dummy = winapi_h_assert_utf8_codepage();
        }
    };
    
    static const Winapi_envelope ensured_globally_single_utf8_assertion{};
}  // namespace uuid_0985060C_1AAD_453C_B3F9_A2E543F4CF1E
