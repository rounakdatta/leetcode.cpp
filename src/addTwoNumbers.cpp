#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

void insert(ListNode **ref, int data) {
	ListNode *newn = new ListNode;
	newn->val = data;
	newn->next = NULL;

	if (*ref == NULL) {
		*ref = newn;
	} else {
		ListNode *temp = *ref;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newn;
	}
}

void display(ListNode *ref) {
	ListNode *itr = ref;
	while (itr != NULL) {
		cout << itr->val << " ";
		itr = itr->next;
	}
	cout << endl;
}

int getReverse(ListNode *lx) {
	if (lx == NULL) {
		return 0;
	} else {
		return lx->val + getReverse(lx->next) * 10;

	}
}

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *l3 = NULL;

	int carry = 0;
	while (l1 != NULL && l2 != NULL) {
		insert(&l3, ((l1->val + l2->val + max(carry, 0)) % 10));
		carry = (l1->val + l2->val) / 10;
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1 != NULL) {
		insert(&l3, (l1->val + max(carry, 0)) % 10);
		carry = l1->val / 10;
		l1 = l1->next;
	}

	while (l2 != NULL) {
		insert(&l3, (l2->val + max(carry, 0)) % 10);
		carry = l2->val / 10;
		l2 = l2->next;
	}

	if (carry != 0) {
		insert(&l3, carry);
	}

	return l3;
}

int main() {
	ListNode *l1 = NULL;
	insert(&l1, 1);
	insert(&l1, 3);
	insert(&l1, 3);
	insert(&l1, 5);
	insert(&l1, 3);

	ListNode *l2 = NULL;
	insert(&l2, 3);
	insert(&l2, 8);
	insert(&l2, 6);
	insert(&l2, 7);

	display(l1);
	display(l2);
	ListNode *l3 = addTwoNumbers(l1, l2);
	int sumNum = getReverse(l3);
	cout << sumNum;
	return 0;
}