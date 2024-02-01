#include "iostream"
using namespace std;
// template <typename T>
class Node
{
public:
    int  data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

 

class stack
{
public:
    Node *head = NULL;  //To store address of head 
    int size = 0;

    // stack()
    // {
    //     head = NULL;
    // }
    bool isempty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int top() 
    {
        if(isempty())
        {
            return 0;
        }
        return head->data;
    }

    void push(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            size++;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            size++;
        }
    }

    int pop()
    {
        if (isempty())
        {
            return 0;
        }
        Node *temp = head;
        int store = temp->data;
        head = head->next;
        delete temp;
        size--;
        return store;
    }

    int tsize()
    {
        return size;
    }
};

int main()
{
    stack s1;
    s1.push(101);
    s1.push(91);
    s1.push(121);
    s1.push(86);
    s1.push(95 );
    cout << s1.top() << endl;
    cout << s1.tsize() << endl;
    cout << s1.pop() << endl;
    cout << s1.tsize() << endl;
    cout << s1.isempty() << endl;

    return 0;
}