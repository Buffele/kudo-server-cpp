#pragma once

#include <stdint.h>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <mutex>
#include <stdarg.h>
#include <srpc/StringTypes.h>

//=========================================================================================================================================

static inline uint8_t ROTL8(uint8_t x, size_t y)
{
	return (x << y) | (x >> (8 - y));
}

static inline uint8_t ROTR8(uint8_t x, size_t y)
{
	return (x >> y) | (x << (8 - y));
}

//=========================================================================================================================================

enum
{
	Logf_Hidden = 0,
	Logf_Normal = 1,
	Logf_Nolock = 2,
};

inline std::mutex& LogLock()
{
	static std::mutex g_log_lock;
	return g_log_lock;
}

inline bool LogBegin(uint32_t flags)
{
	if (flags & Logf_Normal)
	{
		if (!(flags & Logf_Nolock))
			LogLock().lock();
		return true;
	}
	return false;
}

inline void LogEnd(uint32_t flags)
{
	if (!(flags & Logf_Nolock))
		LogLock().unlock();
}

template<typename... Args>
inline void LogRaw(const char* format, Args... args)
{
	printf(format, args...);
}

template<typename... Args>
inline void LogEx(uint32_t flags, const char* format, Args... args)
{
	if (LogBegin(flags))
	{
		LogRaw(format, args...);
		LogEnd(flags);
	}
}

#define LogLine(flags, ...) LogEx(flags, __VA_ARGS__)

//=========================================================================================================================================

inline srpc::String Format(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	size_t len = std::vsnprintf(NULL, 0, format, args);
	va_end(args);
	std::vector<char> vec(len + 1);
	va_start(args, format);
	std::vsnprintf(&vec[0], len + 1, format, args);
	va_end(args);
	return &vec[0];
}

inline srpc::WString Format(const wchar_t* format, ...)
{
	va_list args;
	va_start(args, format);
	size_t len = std::vswprintf(NULL, 0, format, args);
	va_end(args);
	std::vector<wchar_t> vec(len + 1);
	va_start(args, format);
	std::vswprintf(&vec[0], len + 1, format, args);
	va_end(args);
	return &vec[0];
}

//=========================================================================================================================================