#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
    string longestPalindrome(string s) {
        auto s1 = odd(s);
        auto s2 = even(s);

        return (s1.size() > s2.size()) ? s1 : s2;
    }
    private:
    string odd(const string& s) {
            int n = s.size();
            int max = 0;
            int maxCnt = 0;
            vector<int> d1 (n);
            int l=0, r=-1;
            for (int i=0; i<n; ++i) {
                int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
                while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
                d1[i] = k;
                if (i+k-1 > r)
                    l = i-k+1,  r = i+k-1;
                if(d1[i]-1 > maxCnt) {
                    maxCnt = d1[i]-1;
                    max = i;
                }
            }
            return s.substr(max-maxCnt,2*maxCnt+1);
    }
    string even(const string& s) {
        int n = s.size();
        vector<int> d2 (n);
        int max = 0;
        int maxCnt = 0;
        int l=0, r=-1;
        for (int i=0; i<n; ++i) {
            int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
            while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
            d2[i] = k;
            if (i+k-1 > r)
                l = i-k,  r = i+k-1;
            if(d2[i] > maxCnt) {
                maxCnt = d2[i];
                max = i;
            }
        }
        return s.substr(max-maxCnt,2*maxCnt);
    }
};

int main(int argc, char* argv[]) {
    return 0;
}