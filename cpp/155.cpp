#include <vector>
#include <set>

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        data_.push_back(x);
        sorted_data_.insert(x);
    }

    void pop()
    {
        const auto v = data_.back();
        data_.pop_back();
        sorted_data_.erase(sorted_data_.find(v));
    }

    int top()
    {
        return data_.back();
    }

    int getMin()
    {
        return *sorted_data_.cbegin();
    }

private:
    std::vector<int> data_;
    std::multiset<int> sorted_data_;
};
