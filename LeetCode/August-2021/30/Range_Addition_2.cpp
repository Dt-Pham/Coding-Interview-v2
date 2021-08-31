// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/617/week-5-august-29th-august-31st/3957/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int w = m, h = n;
        for (auto op: ops) {
            w = min(w, op[0]);
            h = min(h, op[1]);
        }
        return w * h;
    }
};

int main() {
}
