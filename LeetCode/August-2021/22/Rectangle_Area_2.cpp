// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3907/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rectangleArea(vector<vector<int>> &rectangles) {
        n = rectangles.size();
        vector<int> xCoordinates;
        for (auto v : rectangles) {
            rects.push_back(Rect(v[0], v[1], v[2], v[3]));
            xCoordinates.push_back(v[0]);
            xCoordinates.push_back(v[2]);
        }
        
        sort(xCoordinates.begin(), xCoordinates.end());
        xCoordinates.resize(unique(xCoordinates.begin(), xCoordinates.end()) - xCoordinates.begin());

        int totalArea = 0;
        for (size_t i = 1; i < xCoordinates.size(); ++i) {
            int width = xCoordinates[i] - xCoordinates[i - 1];
            
            vector<pair<int, int>> intervals;
            for (auto rect : rects) {
                if (rect.l >= xCoordinates[i] || rect.r <= xCoordinates[i - 1]) continue;
                intervals.push_back(make_pair(rect.d, rect.u));
            }

            int height = 0;
            int mx = 0;
            sort(intervals.begin(), intervals.end());
            for (auto interval : intervals) {
                if (mx < interval.first) {
                    mx = interval.first;
                }
                if (mx < interval.second) {
                    height += interval.second - mx;
                    mx = interval.second;
                }
            }
            totalArea += 1LL * width * height % mod;
            totalArea %= mod;
        }
        return totalArea;
    }
private:
    const int mod = static_cast<int>(1e9) + 7;
    struct Rect {
        int l, r, u, d;
        Rect(int x0, int y0, int x1, int y1) : l(x0), d(y0), r(x1), u(y1) {}
    };

    int n;
    vector<Rect> rects;
};
