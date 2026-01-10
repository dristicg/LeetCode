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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
        return nullptr;


        ListNode* ptr1=head;
        ListNode* ptr2= head;
        ListNode* prev =nullptr;

        while(ptr2 && ptr2->next){
            prev = ptr1;
            ptr1= ptr1->next;
            ptr2= ptr2->next->next;
        }
        prev->next=ptr1->next;
        return head;
        
    }
};