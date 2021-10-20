#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void Inorder(Node* root){
    if(!root) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

vector<int> inorderprint(Node* root){
    static vector<int> ans;
    if(!root) return ans;

    inorderprint(root->left);
    ans.push_back(root->data);
    inorderprint(root->right);
    return ans;
}

Node * createBST(Node* node, int val){
    if(!node){
        node = new Node(val);
    }
    else if(val <= node->data){
        node->left = createBST(node->left, val);
    }
    else{
        node->right = createBST(node->right, val);
    }
    return node;
}

void binarySearch(vector<int> inorder, int x){
    int i = 1;
    int j = inorder.size()-2;
    
    while(i <= j){
        int mid = (i+j)/2;
        if(inorder[mid] == x){
            cout<<inorder[mid-1]<<" "<<inorder[mid+1];
            return;
        }
        else if(x < inorder[mid]){
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    cout<<inorder[j]<<" "<<inorder[i];
    return;
}

void printBothSide(Node* root, int x){
    vector<int> inorder = inorderprint(root);
    inorder.insert(inorder.begin(), -1);
    inorder.insert(inorder.end(), -1);
    for(int i = 0; i < inorder.size(); i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;
    binarySearch(inorder, x);
}

int main(){
    int n;
    Node* root = NULL;
    cin>>n;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = createBST(root, val);
    }
    /*
            3
          /   \
         1     4
       /   \    \
      N     2    5
       
    */
    Inorder(root);
    cout<<endl;
    int x;
    cin>>x;
    printBothSide(root, x);
    cout<<endl;
}