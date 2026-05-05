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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 0;
        ListNode* temp = head;
        // Find the length of the list
        while (temp) {
            len++;
            temp = temp->next;
        }
        k = k % len;
        if (k == 0) return head;

        for (int i = 0; i < k; ++i) {
            ListNode* curr = head;
            ListNode* prev = nullptr;
            // Move to the last node
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }
            // Move last node to front
            prev->next = nullptr;
            curr->next = head;
            head = curr;
        }
        return head;
    }
};