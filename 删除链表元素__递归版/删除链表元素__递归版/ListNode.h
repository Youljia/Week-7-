#pragma once
class ListNode
{
public:
	int val;
	ListNode* next;
public:
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

