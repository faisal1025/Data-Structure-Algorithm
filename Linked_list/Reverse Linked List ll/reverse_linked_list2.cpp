#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        val = 0;
        next = NULL;
    }
    ListNode(int x){
        val = x;
        next = NULL;
    }
}* start = NULL;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        
        
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* st = dummyNode;
        
        for(int i = 0; i < left-1; i++){
            st = st->next;
        }
        if(!st->next) return head;
        
        ListNode* en = dummyNode;
        
        for(int j = 0; j < right+1; j++){
            en = en->next;
        }
        
        ListNode* pre = st->next;
        ListNode* node = st->next->next;
        ListNode* nxt;
        pre->next = en;
        
        while(node != en){
            nxt = node->next;
            node->next = pre;
            pre = node;
            node = nxt;
        }
        st->next = pre;
        
        return dummyNode->next;
        
    }
};

int main(){
    int n;
    cin>>n;
    ListNode* head = NULL;
    while(n--){
        int data;
        cin>>data;
        ListNode* temp = new ListNode(data);
        if(start == NULL){
            start = temp;
            head = temp;
        }else{
            head->next = temp;
            head = head->next;
        }
    }
    int left, right;
    cin>>left>>right;

    Solution obj;
    ListNode* sol = obj.reverseBetween(start, left, right);
    while(sol != NULL){
        cout<<sol->val;
        sol = sol->next;
    }
    return 0;
}