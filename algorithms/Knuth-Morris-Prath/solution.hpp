// Knuths-Morris-Praths algorithm for finding substring W in string S

#include <optional>
#include <string>
#include <string_view>

using namespace std;

class Solution {
 public:
  optional<size_t> Find(string_view W, string_view S) {
    if (W.size() > S.size() || S.empty()) {
      return nullopt;
    }
    if (W.empty()) {
      return 0;
    }
    size_t m = 0;
    size_t i = 0;
    while (m + i < S.size()) {
      if (S.at(m + i) != W.at(i)) {
        ++m;
        i = 0;
        continue;
      }
      ++i;
      if (W.size() == i) {
        return m;
      }
    }
    return nullopt;
  }
};
