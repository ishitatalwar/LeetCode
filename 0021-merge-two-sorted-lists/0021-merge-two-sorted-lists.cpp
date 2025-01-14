/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Iterative
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        // Ensuring l1 points to the list with the smaller first value
        if (list1->val > list2->val) {
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
        }

        // Store the head of the result
        ListNode* res = list1;

        while (list1 != NULL && list2 != NULL) {
            ListNode* tmp = NULL;

            // Traverse l1 while its values are smaller than or equal to l2
            while (list1 != NULL && list1->val <= list2->val) {
                tmp = list1; // Keep track of the last node where l1 is smaller or equal
                list1 = list1->next; // Move l1 forward
            }

            // At this point, l1 is greater than l2 or NULL
            // Insert l2 node after tmp and adjust pointers
            tmp->next = list2;

            // Swap l1 and l2 so that the smaller list is processed in the next iteration
            ListNode* temp = list1;
            list1 = list2;
            list2 = temp;
        }

        return res; // Return the merged list's head
    }
};
