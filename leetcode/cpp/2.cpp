struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result;
        ListNode *tail;
        int carry = 0;

        {
            int sum = l1->val + l2->val;
            if (sum > 9)
            {
                carry = 1;
                sum -= 10;
            }

            result = new ListNode(sum);
            tail = result;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 || l2)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            if (sum > 9)
            {
                carry = 1;
                sum -= 10;
            }
            else
            {
                carry = 0;
            }
            tail->next = new ListNode(sum);
            tail = tail->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (carry)
        {
            tail->next = new ListNode(1);
        }

        return result;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next = new ListNode(4);

    ListNode *result = Solution{}.addTwoNumbers(l1, l2);

    return 0;
}
