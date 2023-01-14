#include <gtest/gtest.h>

#include <string_view>

#include "solution.hpp"

inline constexpr static const string_view str = "ABC ABCDAB ABCDABCDABDE";

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.Find("ABCDABD", str);
  EXPECT_EQ(result, 15);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.Find("ABCDABZ", str);
  EXPECT_EQ(result, nullopt);
}

TEST(SolutionTest, Case3) {
  Solution s;
  const auto result = s.Find("ABCD", str);
  EXPECT_EQ(result, 4);
}
