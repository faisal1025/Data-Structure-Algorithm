//given a length of a binary string n. generate a string that having no any consecutive 
//one i.e(101101) not accepted of length n.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
         void no_consecutive_one(int n, int i, string osf){
             //base case
             if(i == n){
                 cout<<"["+osf+"]"<<endl;
                 return;
             }
             //recursive intution + self work
             if(osf[i-1] != '1'){
                 no_consecutive_one(n, i+1, osf+"1");
             }
             no_consecutive_one(n, i+1, osf+"0");
         }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    Solution obj;
    obj.no_consecutive_one(n, 0, "");
}