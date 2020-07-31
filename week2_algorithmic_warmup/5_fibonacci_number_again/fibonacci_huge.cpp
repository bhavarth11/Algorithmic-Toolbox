#include <iostream>
#include <climits>
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current % m;
}

//We use the periodicity property of mod of nth fibonacci number
// i.e for any integer 𝑚 ≥ 2, the sequence 𝐹𝑛 mod 𝑚 is periodic
// Refer to pdf file for more info
long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    
    long long b = 0; //For b in Fb mod m = Fn mod m

    //Gives bth fibonacci number such that Fn mod m = Fb mod m
    for (long long i = 0; i < INT_MAX; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        long long next = (current + previous) % m;  // Calculate next and next to next numbers
        // std::cout << i << " ";
        long long next_to_next = (next + current) % m;
        //Check if they are 0 & 1 because period always starts with 01 known as Pisano period.
        if(next == 0 && next_to_next == 1) {  
            b = n % (i+3);  //If they are, the mods will start repeating from now on.
            // std::cout << b << std::endl;
            break; 
        }
    }

    if (b <= 1) return b; //If b is 0 or 1 return F(0) or F(1)

    previous = 0;
    current  = 1;
    //Calculate Fb mod m
    for (long long i = 0; i < b - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }
    // std::cout << current << std::endl;

    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
