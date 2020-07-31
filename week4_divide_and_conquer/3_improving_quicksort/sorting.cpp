#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

std::pair<int, int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int m1 = l;
  int m2 = r;

  //Swap all elements smaller than pivot to the left
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      m1++;
      swap(a[i], a[m1]);
    }
  }
  // std::cout<<m1<<" ";

  //Swap all elements greater than pivot to the right
  swap(a[l], a[m1]);
  for (int i = r; i > m1; i--) {
    if (a[i] > x) {
      swap(a[i], a[m2]);
      m2--;
    }
  }
  // std::cout<<m2<<"\n";

  //All elements between m1 and m2 are equal to the pivot
  return std::make_pair(m1 ,m2);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  // int k = l + rand() % (r - l + 1);
  // swap(a[l], a[k]);
  std::pair<int, int> m = partition3(a, l, r);
  // for (size_t i = 0; i < a.size(); ++i) {
  //   std::cout << a[i] << ' ';
  // }
  // std::cout<<std::endl;
  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
