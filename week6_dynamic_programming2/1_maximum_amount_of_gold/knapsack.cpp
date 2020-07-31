#include <iostream>
#include <vector>

using std::vector;
using std::max;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  vector<vector<int>> max_value(n + 1, vector<int> (W + 1));

  for (size_t i = 0; i <= n; i++)
  {
    max_value[i][0] = 0;
  }

  for (size_t i = 0; i <= W; i++)
  {
    max_value[0][i] = 0;
  }
  

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= W; j++) {
      max_value[i][j] = max_value[i - 1][j];  //Assign previous optimum value without the ith item
      if(w[i - 1] <= j) 
      //If current item's weight is less than the knapsack's weight, then check if adding it 
      //will result in max value or not
        max_value[i][j] = max(max_value[i - 1][j - w[i - 1]] + w[i - 1], max_value[i][j]);
    }    
  }

    for (size_t i = 0; i <= n; i++) {
      for (size_t j = 0; j <= W; j++) {
        std::cout<<max_value[i][j]<<" ";
      }
      std::cout<<std::endl;    
  }
  
  return max_value[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
