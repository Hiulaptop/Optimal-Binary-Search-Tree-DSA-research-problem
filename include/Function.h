#pragma once
#include <AllLibrary.h>
#include <algorithm>

void Example();
bool ModeMenu();
void Input(std::vector<int> &nums, std::vector<int> &freq);
bool AlgoMenu(std::vector<int> &nums, std::vector<int> &freq);
void GenTest(std::vector<int> &nums, std::vector<int> &freq, int n);
int RandInt(int left, int right);
int SearchNode(Node * root, int key);
void TestMode(std::vector<int> &nums, std::vector<int> &freq);
long long TotalCost(Node * root, int level);
