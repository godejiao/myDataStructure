#pragma once
#ifndef _LISTSORT_H_
#define _LISTSORT_H_
#include"listnode.h"
#include<iostream>
class ListSort {
public:
	ListNode *insertionSortList(ListNode *head) {
		ListNode dummy(INT_MIN);
		for (ListNode* cur = head; cur != nullptr;) {
			auto pos = findInsertPos(&dummy, cur->val);//找到要插入的位置，在其后插入
			ListNode *tmp = cur->next;
			cur->next = pos->next;//pos->next可能为空也可能为一串.起到切断的作用
			pos->next = cur;
			cur = tmp;
			//std::cout << dummy.next->val << " ";
		}
		return dummy.next;
	}
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)return;
		ListNode* pSlow = head;
		ListNode* pFast = head;
		ListNode *pre = nullptr;
		while (pFast&&pFast->next) {
			pre = pSlow;
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}
		pre->next = nullptr;
		ListNode* pPostList = reverseList(pSlow);

		ListNode *pCurr = head;
		while (pCurr->next) {
			ListNode* pTemp = pCurr->next;
			pCurr->next = pPostList;
			pPostList = pPostList->next;
			pCurr->next->next = pTemp;
			pCurr = pTemp;
		}
		pCurr->next = pPostList;
	}
	void mergeTwoList(ListNode* p1, ListNode* p2) {
		if (!p1 && !p2)return ;// nullptr;
		ListNode dummy(-1);
		ListNode *pHead = &dummy;
		pHead->next = p1;
		while(p1->next){ 
			auto pTemp = p1->next;
			p1->next = p2;
			p2 = p2->next;
			p1->next->next = pTemp;
			p1 = pTemp;
		}
		p1->next = p2;
		//return dummy.next;
	}
private:
	ListNode* findInsertPos(ListNode* head, int x) {
		ListNode* pPos=nullptr;
		for (ListNode* pCurr = head; pCurr != nullptr&&pCurr->val <= x; pPos = pCurr, pCurr = pCurr->next);
		return pPos; 
	}
	ListNode* reverseList(ListNode*head) {
		if (head == nullptr || head->next == nullptr)return head;
		ListNode* pNewHead=nullptr;
		while (head) {
			ListNode* pTemp = head->next;
			head->next = pNewHead;
			pNewHead = head;
			head = pTemp;
		}
		return pNewHead;
	}
};
#endif // !_LISTSORT_H_
