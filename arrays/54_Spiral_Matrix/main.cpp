#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

void print(const vector<vector<int>>& matrix) {
    for(size_t i = 0; i < matrix.size(); ++i) {
        cout << "(";
        for(size_t j = 0; j < matrix[0].size(); ++j) {
            if(j != 0)
                cout << " ";
            cout << matrix[i][j];
        }
        cout << ")" << endl;
    }
}

int main(int argc, char* argv[]) {
    const vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    // const vector<vector<int>> matrix = {{1,2,3,4,5,6,7,8,9,10}};
    Solution s;
    cout << "IN:" << endl;
    print(matrix);
    cout << endl;
    cout << "OUT: [";
    auto vec = s.spiralOrder(matrix);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    

    return 0;
}
 