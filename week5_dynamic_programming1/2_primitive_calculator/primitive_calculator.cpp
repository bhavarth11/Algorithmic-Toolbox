#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> dp_lookup(n + 1, 1e9);
  dp_lookup[0] = 0;
  dp_lookup[1] = 0;

  //Create look up table for minimum number of steps to reach given number
  for(int i = 1; i < n; i++) {
    if(i * 3 <= n) dp_lookup[i*3] = min(dp_lookup[i*3] - 1, dp_lookup[i]) + 1;
    if(i * 2 <= n) dp_lookup[i*2] = min(dp_lookup[i*2] - 1, dp_lookup[i]) + 1;
    if(i + 1 <= n) dp_lookup[i+1] = min(dp_lookup[i+1] - 1, dp_lookup[i]) + 1;
  } 
  
  sequence.push_back(n);

  size_t x = dp_lookup[n];

//Shorten the number by identifying shortest path using look up table
  for(size_t i = 0; i < x; i++) {
    if(n%3 == 0 && dp_lookup[n/3] <= dp_lookup[n/2] && dp_lookup[n/3] <= dp_lookup[n - 1]) {
      sequence.push_back(n/3);
      n /= 3;
    }
    else if(n%2 == 0 && dp_lookup[n/2] <= dp_lookup[n - 1]) {
      sequence.push_back(n/2);
      n /= 2;
    }
    else {
      sequence.push_back(n-1);
      n -= 1;
    }
  }
  
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
