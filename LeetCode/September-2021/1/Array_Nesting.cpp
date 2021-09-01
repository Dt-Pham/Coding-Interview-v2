// https://leetcode.com/explore/featured/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        vector<bool> seen(n, false);
        for (int i = 0; i < n; ++i) {
            if (seen[i]) continue;
            seen[i] = true;
            int j = nums[i];
            int len = 1;
            while (j != i) {
                seen[j] = true;
                j = nums[j];
                ++len;
            }
            res = max(res, len);
        }
        return res;
    }
};

int main() {
}
