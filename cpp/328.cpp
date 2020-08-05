struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        if (head->next == nullptr)
            return head;

        ListNode *odd_head = head;
        head = head->next;
        ListNode *even_head = head;
        head = head->next;

        ListNode *odd_current = odd_head;
        ListNode *even_current = even_head;

        bool odd = true;
        while (head != nullptr)
        {
            if (odd)
            {
                odd_current->next = head;
                odd_current = head;
            }
            else
            {
                even_current->next = head;
                even_current = head;
            }
            head = head->next;
            odd = !odd;
        }

        odd_current->next = even_head;
        even_current->next = nullptr;

        return odd_head;
    }
};
