#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
}*start = NULL;

//print linkedlist
void printResult(Node* head){
    Node* current = head;
    while(current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}

//Sort k-sorted linkedlist in O(N * log k)
void heapSort(Node *head, int k){
    Node * current = head;
    Node * result = head;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= k+1; ++i){
        pq.push(current->data);
        current = current->next;
    }
    while(current!=NULL){
        result->data = pq.top();
        pq.pop();
        pq.push(current->data);
        current = current->next;
        result = result->next;
    }
    while (!pq.empty() && result != NULL)
    {
        result->data = pq.top();
        pq.pop();
        result = result->next;   
    }

}

int main(){
    int n;
    cin>>n;
    Node *head = NULL;
    for(int i = 0; i < n; ++i){
        int x;
        cin>>x;
        Node *temp = new Node(x);
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
    heapSort(start, k);
    printResult(start);
    return 0;
}