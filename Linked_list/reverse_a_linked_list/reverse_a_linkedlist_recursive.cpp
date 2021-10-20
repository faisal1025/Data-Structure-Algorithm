#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
}*start = NULL;

typedef struct Node node;

class Reverse{
    private:
        node * pre = NULL;
        node * nxt = NULL;
    public:
        node* reverse_a_list(node * head){
            if(head == NULL){
                head = pre;
                return head;
            }
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
            return reverse_a_list(head);
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
            start = head = temp;
        }else{
            head->next = temp;
            head = temp;
        }
    }
    Reverse obj;
    node *ans = obj.reverse_a_list(start);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
}
