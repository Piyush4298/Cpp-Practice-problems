#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

void printListRec(Node *head)
{
    if(head == NULL)
        return;
    cout << head->data << " ";
    printListRec(head->next);
}

Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    if(head != NULL)
        head->prev = temp;
    return temp;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    temp2->next = temp3;
    temp3->prev = temp2;

    cout << "Before inserting: ";
    printListRec(head);
    head = insertBegin(head, 5);
    cout << "\nAfter inserting: ";
    printListRec(head);
    return 0;
}