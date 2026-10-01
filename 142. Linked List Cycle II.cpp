class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Check if cycle exists
        while (fast != NULL && fast->next != NULL) {
            
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                
                // Step 2: Find starting point of cycle
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        // No cycle
        return NULL;
    }
};
