class Solution
{
public:

    ListNode* sortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        // Middle find
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Second half
        ListNode* second = slow->next;
        slow->next = NULL;

        // Sort both parts
        ListNode* first = sortList(head);
        second = sortList(second);

        // Merge
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (first != NULL && second != NULL)
        {
            if (first->val < second->val)
            {
                temp->next = first;
                first = first->next;
            }
            else
            {
                temp->next = second;
                second = second->next;
            }

            temp = temp->next;
        }

        if (first != NULL)
            temp->next = first;
        else
            temp->next = second;

        return dummy->next;
    }
};
