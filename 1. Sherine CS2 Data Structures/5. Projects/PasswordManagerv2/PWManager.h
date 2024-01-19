#pragma once
#include "PWObject.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

void welcomeFunction();
std::size_t numObjects();
void printAllLabels(passwordObject*, std::size_t);
std::size_t menuNavigation(size_t&);
passwordObject* populateArray(size_t);
void viewPassword(passwordObject*, std::size_t);