#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
}*start = NULL;

//Print a linkedlist
void printResult(Node* head){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    return;
}

Node* segregate(Node *head) {
        if(head == NULL) return NULL;
        
        Node* current = head;
        Node* zero_head = head;
        while(zero_head!=NULL && zero_head->data != 0){
            zero_head = zero_head->next;
        }
        if(zero_head!=NULL){
            swap(zero_head->data, current->data);
            zero_head = current;
            current = current->next;
        }
        
        Node* one_head = head;
        while(one_head!=NULL && one_head->data != 1){
            one_head = one_head->next;
        }
        if(one_head!=NULL){
            swap(one_head->data, current->data);
            one_head = current;
            current = current->next;
        }
        
        Node* two_head = head;
        while(two_head!=NULL && two_head->data != 2){
            two_head = two_head->next;
        }
        if(two_head!=NULL){
            swap(two_head->data, current->data);
            two_head = current;
            current = current->next;
        }
        Node* zero = zero_head;
        Node* one = one_head;
        Node* two = two_head;
        while(current != NULL){
            if(current->data == 0){
                zero->next = current;
                zero = zero->next;
            }else if(current->data == 1){
                one->next = current;
                one = one->next;
            }else{
                two->next = current;
                two = two->next;
            }
            current = current->next;
        }
        if(zero_head==NULL && one_head!=NULL && two_head!=NULL){
            one->next = two_head;
            two->next = NULL;
        }else if(zero_head!=NULL && one_head==NULL && two_head!=NULL){
            zero->next = two_head;
            two->next = NULL;
        }else if(zero_head!=NULL && one_head!=NULL && two_head==NULL){
            zero->next = one_head;
            one->next = NULL;
        }else if(zero_head!=NULL && one_head==NULL && two_head==NULL){
            return zero_head;
        }else if(zero_head==NULL && one_head!=NULL && two_head==NULL){
            return one_head;
        }else if(zero_head==NULL && one_head==NULL && two_head!=NULL){
            return two_head;
        }else{
            zero->next = one_head;
            one->next = two_head;
            two->next = NULL;
        }
        return head;
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
            head = temp;
        }
    }
    Node *res = segregate(start);
    printResult(res);
    return 0;
}