void swap(Node* root, Node* pre){
    int temp = root->data;
    root->data = pre->data;
    pre->data = temp;
}