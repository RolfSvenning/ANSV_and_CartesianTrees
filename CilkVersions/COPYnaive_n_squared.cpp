#include <iostream>
#include <array>
#include "list"

#include <algorithm>
#include <random>
#include <cilk/cilk.h>

const int n = 20;
//const std::array<int, n> A = {19,15,3,4,1,7,9,8,5,6,11,12,13,10,16,17,18,20,2};

std::array<int, n> returnRandomArray() {
    std::array<int, n> A_ = {};
    for (int i = 0; i < A_.size(); ++i) {
        A_[i] = i + 1;
    }

    // Shuffle the array by swapping with previous element with probability 1/(n-1)
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 1; i < n; ++i) {
        std::uniform_real_distribution<> dis(0.0, 1.0);
        if (dis(gen) > 1.0 / (i - 1)) {
            // Seed the random number generator
            std::random_device rd2;
            std::mt19937 gen2(rd2());
            // Define the uniform distribution
            std::uniform_int_distribution<int> dist2(0, i - 1);

            // Generate a random integer from 0 to n (inclusive)
            int randomNum = dist2(gen2);

            std::swap(A_[i], A_[randomNum]);
        }
    }

    return A_;
}


// Function computing the smaller values of an array A.
// Returns a tuple containing the left smaller values in L and right smaller values in R.
std::tuple<std::array<int, n>, std::array<int, n>> ANSV_naive(std::array<int, n> A) {
    std::array<int, n> L = {};
    std::array<int, n> R = {};
    std::cout << " --- ANSV naive --- " << std::endl;

    cilk_for (int i = 0; i < A.size(); ++i) {
        L[i] = -1;
        R[i] = -1;
        // LEFT SMALLER VALUE
        bool foundOne = false;
        for (int j = i - 1; 0 <= j; --j) {
            if (A[j] < A[i] and !foundOne) {
                L[i] = j;
                foundOne = true;
//                break;
            }
        }
        // RIGHT SMALLER VALUE
        bool foundOne2 = false;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[i] and !foundOne2) {
                R[i] = j;
                foundOne2 = true;
//                break;
            }
        }
    }
    return {L, R};
}

void printArray(const std::array<int,n> A_) {
    for (int a : A_)
        std::cout << a << " ";
    std::cout << std::endl;
}

void printArrays(const std::list<std::array<int,n>>& arrays) {
    for (std::array<int, n> A_: arrays) {
        printArray(A_);
    }
}

int main() {
    std::array<int, n> A = returnRandomArray();
    printArray(A);
    auto [L1, R1] = ANSV_naive(A);
    printArrays(std::list<std::array<int, n>>{A, L1, R1});

    return 0;
}
