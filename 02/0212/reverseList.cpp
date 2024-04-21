#include "leetcode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};

int main() {
    auto t1 = ListNode::create({ 1, 2, 3, 4, 5 });
    Solution().reverseList(t1)->print();

    return 0;
}
