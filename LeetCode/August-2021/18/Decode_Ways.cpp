// https://leetcode.com/explore/featured/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3902/
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s) {
    int n = s.size();

    // f[i] is number of ways to decode substring s[i...n-1]
    vector<int> f(n + 1, 0);
    f[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') continue;
        f[i] = f[i + 1];
        
        if (i + 1 < n) {
            int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (val <= 26) {
                f[i] += f[i + 2];
            }
        }
    }

    return f[0];
}

bool checkInput(string s) {
    if (s.size() > 100 || s.empty()) {
        cout << "String's length must be between 1 and 100." << endl;
        return false;
    }

    for (auto c : s) {
        if (c < '0' || c > '9') {
            cout << "Input string contains invalid character '" << c << "'" << endl;
            return false;
        }
    }

    return true;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " string" << endl;
        return 1;
    }

    string input = argv[1];
    
    if (checkInput(input)) {
        cout << numDecodings(argv[1]) << endl;
        return 0;
    }

    return 1;
}
