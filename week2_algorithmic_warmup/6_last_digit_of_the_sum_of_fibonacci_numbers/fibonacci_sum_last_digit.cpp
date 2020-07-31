#include <iostream>
#include <climits>
//Explanation
//F(n) = F(n+2) - F(n+1)
// F(n-1) = F(n+1) - F(n)
// . . .
// . . .
// . . .
// F(1) = F(3) - F(2)
// ------------------------------------------
// sum = F(n+2) - F(2) .... adding all equations

// In right hand side, the top left and bottom right element remain. Others get cancelled. 
// Left hand side is the sum of fibonacci numbers

// Thus,
// sum = F(n+2) - 1

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    long long b = 0; 
    
    //Now that we know Sn = F(n+2) - 1, we just need to find its mod with 10 to find last its last digit
    //For this we can use previous solution with periodicity property 

    //For bth fibonacci number such that F(n+2) mod m = Fb mod m
    // for (long long i = 0; i < INT_MAX; ++i) {
    //     long long tmp_previous = previous;
    //     previous = current;
    //     current = (tmp_previous + current) % 10;
    //     long long next = (current + previous) % 10;  // Calculate next and next to next numbers
    //     std::cout << i << " ";
    //     long long next_to_next = (next + current) % 10;
    //     //Check if they are 0 & 1 because period always starts with 01 known as Pisano period.
    //     if(next == 0 && next_to_next == 1) {  
    //         b = (n+2) % (i+3);  //If they are, the mods will start repeating from now on.
    //         // std::cout << b << std::endl;
    //         break; 
    //     }
    // }

    //We found out after running the above code many times that for mod 10 period is 60. 
    //So, we don't need to calculate it every time.
    b = (n + 2) % 60;

    // std::cout<<b<<std::endl;

    if (b <= 1) return b == 0 ? 9 : 0; //If b is 0 or 1 return (F(0)-1) % 10 or (F(1)-1) % 10

    // previous = 0;
    // current  = 1;

    //Calculate Fb mod m
    for (long long i = 0; i < b - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 100; 
    }
    //The current value is now F(n+2) mod 100 
    // std::cout << current << std::endl;

    //Because we need to calculate (F(n+2)-1)mod 10 we will subtract 1 from F(n+2) mod 100 and then 
    //calculate F(n+2) mod 10 as it could be zero and subtracting 1 would result in negative value
    return (current - 1) % 10; 
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout <<fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_fast(n);
}
