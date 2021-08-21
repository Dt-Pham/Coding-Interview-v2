#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> boxes(9, vector<bool>(10, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if (rows[i][num]) return false;
                if (cols[j][num]) return false;

                int box_id = (i/3) * 3 + (j/3);
                if (boxes[box_id][num]) return false;

                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box_id][num] = true;
            }
        }

        return true;
    }

};

