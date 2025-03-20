#include <stdio.h>
#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* createNode(int);
struct ListNode* arrayToList(int [], int);
void displayList(struct ListNode*);
int calListLen(struct ListNode*);
struct ListNode* addTwoNumbers(struct ListNode*, struct ListNode*);
void freeList(struct ListNode*);

int main(void)
{
	struct ListNode  *l1, *l2, *l3;

	int arr1[] = {9, 9, 9, 9, 9, 9, 9};
	int arr2[] = {9, 9, 9, 9};
	l1 = arrayToList(arr1, ((int)sizeof(arr1))/4);
	l2 = arrayToList(arr2, ((int)sizeof(arr2))/4);
	l3 = addTwoNumbers(l1, l2);
	displayList(l3);
	freeList(l1);
	freeList(l2);
	freeList(l3);
	return 0;
}

struct ListNode* createNode(int value)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (node == NULL) {
		printf("memory allocation failure!\n");
		exit(EXIT_FAILURE);
	}
	node->val = value;
	node->next = NULL;
	return node;
}

struct ListNode* arrayToList(int arr[], int size)
{
	if (size == 0) {
		return NULL;
	}
	struct ListNode* head = createNode(arr[0]);
	struct ListNode* current = head;

	for (int i = 1; i < size; i++) {
		current->next = createNode(arr[i]);
		current = current->next;
	}
	return head;
}

void displayList(struct ListNode* head)
{
	struct ListNode* current = head;
	while (current != NULL) {
		printf("%d", current->val);
		current = current->next;
	}
	printf("\n");
}

int calListLen(struct ListNode* list)
{
	int len = 0;
	while (list != NULL) {
		len++;
		list = list->next;
	}
	return len;
}

void freeList(struct ListNode* head)
{
	while (head != NULL) {
		struct ListNode* temp = head;
		head = head->next;
		free(temp);
	}
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* dummy = createNode(0);
	struct ListNode* current = dummy;

	int carry = 0;
	int remainder = 0;
	int total = 0;

	while (l1 != NULL || l2 != NULL || carry != 0) {
		
		int x, y;

		if (l1 != NULL) {
			x = l1->val;
		} else {
			x = 0;
		}

		if (l2 != NULL) {
			y = l2->val;
		} else {
			y = 0;
		}

		total = x + y + carry;

		carry = total / 10;
		remainder = total % 10;

		current->next = createNode(remainder);
		current = current->next;
		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
	}
	struct ListNode* result = dummy->next;
	free(dummy);
	return result;
}
