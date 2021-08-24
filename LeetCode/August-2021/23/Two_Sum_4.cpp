// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3908/

#include <iostream>

using namespace std;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        dfs(root, a);

        int j = a.size() - 1;
        for (int i = 0; i < j; ++i) {
            while (j > i + 1 && a[i] + a[j] > k) --j;
            if (a[i] + a[j] == k) return true;
        }
        return false;
    }
private:
    void dfs(TreeNode* root, vector<int> &output) {
        if (root == nullptr) return;
        dfs(root->left, output);
        output.push_back(root->val);
        dfs(root->right, output);
    }
};
