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
 //Merge 2 sorted <int> lists
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if ((list1 == nullptr) && (list2 == nullptr))
            return nullptr;
        ListNode* resList = new ListNode;
        ListNode* currPos = resList;

        while ((list1 != nullptr) && (list2 != nullptr))
        {
            if((list1->val <= list2->val))
            {
                currPos->val = list1->val;
                list1 = list1->next;
            }
            else 
            {
                currPos->val = list2->val;
                list2 = list2->next;
            }
            currPos->next = new ListNode;
            currPos = currPos->next;  
        }
        if(list1 == nullptr)
        {
            currPos->val = list2->val;
            currPos->next = list2->next;
        }
        else
        {
            currPos->val = list1->val;
            currPos->next = list1->next;
        }
        return resList;
    }
};
