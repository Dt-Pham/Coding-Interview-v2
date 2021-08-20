// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3903/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(0), left(left), right(right) {}
};

int get_sum(TreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->val + get_sum(node->left) + get_sum(node->right);
}

int dfs(TreeNode *node, long long &max_product, int total) {
    if (node == nullptr) {
        return 0;
    }

    int sum = node->val + dfs(node->left, max_product) + dfs(node->right, max_product);
    max_product = max(max_product, 1LL * sum * (total - sum));
    return sum;
}

int maxProduct(TreeNode *root) {
    const int mod = static_cast<int>(1e9) + 7; 

    int total = get_sum(root);
    long long max_product = 0;

    dfs(root, max_product, total);
    return max_product % mod;
}

int main() {
}
