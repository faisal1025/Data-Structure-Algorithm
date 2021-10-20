#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//Create BST 
Node* createBst(Node* root, int val){
    if(!root) {
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

//function that gives the inorder list of the a binary search tree
void inorderList(Node* root, int arr[]){
    static int i = 0;
    if(!root) return;

    inorderList(root->left, arr);
    arr[i++] = root->data;
    inorderList(root->right, arr);
}

//Approch - if we get a inorder list of a unbalanced tree mid element can be best root 
//that gives smallest height of the tree
Node* balancedIt(int arr[], int start, int end){
    if(start > end) return NULL;

    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);
    if(start == end)
        return root;

    root->left = balancedIt(arr, start, mid-1);
    root->right = balancedIt(arr, mid+1, end);

    return root;
}

//function to check if a tree is balanced or not
bool balanced;
int  checkIsBalanced(Node* root){
    if(root == NULL) return 0 ;

    int ltree = checkIsBalanced(root->left);
    int rtree = checkIsBalanced(root->right);

    if(ltree-rtree != 0 && ltree-rtree != 1 && ltree-rtree != -1)
        balanced = false;

    return max(ltree, rtree)+1;
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i = 0 ; i < n; i++){
        int val;
        cin>>val;
        root = createBst(root, val);
    }
    int arr[n];
    inorderList(root, arr);
    balanced = true;
    checkIsBalanced(root);
    if(balanced)
        cout<<"yes ";
    else
        cout<<"no ";
    cout<<endl;

    Node* root1 = balancedIt(arr, 0, n-1);
    balanced = true;
    checkIsBalanced(root1);
    if(balanced)
        cout<<"yes ";
    else
        cout<<"no ";
}