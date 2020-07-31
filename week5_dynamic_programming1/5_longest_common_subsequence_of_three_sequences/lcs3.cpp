#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int l = a.size();
  int m = b.size();
  int n = c.size();
  vector<vector<vector<int>>> dp_matrix_3d(l + 1, vector<vector<int>> (m + 1 , vector<int> (n + 1)));

  dp_matrix_3d[0][0][0] = 0;

  for (size_t i = 1; i <= l; i++)
  {
    dp_matrix_3d[i][0][0] = 0;
  }

  for (size_t i = 1; i <= m; i++)
  {
    dp_matrix_3d[0][i][0] = 0;
  }

  for (size_t i = 1; i <= n; i++)
  {
    dp_matrix_3d[0][0][i] = 0;
  }

  // for (size_t i = 0; i <= l; i++)
  // {
  //   for (size_t j = 0; j <= m; j++)
  //   {
  //     for (size_t k = 0; k <= n; k++)
  //     {
  //       std::cout<<dp_matrix_3d[i][j][k]<<" ";
  //     }
  //     std::cout<<std::endl;    
  //   }
  //   std::cout<<std::endl;    
  // }
  
  
  for (size_t i = 1; i <= l; i++)
  {
    for (size_t j = 1; j <= m; j++)
    {
      for (size_t k = 1; k <= n; k++)
      {
        if(a[i - 1] == b[j - 1] && b [j - 1]== c[k - 1]) {
          dp_matrix_3d[i][j][k] = 1 + dp_matrix_3d[i - 1][j - 1][k - 1];
        }
        else {
          dp_matrix_3d[i][j][k] = max(max(dp_matrix_3d[i][j][k - 1], dp_matrix_3d[i][j - 1][k]), dp_matrix_3d[i - 1][j][k]);
        }
        // std::cout<<dp_matrix_3d[i][j][k]<<" ";
      }
      // std::cout<<std::endl;    
    }
    // std::cout<<std::endl;    
  }

  return dp_matrix_3d[l][m][n];
  // return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
