#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
    string longestPalindrome(string s);
    private:
    string odd(const string& s);
    string even(const string& s);
};