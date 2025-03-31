#include <KnuthOBST.h>

void KnuthOBST::Process(std::vector<int> &nums, std::vector<int> &freq){
    int n = freq.size() - 1;
    std::vector<std::vector<int>> c, root;
    std::vector<int>prefix;

    c.resize(n + 2);
    root.resize(n + 2);
    for (int i = 0; i <= n + 1; i ++){
        c[i].resize(n + 1, 0);
        root[i].resize(n + 1, 0);
    }
    
    for (int i = 1; i <= n; i ++){
        c[i][i] = freq[i];
        root[i][i] = i;
    }
    
    prefix.resize(n + 1, 0);
    for (int i = 1; i <= n; i ++){
        prefix[i] = prefix[i - 1] + freq[i];
    }

    for (int d = 1; d < n; d ++){
        for (int i = 1; i <= n - d; i ++){
            int mi = INT_MAX, j = i + d, s;
            int start = root[i][j - 1];
            int end = root[i + 1][j];
            for (int l = start; l <= end; l ++){
                s = c[i][l - 1] + c[l + 1][j];
                if (s < mi){
                    mi = s;
                    root[i][j] = l;
                }
            }

            c[i][j] = mi + prefix[j] - prefix[i - 1];
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 0; j <= n; j ++){
    //         std::cout << std::setw(5) << std::setfill(' ') << c[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j ++){
    //         std::cout << root[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }

    BuildTree(KBSTroot, 1, n, nums, freq, root);
    // NLR(KBSTroot);
}

void KnuthOBST::BuildTree(Node * &root, int l, int r, std::vector<int> &nums, std::vector<int> &freq, std::vector<std::vector<int>> &rootTable){
    if (l > r) return;
    int pivot = rootTable[l][r];
    root = new Node(nums[pivot], freq[pivot]);
    BuildTree(root->left, l, pivot - 1, nums, freq, rootTable);
    BuildTree(root->right, pivot + 1, r, nums, freq, rootTable);
}