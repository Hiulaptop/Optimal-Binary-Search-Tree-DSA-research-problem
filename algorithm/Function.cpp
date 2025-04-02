#include <Function.h>

bool ModeMenu(){
    std::vector<std::string> data = {
        "1. Test mode",
        "2. Manual input mode",
        "3. Random input mode",
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

    std::vector<int> nums, freq;
    if (op == 1){
        TestMode(nums, freq);
        return true;
    }
    if (op == 2){
        Input(nums, freq);
        AlgoMenu(nums, freq);
        return true;
    }
    if (op == 3){
        int n;
        std::cout << "Size of array (input 0 for random size) = ";
        std::cin >> n;
        GenTest(nums, freq, n);
        AlgoMenu(nums, freq);
        return true;
    }

    return false;
}

bool AlgoMenu(std::vector<int> &nums, std::vector<int> &freq){
    std::vector<std::string> data = {
        "1. Optimal Binary Search Tree",
        "2. Knuth's Optimal Binary Search Tree",
        "3. Bisection Heuristic",
        "0. Exit",
    };

    std::cout << std::setfill('-') << std::setw(40) << '\n';
    std::cout << '\n';
    for (std::string i : data){
        std::cout << std::left << '|' << std::setw(38) << i << "|\n";
    }
    std::cout << std::setfill('-') << std::setw(40) << "";
    std::cout << "\n";

    int op = 0;
    std::cin >> op;
    if (op == 0) return true;
    if (op >= data.size()) return false;

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
    std::cout << "Size of array = ";
    std::cin >> n;
    std::cout << "Input value array: \n";
    for (int i = 1; i <= n; i ++){
        std::cout << "Value " << i << "= ";
        std::cin >> u;
        nums.push_back(u);
    }
    //Frequency
    std::cout << "Input frequency array: \n";
    for (int i = 1; i <= n; i ++){
        std::cout << "Value " << i << "= ";
        std::cin >> u;
        freq.push_back(u);
    }
}

int RandInt(int left, int right) {
    static std::random_device rd;                      // Seed ngẫu nhiên
    static std::mt19937 gen(rd());                     // Mersenne Twister PRNG
    std::uniform_int_distribution<int> dist(left, right);
    return dist(gen);
}

void GenTest(std::vector<int> &nums, std::vector<int> &freq, int n){
    //Init array
    nums.clear();
    freq.clear();
    nums.push_back(0);
    freq.push_back(0);

<<<<<<< Updated upstream
<<<<<<< Updated upstream
<<<<<<< Updated upstream

    srand(time(NULL));
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
    if (!n) n = RandInt(5, 1000);
    int cur = 1, prev = 0;
    for (int i = 1; i <= n; i ++){
        cur = RandInt(prev, 100000000);
        prev = cur + 1;
        nums.push_back(cur);
        freq.push_back(RandInt(1, 100000));
    }
}

int SearchNode(Node * root, int key){
    if (!root) return 0;
    if (key == root->value) return 1;
    
    if (key > root->value) return SearchNode(root->left, key) + 1;
    else return SearchNode(root->right, key) + 1;
}

void TestMode(std::vector<int> &nums, std::vector<int> &freq){
    time_t timestamp;
    time(&timestamp);
    std::string filename = ctime(&timestamp);
    filename.pop_back();
    filename += ".csv";
    for (int i = 0; i < filename.size(); i ++){
        if (filename[i] == ' ' || filename[i] == ':') filename[i] = '_';
    }
    std::ofstream fout;
    fout.open("..\\output\\" + filename);
    std::cout << "In processing....\n";

    std::vector<int> testcase;
    testcase.push_back(10);
    testcase.push_back(100);
    // testcase.push_back(1000);
    // testcase.push_back(10000);
    // testcase.push_back(100000);

    std::vector<std::vector<std::string>> data;
    std::vector<std::string> row;
    row.push_back("ID");
    row.push_back("Size Input");
    row.push_back("Optimal BST");
    row.push_back("Knuth's BST");
    row.push_back("Bisection heuristic BST");
    data.push_back(row);

    OptimalBST OBST;
    KnuthOBST KBST;
    BisectionHeu BBST;
    int obst, kbst, bbst;
    int id = 0;
    for (int testsize : testcase){
        for (int i = 0; i < 20; i ++){
            id++;
            GenTest(nums, freq, testsize);
            OBST.Process(nums, freq);
            KBST.Process(nums, freq);
            BBST.Process(nums, freq);
            row.clear();
            row.push_back(std::to_string(id));
            row.push_back(std::to_string(testsize));
            obst = kbst = bbst = 0;
            for (int j = 1; j <= testsize; j ++){
                for (int k = 0; k < freq[j]; k ++){
                    obst += SearchNode(OBST.OBSTroot, nums[j]);
                    kbst += SearchNode(KBST.KBSTroot, nums[j]);
                    bbst += SearchNode(BBST.BBSTroot, nums[j]);
                }
            }
            row.push_back(std::to_string(obst));
            row.push_back(std::to_string(kbst));
            row.push_back(std::to_string(bbst));
            data.push_back(row);
        }
    }

    for (auto roww : data){
        for (int i = 0; i < roww.size() - 1; i ++){
            fout << roww[i] << ",";
        }
        fout << roww.back() << '\n';
    }

<<<<<<< Updated upstream
    std::cout << "Complette output in output\\" << filename;
=======
    std::cout << "Complete output in output\\" << filename;
}