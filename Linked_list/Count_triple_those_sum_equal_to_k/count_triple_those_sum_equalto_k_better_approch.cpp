#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
}*start = NULL;

int findpair(Node* first, Node* last, int k){
    int count = 0;
    Node *begin = first;
    Node *end = last;
    while(begin != end && begin != end->next && end != begin->prev){
        if(begin->data+end->data == k){
            count++;
            begin = begin->next;
            end = end->prev;
        }else if(begin->data+end->data < k){
            begin = begin->next;
        }else{
            end = end->prev;
        }
    }
    return count;
}

int findTriple(Node* head, int k){
    Node* last = head;
    while(last->next != NULL){
        last = last->next;
    }
    int count = 0;
    Node* current = head;
    while(current->next!=NULL){
        Node* first = current->next;
        count += findpair(first, last, k-current->data);
        current = current->next;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    Node* head = NULL;
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
    int k;
    cin>>k;
    cout<<findTriple(start, k);
}