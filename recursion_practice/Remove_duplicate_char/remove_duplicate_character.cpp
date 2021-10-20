//write program to remove all the duplicate character from a string 
//eg. aaabbbbcccc = abc

#include<bits/stdc++.h>

using namespace std;

class solution{
    public:
    string remove_duplicate1(string str){
        if(str.empty()){
            return "";
        }
        string ans = remove_duplicate1(str.substr(1));
        if(str[0] == ans[0]){
            return ans;
        }
        else{
            return str[0]+ans;
        }
    }
};

class solution2: public solution{
    public:
    string remove_duplicate(string str, string osf){
        if(str.empty()){
            return osf;
        }
        if(osf[osf.size()-1] == str[0]){
            return remove_duplicate(str.substr(1), osf);
        }
        else{
            return remove_duplicate(str.substr(1), osf+str[0]);
        }
    }
};

int main(){
    string str;
    cin>> str;
    solution2 obj;
    cout<<obj.remove_duplicate1(str)<<"\n";
}
