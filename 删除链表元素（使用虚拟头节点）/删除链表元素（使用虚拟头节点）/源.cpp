#include<iostream>
#include"ListNode.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode;
        dummyHead->next = head;
        ListNode* prev = dummyHead;
        while (prev->next != nullptr)
        {
            if (prev->next->val == val)
            {
                ListNode* delNode = prev->next;
                prev->next = delNode->next;
                delNode->next = nullptr;
            }
            else
                prev = prev->next;
        }
        return dummyHead->next;
    }
};