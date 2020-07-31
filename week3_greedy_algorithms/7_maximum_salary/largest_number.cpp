#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string NumberToString ( int Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

bool GreaterOrEqual(string& a, string& b) {
	return(b + a < a + b);
}

bool fun(string a, string b)
{
  int n = (a.length() < b.length()) ? a.length() : b.length();
  int i = 0;
  while(i < n) {
    if (a[i] > b[i]) return true;
    if (a[i] < b[i]) return false;
    i++;
  }
  if(a.length() > b.length()) {
    if(a[i] <= a[i-1]) return false;
    return true;
  }
  if(a.length() < b.length()) {
    if(b[i] <= b[i-1]) return true;
    return false;
  }
  return true;
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;

  std::sort(a.begin(),a.end(), GreaterOrEqual);

  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  
  string result;
  ret >> result;
  return result;
}

// string largest_number_naive(vector<string> a) {
//   //write your code here
//   std::stringstream ret;

//   std::sort(a.begin(),a.end(), GreaterOrEqual);

//   for (size_t i = 0; i < a.size(); i++) {
//     ret << a[i];
//   }
  
//   string result;
//   ret >> result;
//   return result;
// }

int main() {

  //Stress Test (Comment out when done)
    // while (true) {
    //     int n;
    //     n = (rand() % 100) + 2;
    //     std::vector<string> numbers(n);
    //     for (int i = 0; i < n; ++i) {
    //         int a = (rand() % 10);
    //         numbers[i] = NumberToString(a);  
    //         std::cout << numbers[i] << " ";
    //     }

    //     std::cout << "\n";

    //     string res1 = largest_number(numbers);
    //     string res2 = largest_number_naive(numbers);

    //     if(res1!=res2) {
    //         std::cout << res1 << " " << res2 << std::endl;
    //         std::cout << "Wrong Answer" << std::endl;
    //         break;
    //     }
    //     else std::cout << "OK" << std::endl;
    // }

  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
