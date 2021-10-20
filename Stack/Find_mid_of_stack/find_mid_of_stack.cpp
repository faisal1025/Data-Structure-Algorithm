#include<iostream>

using namespace std;

struct Node{
    struct Node *pre;
    int data;
    struct Node *next;
}*top = NULL;

typedef struct Node node;

class stack{
    private:
        node *mid;
        node *temp;
        int count;
    public:
        stack(){
            count = 0;
            mid = NULL;
            temp = NULL;
        }

        //to insert and maintaining mid 
        void push(int val){
            temp = new node;
            temp->data = val;
            temp->pre = top;
            temp->next = NULL;
            
            if(top == NULL){
                mid = top = temp;
                count++;
            }else{
                top->next = temp;
                top = temp;
                count++;
                if(count % 2 == 0){
                    mid = mid->next;
                }
            }
        }

        //to remove and maintain mid
        int pop(){
            temp = top;
            int data = temp->data;
            top = top->pre;
            top->next = NULL;
            count--;
            if(count % 2 != 0){
                mid = mid->pre;
            }
            delete temp;

            return data;
        }

        //to return mid
        int find_mid(){
            if(mid == NULL)
                return -1;
            return mid->data;
        }

        //to delete mid element and maintaining mid
        void delete_mid(){
            if(mid == NULL){
                cout<<"stack is empty ....lol"<<endl;
                return;
            }
            if(mid->next == NULL){
                temp = mid;
                mid = mid->pre;
                top = top->pre;
                if (top != NULL)
                    top->next = NULL;
                delete temp;
                count--;
            }else{
                temp = mid;
                node *right = mid->next;
                node *left = mid->pre;
                right->pre = left;
                left->next = right;
                count--;
                if(count % 2 != 0){  //if odd number of element left after removing mid
                    mid = mid->pre;
                    delete temp;
                }else{               //if even number of element left after removing mid
                    mid = mid->next;
                    delete temp;
                }
            }
        }

        //to see size of stack
        int size(){
            return count;
        }

};

int main(){
    int n, x;
    stack st;
    bool run = true;
    while(run){
        cout<<"Press 1 to push operation in stack \n";
        cout<<"Press 2 to pop operation in stack \n";
        cout<<"press 3 to show the mid element \n";
        cout<<"Press 4 to delete mid element from the stack \n";
        cout<<"Press 5 to see size of the element \n";
        cout<<"Press 0 to exit \n";
        cout<<"Enter your choice \n";
        cin>>n;

        if(n == 1){
            cout<<"Enter number: ";
            cin>>x;
            st.push(x);
        }

        if(n == 2){
            cout<<"Your poped element is "<<st.pop()<<endl;
        }

        if(n == 3){
            cout<<"The middle element is "<<st.find_mid()<<endl;
        }

        if(n == 4){
            st.delete_mid();
            if(st.size())
                cout<<"Middle element removed successfully"<<endl;
        }

        if(n == 5){
            cout<<st.size();
        }

        if(n == 0){
            run = false;
        }
    }

    return 0;
}