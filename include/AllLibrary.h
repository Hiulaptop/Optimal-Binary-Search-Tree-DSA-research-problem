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

//define
#define int long long
#define INT_MAX INT64_MAX

//struct
struct Node{
    int value;
    Node * left = nullptr;
    Node * right = nullptr;

    Node(int value) : value(value) {}
};

// Node * OBSTroot = nullptr;

//include project header file
#include <Function.h>
#include <OptimalBST.h>
#include <KnuthOBST.h>
#include <BisectionHeu.h>
#include <BST.h>

Node * OBSTroot = nullptr;