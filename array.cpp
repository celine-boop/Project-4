#include <iostream>
#include <string>
#include <cassert>
using namespace std;

const int NUM_ELEMENTS = 100;
int firstDifference(const string a1[], int n1, const string a2[], int n2)
{
    // This function considers only the first n1 elements of the array a1 and the
    // first n2 elements of the array a2.  It returns the position of the first
    // corresponding elements of a1 and a2 that are not equal.  If the arrays are
    // equal up to the point where one or both of them runs out, then return
    // whichever value of n1 or n2 is less than or equal to the other.  If n1 is
    // 0, that means a1 runs out immediately; similarly, for n2 and a2.  If n1 or
    // n2 is negative, act as if it were 0.

    int i = 0; //initialize i and j
    int j = 0;
    if (n1 < 0) { n1 = 0; } //if n1 or n2 is negative, set them to zero
    if (n2 < 0) { n2 = 0; }
    if (n1 == 0 || n2 == 0) { return 0; } //if n1 or n2 is zero, runs out immediately

    while (i < n1 && j < n2) {
        if (a1[i] != a2[j]) { //if element at position i does not equal element at position j
            return i; //return position i
        }
        i++; //increment i and j to next position if element at i and element at j are equal
        j++;
    }
  
} 


bool isContainedIn(const string a1[], int n1, const string a2[], int n2)
{
    // This function considers only the first n1 elements of the array a1 and the
    // first n2 elements of the array a2.  If all n1 elements of a1 appear as
    // elements in a2, in the same order (though not necessarily consecutively),
    // then return true.  Return false if a2 does not so contain a1.  Of course,
    // a sequence of 0 elements is contained in every sequence, even a sequence
    // of 0 elements.  If n1 or n2 is negative, act as if it were 0.
    int i = 0; //initialize i and j
    int j = 0;
    if (n1 < 0) { n1 = 0; } //if n1 or n2 smaller than 0, set them to 0
    if (n2 < 0) { n2 = 0; }

    if (n1 == 0) { return true; } //if n1 is zero sequence, return true as all sequence contain 0 elements

    while ((j < n2) && (i < n1)) { 
        if (a2[j] == a1[i]) { //if the elements are the same, increment i in a1
            i++;
        }
        j++; //keep checking elements in n2 for ni elements 
        if (j == n2 - 1 && i == n1 - 1 ) { return true; } //if both i and j end up at last position, return true
        if (a2[n2 - 1] != a1 [n1 - 1] ) { return false; } // if last element of a2 does not equal to last element of a1, return false
    } 
 } 

int main(){

    // Here are some tests that demonstrate what these functions do.  You may add
    // more if you wish.
    string colors[6] = { "pink", "blue", "white", "red", "black", "blue" };
    string hues[5] = { "pink", "blue", "white", "black", "green" };
    string tint[5] = { "yellow", "blue", "white", "black", "green" };
    
   
    assert(firstDifference(hues, 5, colors, 6) == 3);
    assert(firstDifference(colors, 4, hues, 5) == 3);
    assert(firstDifference(colors, 2, hues, 5) == 2);  // equal up to where a1 runs out
    assert(firstDifference(colors, 2, hues, 2) == 2);  // equal up to where both run out
    assert(firstDifference(colors, 5, hues, 1) == 1);  // equal up to where a2 runs out
    assert(firstDifference(colors, 0, hues, 0) == 0);  // equal up to where a2 runs out
    assert(firstDifference(colors, 5, tint, 0) == 0);  // equal up to where a2 runs out 

    string little1[4] = { "blue", "white", "red", "black" };
    assert(isContainedIn(little1, 4, colors, 6));

    string little2[2] = { "red", "white" };
    assert(!isContainedIn(little2, 2, colors, 6));

    string little3[3] = { "blue", "blue", "red" };
    assert(!isContainedIn(little3, 3, colors, 6));

    assert(isContainedIn(hues, 3, colors, 3));
    assert(!isContainedIn(hues, 3, colors, 2));

    assert(isContainedIn(hues, 0, tint, 5)); 

    assert(isContainedIn(hues, 0, tint, 0)); 
    cout << "All tests succeeded" << endl; 
} 