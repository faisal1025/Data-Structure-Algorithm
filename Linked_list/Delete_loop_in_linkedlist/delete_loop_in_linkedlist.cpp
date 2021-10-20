#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*start = NULL;

typedef struct Node node;

void loopmaker(node *tail, int pos){
    if(pos == 0)
        return;
    node *t = start;
    for(int i = 1; i < pos; i++){
        t = t->next;
    }
    tail->next = t;
}

void detect_delete_loop(node * head){
    bool found = false;
        Node *slow = head;
        Node *fast = head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                found = true;
                break;
            }
        }
        if(found){
            if(slow == head && fast == head){
                while(fast->next != slow){
                    fast = fast->next;
                }
            }else{
                slow = head;
                while(fast->next != slow->next){
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            fast->next = NULL;
        }else{
            return;
        }
}

int main(){
    int n, pos;
    cin>>n;
    node *head = NULL;
    for(int i = 0; i < n; i++){
        node *temp = new node;
        cin>>temp->data;
        temp->next = NULL;
        if(start == NULL){
            start = head = temp;
        }else{
            head->next = temp;
            head = temp;
        }
    }
    cin>>pos;
    loopmaker(head, pos);
    detect_delete_loop(start);
    node *temp = start;
    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }
}