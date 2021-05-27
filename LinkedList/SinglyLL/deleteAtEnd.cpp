#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printListrec(Node *head){
    if(head == NULL)
        return;
    cout << (head->data) << " ";
    printListrec(head->next);
}

Node *delTail(Node *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(head->next->next != NULL)
        head = head->next;
    delete head->next;
    head->next = NULL;
    return curr;
}

int main(){
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    Node *temp3 = new Node(40);
    Node *temp4 = new Node(50);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    cout << "before deleting tail: ";
    printListrec(head);
    cout << "\nafter deleting tail: ";
    printListrec(delTail(head));
    return 0;
}