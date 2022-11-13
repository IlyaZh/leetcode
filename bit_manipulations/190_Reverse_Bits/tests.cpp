#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const auto result = s.reverseBits(0xff000000);
  decltype(result) answer{0x000000ff};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const auto result = s.reverseBits(0b00000010100101000001111010011100);
  decltype(result) answer{0b00111001011110000010100101000000};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, Case3) {
  Solution s;
  const auto result = s.reverseBits(0b11111111111111111111111111111101);
  decltype(result) answer{0b10111111111111111111111111111111};
  EXPECT_EQ(result, answer);
}
