#ifndef STACK__H_
#define STACK__H_

namespace stack_
{

    typedef unsigned long Item;

    class Stack
    {
    private:
        static const int MAX = 10; // constant specific to class
        Item *items;               // holds stack items
        int size;
        int top; // index for top stack item
    public:
        Stack(int n = MAX);
        Stack(const Stack &stack);
        Stack &operator=(const Stack &stack);
        ~Stack() { delete[] items; }
        bool isempty() { return !top; }
        bool isfull() { return top == size; }
        // push() returns false if stack already is full, true otherwise
        bool push(const Item &item); // add item to stack
        // pop() returns false if stack already is empty, true otherwise
        bool pop(Item &item); // pop top into item
    };
}
#endif
