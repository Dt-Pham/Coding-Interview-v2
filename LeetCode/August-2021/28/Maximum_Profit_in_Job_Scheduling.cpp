// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3950/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.startTime < b.startTime;
        });

        vector<int> f(n + 1, 0);
        // f[i] = max profit we can get from subset job[i] ... job[n-1]
        //      = max profit we can get from time range job[i].startTime ... inf
        f[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            f[i] = f[i + 1];

            // if we decide to do job i.
            int lo = i + 1;
            int hi = n - 1;
            int j = n;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (jobs[i].endTime <= jobs[mid].startTime) {
                    j = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            
            f[i] = max(f[i], f[j] + jobs[i].profit);
        }

        return f[0];
    }

private:
    struct Job {
        int startTime;
        int endTime;
        int profit;
        Job() {}
        Job(int start, int end, int profit) : startTime(start), endTime(end), profit(profit) {}
    };

};

int main() {
}
