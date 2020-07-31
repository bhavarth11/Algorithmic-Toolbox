#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Create structures for storing value/weight ratios and their respective indices
struct ratios {
  double ratio;
  int index;
};

//Function to sort ratios structure in descending order
bool compareRatio(ratios r1, ratios r2) {
  return (r1.ratio > r2.ratio);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<ratios> arr(n);
  // write your code here

  for(int i = 0; i < n; i++) {
    arr[i].ratio = (double)values[i]/weights[i];
    arr[i].index = i;
    // cout << arr[i].ratio << " " << arr[i].index << " ";
  }

//Sort such that item with highest ratio is at start and its index in the original array is reatined
  sort(arr.begin(), arr.end(), compareRatio);

  int i = 0;

  while(capacity > 0 && i < n) {
      if(capacity >= weights[arr[i].index]) {
        value += values[arr[i].index];  
        capacity -= weights[arr[i].index];
      }
      else {
      value += ((double)capacity/weights[arr[i].index]) * values[arr[i].index];    
      capacity -= ((double)capacity/weights[arr[i].index]) * weights[arr[i].index];
      // cout << (double)capacity/weights[arr[i].index] << endl;
      }
      i++;
  }

  // cout << endl;

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
