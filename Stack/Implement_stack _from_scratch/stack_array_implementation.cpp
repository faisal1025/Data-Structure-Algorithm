#include <iostream>
#define MAXSIZE 1000
using namespace std;

class stack{
    private:
        int count;
        int len = MAXSIZE;
        int arr[MAXSIZE];
        int top;
    public:
        stack(){
            len = MAXSIZE;
            top = -1;
            count = 0;
        }
        
        //to check is it empty
        bool isempty(){
            return top == -1;
        }

        //to check is it full
        bool isfull(){
            return top == len-1;
        }

        //to insert element in stack
        void push(int ele){
            arr[++top] = ele;
            count++;
        }

        //to return the top element
        int peak(){
            return arr[top];
        }

        //to remove an element
        int pop(){
            count--;
            return arr[top--];
        }

        int size(){
            return count;
        }

};

int main(){
    stack st;
    if(st.isempty()){
        st.push(36);
        st.push(24);
        st.push(12);
        st.push(18);
        st.push(20);
        st.push(21);
        st.push(100);
    }
    st.pop();
    st.pop();
    cout<<st.peak()<<"\n";
    cout<<st.size();

    return 0;
}