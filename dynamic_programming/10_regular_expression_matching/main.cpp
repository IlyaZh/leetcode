#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Match {
	public:
	virtual bool match(const string& s, const int start, int* end) = 0;
	virtual ~Match() {}
};

class Match_More : public Match {
	string pattern;
	public:
	Match_More(const string& pat) : pattern(pat) {}
	bool match(const string& s, const int start, int* end) override {
		*end = start;
		while(pattern.at(0) == s.at(*end)) {
			++(*end);
		}
		return true;
	}
};

class Match_Any : public Match {
	string pattern;
	public:
	Match_Any(const string& pat) : pattern(pat) {}
	bool match(const string& s, const int start, int* end) override {
		*end = start;
		if((*end) < s.size()) {
			++(*end);
			return true;
		}
		return false;
	}
};

class Match_String : public Match {
	string pattern;
	public:
	Match_String(const string& pat) : pattern(pat) {}
	bool match(const string& s, const int start, int* end) override {
		*end = start;
		for(int i; (*end) < s.size(), i < pattern.size(); ++i, ++(*end)) {
			if(s.at(*end) != pattern.at(i)) {
				return false;
			}
		}
		return false;
	}
};

class Solution {
	shared_ptr<Match> createMatch(const string& pat) {
		// switch() {}
	}
public:
    bool isMatch(string s, string p) {
		vector<string> patternsStr;
		vector<shared_ptr<Match>> patterns;
		string pat;
		string::value_type lastSym;
        for(int i = 0; i < p.size(); ++i) {
			auto sym = p.at(i);
			switch(sym) {
				case '.':
					patternsStr.push_back(move(pat));
					pat.push_back(sym);
					patterns.push_back(make_shared<Match_Any>(pat));
					pat.clear();
					break;
				case '*':
					lastSym = pat.back();
					pat.pop_back();
					patternsStr.push_back(move(pat));
					pat.push_back(lastSym);
					pat.push_back(sym);
					patternsStr.push_back(move(pat));
					break;
				default:
					pat.push_back(sym);
			}
		}
		if(!pat.empty())
		patternsStr.push_back(move(pat));



		
		return false;
    }
};

TEST(ClassTest, Test_1) {
	Solution s;
	string in{"aa"};
	string pattern{"a"};
	bool out {false};
	EXPECT_EQ(s.isMatch(in, pattern), out);
}

TEST(ClassTest, Test_2) {
	Solution s;
	string in{"aa"};
	string pattern{"a*"};
	bool out {true};
	EXPECT_EQ(s.isMatch(in, pattern), out);
}

TEST(ClassTest, Test_3) {
	Solution s;
	string in{"ab"};
	string pattern{".*"};
	bool out {false};
	EXPECT_EQ(s.isMatch(in, pattern), out);
}

TEST(ClassTest, Test_4) {
	Solution s;
	string in{"Ilia Zhitenev"};
	string pattern{"Ilia Z.*"};
	bool out {true};
	EXPECT_EQ(s.isMatch(in, pattern), out);
}

TEST(ClassTest, Test_5) {
	Solution s;
	string in{"Ilia Ivanov"};
	string pattern{"Ilia Z.*"};
	bool out {false};
	EXPECT_EQ(s.isMatch(in, pattern), out);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}