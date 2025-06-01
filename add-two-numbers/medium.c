/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int remain = 0;

    struct ListNode* head = NULL;
    struct ListNode* current = NULL;

    while(l1 != NULL || l2 != NULL) {
        int l1tmp = 0;
        int l2tmp = 0;

        if (l1 != NULL) {
            l1tmp = l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            l2tmp = l2->val;
            l2 = l2->next;
        }

        int sum = l1tmp + l2tmp + remain;
        if (sum >= 10) {
            remain = 1;
            sum -= 10;
        } else {
            remain = 0;
        }

        struct ListNode* ptr = (struct ListNode*) malloc(sizeof(struct ListNode));
        ptr->val = sum;
        ptr->next = NULL;  // Set next pointer to NULL

        if (head == NULL) {
            head = ptr;
        } else {
            current->next = ptr;
        }

        current = ptr;
    }

    if (remain == 1) {
        struct ListNode* ptr = (struct ListNode*) malloc(sizeof(struct ListNode));
        ptr->val = 1;
        ptr->next = NULL;  // Set next pointer to NULL

        if (head == NULL) {
            head = ptr;
        } else {
            current->next = ptr;
        }
    }

    return head;
}
