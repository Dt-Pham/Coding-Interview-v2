// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3917/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        ComplexNumber x(num1);
        ComplexNumber y(num2);
        ComplexNumber z = x * y;
        return z.to_str();
    }

private:
    struct ComplexNumber {
        int a, b; // a + bi
        ComplexNumber(int a = 0, int b = 0) : a(a), b(b) {}
        ComplexNumber(string num) {
            char c;
            stringstream ss(num);
            s >> a;
            s >> c;
            s >> b;
        }

        ComplexNumber operator * (const ComplexNumber& other) const {
            ComplexNumber ans;
            ans.a = a * other.a - b * other.b;
            ans.b = a * other.b + b * other.a;
            return ans;
        }

        string to_str() const {
            stringstream ss;
            ss << a << "+" << b << "i";
            return ss.str();
        }
    };
};

int main() {
}
