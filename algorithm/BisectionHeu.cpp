#include <BisectionHeu.h>

void BisectionHeu::Process(std::vector<int> nums, std::vector<int> freq){

}

void BuildTree(Node * &root, int l, int r, std::vector<int> nums, std::vector<int> prefix){
    if (l > r) return;
    int id = l;
    int s1 = prefix[id - 1] - prefix[l - 1];
    int s2 = prefix[r] - prefix[id];
    int mi = INT_MAX;
    while (s2 > s1){
        s1 = prefix[id - 1] - prefix[l - 1];
        s2 = prefix[r] - prefix[id];
        id ++;
    }
}