// Fabio Motta,     15 November 2019
// Student ID: 9312820199
// Algorithms and Problem Solving Homework #1
// Exercise 1: Find Longest Increasing Subsequence (LIS)

#include <vector>
#include <iostream>
using namespace std;

void longestIncreasingSubsequence(){

    while(true){
        cout << "Please enter your sequence: ";
        //user input
        string input;
        getline(cin, input);

        if(input.empty()){
            cout << "Please enter something!";
            break;
        }

        // Trim input after first blank
        int blank_pos = -1; // Position of blank, set to -1 so that it is not existing in case there are no blanks
        int str_pos = -1;
        for (char &c : input) { //traverse input string
            str_pos = str_pos + 1;
            if (isspace(c)) { // when blank loop stops.
                blank_pos = str_pos;
                break;
            }
        }
        // Only consider inputs up to first blank
        if (blank_pos > 0) {
            input.resize(blank_pos);
        } else if (blank_pos == 0) {
            continue;
        }

        // vector LIS(i) stores the longest increasing subsequence of subproblems (all indeces of input string)
        int n = input.size() - 1;  //integer because dimension
        vector < string > LIS(n);
        // LIS[0] denotes longest increasing subsequence ending with arr[0]
        LIS[0].push_back(input[0]);

        // start from second element in "input" and compare to previous ones
        for (int i = 1; i <= n; i++){
            // do for each element in subarray arr[0..i-1]
            for (int j = 0; j < i; j++)
            {
                // find longest increasing subsequence that ends with arr[j]
                // where arr[j] is less than the current element arr[i]
                if (input[j] < input[i] && LIS[i].size() < LIS[j].size())
                    LIS[i] = LIS[j];
            }
            // include arr[i] in LIS[i]
            LIS[i].push_back(input[i]);
        }

        // j will contain index of LIS
        int j;
        for (int i = 0; i <= n; i++){
            if (LIS[j].size() < LIS[i].size()){
                j = i;
            }
        }
        // Display LIS
        cout <<"The LIS of your input is: ";
        for (int i : LIS[j]) {
            cout  << static_cast<char>(i);   // convert to char
        }
        cout << endl;
    }
}

int main(){
    longestIncreasingSubsequence();
    return 0;
}