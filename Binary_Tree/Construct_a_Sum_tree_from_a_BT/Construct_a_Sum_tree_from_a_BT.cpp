#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void Inorder(Node* node){
    if(!node) return;

    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}

class Solution{
    public:
    void sumTree(Node* node){
        if(!node) return;

        int left = 0;
        int right = 0;
        if(node->left)
            left = node->left->data;
        if(node->right)
            right = node->right->data;
        
        int beforeCall = left+right;
        sumTree(node->left);
        sumTree(node->right);

        if(node->left)
            left = node->left->data;
        if(node->right)
            right = node->right->data;
        
        int afterCall = left+right;
        node->data = beforeCall+afterCall;
        return;
    }
};

int main(){
    int n;
    queue<Node*> q;
    Node* root = nullptr;
    Node* node = nullptr;
    cin>>n;
    while(n--){
        int val;
        cin>>val;
        if(!root){
            root = new Node(val);
            node = root;
            q.push(node);
        }else{
            if(!node->left){
                node->left = new Node(val);
                q.push(node->left);
            }
            else if(!node->right){
                node->right = new Node(val);
                q.push(node->right);
                q.pop();
            }
        }
        node = q.front();     
    }
    Inorder(root);
    Solution obj;
    obj.sumTree(root);
    cout<<"\n";
    Inorder(root);  
}