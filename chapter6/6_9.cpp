#include <iostream>
using namespace std;

class Stack
{
    private:
        static const int MAX = 10;
        int st[MAX];
        int top;
    public:
        Stack()
            {   top =0; }
        void push(int var)
            { st[++top] = var;}
        int pop()
            { return st[top--];}
};
class queue
{
    private:
        static const int MAX = 3;
        int qu[MAX];
        int  head;
        int tail;
    public:
        queue()
        {    head  = 0;  tail = 0;  }
        void put(int var)
        {
            qu[++tail] = var;
            if(tail == MAX - 1)
                tail = -1;
        }
        int get()
        {
            if (head == MAX-1)
                head = -1;
            return qu[++head];
        }
};


int main()
{
    queue s;
    s.put(10);
    s.put(0);
    s.put(8);

    cout<<s.get()<<endl;
    cout<<s.get()<<endl;
    s.put(9);
    s.put(1);
    cout<<s.get()<<endl;
    cout<<s.get()<<endl;
    cout<<s.get()<<endl;

    return 0;

}
