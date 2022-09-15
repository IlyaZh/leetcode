#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "solution.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    const int k = 4;
    Solution s;
    cout << "IN: k = " << k << ", words = [";
    copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
    cout << "]" << endl;
    auto res = s.topKFrequent(words, k);
    cout << "OUT: [";
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, " "));
    cout << "]" << endl;

    return 0;
}
