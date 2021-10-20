#include <iostream>
using namespace std;

void replace_pi(string str, int i, string osf){
    if(i == str.size()){
        cout<<osf<<"\n";
        return;
    }
    string rsf;
    if(str[i] == 'p' && str[i+1] == 'i'){
        rsf = osf+"3.14";
        replace_pi(str, i+2, rsf);
    }
    else{
        rsf = osf+str[i];
        replace_pi(str, i+1, rsf);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin>>str;
    replace_pi(str, 0, "");
    return 0;
}