// https://leetcode.com/problems/equal-row-and-column-pairs/

// 2352. Equal Row and Column Pairs

// Given a 0-indexed n x n integer matrix grid, return the number of pairs (Ri,
// Cj) such that row Ri and column Cj are equal.

// A row and column pair is considered equal if they contain the same elements
// in the same order (i.e. an equal array).

// Example 1:
// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]

// Example 2:
// Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// Output: 3
// Explanation: There are 3 equal row and column pairs:
// - (Row 0, Column 0): [3,1,2,2]
// - (Row 2, Column 2): [2,4,2,2]
// - (Row 3, Column 2): [2,4,2,2]

// Constraints:
// n == grid.length == grid[i].length
// 1 <= n <= 200
// 1 <= grid[i][j] <= 105

#pragma once

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class FoodRatings {
  map<string, int> rating;
  map<string, string> foodCuisineMap;
  map<string, set<pair<int, string>>> best;

 public:
  FoodRatings(const vector<string>& foods, const vector<string>& cuisines,
              const vector<int>& ratings) {
    const auto size = foods.size();
    for (size_t i = 0; i < size; ++i) {
      rating[foods[i]] = ratings[i];
      foodCuisineMap[foods[i]] = cuisines[i];
      best[cuisines[i]].insert({-ratings[i], foods[i]});
    }
  }

  string highestRated(const string& cuisine) {
    return best[cuisine].begin()->second;
  }

  void changeRating(string food, int newRating) {
    auto cur = rating[food];
    rating[food] = newRating;
    auto cuisine = foodCuisineMap[food];
    best[cuisine].erase(best[cuisine].find({-cur, food}));
    best[cuisine].insert({-newRating, food});
  }
};
