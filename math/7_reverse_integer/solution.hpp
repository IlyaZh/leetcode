using namespace std;

#include <cmath>

class Solution {
    public:

enum {
    MAX_INT_32 = 2147483647
};

    int reverse(int x) {
        if(x == 0) return 0;
        long long int result {0};
        bool isNeg = (x < 0);
        if(isNeg) x = abs(x);

        while(x != 0) {
            result *= 10;
            if(result > MAX_INT_32 || result < -MAX_INT_32) return 0;
            result += abs(x) % 10;
            x /= 10;
        }
        if(isNeg) result = -result;

        return result;
    }
};