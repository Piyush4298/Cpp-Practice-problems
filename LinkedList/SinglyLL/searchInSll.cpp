#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x){
        this->data = x;
        next = NULL;
    }
};

bool search(Node *head, int key){
    if(head == NULL)
        return false;
    Node *curr = head;
    while (curr != NULL)
    {
        if(curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
    
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
    if(search(head, 60))
        cout << "Searched key is present in Linked list!";
    else
        cout << "Searched key is not present in Linked list!";
}