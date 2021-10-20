//write a function to reverse a string eg. noobi -> iboon

#include<iostream>

using namespace std;

//this is also a polymorphism function overloading two function of same name but
//but different parameter.

class solution{
    public:
    string reverse(string str){
        if(str.empty()){
            return "";
        }
        string ans = reverse(str.substr(1));
        return ans+str[0];
    }
    
    string reverse(string str, string osf){
        if(str.empty()){
            return osf;
        }
        return reverse(str.substr(1), str[0]+osf);
    }
};

int main(){
    string str;
    cin>>str;
    solution obj;
    cout<<obj.reverse(str)<<"\t";
    cout<<obj.reverse(str, "");
}