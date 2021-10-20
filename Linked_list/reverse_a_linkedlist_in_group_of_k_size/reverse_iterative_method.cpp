#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*start = NULL;

typedef struct Node node;

class Reverse {
    public:
        node * reverse_in_part(node * head, int k){
            node * top = NULL;
            node * nxt = NULL;
            node * current = NULL;
            if(head == NULL){
                return top;
            }
            current = head;
            for(int i = 0; current != NULL && i < k; i++){
                nxt = current->next;
                current->next = top;
                top = current;
                current = nxt;
            }
            head->next = reverse_in_part(nxt, k);
            return top;
            
        }
};
int main(){
    int n, k;
    cin>>n>>k;
    node *head = NULL;
    for(int i = 0; i <n; i++){
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
    node *ans = obj.reverse_in_part(start, k);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
}