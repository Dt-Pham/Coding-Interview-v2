// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/617/week-5-august-29th-august-31st/3958/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int res = nums[0];

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] < nums[0]) {
                res = nums[mid];
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return res;
    }
};

int main() {}

