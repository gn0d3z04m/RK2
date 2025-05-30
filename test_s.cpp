#include "singleton_class.cpp"
#include <gtest/gtest.h>

TEST(Singleton, SimpleTest) {
	auto& a = Singleton::Instance();
	auto& b = Singleton::Instance();
	EXPECT_EQ(&a, &b);
}
