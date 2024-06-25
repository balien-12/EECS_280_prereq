#ifndef ARRAYS_CPP
#define ARRAYS_CPP

#include <iostream>
#include <string>
#include <array>
using namespace std;

const int SIZE = 60;

const int MAX_PRINTABLE_ASCII = '~';
const int MIN_PRINTABLE_ASCII = ' ';
const int ASCII_PRINTABLE_RANGE = MAX_PRINTABLE_ASCII - MIN_PRINTABLE_ASCII + 1;

void printRight(int n) { //WE GOOD
    if(n > 0) {
        for(int x = 1; x < n+1; x++) {
           for(int y = x; y > 0; y--) {
                cout << '*';
           }
           cout << endl;
        }
    } else {}
}

void printRight_upsideDown_rightJustified(int n) { //WE GOOD
    if(n > 0) {
        for(int x = n; x > 0; x--) {
           for(int y = 0; y < (n-x); y++) {
                cout << ' ';
           }
           for(int z = x; z > 0; z--) {
                cout << '*';
           }
           cout << endl;
        }
    } else {}
}

void printArray(const char arr[], int size) { //F them pointers
    try {
        if(size > 0 && size <= SIZE) { 
            for(int x = 0; x < size; x++) {
                cout << arr[x];
            }
            cout << endl;
        } else {}
    } catch(out_of_range) {}
}

void printArray(const char arr[][SIZE], int rows, int cols) {
    try {
        if(cols > 0 && cols <= SIZE) {
            for(int y = 0; y < rows; y++) {
                printArray(arr[y], cols);
            }
        } else {}
    } catch(out_of_range) {}
}

void add(char arr[], int size, int val) {
   int ascii;
   try{
        if(size > 0 && size <= SIZE) {
            for(int x = 0; x < size; x++) {
                ascii = int(arr[x]);
                ascii += val;
                while(ascii > MAX_PRINTABLE_ASCII || ascii < MIN_PRINTABLE_ASCII) {
                    if(ascii > MAX_PRINTABLE_ASCII) {
                        ascii -= ASCII_PRINTABLE_RANGE;
                    } else if(ascii < MIN_PRINTABLE_ASCII) {
                        ascii += ASCII_PRINTABLE_RANGE;
                    }
                }
                arr[x] = char(ascii);
            }
        } else {}
    } catch(out_of_range) {}
}

void add(char arr[][SIZE], int rows, int cols, int val) {
    try {
        if(rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE) {
            for(int y = 0; y < rows; y++) {
                add(arr[y], cols, val);
            }
        }
    } catch(out_of_range) {}
}

void rotateLeft(char arr[], int size) {
    char temp;
    try {
        if(size > 0 && size <= SIZE) {
            temp=arr[0];
            for(int x = 0; x < size; x++) {
                if(x<size-1) {
                    arr[x]=arr[x+1];
                } else {
                    arr[x]=temp;
                }
            }
        }
    } catch(out_of_range) {}
}

void rotateLeft(char arr[][SIZE], int rows, int cols) { 
    try { 
        if(rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE) {
            for(int y = 0; y < rows; y++) {
                rotateLeft(arr[y], cols); 
            }
        } else {}
    } catch(out_of_range) {}    
}

void rotateRight(char arr[], int size) {
    char temp;
    try {
        if(size > 0 && size <= SIZE) {
            temp=arr[size-1];
            for(int x = size-1; x >= 0; x--) {
                if(x>0) {
                    arr[x]=arr[x-1];
                } else {
                    arr[x]=temp;
                }
            }
        }
    } catch(out_of_range) {}
}

void rotateRight(char arr[][SIZE], int rows, int cols) { 
    try { 
        if(rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE) {
            for(int y = 0; y < rows; y++) {
                rotateRight(arr[y], cols); 
            }
        } else {}
    } catch(out_of_range) {}  
}

void reverse(char arr[], int size) { 
    int index1;
    int index2;
    char temp;
    try{
        if(size > 0 && size <= SIZE) {
            for(int x = 0; x < size/2; x++) {
                index1 = x;
                index2 = (size-1)-x;
                temp = arr[index1];
                arr[index1] = arr[index2];
                arr[index2] = temp;
            }
        } else {}
    } catch(out_of_range) {}
}

void swapRange(char arr1[], int size1, int index1,
               char arr2[], int size2, int index2, int len) {
    char temp;
    try{
        if(size1 >= index1+len && size1 > 0 && size1 <= SIZE && size2 >= index2+len && size2 > 0 && size2 <= SIZE && len >= 0) {
            for(int x = 0; x < len; x++) {
                temp = arr1[index1+x];
                arr1[index1+x] = arr2[index2+x];
                arr2[index2+x] = temp;
            }
        } else {}
    } catch(out_of_range) {}
}

void swapWithinOneRow(char arr[], int size, int len) {
    try {
        if(size > 0 && size <= SIZE && size/len >= 2) {
            for(int x = 0; x <= size - (2*len); x+=(2*len)) {
                swapRange(arr, size, x, arr, size, x + len, len);
            }
        } else {}
    } catch(out_of_range) {}
}

void swapRows(char arr[][SIZE], int rows, int cols) { 
    try {
        if(rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE) {
            for(int x = 0; x < rows-1; x+=2) {
                swapRange(arr[x], cols, 0, arr[x+1], cols, 0, cols);
            }
        } else {}
    } catch(out_of_range) {}
}

#endif