#include <iostream>
#include <vector>

using std::vector;

/* Just use merge sort and calculate number if inversions in merge part of the code*/

long long merge(vector<int> &a, size_t l, size_t r, size_t m) {
  int i;
  int j;
  int inversions = 0;
  int n1 = m - l + 1; 
  int n2 = r - m; 
  vector<int> L(n1);
  vector<int> R(n2);

  for (i = 0; i < n1; i++) 
      L[i] = a[l + i]; 

  for (j = 0; j < n2; j++) 
      R[j] = a[m + 1 + j]; 

  i = 0; 
  j = 0;
  int k = l;
  while(i < n1 && j < n2) {
    if(L[i] <= R[j]) {
      a[k] = L[i]; 
      i++;
    }
    else
    {
      a[k] = R[j]; 
      j++;
      inversions += n1 - i; 
      //Number of inversions is the number of elements remaining in L that are greater than the smallest element in R
    }
    k++;
  }  

/* Copy the remaining elements of L[], if there 
      are any */
  while (i < n1) { 
      a[k] = L[i]; 
      i++; 
      k++; 
  } 

  /* Copy the remaining elements of R[], if there 
      are any */
  while (j < n2) { 
      a[k] = R[j]; 
      j++; 
      k++; 
  }
  return inversions;  
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave);
  number_of_inversions += get_number_of_inversions(a, ave + 1, right);
  //write your code here
  number_of_inversions += merge(a, left, right, ave);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  // vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, 0, a.size() - 1) << '\n';
  // for (size_t i = 0; i < a.size(); i++) {
  //   std::cout << a[i] << " ";
  // }
}
