#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        this->data = x;
        next = NULL;
    }
};

void printListrec(Node *head){
    if(head == NULL)
        return;
    cout << (head->data) << " ";
    printListrec(head->next);
}

Node *delHead(Node *head){
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    else{
        Node *temp = head->next;
        delete head;
        return temp;
    }
    
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
    cout << "before deleting head: ";
    printListrec(head);

    Node *new_head = delHead(head);
    cout << "\nafter deleting head: ";
    printListrec(new_head);

    return 0;
}