#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
}* start = NULL;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode* curr = head;
        int sz = 0;
        while(curr){
            sz++;
            curr = curr->next;
        }
        
        curr = head;
        if(sz == 1) {
            TreeNode* root = new TreeNode(curr->val);
            return root;
        }
        for(int i = 0; i < (sz/2)-1; i++){
            curr = curr->next;
        }
        ListNode* mid = curr->next;
        curr->next = NULL;
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};

void inorderPrint(TreeNode* root, vector<string> &ans){
    if(!root) {
        return;
    }
    inorderPrint(root->left, ans);
    ans.push_back(to_string(root->val));
    inorderPrint(root->right, ans);
}

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

    Solution obj;
    TreeNode* root = obj.sortedListToBST(start);
    vector<string> ans;
    inorderPrint(root, ans);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}