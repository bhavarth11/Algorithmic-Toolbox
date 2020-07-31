#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <utility>

//O(n^2) solution
long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * (long long)numbers[second]);
        }
    }

    return max_product;
}

//O(2n) solution
long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    //Largest number in array
    int max1 = 0; 
    //Index of max number
    int max1_idx = 0; 
    //2nd largest number in array
    int max2 = 0;     
    int n = numbers.size();

    //Find largest number
    for (int i = 0; i < n; i++) {
        if(numbers[i] > max1) {
        max1 = numbers[i];
        max1_idx = i;
        }
    }

    //Find 2nd largest number
    for (int i = 0; i < n; i++) {
        if((numbers[i] > max2) && (i!=max1_idx)) {
            max2 = numbers[i];
        }
    }

    return (long long)max1 * (long long)max2;
}

//(1.5n) comparisons solution
long long MaxPairwiseProductFaster(const std::vector<int>& numbers) {
    //Largest number in even array
    int max1 = 0; 
    //Index of max number in even array
    int max1_idx = 0; 
    //Largest number in odd array
    int max2 = 0;     
    //Index of max number in odd array
    int max2_idx = 0; 
    int n = numbers.size();

    //Find largest number in even array
    for (int i = 0; i < n; i+=2) {
        if(numbers[i] > max1) {
        max1 = numbers[i];
        max1_idx = i;
        }
    }

    //Find largest number in odd array
    for (int i = 1; i < n; i+=2) {
        if((numbers[i] > max2) && (i!=max1_idx)) {
            max2 = numbers[i];
            max2_idx = i;
        }
    }

    //If max1 > max2 then 2nd largest number overall could be in even array. So we find the 2nd largest number
    //in even array and compare it with largest number in odd array. Thus, we find 2nd largest number overall.
    //Similarly, if max2 > max1 then we check odd array.
    if(max1 > max2) {
        for (int i = 0; i < n; i+=2) {
            if((numbers[i] > max2) && (i!=max1_idx)) {
                max2 = numbers[i];
            }
        }   
    }
    else if(max2 > max1) {
        for (int i = 1; i < n; i+=2) {
            if((numbers[i] > max1) && (i!=max2_idx)) {
                max1 = numbers[i];
            }
        }
    }

    return (long long)max1 * (long long)max2;
    
}

std::pair<int, int> FastestHelperFunction(std::vector<int> a) {
    
    int n = a.size();

    if (n==2) {
        if (a[0] > a[1]) return std::make_pair(0, 1);
        else return std::make_pair(1, 0);
    }
    else if (n%2 != 0) {
        a.push_back(0);
        n++;
    }    

    std::vector<int> w(n/2);
    std::vector<int> swaps(n/2, 0);
    
    for(int i = 0; i < n/2; i++)
    {
        if(a[2*i] < a[2*i+1]) {
            int temp = a[2*i+1];
            a[2*i+1] = a[2*i];
            a[2*i] = temp;
            swaps[i] = 1;
        }
        w[i] = a[2*i];
    }


    std::pair<int, int> jk = FastestHelperFunction(w);
    int j_swap = swaps[jk.first];
    int k_swap = swaps[jk.second]; 
    int j = 2*jk.first;
    int k = 2*jk.second;

    if (a[j + 1] > a[k]) {
        k = j + 1;
        k_swap = 0 - j_swap;
    }
    return std::make_pair(j + j_swap, k + k_swap);
}

//(n + logn - 3) comparisons solution
long long MaxPairwiseProductFastest(const std::vector<int>& numbers) {
    std::vector<int> a = numbers;
    std::pair<int, int> indices = FastestHelperFunction(a);
    return (long long)a[indices.first] * (long long)a[indices.second];
}

int main() {
    
    /*
    A stress test consists of four parts:
    1. Your implementation of an algorithm.
    2. An alternative, trivial and slow, but correct implementation of an
    algorithm for the same problem.
    3. A random test generator.
    4. An infinite loop in which a new test is generated and fed into both
    implementations to compare the results. If their results differ, the
    test and both answers are output, and the program stops, otherwise
    the loop repeats.
    */

    //Stress Test (Comment out when done)
    // while (true) {
    //     int n;
    //     n = (rand() % 1000) + 2;
    //     std::vector<int> numbers(n);
    //     for (int i = 0; i < n; ++i) {
    //         numbers[i] = (rand() % 10000);
    //         std::cout << numbers[i] << " ";
    //     }

    //     std::cout << "\n";

    //     long long res1 = MaxPairwiseProduct(numbers);
    //     long long res2 = MaxPairwiseProductFaster(numbers);

    //     if(res1!=res2) {
    //         std::cout << res1 << " " << res2 << std::endl;
    //         std::cout << "Wrong Answer" << std::endl;
    //         break;
    //     }
    //     else std::cout << "OK" << std::endl;
    // }

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }


    // //Start clock used to check time elapsed during algo. Comment it out when submitting!
    // // auto start = std::chrono::high_resolution_clock::now(); 

    std::cout << MaxPairwiseProductFastest(numbers) << "\n";

    // //Stop clock
    // // auto end = std::chrono::high_resolution_clock::now(); 

    // // std::cout << "Elapsed time in nanoseconds : "
    // //     << (double)std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
    // //     << " ns" << std::endl;

    return 0;
}
