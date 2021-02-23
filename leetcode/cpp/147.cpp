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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode *next_sort = head->next;

        head->next = nullptr;

        while (next_sort != nullptr)
        {
            ListNode *current_sort = next_sort;
            next_sort = current_sort->next;

            ListNode *prev = nullptr;
            ListNode *current = head;

            int i = 0;

            while (current != nullptr && current->val < current_sort->val)
            {
                i++;
                prev = current;
                current = current->next;
            }

            if (prev == nullptr)
            {
                current_sort->next = head;
                head = current_sort;
            }
            else
            {
                ListNode *prev_next = prev->next;
                prev->next = current_sort;
                current_sort->next = prev_next;
            }
        }

        return head;
    }
};
