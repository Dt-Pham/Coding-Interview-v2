// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3918/

#include <iostream>
#include <cmath>

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a * a <= c / 2; ++a) {
            int b2 = c - a * a;
            int b = sqrt(b2);
            if (b * b == b2) {
                return true;
            }
        }
        return false;
    }
};
