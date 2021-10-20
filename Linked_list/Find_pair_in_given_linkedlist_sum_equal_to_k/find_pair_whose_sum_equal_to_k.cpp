#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
} *start = NULL;

void findpair(Node* head, int k){
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    Node* first = head;
    Node* last = current;
    while(first!=last && first != last->next && last != first->prev){
        if(first->data+last->data == k){
            cout<<first->data<<" "<<last->data<<endl;
            first = first->next;
            last = last->prev;
        }else if(first->data+last->data < k){
            first = first->next;
        }else if(first->data+last->data > k){
            last = last->prev;
        }
    }
}
int main(){
    int n, k;
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
    cin>>k;
    findpair(start, k);
}