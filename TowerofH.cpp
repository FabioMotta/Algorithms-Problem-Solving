// C++ recursive function to solve tower of hanoi puzzle  

#include <iostream> 
using namespace std; 
  
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){ // A, C, B

    if(n == 1){
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;    // from A to C
        return;
    }
    
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);   // move n-1 disks from A to B using C
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;

    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);   // move n-1 disks from B to C using A

}  
  
// main
int main(){
    
    int n = 3; // Number of disks  
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods  
    return 0;  
}  