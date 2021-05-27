#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node *insertAtBegin(Node *head, int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

void printListrec(Node *head){
    if(head == NULL)
        return;
    cout << (head->data) << " ";
    printListrec(head->next);
}

int main(){
    Node *head = NULL;
    head = insertAtBegin(head, 50);
    head = insertAtBegin(head, 40);
    head = insertAtBegin(head, 30);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 10);
    printListrec(head);
    return 0;
}