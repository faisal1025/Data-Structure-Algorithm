#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*x = NULL, *y = NULL;

typedef struct Node Node;

Node * reverse(Node * head){
    Node *top = NULL;
    Node *nxt = NULL;
    Node *current = head;
    while(current != NULL){
        nxt = current->next;
        current->next = top;
        top = current;
        current = nxt;
    }
    return top;
}

Node * Add_two_numbers(Node *head1, Node *head2){
    head1 = reverse(head1);
    head2 = reverse(head2);
    Node *curr = head1;
    Node *curr2 = head2;
    int x = 0;
    Node *res = NULL;
    Node *head = NULL;
    while(curr!=NULL && curr2!=NULL){
        Node *temp = new Node;
        int ans = curr->data+curr2->data+x;
        temp->data = ans%10;
        temp->next = NULL;
        x = ans/10;
        if(res == NULL){
            res = head = temp;
        }else{
            head->next = temp;
            head = temp;
        }
        curr = curr->next;
        curr2 = curr2->next;
    }
    if(curr!=NULL){
        while(curr!=NULL){
            Node *temp = new Node;
            int ans = curr->data+x;
            temp->data = ans%10;
            temp->next = NULL;
            x = ans/10;
            if(head == NULL){
                head = temp;
            }else{
                head->next = temp;
                head = temp;
            }
            curr = curr->next;
        }
    }else if(curr2!=NULL){
        while(curr2!=NULL){
            Node *temp = new Node;
            int ans = curr2->data+x;
            temp->data = ans%10;
            temp->next = NULL;
            x = ans/10;
            if(head == NULL){
                head = temp;
            }else{
                head->next = temp;
                head = temp;
            }
            curr2 = curr2->next;
        } 
    }
    while(x!=0){
        Node *temp = new Node;
        temp->data = x%10;
        temp ->next = NULL;
        head->next = temp;
        head = temp;
        x = x/10;
    }
    head = reverse(res);
    return head;
}

int main(){
    Node * head = NULL;
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        Node *temp = new Node;
        cin>>temp->data;
        temp->next = NULL;
        if(x == NULL){
            x = head = temp;
        }else{
            head->next = temp;
            head = head->next;
        }
    }

    for(int j = 0; j < m; j++){
        Node *temp = new Node;
        cin>>temp->data;
        temp->next = NULL;
        if(y == NULL){
            y = head = temp;
        }else{
            head->next = temp;
            head = head->next;
        }
    }

    Node *result = Add_two_numbers(x, y);
    while(result!=NULL){
        cout<<result->data;
        result = result->next;
    }
}