#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, Case1) {
  Solution s;
  const vector<string> input = {};
  const auto encoded = s.Encode(input);
  const auto output = s.Decode(encoded);
  EXPECT_EQ(input, output);
}

TEST(SolutionTest, Case2) {
  Solution s;
  const vector<string> input = {"hello"};
  const auto encoded = s.Encode(input);
  const auto output = s.Decode(encoded);
  EXPECT_EQ(input, output);
}

TEST(SolutionTest, Case3) {
  Solution s;
  const vector<string> input = {"hello:@#$%^&*()"};
  const auto encoded = s.Encode(input);
  const auto output = s.Decode(encoded);
  EXPECT_EQ(input, output);
}

TEST(SolutionTest, Case4) {
  Solution s;
  const vector<string> input = {"hello:@#$%^&*()", "hello:@#$%^&*()"};
  const auto encoded = s.Encode(input);
  const auto output = s.Decode(encoded);
  EXPECT_EQ(input, output);
}

TEST(SolutionTest, Case5) {
  Solution s;
  const vector<string> input = {"h", "e", "l", "l", "o"};
  const auto encoded = s.Encode(input);
  const auto output = s.Decode(encoded);
  EXPECT_EQ(input, output);
}