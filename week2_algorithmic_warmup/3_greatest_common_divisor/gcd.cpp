#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  if (a == 0 || b == 0) {
    return a > b ? a : b;
  }
  if (a > b)  return gcd_fast(b, a%b);
  else return gcd_fast(a, b%a);
}

int main() {
  //Stress Test (Comment out when done)
    // while (true) {
    //     int a, b;
    //     a = (rand() % 100000) + 2;
    //     b = (rand() % 1000) + 2;
    //     std::cout << a << " " << b;

    //     std::cout << "\n";

    //     long long res1 = gcd_naive(a, b);
    //     long long res2 = gcd_fast(a, b);

    //     if(res1!=res2) {
    //         std::cout << res1 << " " << res2 << std::endl;
    //         std::cout << "Wrong Answer" << std::endl;
    //         break;
    //     }
    //     else std::cout << "OK" << std::endl;
    // }

  int a, b;
  std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
