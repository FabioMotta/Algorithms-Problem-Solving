// Find LIS, only length! Not actual values

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// Function which has a string as input and returns a string
// String is a array of characters!! Use it as an array
// In c++, characters are comparable! b is > than a.

int lis(string input){ 
  
  int n = input.length()-1;  //integer because dimension

  // array which holds the lenght of lis for each index, has to be integer because holds sizes. 
  int* array = NULL; // pointer to int, initialize to nothing. Remember to late delete this variable!! 
  array = new int [n]; // Allocate n ints and save pointer in array

  //initialize array with all its element to 1:
  for(int z =0; z < n; z++){
    array[z] = 1; //Initialized with 1 because each element of the array can be treated as a subproblem of size 1
  }


  int max = 1;  //variable to determine which value of "array" is the longest
  //string output[n] = {};  //array which in each index holds the string for the longest sequence up to that index
  //string longest = {};  // string to hold the currently logest increasing subsequence


  // double for loop. First one determines the index to which all previous values are compared. Second one goes through all 
  // values up to j.
  for(int j = 1; j <= n; j++){ // j is compare to prevoius values, that is why it has to start at 1 and not at 0
    
    for(int i = 0; i < j; i++){
      
      if(input[i] < input[j]){  //<= makes it longest non-decreasing subsequence
        array[j] = array[i] + 1;  // if condition is fulfilled increase the legth of the subsequence up to that point
        //output[j] = output[j] + input[i]; // increase the output string at j-th position by element of input[i]
      }

      if (array[j] > max){ // keep track of currently longest increasing subsequence
        max = array[j];
      }
    }
  }
  //output[j] = output[j] + input[j];    // add j-th elem. (input[j]) to output string in j-th position

  //string resultingLIS = output[max];  //return the string with max length (LIS)

  //When done, free memory pointed at by "array"
  delete [] array;
  array = NULL; // Clear a to prevent using invalid memory reference.

  return max;
  
}  

int main() {

  string inputarray = "1204" ;
  int result = lis(inputarray);

  
  cout << result << endl;
  return 0;
}