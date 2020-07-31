#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

/*
Consider there are 'n' segments in total, 'l' start points is on the left of the point, 
'r' end points is on the right of the point, both inclusive. 
Then it's easy to prove that the number of segments covering that point = s + l - n.
*/

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  std::sort(ends.begin(), ends.end());
  std::sort(starts.begin(), starts.end());
  int left = 0;
  int right = (int)starts.size() - 1;
  
  for(int i = 0; i < points.size(); i++) {
    int point = points[i];
    int left = 0;
    int right = starts.size(); 
    int mid = (left + right)/2;
   
    while(left != right) {
      int mid = (left + right) / 2; // Or a fancy way to avoid int overflow
      if (starts[mid] <= point) {
          /* This index, and everything below it, must not be the first element
          * greater than what we're looking for because this element is no greater
          * than the element.
          */
          left = mid + 1;
      }
      else {
          /* This element is at least as large as the element, so anything after it can't
          * be the first element that's at least as large.
          */
          right = mid;
      }
    }
      
      int l = left; //Count of starting points less than x;
      // std::cout<<l<<"\n";

      left = 0;
      right = ends.size();

      while(left != right) {
        int mid = (left + right) / 2; // Or a fancy way to avoid int overflow
        if (ends[mid] >= point) {
          /* This index, and everything below it, must not be the first element
          * greater than what we're looking for because this element is no greater
          * than the element.
          */
          right = mid;
        }
        else {
          /* This element is at least as large as the element, so anything after it can't
          * be the first element that's at least as large.
          */
          left = mid + 1;
        }
      }

      int r = ends.size() - left;
      // std::cout<<r<<"\n";

      cnt[i] =  l + r - starts.size();
    }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
