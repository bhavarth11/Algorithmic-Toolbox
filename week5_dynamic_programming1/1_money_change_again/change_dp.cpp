#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int get_change(int m) {
  //write your code here
  if(m == 0) return 0;
  vector<int> denoms = {1, 3, 4};
  vector<int> ans(m + 1);
  ans[0] = 0;
  for(int i = 1; i <= m; i++) {
    int min = ans[i-1];
    for(int j = 0; j < denoms.size(); j++) {
      if(i - denoms[j] >= 0 && ans[i - denoms[j]] < ans[i - 1])
        min = ans[i - denoms[j]];
    }
    ans[i] = min + 1;
  }

  return ans[m];

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
