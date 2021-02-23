#include <cstddef>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return NULL;

        ListNode *last = NULL;
        ListNode *current = head;

        while (current != NULL)
        {
            if (current->val == val)
            {
                if (last == NULL)
                {
                    auto temp = current;
                    current = current->next;
                    head = current;
                    delete temp;
                }
                else
                {
                    auto temp = current;
                    current = current->next;
                    last->next = current;
                    delete temp;
                }
            }
            else
            {
                last = current;
                current = current->next;
            }
        }
        return head;
    }
};
