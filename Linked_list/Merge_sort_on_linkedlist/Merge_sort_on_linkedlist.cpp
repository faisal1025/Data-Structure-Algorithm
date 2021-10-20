#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
}*x = NULL;

typedef struct Node Node;

Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
}

//merge function 
void merge(Node **head, Node **head2){
    Node *current = *head;
    Node *current1 = *head2;
    Node *res = new Node(-1);
    Node *ans = res;
    while(current!=NULL && current1!=NULL){
        
        if(current->data <= current1->data){
            res->next = current;
            current = current->next;
        }
        else if(current->data > current1->data){
            res->next = current1;
            current1 = current1->next;
        }
        res = res->next;
    }

    if(current!=NULL){
        while(current!=NULL){
            res->next = current;
            current = current->next;
            res = res->next;
        }
    }else if (current1 != NULL){
        while(current1!= NULL){
            res->next = current1;
            current1 = current1->next;
            res = res->next;
        }
    }
    *head =  ans->next;
}

//this is a merge function recursively
Node * mergeRecursive(Node* first, Node* second){
    Node * answer = NULL;
    if (!first){
        return second;
    }else if(!second){
        return first;
    }

    if(first->data<=second->data){
        answer = first;
        answer->next = mergeRecursive(first->next, second);
    }else if(first->data>second->data){
        answer = second;
        answer->next = mergeRecursive(first, second->next);
    }
    return answer;
}

void mergeSort(Node** head) {
        Node* current = *head;
        if(current->next != NULL){
            Node* mid = middleNode(current);
            Node *current1 = mid->next;
            mid->next = NULL;
            mergeSort(&current);
            mergeSort(&current1);
            current = mergeRecursive(current, current1);
        }
        *head = current;
    }

int main(){
    Node * head = NULL;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        Node *temp = new Node(val);
        temp->next = NULL;
        if(x == NULL){
            x = head = temp;
        }else{
            head->next = temp;
            head = head->next;
        }
    }
    mergeSort(&x);
    Node* result = x;
    while(result!=NULL){
        cout<<result->data<<" ";
        result = result->next;
    }

}
