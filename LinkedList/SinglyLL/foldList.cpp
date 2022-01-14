#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void printList(Node *head){
    Node *curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node* reverseList(Node* head){
    Node *prev = NULL, *curr = head;

    while(curr != NULL)
    {
        Node *next_ = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_;
    }

    return prev;
}

Node* foldList(Node* head){
    if(head == NULL || head->next == NULL) 
        return head;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHead = reverseList(slow->next);
    slow->next = NULL;

    Node* curr1 = head;
    Node* curr2 = secondHead;

    while(curr2 != NULL)
    {
        Node *fwd1 = curr1->next;
        Node *fwd2 = curr2->next;

        curr1->next = curr2;
        curr2->next = fwd1;

        curr1 = fwd1;
        curr2 = fwd2;
    }

    return head;
}

int main(){
    Node *head = new Node(10);
    Node *t1 = new Node(20);
    Node *t2 = new Node(30);
    Node *t3 = new Node(40);
    Node *t4 = new Node(50);
    //Node *t5 = new Node(60);
    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    //t4->next = t5;
    // 10->20->30->40->50
    printList(foldList(head));
    
}