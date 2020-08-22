#include <vector>
#include <memory>

class MyHashSet
{
    static const int max = 100;

private:
    std::unique_ptr<std::vector<int>> data_[max];

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        const auto index = key % max;
        auto &ptr = data_[index];
        if (ptr == nullptr)
        {
            ptr.reset(new std::vector<int>());
        }

        auto &v = *ptr;
        for (auto d : v)
        {
            if (d == key)
                return;
        }

        v.push_back(key);
    }

    void remove(int key)
    {
        const auto index = key % max;
        auto &ptr = data_[index];
        if (ptr == nullptr)
            return;
        auto &v = *ptr;
        const auto end = v.cend();
        for (auto iter = v.cbegin(); iter != end; ++iter)
        {
            if (*iter == key)
            {
                v.erase(iter);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        const auto index = key % max;
        auto &ptr = data_[index];
        if (ptr == nullptr)
            return false;

        const auto &v = *ptr;
        for (auto d : v)
        {
            if (d == key)
                return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
