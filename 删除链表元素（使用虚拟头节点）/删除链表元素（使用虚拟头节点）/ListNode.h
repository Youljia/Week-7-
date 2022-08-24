#pragma once
class ListNode
{
public:
	ListNode();
	ListNode(int x);
	ListNode(int x, ListNode* next);
public:
	int val;
	ListNode* next;
};

