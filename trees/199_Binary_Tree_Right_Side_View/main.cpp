#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "solution.hpp"

using namespace std;

template<typename Container>
void printCont(const Container& cont) {
    cout << "[ ";
    copy(cont.begin(), cont.end(), ostream_iterator<typename Container::value_type>(cout, " "));
    cout << "]";
}

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1, 
                                    new TreeNode(2, 
                                        nullptr,
                                        new TreeNode(5,
                                            new TreeNode(5,nullptr,nullptr), 
                                            nullptr
										)
									),
                                        new TreeNode(3, 
                                            nullptr, 
                                            new TreeNode(4, nullptr, nullptr)
                                        )
                                );
    vector<int> expectVec = {1,3,4,5};
    Solution s;
    cout << "OUT: ";
    printCont(s.rightSideView(root));
    cout << endl <<  "Expected: ";
    printCont(expectVec);

    return 0;
}
