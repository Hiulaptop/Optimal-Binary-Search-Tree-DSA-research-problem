#include <Function.h>


void Input(std::vector<int> &nums, std::vector<int> &freq){
    std::vector<std::string> data = {
        "1. Value array",
        "2. Frequency array",
        "0. Exit",
    };

    int n, u;
    //Init array
    nums.clear();
    freq.clear();
    nums.push_back(0);
    freq.push_back(0);

    //Value
    std::cout << "Input value array: \n";
    std::cout << "Size of array = ";
    std::cin >> n;
    for (int i = 1; i <= n; i ++){
        std::cout << "Value " << i << "= ";
        std::cin >> u;
        nums.push_back(u);
    }
    //Frequency
    std::cout << "Input frequency array: \n";
    std::cout << "Size of array = ";
    std::cin >> n;
    for (int i = 1; i <= n; i ++){
        std::cout << "Value " << i << "= ";
        std::cin >> u;
        freq.push_back(u);
    }
}

bool AlgoMenu(std::vector<int> &nums, std::vector<int> &freq){
    std::vector<std::string> data = {
        "1. Optimal Binary Search Tree",
        "2. Knuth's Optimal Binary Search Tree",
        "3. Bisection Heuristic",
        "0. Exit",
    };

    std::cout << std::setfill('-') << std::setw(40) << '\n';
    for (std::string i : data){
        std::cout << std::left << '|' << std::setw(38) << i << "|\n";
    }
    std::cout << std::setfill('-') << std::setw(40) << "";
    std::cout << "\n";

    int op = 0;
    std::cin >> op;
    if (op == 0) return true;
    if (op >= data.size()) return false;

    Input(nums, freq);
    // GenTest(nums, freq);
    if (op == 1){
        OptimalBST algo;
        algo.Process(nums, freq);
        return true;
    }
    if (op == 2){
        KnuthOBST algo;
        algo.Process(nums, freq);
        return true;
    }
    if (op == 3){
        BisectionHeu algo;
        algo.Process(nums, freq);
        return true;
    }

    return false;
}

int RandInt(int left, int right){
    int s = rand();
    return (s % (right - left)) + left;
}

void GenTest(std::vector<int> &nums, std::vector<int> &freq){
    //Init array
    nums.clear();
    freq.clear();
    nums.push_back(0);
    freq.push_back(0);


    srand(time(NULL));
    int n = RandInt(5, 10), cur = 1, prev = 0;
    for (int i = 1; i <= n; i ++){
        cur = RandInt(prev, 100000);
        prev = cur + 1;
        nums.push_back(cur);
        freq.push_back(RandInt(1, 1000));
    }

    // std::cout << n << '\n';
    // for (int i = 1; i <= n; i ++){
    //     std::cout << nums[i] << ' ';
    // }
    // std::cout << '\n';
    // for (int i = 1; i <= n; i ++){
    //     std::cout << freq[i] << ' ';
    // }
    // std::cout << '\n';
}