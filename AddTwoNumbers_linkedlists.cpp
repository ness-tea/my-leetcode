/** Vanessa Truong **/
/** Add Two Numbers

    Given two numbers represented as linked lists, add them and store the result in a third linked list. 
**/

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
	// Track sum of each digt place.  Also used to calculate carry-over amount.
        int sum = 0;
	
	// Create new node to store digit sum (beginning ones place) and store in a temp pointer to operate on.
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        
	// Check that lists are not empty before operating on.
        while (l1 != NULL || l2 != NULL)
        {
            // Add value of each list to sum per digit place if value exists.
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
            
	    // Store value of sum modulo 10 in temp node. If sum > 10, reassign sum to sum/10 to carry-over to next digit place sum. 
            temp->val = sum%10;
            sum = sum/10;
            
	    // If there is carry-over left, create new node to store carry-over amount in.
            if (sum > 0)
            {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
        }
        
        return result;
    }
};
