#include "stack_.h"

namespace stack_
{

    Stack::Stack(int n) // creat stack with n elements
    {
        size = n;
        top = 0;
        items = new Item[size];
    }

    Stack::Stack(const Stack &stack)
    {
        size = stack.size;
        top = stack.top;
        items = new Item[size];
        for (int i = 0; i < size; i++)
            items[i] = stack.items[i];
    }

    Stack &Stack::operator=(const Stack &stack)
    {
        if (&stack != this)
        {
            delete[] items;
            size = stack.size;
            top = stack.top;
            items = new Item[size];
            for (int i = 0; i < size; i++)
                items[i] = stack.items[i];
        }
        return *this;
    }

    bool Stack::push(const Item &item)
    {
        if (top < size)
        {
            items[top++] = item;
            return true;
        }
        else
            return false;
    }

    bool Stack::pop(Item &item)
    {
        if (top > 0)
        {
            item = items[--top];
            return true;
        }
        else
            return false;
    }
}
