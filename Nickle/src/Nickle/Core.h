#pragma once

#ifdef NK_PLATFORM_WINDOWS

#ifdef NK_BUILD_DLL
#define NK_API __declspec(dllexport)
#else
#define NK_API __declspec(dllimport)
#endif

#else
#error Nickle only supports Windows
#endif