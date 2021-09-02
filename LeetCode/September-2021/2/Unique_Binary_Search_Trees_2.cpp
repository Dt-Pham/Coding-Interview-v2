// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3961/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        memory.assign(n + 1, vector<vector<TreeNode*>>(n + 1, vector<TreeNode*>()));
        return generate(1, n); 
    }
private:
    vector<vector<vector<TreeNode*>>> memory;

    vector<TreeNode*> generate(int minValue, int maxValue) {
        if (minValue > maxValue) {
            return vector<TreeNode*> {nullptr};
        }
        if (minValue == maxValue) {
            TreeNode* root = new TreeNode(minValue);
            return vector<TreeNode*> {root};
        }

        vector<TreeNode*> &res = memory[minValue][maxValue];
        if (!res.empty()) {
            return res;
        }
        for (int value = minValue; value <= maxValue; ++value) {
            vector<TreeNode*> leftSubTrees = generate(minValue, value - 1);
            vector<TreeNode*> rightSubTrees = generate(value + 1, maxValue);
            
            for (auto left : leftSubTrees) {
                for (auto right : rightSubTrees) {
                    TreeNode *root = new TreeNode(value);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};

int main() {
}
