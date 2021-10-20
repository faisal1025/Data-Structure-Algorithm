//write a progrma that move all 'x' char present in string to the right
#include<bits/stdc++.h>

using namespace std;

class solution{
    public:
    string move_x(string str){
        if(str.empty()){
            return "";
        }
        string ans = move_x(str.substr(1));
        if(str[0] == 'x'){
            return ans+str[0];
        }
        else{
            return str[0]+ans;
        }
    }

    string move_x(string str, string osf){
        //base case
        if (str.empty()){
            return osf;
        }
        int last_index = str.size()-1;
        if(str[last_index] == 'x'){
            return move_x(str.substr(0, last_index), osf+str[last_index]);
        }
        else{
            return move_x(str.substr(0, last_index), str[last_index]+osf);
        }
    }
};

int main(){
    string str;
    solution obj;
    cin>>str;
    cout<<obj.move_x(str)<<endl;
    cout<<obj.move_x(str, "");
}