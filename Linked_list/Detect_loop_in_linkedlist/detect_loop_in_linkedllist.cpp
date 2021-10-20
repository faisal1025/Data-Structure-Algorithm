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

//Detecting loop in linkedlist by using hashmap tc = O(N) sc = O(N)
bool is_loop(node *head){
    unordered_map<node*, node*>add;
        while(head!=NULL){
            if(add.find(head->next) != add.end()){
                return true;
            }
            add[head] = head->next;
            head = head->next;
        }
        return false;
}

//Floyd's cycle finding algorithm is doesn't require any extra space tc = O(N) 
bool is_loop_efficient(node *head){
    node *slow = head;
    node *fast = head;
        while(slow!=NULL && fast != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
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
    if(is_loop_efficient(start))
        cout<<"YES";
    else{
        cout<<"NO";
    }
}