#include "ANSV/naive_n2_work.h"
#include "Glue/_aux.h"
#include "ANSV/seq_array_n_work.h"
#include "ANSV/seq_stack_n_work.h"
#include "Cartesian_tree/CT_from_ANSV_naive.h"
#include "Testing/TestANSV.h"
#include "Testing/TestCT.h"

int main() {
    // ----- TESTING -----
    std::array<int, n> A = returnRandomArray();
    bool verbose = true;
    compareOutputOfNaiveSeqArraySeqStack(A, verbose);

    verifyHeapAndSortedPropertyOfCT(A, verbose);

    return 0;
}


