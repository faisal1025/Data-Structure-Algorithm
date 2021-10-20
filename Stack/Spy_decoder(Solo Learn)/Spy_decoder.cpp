#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s, o = "";
    getline(cin, s);
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ' || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        st.push(s[i]);
    }
    while(!st.empty()){
        o += st.top();
        st.pop();
    }
    cout<<o;
    return 0;
    // t`a=e+r8g 9e78r3a4 u^o%y*
}