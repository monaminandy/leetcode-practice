#Add Two Numbers In Linked List

#include <stdio.h>
#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head, *newnode, *temp;
    head = 0;
    int d;
    int r = 0;

    while (l1 != 0 || l2 != 0 || r != 0) { 
        newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        d = 0; 

        if (l1 != 0) {
            d += l1->val;
            l1 = l1->next;
        }
        if (l2 != 0) {
            d += l2->val;
            l2 = l2->next;
        }

        d += r; 

        newnode->val = d % 10;
        r = d / 10;
        newnode->next = 0;

        if (head == 0) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}
