// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3968/

#include <iostream>

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        string res = string(n, ' ');

        int shift = 0;
        for (int i = n - 1; i >= 0; --i) {
            shift = (shift + shifts[i]) % 26;
            int c = (s[i] - 'a' + shift) % 26;
            res[i] = 'a' + c;
        }
        return res;
    }
};

int main() {
}
