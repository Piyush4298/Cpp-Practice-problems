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

Node *insertAtEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

void printListrec(Node *head){
    if(head == NULL)
        return;
    cout << (head->data) << " ";
    printListrec(head->next);
}


int main(){
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    Node *t3 = new Node(40);
    Node *t4 = new Node(50);
    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    cout << "Before inserting : ";
    printListrec(head);
    cout << endl;
    cout << "After inserting : ";
    printListrec(insertAtEnd(head, 60));
    
    return 0;
}