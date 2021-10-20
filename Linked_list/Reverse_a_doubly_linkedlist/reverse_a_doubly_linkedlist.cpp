#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
}*start = NULL;

Node* reverse(Node * head){
    Node* current = head->next;
    head->next = NULL;
    Node* top = head;
    Node* nxt = NULL;
    while(current!=NULL){
        nxt = current->next;
        current->next = top;
        current->prev = NULL;
        top->prev = current;
        top = current;
        current = nxt;
    }
    return top;
}

int main(){
    int n;
    cin>>n;
    Node *head = NULL;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        Node* temp = new Node(x);
        if(start == NULL){
            start = head = temp;
        }else{
            head->next = temp;
            temp->prev = head;
            head = temp;
        }
    }
    head = start;
    Node* rev_start = reverse(start);
    while(rev_start!=NULL){
        cout<<rev_start->data<<" ";
        rev_start = rev_start->next;
    }
}