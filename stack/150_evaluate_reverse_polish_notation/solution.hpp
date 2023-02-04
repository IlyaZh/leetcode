// https://leetcode.com/problems/evaluate-reverse-polish-notation/

// 150. Evaluate Reverse Polish Notation

// You are given an array of strings tokens that represents an arithmetic
// expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the
// expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish
// notation. The answer and all the intermediate calculations can be represented
// in a 32-bit integer.

// Example 1:
// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

// Example 2:
// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

// Example 3:
// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22

// Constraints:
// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
// range [-200, 200].

#include <memory>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

using namespace std;

struct Operation {
  virtual ~Operation() = default;
  virtual string_view GetOp() const = 0;
  virtual int Result(const int lhs, const int rhs) = 0;
};

struct Add : public Operation {
  constexpr static const string_view kOperationSymbol{"+"};
  string_view GetOp() const override { return kOperationSymbol; }
  int Result(const int lhs, const int rhs) override { return lhs + rhs; }
};

struct Sub : public Operation {
  constexpr static const string_view kOperationSymbol{"-"};
  string_view GetOp() const override { return kOperationSymbol; }
  int Result(const int lhs, const int rhs) override { return lhs - rhs; }
};

struct Mult : public Operation {
  constexpr static const string_view kOperationSymbol{"*"};
  string_view GetOp() const override { return kOperationSymbol; }
  int Result(const int lhs, const int rhs) override { return lhs * rhs; }
};

struct Divide : public Operation {
  constexpr static const string_view kOperationSymbol{"/"};
  string_view GetOp() const override { return kOperationSymbol; }
  int Result(const int lhs, const int rhs) override { return lhs / rhs; }
};

class Solution {
  inline static const unordered_map<string, shared_ptr<Operation>>
      kValidOperators{
          make_pair<string, shared_ptr<Operation>>("+", make_shared<Add>()),
          make_pair<string, shared_ptr<Operation>>("-", make_shared<Sub>()),
          make_pair<string, shared_ptr<Operation>>("*", make_shared<Mult>()),
          make_pair<string, shared_ptr<Operation>>("/", make_shared<Divide>()),
      };

 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> pipeline;
    for (const auto& token : tokens) {
      if (kValidOperators.count(token) > 0) {
        const int rhs = pipeline.top();
        pipeline.pop();
        const int lhs = pipeline.top();
        pipeline.pop();
        auto op = kValidOperators.at(token);
        pipeline.push(op->Result(lhs, rhs));
      } else {
        pipeline.push(stoi(token));
      }
    }
    return pipeline.top();
  }
};
