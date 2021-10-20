//current position is 1 from 1 enter any number to reach. From each position it can
//jump either from 1 step to 6 steps (6 options from each position = 6 calls) 

#include<bits/stdc++.h>
using namespace std;

void dice_jump (int i, int n, string osf){
    //base case 
    if(i > n)
        return;
    if(i == n-1){
        cout<<osf<<"\n";
        return;
    }

    //recursive intution and self work
    dice_jump (i+1, n, osf+"1"+"->");
    dice_jump (i+2, n, osf+"2"+"->");
    dice_jump (i+3, n, osf+"3"+"->");
    dice_jump (i+4, n, osf+"4"+"->");
    dice_jump (i+5, n, osf+"5"+"->");
    dice_jump (i+6, n, osf+"6"+"->");
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    dice_jump(0, n, "");
}