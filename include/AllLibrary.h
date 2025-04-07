#pragma once

//include c and cpp lib
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <random>
#include <string>

//struct
struct Node{
    int value;
    int freq;
    Node * left = nullptr;
    Node * right = nullptr;

    Node(int value, int freq) : value(value), freq(freq) {}
};

//include project header file
#include <Function.h>
#include <OptimalBST.h>
#include <KnuthOBST.h>
#include <BisectionHeu.h>
#include <PerfectBST.h>
