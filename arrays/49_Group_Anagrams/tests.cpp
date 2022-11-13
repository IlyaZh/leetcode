#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, case1) {
  Solution s;
  std::vector<std::string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
  for (auto vec : input) {
    std::sort(vec.begin(), vec.end());
  }
  const auto result = s.groupAnagrams(input);
  std::vector<std::vector<std::string>> answer{
      {"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, case2) {
  Solution s;
  std::vector<std::string> input{""};
  const auto result = s.groupAnagrams(input);
  std::vector<std::vector<std::string>> answer{{""}};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, case3) {
  Solution s;
  std::vector<std::string> input{"a"};
  const auto result = s.groupAnagrams(input);
  std::vector<std::vector<std::string>> answer{{"a"}};
  EXPECT_EQ(result, answer);
}
