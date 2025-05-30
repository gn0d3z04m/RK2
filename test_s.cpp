#include "singleton_class.cpp"
#include <gtest/gtest.h>

TEST(Singleton, SimpleTest) {
	auto& a = Singleton::Instance();
	auto& b = Singleton::Instance();
	EXPECT_THROW(b = a, std::logic_error);
}
