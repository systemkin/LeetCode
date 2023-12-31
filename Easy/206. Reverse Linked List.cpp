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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        
        //Unnecessary "if" - Commented after checking other solutions
        if (head->next == nullptr)
            return head;
        ListNode *prev;
        ListNode *next = head->next;
        head->next = nullptr;
        while(next != nullptr)
        {
            prev = head;
            head = next;
            next = head->next;
            head->next = prev;
        }
        return head;

    }
};
