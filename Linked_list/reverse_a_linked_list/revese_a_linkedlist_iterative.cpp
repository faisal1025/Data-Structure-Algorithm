#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*start = NULL;

typedef struct Node node;

class Reverse{
    private:
    node *pre = NULL;
    node *nxt = NULL;
    public:
    node * reverse_a_list(node * head){
        while(head != NULL){
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        head = pre;
        return head;
    }
};


int main(){
    int n;
    cin>>n;
    node *head = NULL;
    for(int i = 0; i < n; i++){
        node *temp = new node;
        cin>>temp->data;
        temp->next = NULL;
        if(start == NULL){
            head = start = temp;
        }else{
            head->next = temp;
            head = temp;
        }
    }
    Reverse obj;
    node *ans = obj.reverse_a_list(start);
    for(int i = 0; ans!=NULL; i++){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<"\n";

}