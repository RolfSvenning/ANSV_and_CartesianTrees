//
// Created by Rolf Svenning on 12/04/2023.
//
#include "_constants.h"
#include "list"
#include "VI.h"

#ifndef IMPLEMENTATIONS_AUX_H
#define IMPLEMENTATIONS_AUX_H

void printArraysVI(const std::list<std::array<VI, n>>& arrays);

void printArrayVI(std::array<VI, n> A);

void printArray(std::array<int, n> A);

std::array<int, n> returnRandomArray();

std::array<std::tuple<int, int>, 2 * n - 1> returnPerfectBinaryTreeOnA(std::array<int, n> A);


#endif //IMPLEMENTATIONS_AUX_H
