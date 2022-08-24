#include<iostream>
#include"ListNode.h"
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //����ͷ����ָ��Ԫ��ʱ
        while (head->val == val && head != nullptr)
        {
            ListNode* detNode = head;
            head = head->next;
            detNode->next = nullptr;
        }
        //ɾ��Ϊ��
        if (head == nullptr)
            return head;
        //λ���м�λ��ָ��Ԫ�ص�ɾ��
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