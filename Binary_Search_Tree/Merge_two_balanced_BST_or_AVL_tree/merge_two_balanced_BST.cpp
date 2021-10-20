#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Create BST
Node* createBst(Node * root, int val){
    if(!root) {
        root = new Node(val);
    }
    else if(val <= root->data){
        root->left = createBst(root->left, val);
    }
    else{
        root->right = createBst(root->right, val);
    }
    return root ;
}

int i;
void inorderList(Node* root, int arr[]){
    if(!root) return ;

    inorderList(root->left, arr);
    arr[i++] = root->data;
    inorderList(root->right, arr);
}

//merging two inorder list which is sorted in a bst 
int arr[100];
int * mergeList(int arr1[], int arr2[], int n, int m){  
    static int i = 0;
    static int j = 0;
    static int z = 0;
    if(i == n){
        for(; j < m; j++){
            arr[z++] = arr2[j];
        }
        return arr;
    }
    else if(j == m){
        for(; i < n; i++){
            arr[z++] = arr1[i];
        }
        return arr;
    }

    if(arr1[i] <= arr2[j]){
        arr[z++] = arr1[i++];
    }else{
        arr[z++] = arr2[j++];
    }
    return mergeList(arr1, arr2, n, m);
}

//Creating a balanced binary search tree from a inorder array
Node*  mergedBst(Node* root, int arr3[], int start, int end){
    static int i = 0;
    if(start > end){
        return NULL;
    }
    int mid = (start+end)/2;
    root = new Node(arr3[mid]);
    if(start == end){
        return root;
    }
    root->left = mergedBst(root->left, arr3, start, mid-1);
    root->right = mergedBst(root->right, arr3, mid+1, end);
    return root;

}

//for printing inorder of BST 
void printInorder(Node* root){
    if(root == NULL) return ;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

int main(){
    int n, m;
    cin>>n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = createBst(root, val);
    }
    cin>>m;
    Node* root1 = NULL;
    for(int i = 0; i < m; i++){
        int val;
        cin >> val;
        root1 = createBst(root1, val);
    }
    int arr1[n];
    int arr2[m];
    i = 0;
    inorderList(root, arr1);
    i = 0;
    inorderList(root1, arr2);
    cout<<"First BST inorder list- ";
    for(int i = 0; i < n; i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"Second BST inorder list- ";
    for(int i = 0; i < m; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    int *arr3 = mergeList(arr1, arr2, n, m);
    cout<<"After merging both BST inorder list in sorted fashion- ";
    for(int i = 0; i < n+m; i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    Node* res = NULL;
    //creating BST from a sorted inorder list arr3 to produce a merged BST of two BST
    res = mergedBst(res, arr3, 0, n+m-1);
    cout<<"inorder print of merged BST must be same as arr3 list - ";
    printInorder(res);

}