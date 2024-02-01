#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node *take()
{

    int data;
    cin >> data;
    Node *head = NULL;
    Node *temp = NULL;
    while (data != -1)
    {

        Node *newnode = new Node(data);

        if (head == NULL)
        {
            
            head = newnode;  // it is fix
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        cin >> data;
    }
    return head;
}
Node *insert(Node *head,int i,int data)
{

    Node *newnode = new Node(data);

    Node *temp = head;
    int count =0;
    while(temp!=NULL && count<i-1)
    {
        temp = temp->next;
        count++;
    }
   
    if(temp!=NULL)
    {
        Node * a = temp->next;
        Node *b  = temp->next->prev;
        temp->next = newnode;
        newnode->next =a; 
        newnode->prev = b;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp= temp->next;
    
    }

}

int main()
{
    Node *head = take();
    Node *h = insert(head,2,100);
    print(h);

    return 0;
}