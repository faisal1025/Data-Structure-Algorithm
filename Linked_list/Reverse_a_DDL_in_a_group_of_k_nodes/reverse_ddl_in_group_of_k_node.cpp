#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node * next;
    Node * prev;
    Node(char x){
        data = x;
        next = NULL;
        prev = NULL;
    }
}*start = NULL;

//Print a linkedlist
void printResult(Node* head){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

//Recursive function to reverse a ddl in group of k nodes
Node* reverseddl(Node *head, int k){
    Node* current = head;
    Node* nxt = NULL;
    Node* top = NULL;
    if(head == NULL){
        return top;
    }
    int i = 1;
    while(current!=NULL && i <= k){
        nxt = current->next;
        current->next = top;
        if(top != NULL){
            top->prev = current;
        }
        top = current;
        top->prev = NULL;
        current = nxt;
        i++;
    }
    Node* res = reverseddl(nxt, k);
    head->next = res;
    if(res!=NULL) res->prev = head;
    return top;
}

int main(){
    int n;
    cin>>n;
    Node *head = NULL;
    for(int i = 0; i < n; ++i){
        char c;
        cin >> c;
        Node* temp = new Node(c);
        if(start == NULL){
            start = head = temp;
        }else{
            head->next = temp;
            temp->prev = head;
            head = temp;
        }
    }
    int k;
    cin>>k;
    Node* rev_start = reverseddl(start, k);
    printResult(rev_start);
    return 0;
}