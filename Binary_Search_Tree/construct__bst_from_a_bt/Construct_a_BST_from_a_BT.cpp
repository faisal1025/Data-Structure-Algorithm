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

vector<int> inorderList(Node* root){
    static vector<int> ans;
    if(!root)  return ans;

    inorderList(root->left);
    ans.push_back(root->data);
    inorderList(root->right);

    return ans;
}

void makeBstFromInorder(Node* root, vector<int> res){
    static int i = 0;
    if(!root) return ;
    makeBstFromInorder(root->left, res);
    if(res[i] != root->data){
        root->data = res[i];
        i++;
    }
    makeBstFromInorder(root->right, res);
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

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
    vector<int> result = inorderList(root);
    
    sort(result.begin(), result.end());
    
    makeBstFromInorder(root, result);

    inorder(root);


    
}
