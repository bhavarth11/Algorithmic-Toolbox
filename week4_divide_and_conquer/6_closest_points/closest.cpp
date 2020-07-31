#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::cout;
using std::pair;
using std::cin;
using std::min;

//Function for sorting according to y-coordinates
bool fun(pair<int, int> a, pair<int, int> b) {
  return a.second != b.second ? a.second < b.second : a.first < b.first;
}

bool fun2(pair<int, int> a, pair<int, int> b) {
  return a.first!=b.first ? a.first < b.first : a.second < b.second; 
}

//Function to calculate distance between two pX
double dist(pair<int, int> a, pair<int, int> b) {
  return sqrt((double)(a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


double bruteForce(vector<pair<int, int>> &pX) 
{ 
    double min = 1000000000; 
    for (int i = 0; i < pX.size(); ++i) 
        for (int j = i+1; j < pX.size(); ++j) 
            if (dist(pX[i], pX[j]) < min) 
                min = dist(pX[i], pX[j]); 
    return min; 
} 

double split_min_dist(vector<pair<int, int>> &pX, vector<pair<int, int>> &pY, double x, int left, int right) {
  int mid = (left + right) / 2;

   vector<pair<int, int>> strip;

   for(int i = 0; i < pY.size(); i++) {
     if(abs(pY[i].first - pX[mid].first) <= x) {
       strip.push_back(pY[i]);
     }
   }


   for(int i = 0; i < strip.size(); i++) {
     for(int j = i + 1; j < strip.size() && (double)(strip[j].second - strip[i].second < x); j++) {
       x = min(dist(strip[i], strip[j]), x);
     }
   }

   return x;
}

double minimal_distance(vector<pair<int, int>> &pX, vector<pair<int, int>> &pY, int left, int right) {
  if(pY.size() <= 3) return bruteForce(pY);
  
  int mid = (left + right) / 2;
  int n1 = (mid - left + 1);
  int n2 = pY.size() - n1;
  vector<pair<int, int>> pYL(n1);
  vector<pair<int, int>> pYR(n2);

  int l = 0;
  int r = 0;

  int k = mid;
  //To count number of points on the vertical line that are part of the left subarray
  int on_line_pts = 0;

  while(pX[k].first == pX[mid].first) {
    k--;
    on_line_pts++;
  }

//To create sorted y coordinate subarrays to pass in recursive calls
  for(int i = 0; i < pY.size(); i++) {
    //If point has x < x of mid, then it is part of left sub-array
    if(pY[i].first < pX[mid].first && l < n1) {
      pYL[l] = pY[i];
      l++;
    }
    //Special Case: If point has x = x of mid. Because these points can be on either side of vertical line, 
    // we need to check for additional things such as if y coordinate is less than y coordinate of mid
    //Also, if there are multiple points with x = x of mid, we need to consider the number of those points that were
    // to the left of mid. Otherwise, we might add points that were to the right of mid.
    else if(pY[i].first == pX[mid].first && pY[i].second <= pX[mid].second && l <n1 && on_line_pts > 0) {
      pYL[l] = pY[i];
      l++;
      on_line_pts--;
    }
    //Else add point to right subarray
    else {
      pYR[r] = pY[i];
      r++;
    }
  }

  double d1 = minimal_distance(pX, pYL, left, mid);
  double d2 = minimal_distance(pX, pYR, mid + 1, right);
  double d = split_min_dist(pX, pY, min(d1, d2), left, right);

  return d;
}

int main() {

//Stress Test (Comment out when done)
  // while (true) {
  //   size_t n;
  //   n = (rand() % 10) + 2;
  //   vector<pair<int, int>> pX(n);
  //   for (size_t i = 0; i < n; i++) {
  //     pX[i].first = (rand() % 1);
  //     pX[i].second = (rand() % 100);
  //     std::cout << pX[i].first << " " << pX[i].second << std::endl;
  //   }

  //   std::sort(pX.begin(), pX.end(), fun2); //Sort according to x axis

  //   vector<pair<int, int>> pY(pX);

  //   std::sort(pY.begin(), pY.end(), fun); //Sort according to y axis
        
  //   double res1 = bruteForce(pX);
  //   double res2 = minimal_distance(pX, pY, 0, pX.size() - 1);

  //   if(res1!=res2) {
  //       std::cout << std::setprecision(9) << res1 << " " << res2 << std::endl;
  //       std::cout << "Wrong Answer" << std::endl;
  //       break;
  //   }
  //   else std::cout << "OK" << std::endl;
  // }

  size_t n;
  std::cin >> n;
  vector<pair<int, int>> pX(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> pX[i].first >> pX[i].second;
  }
  std::cout << std::fixed;

  std::sort(pX.begin(), pX.end(), fun2); //Sort according to x axis

  // cout << "X Sorted:\n"; 
  // for (size_t i = 0; i < n; i++) {
  //   cout << pX[i].first << " " << pX[i].second << endl;
  // }

  vector<pair<int, int>> pY(pX);

  std::sort(pY.begin(), pY.end(), fun); //Sort according to y axis

  // cout << "Y Sorted:\n";
  // for (size_t i = 0; i < n; i++) {
  //   cout << pY[i].first << " " << pY[i].second << endl;
  // }

  std::cout << std::setprecision(9) << minimal_distance(pX, pY, 0, pX.size() - 1) << "\n";

  // std::cout << std::setprecision(9) << bruteForce(pX) << "\n";
}
