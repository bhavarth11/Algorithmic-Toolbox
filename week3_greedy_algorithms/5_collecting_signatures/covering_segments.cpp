#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

//Struct for modelling line segments
struct Segment {
  int start, end;
};

bool compareSegments(Segment s1, Segment s2) {
  if(s1.end == s2.end) return (s1.start < s2.start);
  return (s1.end < s2.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  
  //Sort line segments according to starting points from left to right
  sort(segments.begin(), segments.end(), compareSegments);

  int n = segments.size();
  int currentSegment = 0;
  int nextSegment = 0;
  int pos = 0;
  int count = 0;

  // for (int x = 0; x < n; ++x) {
  //   std::cout << segments[x].start << " " << segments[x].end << std::endl;
  // }
  // std::cout<<std::endl;

  int point = segments[0].end; // set the point to the first end point i-e shortest end point
    points.push_back(point);

    for (size_t i = 1; i < n; ++i) {
        if (point < segments[i].start || point > segments[i].end) { // if the point is not in the segment
            point = segments[i].end; // update the point to the end point of the current segment
            points.push_back(point); // store it in the vector
        }
    }
  

  // while(nextSegment <= n)
  // {
  //   points.push_back(segments[currentSegment].end);  
  //   while(segments[currentSegment].end >= segments[nextSegment].start) {
  //     nextSegment++;
  //   }
  //   currentSegment = nextSegment;
  //   nextSegment++;
  // }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
