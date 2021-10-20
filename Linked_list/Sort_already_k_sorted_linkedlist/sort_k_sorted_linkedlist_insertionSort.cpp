
//this is a sort of time complexity O(N.k)

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

//Insertion Sort function to sort in O(N.k)
void insertionSort(Node* head){
    Node *current = head->next;
    while(current!=NULL){
        Node *compare1 = current;
        Node *compare2 = current->prev;
        while(compare2!=NULL && compare2->data>compare1->data){
            swap(compare2->data, compare1->data);
            compare1 = compare2;
            compare2 = compare2->prev;
        }
        current = current->next;
    }
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
    insertionSort(start);
    Node * result = start;
    while(result!=NULL)
    {
        cout<<result->data<<" ";
        result = result->next;
    }
    
}