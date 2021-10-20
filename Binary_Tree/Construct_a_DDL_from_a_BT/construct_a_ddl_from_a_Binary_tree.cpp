#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;  //pre
    struct Node* right; //next
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void Inorder(Node* root, vector<int> &ans){
    if(root == NULL) return;
    
    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
    
}

Node* createDdl(vector<int> ans){
    Node* start = NULL;
    Node* head = NULL;
    for(int i = 0; i < ans.size(); i++){
        if(start == NULL && i == 0){
            start = head = new Node(ans[i]);
        }
        else{
            Node* temp = new Node(ans[i]);
            head->right = temp;
            temp->left = head;
            head = temp;
        }
    }
    return start;
}
// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        vector<int> ans;
        Inorder(root, ans);
        Node* head = createDdl(ans);
        return head;
    }
};


int main(){
    Node* root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->left->left = new Node(1);
    root1->right->left = new Node(6);
    root1->right->right = new Node(14);
    root1->right->right->left = new Node(13);
    root1->right->left->left = new Node(4);
    root1->right->left->right = new Node(7);
    /*
                8
              /   \
             3     10
           /     /   \
          1     6    14
              /  \   /
             4    7 13

        DDL : 1 3 8 4 6 7 10 13 14
              14 13 10 7 6 4 8 3 1
        
    */
   Solution obj;
   Node * head = obj.bToDLL(root1);
   Node* temp = head;
   Node* last;
   while(temp){
       cout<<temp->data<<" ";
       if(temp->right == NULL){
           last = temp;
       }
       temp = temp->right;
   }
   cout<<"\n";
   while(last){
       cout<<last->data<<" ";
       last = last->left;
   }
}