#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//vector to store inorder sequence of each bst
vector<int> ans;

//solution
class Solution {
    public:
    vector<int> Inorder (Node* root){
    
        if(root->left) Inorder(root->left);
        ans.push_back(root->data);
        if(root->right) Inorder(root->right);
        return ans;
    }

    bool isBST(Node* root) 
    {
        ans.clear();
        unordered_map<int, int> ump;
        if(!root) return false;
        
        vector<int> inorder;
        inorder = Inorder(root);
        for(int i = 0; i < inorder.size(); i++){
            if(ump[inorder[i]] > 0){
                return false;
            }
            ump[inorder[i]]++; 
        }
        if(is_sorted(inorder.begin(), inorder.end()))
            return true;
        else
            return false;
    }

};
// creating BST
Node* createBst(Node*root, int val){
    if(root == NULL){
        root = new Node(val);
    }
    else if(val <= root->data){
        root->left = createBst(root->left, val);
    }
    else{
        root->right = createBst(root->right, val);
    }
    return root;
}
// main function
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        Node* root = NULL;
        cin>>n;
        for(int i = 0 ; i < n; i++){
            int val;
            cin>>val;
            root = createBst(root, val);
        }
        Solution obj;
        cout<<obj.isBST(root)<<endl;
    }
}