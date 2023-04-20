cmake_minimum_required(VERSION 3.25)
project(Implementations)

set(CMAKE_CXX_STANDARD 17)

add_executable(Implementations main.cpp ANSV/naive_n2_work.cpp Glue/_constants.h ANSV/naive_n2_work.h Glue/_aux.cpp Glue/_aux.h ANSV/seq_array_n_work.cpp ANSV/seq_array_n_work.h ANSV/seq_stack_n_work.cpp ANSV/seq_stack_n_work.h ANSV/par_naive_nlgn_work.cpp ANSV/par_naive_nlgn_work.h Glue/Node.cpp Glue/Node.h Cartesian_tree/CT_from_ANSV_naive.cpp Cartesian_tree/CT_from_ANSV_naive.h Glue/VI.cpp Glue/VI.h Testing/TestANSV.cpp Testing/TestANSV.h Testing/TestCT.cpp Testing/TestCT.h Cartesian_tree/CT_from_ANSV_seq_IO.cpp Cartesian_tree/CT_from_ANSV_seq_IO.h Glue/CT.cpp Glue/CT.h)

