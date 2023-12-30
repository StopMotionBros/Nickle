#pragma once

#ifdef NK_PLATFORM_WINDOWS

#ifdef NK_BUILD_DLL
#define NICKLE_API __declspec(dllexport)
#else
#define NICKLE_API __declspec(dllimport)
#endif

#else
#error Nickle only supports Windows
#endif

#ifdef NK_ENABLE_ASSERTS

#define NK_ASSERT(x, ...) { if (!x) { NK_FATAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define NK_CORE_ASSERT(x, ...) { if (!x) { NK_CORE_FATAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#else

#define NK_ASSERT(x, ...)
#define NK_CORE_ASSERT(x, ...)

#endif

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#define BIT(x) (1 << x)