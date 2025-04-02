#include <Function.h>


void Example(){
    std::vector<int> nums, freq;
    nums.push_back(0);
    freq.push_back(0);
    nums.push_back(1);
    freq.push_back(210);
    nums.push_back(2);
    freq.push_back(20);
    nums.push_back(3);
    freq.push_back(547);
    nums.push_back(4);
    freq.push_back(100);
    nums.push_back(5);
    freq.push_back(120);
    std::cout << "Nums: ";
    for (int i = 1; i < nums.size(); i ++){
        std::cout << nums[i] << " ";
    }
    std::cout << "\nFreq: ";
    for (int i = 1; i < freq.size(); i ++){
        std::cout << freq[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Optimal BST: \n";
    OptimalBST OBST;
    OBST.Process(nums, freq);
    PerfectBST PBST;
    PBST.NLR(OBST.OBSTroot);
    std::cout << "\n";
}

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

    return false;
}

int RandInt(int left, int right) {
    static std::random_device rd;                      // Random seed
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

    if (!n) n = RandInt(5, 1000);
    int cur = 1, prev = 0;
    for (int i = 1; i <= n; i ++){
        cur = RandInt(1, 10000);
        nums.push_back(cur);
        freq.push_back(RandInt(1, 10000));
    }
    
    std::sort(nums.begin(), nums.end());
}

int SearchNode(Node * root, int key){
    if (!root) return 0;
    if (key == root->value) return 1;
    
    if (key > root->value) return SearchNode(root->left, key) + 1;
    else return SearchNode(root->right, key) + 1;
}

long long TotalCost(Node * root, int level){
    if (!root) return 0;
    return 1ll*root->freq * level + TotalCost(root->left, level + 1) + TotalCost(root->right, level + 1);
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
    testcase.push_back(1000);

    std::vector<std::vector<std::string>> data;
    std::vector<std::string> row;
    row.push_back("ID");
    row.push_back("Size Input");
    row.push_back("Knuth's BST");
    row.push_back("Bisection heuristic BST");
    row.push_back("Perfectly Balanced BST");
    data.push_back(row);

    //OptimalBST OBST;
    KnuthOBST KBST;
    BisectionHeu HBST;
    PerfectBST PBST;
    long long kbst, hbst, pbst;
    long double diffHeu = 0, diffPerfect = 0;
    int id = 0;
    int dem = 0;
    // int len = testcase.size();
    int len = 1000;
    for (int k = 1; k <= len; k ++){
        // int testsize = testcase[k];
        //std::cout << 100.0 * ((double)(k) / len) << "%\n";
        int testsize = k;
        for (int i = 0; i < 1; i ++){
            id++;
            GenTest(nums, freq, testsize);
            KBST.Process(nums, freq);
            HBST.Process(nums, freq);
            PBST.Process(nums, freq);
            row.clear();
            row.push_back(std::to_string(id));
            row.push_back(std::to_string(testsize));
            kbst = hbst = pbst = 0;
            kbst = TotalCost(KBST.KBSTroot, 1);
            hbst = TotalCost(HBST.HBSTroot, 1);
            pbst = TotalCost(PBST.PBSTroot, 1);

            diffHeu += 1.0*hbst/kbst;
            diffPerfect += 1.0*pbst/kbst;
            row.push_back(std::to_string(kbst));
            row.push_back(std::to_string(hbst));
            row.push_back(std::to_string(pbst));
            data.push_back(row);
        }
    }

    diffHeu *= 100.0/len; diffPerfect *= 100.0/len;
    for (auto roww : data){
        for (int i = 0; i < roww.size() - 1; i ++){
            fout << roww[i] << ",";
        }
        fout << roww.back() << '\n';
    }
    fout << diffHeu << ' ' << diffPerfect << '\n';

    std::cout << "Complete output in output\\" << filename;
}