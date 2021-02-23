class MyCircularDeque
{
private:
    int *data_;
    int *data_end_;
    int *front_;
    int *end_;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        data_ = new int[k];
        data_end_ = data_ + k - 1;
        front_ = nullptr;
        end_ = nullptr;
    }

    ~MyCircularDeque()
    {
        delete[] data_;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (front_ == nullptr)
            front_ = end_ = data_;
        else if (front_ == data_)
            front_ = data_end_;
        else
            front_ -= 1;
        *front_ = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (front_ == nullptr)
            front_ = end_ = data_;
        else if (end_ == data_end_)
            end_ = data_;
        else
            end_ += 1;
        *end_ = value;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        if (front_ == end_)
            front_ = end_ = nullptr;
        else if (front_ == data_end_)
            front_ = data_;
        else
            front_ += 1;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        if (front_ == end_)
            front_ = end_ = nullptr;
        else if (end_ == data_)
            end_ = data_end_;
        else
            end_ -= 1;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (isEmpty())
            return -1;
        return *front_;
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (isEmpty())
            return -1;
        return *end_;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return front_ == nullptr;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        if (front_ == nullptr)
            return false;
        return (front_ == data_ && end_ == data_end_) || (end_ + 1 == front_);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */