#include <iostream>
using namespace std;

int get_change(int m) {
  //write your code here
  int n = 0;
  int denomination[] = {10, 5, 1};
  int i = 0;
  while(m > 0) {
    if(m >= denomination[i]) {
      m -= denomination[i];
      n++;
    }
    else i++;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}