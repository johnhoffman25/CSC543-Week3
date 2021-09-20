//John Hoffman - F00555643
//CSC 543
//Assignment 5 - Longest Common Substring
//09/19/2021

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Function for the user to input a string
string getInputString() {
    string inputString;
    cin >> inputString;
    return inputString;
}
 
// Function to find the longest common substring shared between two strings
string longestCommonSubstring(string X, string Y, int m, int n)
{
    int maxLength = 0;
    int endingIndex = m;
 
    //Table to store the length of the substrings
    int lookupTable[m + 1][n + 1];
 
    //Initialize all of the cells in the lookupTable
    memset(lookupTable, 0, sizeof(lookupTable));
 
    //Beging looping to fill the lookupTable
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1;
 
                //Update the maximum length and the ending index
                if (lookupTable[i][j] > maxLength)
                {
                    maxLength = lookupTable[i][j];
                    endingIndex = i;
                }
            }
        }
    }

    //Output the 2D matrix
    cout << "-----------------------------------------" << endl;
    cout << "2D matrix representation of the solution" << endl;
    cout << "\n    ";
    for (int i = 0; i < m; i++) {
        cout << X[i] << " ";
    }

    int count = 0;

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (count % (m + 1) == 0) {
                cout << endl;
            }
            if (count % (m + 1) == 0 && count != 0) {
                cout << Y[i - 1] << " ";
            }
            if (count == 0) {
                cout << "  ";
            }
            cout << lookupTable[i][j] << " ";
            count++;
        }
    }
 
    //Return the longest common substring, in this case using maxLength
    return X.substr(endingIndex - maxLength, maxLength);
}

//Main driver for the program
int main()
{
    cout << "\nPlease enter the first string: ";
    string firstString = getInputString();
    cout << "\nPlease enter the second string: ";
    string secondString = getInputString();

    int firstStringLength = firstString.size();
    int secondStringLength = secondString.size();
 
    string lcs = longestCommonSubstring(firstString, secondString, firstStringLength, secondStringLength);
    cout << "\n\nThe longest common substring is: " << lcs;
 
    return 0;
}