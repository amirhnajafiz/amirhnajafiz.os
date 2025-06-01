/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* header = NULL;
    struct ListNode* current = NULL;

    while(list1 != NULL || list2 != NULL)
    {
        // Create a tmp
        struct ListNode* tmp = NULL;

        // Select the next pointer based on tmp
        if (list1 == NULL) {
            tmp = list2;
            list2 = list2->next;
        } else if (list2 == NULL) {
            tmp = list1;
            list1 = list1->next;
        } else {
            if (list2->val > list1->val) {
                tmp = list1;
                list1 = list1->next;
            } else {
                tmp = list2;
                list2 = list2->next;
            }
        }

        // Update head current
        if (current == NULL) {
            header = tmp;
            current = tmp;
        } else {
            current->next = tmp;
            current = tmp;
        }
    }

    return header;
}
