#pragma once
#include <AllLibrary.h>

bool ModeMenu();
bool AlgoMenu(std::vector<int> &nums, std::vector<int> &freq);
void Input(std::vector<int> &nums, std::vector<int> &freq);
void GenTest(std::vector<int> &nums, std::vector<int> &freq, int n);
int RandInt(int left, int right);
int SearchNode(Node * root, int key);
void TestMode(std::vector<int> &nums, std::vector<int> &freq);