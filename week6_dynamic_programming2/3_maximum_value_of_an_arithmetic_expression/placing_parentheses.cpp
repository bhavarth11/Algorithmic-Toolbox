#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

//LOGIC: At one point of time we will come across one last operation like this: d1 op d2,
//where d1 and d2 are precomputed values of the subexpression to the left and right of the operator respectively
//These values should already be computed. So, we gradually increase the size of our subexpressions and calculate it's 
//max and min values to eventually find max value of the expression.

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

std::pair<long long, long long> MinAndMax(vector<vector<long long>> &Max, vector<vector<long long>> &Min, int i, int j, const string &exp) {
  long long max = LLONG_MIN;
  long long min = LLONG_MAX;
  // int m = i + 1;
  for (int k = i; k <= j - 1; k++) {
    long long a = eval(Max[i][k], Max[k + 1][j], exp[2 * k + 1]);
    long long b = eval(Max[i][k], Min[k + 1][j], exp[2 * k + 1]);
    long long c = eval(Min[i][k], Max[k + 1][j], exp[2 * k + 1]);
    long long d = eval(Min[i][k], Min[k + 1][j], exp[2 * k + 1]);
    // m += 2;
    min = std::min(std::min(std::min(a, b), std::min(c, d)), min);
    max = std::max(std::max(std::max(a, b), std::max(c, d)), max);
  }
  return std::make_pair(min, max);
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int n = (exp.size() / 2) + 1; //Number of operands
  vector<vector<long long>> Max(n, vector<long long> (n));
  vector<vector<long long>> Min(n, vector<long long> (n));
   int j = 0;

  //Initialize max and min matrices with numbers
  //Max[i][j] means max value of subexpression from i to j
  //For example if expression is 1+3-4*9, Max[0][2] means max of subexpression 1+3-4
  for(int i = 0; i < n; i++) {
    Max[i][i]  = (int)exp[j] - '0';
    Min[i][i]  = (int)exp[j] - '0';
    j+=2;
    // std::cout<<Max[i][i]<<" ";
  }
  // std::cout<<"\n";

  for(int s = 1; s < n; s++) {
    for(int i = 0; i < n - s; i++) {
      j = i + s;
      std::pair<long long, long long> x = MinAndMax(Max, Min, i, j, exp);
      Min[i][j] = x.first;
      Max[i][j] = x.second;
    }
  }

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //   std::cout<< Max[i][j] <<" ";
  //   }
  //   std::cout << "\n";
  // }

  return Max[0][n - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
