/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            
            temp->val = sum%10;
            sum = sum/10;
            
            if (l1 != NULL || l2 != NULL || sum > 0)
            {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
        }
        
        return result;
    }
};
