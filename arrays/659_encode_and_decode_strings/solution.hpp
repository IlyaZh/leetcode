// https://lintcode.com/problems/encode-and-decode-strings/

// 659. Encode and Decode Strings

// Design an algorithm to encode a list of strings to a string.
// The encoded string is then sent over the network and is decoded back to
// the original list of strings.

// Machine 1 (sender) has the function:

// string encode(vector<string> strs) {
//   // ... your code
//   return encoded_string;
// }
// Machine 2 (receiver) has the function:
// vector<string> decode(string s) {
//   //... your code
//   return strs;
// }
// So Machine 1 does:

// string encoded_string = encode(strs);
// and Machine 2 does:

// vector<string> strs2 = decode(encoded_string);
// strs2 in Machine 2 should be the same as strs in Machine 1.

// Implement the encode and decode methods.

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  inline constexpr static const char kDelimiter = '#';

 public:
  string Encode(const vector<string>& list) {
    string encoded;
    for (const auto& s : list) {
      encoded.append(to_string(s.size()) + kDelimiter + s);
    }
    return encoded;
  }
  vector<string> Decode(const string& encoded) {
    vector<string> result;
    for (size_t i = 0; i < encoded.size();) {
      auto j = i;
      while (encoded.at(j) != kDelimiter) {
        ++j;
      }
      const auto word_length = stoull(encoded.substr(i, j - i));
      result.emplace_back(encoded.substr(j + 1, word_length));
      i = j + 1 + word_length;
    }
    return result;
  }
};
