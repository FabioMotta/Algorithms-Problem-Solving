//  Autor: Fabio Motta
//  Date: 26.11.2019
//  Program which takes an (n, m) matrix (dynamic 2D array) as input (user defined) and returns transpose of it

#include <iostream>
#include <sstream>
using namespace std;

void transpose(){
    string a, b;
    int r, c;   // Variables to store size of rows and cols

    // User input (size)
    cout << "Enter number of rows: ";
    cin >> a;
    cout << "Enter number of columns: ";
    cin >> b;
    // Ensure that input is integer (if not, assign 0)
    if(!(istringstream(a) >> r)) r = 0;
    if(!(istringstream(b) >> c)) c = 0;

    // To create a matrix which can accept a dynamic input ("dynamic 2D matrix") we have to create a dynamic
    // array of size r (for rows) which at each index contains a further dynamic array of size c (for cols).
    // A dynamic array has to be created through a pointer to an array. In this case, since we are going to store
    // an array in an array (matrix), we need two pointers (pointer to a pointer). one to point at the first array
    // and the other for the array within the array.
    int** matrix = NULL; // Each element will be a pointer to an array. Initialize to nothing.
    matrix = new int*[r]; // Allocate r and c ints and save pointer in matrix
    // Alternative declaration of main array:     int** matrix = new int*[n];
    for(int i = 0; i < c; i++){
        matrix[i] = new int[c];     // Declare new pointer to array for each index of the main array
    }

    // User input (matrix values) --> initialize matrix
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << "Value at position (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }

    //Print Matrix
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;   // Start printing new line when inner loop is done
    }
    cout << endl;   // Leaves space between the two matrices

    // Transpose matrix (overwrite value to which pointer points. DOES NOT store values in new matrix
    int z = 0;
    for(int i = 0; i < (r); i++){
        for(int j = i + 1; j < c; j++){
            z = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = z;
        }
    }

    // Print array
    for(int i = 0; i < (r); i++){
        for(int j = 0; j < c; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;   // Start printing new line when inner loop is done
    }

    // Matrix has to be deleted!    Memory space filled by the pointer can be fred up.
    for(int i = 0; i < c; i++){ // Delete arrays in array
        delete matrix[i];
    }
    delete matrix;  // Delete array
}

int main(){
    transpose();
}