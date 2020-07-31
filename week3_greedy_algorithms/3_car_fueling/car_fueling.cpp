#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int i = 0;
    int reached = 0;
    int lastRefill = 0;
    int ans = 0;
    while (reached + tank < dist)
    {   
        lastRefill = reached;
        while(i < stops.size() && (stops[i] - lastRefill <= tank)) {
                reached = stops[i];
                i++;
        }
        if(lastRefill == reached) return -1; //This means no movement happened which means car doesn't have enough fuel to reach next stop.
        ans++; //If destination is not reached means another refill.
    }
    return ans;
}


// int compute_min_refills(int dist, int tank, vector<int> & stops) {
//     // write your code here
//     int i = 0;
//     int reached = 0;
//     int lastRefill = 0;
//     int ans = 0;
//     stops.push_back(dist);
//     int n = stops.size();
//     while (i < n)
//     {   
//         lastRefill = reached;
//         while(i < stops.size() && (stops[i] - lastRefill <= tank)) {
//                 reached = stops[i];
//                 i++;
//         }
//         if(lastRefill == reached) return -1; //This means no movement happened which means car doesn't have enough fuel to reach next stop.
//         if(reached < dist) ans++; //If destination is not reached means another refill.
//     }
//     return ans;
// }


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
