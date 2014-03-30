#pragma once

#include "core/math_utils.h"
#include <string.h>

namespace Lux
{
	namespace UnitTest
	{
		template<typename T>
		LUX_FORCE_INLINE void expectEq(T p1, T p2, const char* file, uint32_t line)
		{
			if(p1 != p2)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<>
		LUX_FORCE_INLINE void expectEq<const char*>(const char* p1, const char* p2, const char* file, uint32_t line)
		{
			if(strcmp(p1, p2) != 0)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<typename T>
		LUX_FORCE_INLINE void expectNe(T p1, T p2, const char* file, uint32_t line)
		{
			if(p1 == p2)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<>
		LUX_FORCE_INLINE void expectNe<const char*>(const char* p1, const char* p2, const char* file, uint32_t line)
		{
			if(strcmp(p1, p2) == 0)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<typename T>
		LUX_FORCE_INLINE void expectLt(T p1, T p2, const char* file, uint32_t line)
		{
			if(p1 >= p2)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<>
		LUX_FORCE_INLINE void expectLt<const char*>(const char* p1, const char* p2, const char* file, uint32_t line)
		{
			if(strcmp(p1, p2) >= 0)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<typename T>
		LUX_FORCE_INLINE void expectGt(T p1, T p2, const char* file, uint32_t line)
		{
			if(p1 <= p2)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<>
		LUX_FORCE_INLINE void expectGt<const char*>(const char* p1, const char* p2, const char* file, uint32_t line)
		{
			if(strcmp(p1, p2) <= 0)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<typename T>
		LUX_FORCE_INLINE void expectLe(T p1, T p2, const char* file, uint32_t line)
		{
			if(p1 > p2)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<>
		LUX_FORCE_INLINE void expectLe<const char*>(const char* p1, const char* p2, const char* file, uint32_t line)
		{
			if(strcmp(p1, p2) > 0)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<typename T>
		LUX_FORCE_INLINE void expectGe(T p1, T p2, const char* file, uint32_t line)
		{
			if(p1 < p2)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		template<>
		LUX_FORCE_INLINE void expectGe<const char*>(const char* p1, const char* p2, const char* file, uint32_t line)
		{
			if(strcmp(p1, p2) < 0)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		LUX_FORCE_INLINE void expectCloseEq(float p1, float p2, float t, const char* file, uint32_t line)
		{
			ASSERT(t > 0);
			if(Math::abs(p1 - p2) > t)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		LUX_FORCE_INLINE void expectCloseNe(float p1, float p2, float t, const char* file, uint32_t line)
		{
			ASSERT(t > 0);
			if(Math::abs(p1 - p2) <= t)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		LUX_FORCE_INLINE void expectTrue(bool b, const char* file, uint32_t line)
		{
			if(!b)
			{
				Manager::instance().handleFail(file, line);
			}
		}

		LUX_FORCE_INLINE void expectFalse(bool b, const char* file, uint32_t line)
		{
			if(b)
			{
				Manager::instance().handleFail(file, line);
			}
		}
	} // ~UnitTest
} // ~Lux

#define LUX_EXPECT_EQ(p1, p2)	Lux::UnitTest::expectEq(p1, p2, __FILE__, __LINE__)
#define LUX_EXPECT_NE(p1, p2)	Lux::UnitTest::expectNe(p1, p2, __FILE__, __LINE__)
#define LUX_EXPECT_GT(p1, p2)	Lux::UnitTest::expectGt(p1, p2, __FILE__, __LINE__)
#define LUX_EXPECT_LT(p1, p2)	Lux::UnitTest::expectLt(p1, p2, __FILE__, __LINE__)
#define LUX_EXPECT_GE(p1, p2)	Lux::UnitTest::expectGe(p1, p2, __FILE__, __LINE__)
#define LUX_EXPECT_LE(p1, p2)	Lux::UnitTest::expectLe(p1, p2, __FILE__, __LINE__)
#define LUX_EXPECT_CLOSE_EQ(p1, p2)	Lux::UnitTest::expectCloseEq(p1, p2, __FILE__, __LINE__)
#define LUX_EXPECT_CLOSE_NE(p1, p2)	Lux::UnitTest::expectCloseNe(p1, p2, __FILE__, __LINE__)
#define LUX_EXPECT_TRUE(p1)		Lux::UnitTest::expectTrue(p1, __FILE__, __LINE__)
#define LUX_EXPECT_FALSE(p1)	Lux::UnitTest::expectFalse(p1, __FILE__, __LINE__)
