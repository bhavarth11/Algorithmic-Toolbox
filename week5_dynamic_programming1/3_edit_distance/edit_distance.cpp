#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::min;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m = str1.size();
  int n = str2.size();
  vector<vector<int>> dp_matrix(m + 1, vector<int> (n + 1));

  dp_matrix[0][0] = 0;

  for (size_t i = 1; i <= m; i++)
  {
    dp_matrix[i][0] = i;
  }

  for (size_t i = 1; i <= n; i++)
  {
    dp_matrix[0][i] = i;
  }

  // for (size_t i = 0; i <= m; i++)
  // {
  //   for (size_t j = 0; j <= n; j++)
  //   {
  //     std::cout<<dp_matrix[i][j]<<" ";
  //   }
  //   std::cout<<std::endl;    
  // }
  
  
  for (size_t i = 1; i <= m; i++)
  {
    for (size_t j = 1; j <= n; j++)
    {
      if(str1[i - 1] == str2[j - 1]) {
        dp_matrix[i][j] = min(min(dp_matrix[i][j - 1] + 1, dp_matrix[i - 1][j] + 1), dp_matrix[i - 1][j - 1]);
      }
      else {
        dp_matrix[i][j] = min(min(dp_matrix[i][j - 1] + 1, dp_matrix[i - 1][j] + 1), dp_matrix[i - 1][j - 1] + 1);
      }
      // std::cout<<dp_matrix[i][j]<<" "
    }
    // std::cout<<std::endl;    
  }

  return dp_matrix[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
