// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3835/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>> &grid) {
        n = grid.size();
        board = grid;
        island.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (island[i][j] == -1 && board[i][j] == 1) {
                    island[i][j] = islandSize.size();
                    islandSize.push_back(0);
                    dfs(i, j);
                }
            }
        }

        if (islandSize.empty()) return 1;
        int res = *max_element(islandSize.begin(), islandSize.end());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 1) continue;

                set<int> adjIslands;
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isOutside(x, y) || island[x][y] == -1) continue;
                    adjIslands.insert(island[x][y]);
                }

                int totalSize = 1;
                for (auto id: adjIslands) {
                    totalSize += islandSize[id];
                }

                res = max(res, totalSize);
            }
        }

        return res;
    }

private:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};

    int n;
    vector<vector<int>> board;
    vector<vector<int>> island;
    vector<int> islandSize;

    bool isOutside(int i, int j) {
        return i < 0 || j < 0 || i >= n || j >= n;
    }

    void dfs(int x, int y) {
        ++islandSize[island[x][y]];
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isOutside(nx, ny)) continue;
            if (board[nx][ny] == 1 && island[nx][ny] == -1) {
                island[nx][ny] = island[x][y];
                dfs(nx, ny);
            }
        }
    }
};
