#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element_hash(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int n = a.size();
  vector<int> hash(n);
  int max = 0;
  for (size_t i = 0; i < n; i++)
  { 
    hash[a[i] % n]++;
    if(hash[a[i] % n] > max) {
      max = hash[a[i] % n];
    }
  }

  if(max > n/2) return 1;
  
  return -1;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return a[left];
  if (left > right) return -1;
  //write your code here
  int n = right - left + 1;
  int mid = (left + right)/2;
  int x = get_majority_element(a, left, mid);
  int y = get_majority_element(a, mid + 1, right);
  if(x == y) return x;
  if(n == 2) return -1;
  int count_x = 0;
  int count_y = 0;
  for(size_t i = left; i <= right; i++) {
    if(a[i] == x) count_x++;
    if(a[i] == y) count_y++;
    if(count_x > n/2) return x;
    if(count_y > n/2) return y;
  }
  return -1;
}


int main() {

  //Stress Test (Comment out when done)
    // while (true) {
    //     int n;
    //     n = (rand() % 1000) + 2;
    //     std::vector<int> numbers(n);
    //     for (int i = 0; i < n; ++i) {
    //         numbers[i] = (rand() % n);  
    //         std::cout << numbers[i] << " ";
    //     }

    //     std::cout << "\n";
        
    //     int res1 = (get_majority_element(numbers, 0, numbers.size() - 1) != -1);
    //     int res2 = (get_majority_element_hash(numbers, 0, numbers.size()) != -1);

    //     if(res1!=res2) {
    //         std::cout << res1 << " " << res2 << std::endl;
    //         std::cout << "Wrong Answer" << std::endl;
    //         break;
    //     }
    //     else std::cout << "OK" << std::endl;
    // }

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}
