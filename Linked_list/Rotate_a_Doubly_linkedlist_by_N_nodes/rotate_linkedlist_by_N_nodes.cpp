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

void printResult(Node* head){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

void rotateByN(Node **head, int N){
    if(N == 0) return;

    Node *current = *head;
    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    Node *n_Node = *head;
    int i = 1;
    while(i < N && n_Node!=NULL){
        n_Node = n_Node->next;
        i++;
    }
    if(n_Node == NULL || n_Node->next == NULL){
        return;
    }
    *head = n_Node->next;
    n_Node->next->prev = NULL;
    n_Node->next = NULL;
    last->next = current;
    current->prev = last;
}

int main(){
    int n;
    cin >> n;
    Node *head = NULL;
    int i = 0;
    while (i < n){
        int x;
        cin >> x;
        Node* temp = new Node(x);
        if(start == NULL){
            start = head = temp;
        }else{
            head->next = temp;
            temp->prev = head;
            head = temp;
        }
        i++;
    }
    int N;
    cin>>N;
    rotateByN(&start, N);
    printResult(start);
}