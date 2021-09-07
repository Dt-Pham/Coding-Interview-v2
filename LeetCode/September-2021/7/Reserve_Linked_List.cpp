// https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3966/

#include <iostream>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode* next = head->next;
        ListNode* newHead = reverseList(next);
        next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};

int main() {
}
