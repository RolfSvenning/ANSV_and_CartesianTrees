//
// Created by Rolf Svenning on 18/04/2023.
//

#include "iostream"
#include "../Glue/_constants.h"
#include "../Glue/_aux.h"
#include "../ANSV/naive_n2_work.h"
#include "../ANSV/seq_array_n_work.h"
#include "../ANSV/seq_stack_n_work.h"
#include "TestANSV.h"

void compareOutputOfNaiveSeqArraySeqStack(std::array<int, n> A, bool verbose) {
    if (verbose) printArray(A);
    auto [L1, R1] = ANSV_naive(A);
    if (verbose) {
        std::cout << " --- ANSV naive --- " << std::endl;
        printArraysVI(std::list<std::array<VI, n>>{L1, R1});}

    auto [L2, R2] = ANSV_seq_array(A);
    if (verbose) {
        std::cout << " --- ANSV sequential array based --- " << std::endl;
        printArraysVI(std::list<std::array<VI, n>>{L2, R2});
    }

    assert(L1 == L2 and R1 == R2);

    auto [L3, R3] = ANSV_seq_stack(A);
    if (verbose) {
        std::cout << " --- ANSV sequential seq based --- " << std::endl;
        printArraysVI(std::list<std::array<VI, n>>{L3, R3});
    }

    assert(L2 == L3 and R2 == R3);
}