#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x){
        data = x;
        next=NULL;
        prev=NULL;
    }
}*start = NULL;

int countTriple(Node *head, int k){
    unordered_map<int, Node*>map;
    Node *current = head;
    while(current!=NULL){
        map[current->data] = current;
        current = current->next;
    }
    int cnt = 0;
    Node *first = head;
    while(first!=NULL){
        Node *second = first->next;
        while(second!=NULL){
            int req = k - (first->data+second->data);
            if(map.find(req) != map.end()){
                Node *check = map[req];
                if(check != first && check != second){
                    cnt++;
                }
            }
            second = second->next;
        }
        first = first->next;
    }
    return cnt/3;
}

int main(){
    int n;
    cin>>n;
    Node * head = NULL;
    for(int i = 0; i < n; ++i){
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
    cout<<countTriple(start, k);
}