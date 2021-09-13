// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3973/

#include <iostream>
#include <string>

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bCount = 0;
        int aCount = 0;
        int lCount = 0;
        int oCount = 0;
        int nCount = 0;

        for (auto c : text) {
            switch (c) {
            case 'b':
                ++bCount;
                break;
            case 'a':
                ++aCount;
                break;
            case 'l':
                ++lCount;
                break;
            case 'o':
                ++oCount;
                break;
            case 'n':
                ++nCount;
                break;
            default:
                break;
            }
        }

        int res = bCount;
        res = min(res, aCount);
        res = min(res, lCount / 2);
        res = min(res, oCount / 2);
        res = min(res, nCount);
        return res;
    }
};

int main() {
}

