#include <iostream>
#include <vector>

using std::vector;
using std::max;
using std::min;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int m = a.size();
  int n = b.size();
  vector<vector<int>> dp_matrix_2d(m + 1, vector<int> (n + 1));

  dp_matrix_2d[0][0] = 0;

  for (size_t i = 1; i <= m; i++)
  {
    dp_matrix_2d[i][0] = 0;
  }

  for (size_t i = 1; i <= n; i++)
  {
    dp_matrix_2d[0][i] = 0;
  }

  // for (size_t i = 0; i <= m; i++)
  // {
  //   for (size_t j = 0; j <= n; j++)
  //   {
  //     std::cout<<dp_matrix_2d[i][j]<<" ";
  //   }
  //   std::cout<<std::endl;    
  // }
  
  
  for (size_t i = 1; i <= m; i++)
  {
    for (size_t j = 1; j <= n; j++)
    {
      if(a[i - 1] == b[j - 1]) {
        dp_matrix_2d[i][j] = 1 + dp_matrix_2d[i - 1][j - 1];
      }
      else {
        dp_matrix_2d[i][j] = max(dp_matrix_2d[i][j - 1], dp_matrix_2d[i - 1][j]);
      }
      // std::cout<<dp_matrix_2d[i][j]<<" ";
    }
    // std::cout<<std::endl;    
  }

  return dp_matrix_2d[m][n];
  // return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
