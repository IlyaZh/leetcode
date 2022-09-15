#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#include "solution.hpp"

using namespace std;

template<typename Container>
void printCont(const Container& cont) {
    cout << "[ ";
    copy(cont.begin(), cont.end(), ostream_iterator<typename Container::value_type>(cout, " "));
    cout << "]";
}

int main(int argc, char* argv[]) {
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};
    
    FoodRatings foodRatings(foods, cuisines, ratings);
    cout << foodRatings.highestRated("korean") << endl; // return "kimchi"
                                        // "kimchi" is the highest rated korean food with a rating of 9.
    cout << foodRatings.highestRated("japanese") << endl; // return "ramen"
                                        // "ramen" is the highest rated japanese food with a rating of 14.
    foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
    cout << foodRatings.highestRated("japanese") << endl; // return "sushi"
                                        // "sushi" is the highest rated japanese food with a rating of 16.
    foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
    cout << foodRatings.highestRated("japanese") << endl; // return "ramen"
                                        // Both "sushi" and "ramen" have a rating of 16.
                                        // However, "ramen" is lexicographically smaller than "sushi".

    return 0;
}
