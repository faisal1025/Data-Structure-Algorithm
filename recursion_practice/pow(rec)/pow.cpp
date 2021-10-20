#include <bits/stdc++.h>

using namespace std;

class power{
    public:
    int pow(int x, int n, int count){
        //base condition
        if (count == n){
            return 1;
        }
        //recursive intution
        return x * pow(x, n, count+1);
    }
};

int main(){
    power p;
    int X, n, ans;
    cin>>X>>n;
    ans = p.pow(X, n, 0);
    cout<<ans;

}