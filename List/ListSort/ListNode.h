#pragma once
#ifndef _LISTNODE_H_
#define _LISTNODE_H_


class ListNode
{
public:
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode() {}
	~ListNode() {}
	int val;
	ListNode *next;
};
#endif // !_LISTNODE_H_

