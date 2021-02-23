/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr)
        {
            return head;
        }

        ListNode less_list_head(0);
        ListNode greater_list_head(0);

        ListNode *less_list_tail = &less_list_head;
        ListNode *greater_list_tail = &greater_list_head;

        auto current_head = head;
        auto prev = head;
        auto current = head->next;
        bool less = head->val < x;

        while (current != nullptr)
        {
            const bool current_less = (current->val < x);
            if (less != current_less)
            {
                if (less)
                {
                    less_list_tail->next = current_head;
                    less_list_tail = prev;
                }
                else
                {
                    greater_list_tail->next = current_head;
                    greater_list_tail = prev;
                }

                less = current_less;
                current_head = current;
            }
            prev = current;
            current = current->next;
        }

        if (less)
        {
            less_list_tail->next = current_head;
            less_list_tail = prev;
        }
        else
        {
            greater_list_tail->next = current_head;
            greater_list_tail = prev;
        }

        less_list_tail->next = greater_list_head.next;
        greater_list_tail->next = nullptr;

        return less_list_head.next;
    }
};