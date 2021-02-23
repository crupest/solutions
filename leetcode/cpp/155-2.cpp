#include <vector>
#include <algorithm>

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        // Although I really think this is just a trick for this problem.
        // Leetcode does not give the input size. So I just make a reasonable assumption.
        data_.reserve(10000);
        min_stack_.reserve(10000);
    }

    void push(int x)
    {
        data_.push_back(x);
        if (min_stack_.empty())
        {
            min_stack_.push_back(x);
        }
        else
        {
            min_stack_.push_back(std::min(min_stack_.back(), x));
        }
    }

    void pop()
    {
        data_.pop_back();
        min_stack_.pop_back();
    }

    int top()
    {
        return data_.back();
    }

    int getMin()
    {
        return min_stack_.back();
    }

private:
    std::vector<int> data_;
    std::vector<int> min_stack_;
};
