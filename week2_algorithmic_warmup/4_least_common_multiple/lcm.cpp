#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long gcd_fast(int a, int b) {
  if (a == 0 || b == 0) {
    return a > b ? a : b;
  }
  if (a > b)  return gcd_fast(b, a%b);
  else return gcd_fast(a, b%a);
}

long long lcm_fast(int a, int b) {
    long long gcd = gcd_fast(a, b);
    return (a / gcd) * b; 
}

int main() {
   //Stress Test (Comment out when done)
    // while (true) {
    //     int a, b;
    //     a = (rand() % 100000) + 2;
    //     b = (rand() % 1000) + 2;
    //     std::cout << a << " " << b;

    //     std::cout << "\n";

    //     long long res1 = lcm_naive(a, b);
    //     long long res2 = lcm_fast(a, b);

    //     if(res1!=res2) {
    //         std::cout << res1 << " " << res2 << std::endl;
    //         std::cout << "Wrong Answer" << std::endl;
    //         break;
    //     }
    //     else std::cout << "OK" << std::endl;
    // }

  int a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
