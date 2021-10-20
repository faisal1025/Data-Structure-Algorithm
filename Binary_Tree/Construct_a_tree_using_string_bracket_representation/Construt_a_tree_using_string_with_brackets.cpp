#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }  
};

void preorder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* constructTree(string s){
    stack<Node*>st;
    Node* root = new Node(s[0]-'0');
    Node* ans = root;
    st.push(root);
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '('){
            if(root->left){
                root->right = new Node(s[i+1]-'0');
                st.push(root->right);
            }
            else{
                root->left = new Node(s[i+1]-'0');
                st.push(root->left);
            }
        }else if(s[i] == ')'){
            st.pop();
        }
        root = st.top();
    }
    return ans;
}

int main(){
    string s;
    Node* root = NULL;
    cin>>s;
    if(s[0] != ')' and s[0] != '(')
        root = constructTree(s);
        
    preorder(root);
}