#include<iostream>
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //链表头就是指定元素时
        while (head->val == val && head != nullptr)
        {
            ListNode* detNode = head;
            head = head->next;
            detNode->next = nullptr;
        }
        //删完为空
        if (head == nullptr)
            return head;
        //位于中间位置指定元素的删除
        ListNode* prev = head;
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
        return head;
    }
};