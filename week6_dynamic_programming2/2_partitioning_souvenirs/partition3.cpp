#include <iostream>
#include <vector>

using std::vector;
using std::max;


//Similar to knapsack problem
int partition3(vector<int> &A) {
  //write your code here
  int sum = 0;
  for(int i = 0; i < A.size(); i++) {
    sum += A[i];
  }
  if(sum % 3 != 0) return 0;

  int n = A.size();
  int target = sum / 3;
  vector<vector<bool>> part(sum + 1, vector<bool> (sum + 1, 0));
  
  //Initialize dp matrix
  part[0][0] = true;

  // for (size_t i = 1; i <= sum; i++)
  // {
  //   part[i][0] = false;
  // }

  // for (size_t i = 1; i <= sum; i++)
  // {
  //   part[0][i] = false;
  // }
  
  // vector<bool> visited(n + 1, false);

  for (int i = 0; i < n; i++) {
    for (int j = sum; j >= 0; j--) {
      for (int k = sum; k >= 0; k--) {
        if(part[j][k]) {
          //If sum can be partitioned into j & k, then sum after adding number on either side will also be true
          part[j + A[i]][k] = true;
          part[j][k + A[i]] = true;
        }
      }
    }    
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= target; j++) {
  //     part[i][j] = part[i - 1][j];  //Assign previous optimum value without the ith item
  //     if(A[i - 1] <= j) 
  //     //If current item's weight is less than the knapsack's weight, then check if adding it 
  //     //will result in max value or not
  //       part[i][j] = part[i - 1][j - A[i - 1]] || part[i][j];
  //   }    
  // }

  // for (size_t i = 0; i <= n; i++) {
  //   for (size_t j = 0; j <= target; j++) {
  //     std::cout<<part[i][j]<<" ";
  //   }
  //   std::cout<<std::endl;    
  // }

  return (int)part[sum / 3][sum / 3];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
