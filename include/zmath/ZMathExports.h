#pragma once

#ifdef ZMATH_EXPORTS
#define ZMATH_API __declspec(dllexport)
#else
#define ZMATH_API __declspec(dllimport)
#endif
