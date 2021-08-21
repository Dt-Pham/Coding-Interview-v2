// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3905/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        rows.assign(9, vector<bool>(10, false));
        cols.assign(9, vector<bool>(10, false));
        boxes.assign(9, vector<bool>(10, false));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '0';
                rows[i][val] = true;
                cols[j][val] = true;
                boxes[(i / 3) * 3 + (j / 3)][val] = true;
            }
        }

        backtrack(0, board);
    }

private:
    bool backtrack(int pos, vector<vector<char>> &board) {
        if (pos == 81) return true;

        int r = pos / 9;
        int c = pos % 9;
        int b = (r / 3) * 3 + (c / 3);

        if (board[r][c] != '.') {
            return backtrack(pos + 1, board);
        } else {
            for (int val = 1; val <= 9; ++val) {
                if (rows[r][val] || cols[c][val] || boxes[b][val]) continue;
                board[r][c] = '0' + val;
                rows[r][val] = true;
                cols[c][val] = true;
                boxes[b][val] = true;
                if (backtrack(pos + 1, board)) {
                    return true;
                } else {
                    board[r][c] = '.';
                    rows[r][val] = false;
                    cols[c][val] = false;
                    boxes[b][val] = false;
                }
            }
            return false;
        }
    }
    
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> boxes;
};


int main() {
}
