// Fabio Motta,     15 November 2019
// Student ID: 9312820199
// Algorithms and Problem Solving Homework #1
// Exercise 2: Merge Slides in optimal manner (while keeping order)

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void Parenthesization(int i, int j, int n, int **p, int *s) {
    // This function finds the optimal parenthesization and inserts parenthesis into the output
    if (i == j) {
        cout << *(s + i);
        return;
    } else {
        cout << "(";
        Parenthesization(i, *(*(p + i) + j), n, p, s);
        cout << ",";
        Parenthesization(*(*(p + i) + j) + 1, j, n, p, s);
        cout << ")";
    }
}


void MatrixChainOrder() {

    //input
    while(true){

        //user input
        cout << "Please enter your slides : ";
        string input;
        getline(cin, input);

        if(input.empty()){
            cout << "Please input something!";
            break;
        }

        // check for inputs (ASCII) which are not numbers and terminate program if there are any
        for (char &c : input) {
            if (c < 32) {
                cout << "not Number!";
                exit(EXIT_FAILURE);
            } else if (c >= 33 && c<= 47) {
                cout << "not Number!";
                exit(EXIT_FAILURE);
            } else if (c >= 58){
                cout << "not Number!";
                exit(EXIT_FAILURE);
            }
        }

        // separate input string into numbers and store these into a vector
        // Procedure: traverse through all chars, if current one is a space (or tab), we have reached end of a num.
        // store current word and reset to empty, else we append current char to num.

        // Replace Tab for Space if found, this avoids having a problem if input starts with '\t'
        replace(input.begin(), input.end(), '\t', ' ');

        istringstream ss(input);
        string token;

        vector<string> inputVector;
        int counter = 0;
        while(getline(ss, token, ' ' )){   // get a whole line
            stringstream ss(token);
            while(getline(ss, token, '\t')){
                inputVector.push_back(token);
                //cout << token << '\n';    // print in a new line each of the inputs
                counter++;
            }
        }

        // insert all elements of vector into array "slides" and convert to int
        // & terminate program if elements are not numbers
        int* slides = NULL; // pointer to int, initialize to nothing. Remember to late delete this variable!!
        slides = new int [counter]; // Allocate n ints and save pointer in array
        // initialize array "slides" [0, ..., counter-1]
        for( int i = 0; i < counter; i++ ){
            try{
                slides[i] = stoi(inputVector[i]); // convert string from vector to int and insert into array
            }catch(...){
                cout << "Input only numbers!";
                exit(EXIT_FAILURE); //if elements in vector are not numbers the program is terminated
            }
        }

        // create matrix to hold values of additions
        int n = counter;
        int m[n][n];

        // "s" stores the optimal 'k' for tracing the optimal solution
        // array 's' is also used in Parenthesization(). Hence, the use of pointers to use the array
        // as argument for function and asses the parenthesis position to display the optimal parenthesization.
        int **s = new int *[n];
        for (int i = 0; i < n; i++) {
            s[i] = new int[n];
        }

        // cost for 1 slide is null (nothing to merge) --> fill left diagonal with zeros
        for(int i = 0; i < n; i++){
            m[i][i] = 0;
        }

        int min, j, q;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                j = i + len - 1;
                m[i][j] = INT_MAX; // maximum possible value for int

                // Somma degli elementi di A (array)(da i a j)
                int sum = 0;
                for(int z = i; z <= j; z++){
                    sum = sum + slides[z];
                }

                for (int k = i; k <= j - 1; k++) {
                    q = m[i][k] + m[k + 1][j] + sum;    // // q = cost of additions
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
        // Print out minimum cost
        cout << "Minimum cost is " << m[0][n - 1] << '\n';
        // Print optimal parenthesization for all inputs that contain more than one set of "slides"
        if (n > 1) {
            cout << "Optimal parenthesization is ";
            Parenthesization(0, n - 1, n, s, slides);
        }
        cout << endl << '\n';   //leaves a blank line before asking for new input
    }
}


int main(){
    MatrixChainOrder();
    return 0;
}