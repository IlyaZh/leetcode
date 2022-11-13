#include <gtest/gtest.h>

#include "solution.hpp"

TEST(SolutionTest, case1) {
  Solution s;
  std::vector<Event> events{{1, 3}, {3, 5}, {5, 6}};
  const auto result = s.canAttendMeetings(events);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, case2) {
  Solution s;
  std::vector<Event> events{{1, 3}, {2, 5}, {5, 6}};
  const auto result = s.canAttendMeetings(events);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, case3) {
  Solution s;
  std::vector<Event> events{{1, 3}, {2, 5}, {5, 6}, {5, 7}, {1, 7}};
  const auto result = s.canAttendMeetings(events);
  decltype(result) answer{false};
  EXPECT_EQ(result, answer);
}

TEST(SolutionTest, case4) {
  Solution s;
  std::vector<Event> events{{1, 3}, {3, 5}, {5, 6}, {9, 22}};
  const auto result = s.canAttendMeetings(events);
  decltype(result) answer{true};
  EXPECT_EQ(result, answer);
}
