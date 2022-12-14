#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;

        ListNode* res = removeElements(head->next, val);
        if (head->val == val)
            return res;
        else
        {
            head->next = res;
            return head;
        }
    }
};
