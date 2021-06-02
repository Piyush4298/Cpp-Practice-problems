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

void makeCircular(Node *head)
{
    if(head == NULL)
        return;
    Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head;
}

void printList(Node *head)
{
    Node *curr = head;
    do{
        cout << curr->data << " ";
        curr = curr->next;
    }while(curr != head);
}

Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    swap(head->data, temp->data);
    return temp;
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
    cout << "Before inserting: ";
    printList(head);

    head = insertEnd(head, 60);
    cout << "\nAfter inserting :";
    printList(head);
    return 0;
}