#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
}

void makeCircular(Node *head)
{
    if(head == NULL)
        return;
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = head;
}

Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = head->next;
        head->next = temp;
        swap(head->data, temp->data);
        return head;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);
    Node *temp4 = new Node(50);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;

    makeCircular(head);

    cout << "Before insert : ";
    printList(head);

    head = insertBegin(head, 5);

    cout << "\nAfter insert : ";
    printList(head);
    return 0;
}