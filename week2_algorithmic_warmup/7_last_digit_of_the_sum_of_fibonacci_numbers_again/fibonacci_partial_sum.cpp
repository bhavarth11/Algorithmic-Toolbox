#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

//Code for calculating last digit of sum till n fibonacci numbers
int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    long long b = 0; 
    
    //Now that we know Sn = F(n+2) - 1, we just need to find its mod with 10 to find last its last digit
    //For this we can use previous solution with periodicity property 



    //We found out after running the code many times that for mod 10 period is 60. 
    //So, we don't need to calculate it every time.
    b = (n + 2) % 60;

    // std::cout<<b<<std::endl;

    if (b <= 1) return b == 0 ? 9 : 10; //If b is 0 or 1 return (F(0)-1) % 10 or (F(1)-1) % 10

    // previous = 0;
    // current  = 1;

    //Calculate Fb mod m
    for (long long i = 0; i < b - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 100; 
    }
    //The current value is now F(n+2) mod 10 
    // std::cout << current << std::endl;

    //Because we need to calculate (F(n+2)-1)mod 10 we will subtract 1 from F(n+2) mod 100 and then 
    //calculate F(n+2) mod 10 as it could be zero and subtracting 1 would result in negative value
    // std::cout<<current-1<<std::endl;
    return (current - 1); 
}

//Basic idea is that we calculate last digit of sum till 'from' fibonacci numbers
// and 'to' fibonacci numbers. Then subtract to find last digit of partial sum
//Because we are subtracting, we calculate last two digits while calculating 'to' sum
long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    if (from == 0) return (fibonacci_sum_fast(to) % 10); //If from is zero, then partial sum is equal to overall sum.
    int from_sum = fibonacci_sum_fast(from - 1) % 10;
    int to_sum = fibonacci_sum_fast(to);
    return (to_sum - from_sum) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
