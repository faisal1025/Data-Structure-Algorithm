#include <iostream>

using namespace std;

void tower_of_hanoi(int n, char rod_from, char rod_to, char helping_rod){
    //base case
    if(n == 1){
        cout<<"move 1 from "<<rod_from<<" to "<<rod_to<<"\n";
        return;
    }
    tower_of_hanoi(n-1, rod_from, helping_rod, rod_to);  //recursive call to place n-1 sticks start rod to helping rod 
    cout<<"move "<<n<<" from "<<rod_from<<" to "<<rod_to<<"\n"; //self work
    tower_of_hanoi(n-1, helping_rod, rod_to, rod_from);  //recursive call to place n-1 sticks helping rod to target rod
}

int main(){
    tower_of_hanoi(4, 'A', 'C', 'B');
}