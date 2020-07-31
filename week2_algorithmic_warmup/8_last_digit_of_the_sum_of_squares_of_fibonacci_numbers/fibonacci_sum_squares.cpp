#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

//We use property that 𝐹1^2 + F2^2 + ... Fn^2 = Fn * F(n+1)
//To find last digit of Fn, we use periodicity property as in problem 5
long long fibonacci_sum_squares_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long next = 0;

    long long b = 0; //For b in Fb mod m = Fn mod m
    b = n % 60; //Because period for mod 10 is 60

    if (b <= 1) return b; //If b is 0 or 1 return F(0) or F(1)

    //Calculate Fb mod 10
    for (long long i = 0; i < b - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        next = current + previous;
    }
    // std::cout << current << std::endl;

    return (current * next) % 10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n);
    std::cout << fibonacci_sum_squares_fast(n);
}
