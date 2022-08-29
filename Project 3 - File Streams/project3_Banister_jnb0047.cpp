//  FILE NAME: project3_Banister_jnb0047.cpp
//
//  AUTHOR: Jess Banister on 2/17/22.
//
//  SOURCES: I looked at cplusplus.com to get a further understanding of
//  what the stream functions do in the code and how to use them to read the
//  files inputed from the keyboard.  I also watched a YouTude video by the user
//  Alex Clarke to understand how to make/ import test files in Xcode. Finally I
//  used the Project 3 Hints given to us by Dr.Li and the hints in the Project 3
//   file in canvas.

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;

const int MAX_SIZE = 100;
//Prototypes
/* A function that checks to see if it's a valid file
 */
bool check_file(string);

/* Array recieved from the input file and input file stream object
 * Returns the size of the array
 */
int readfile(int inputArray[], ifstream& inStream);

/*Takes in arrays and sizes
* Returns the size of the output array
 */
int merge(int inputArray[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);

ifstream stream;
string filename;
string filename2;
string file;

int iArray1[MAX_SIZE];
int iArray1_size;
int iArray2[MAX_SIZE];
int iArray2_size;
int outputArray[MAX_SIZE];
int outputArray_size;

         
/* Writes to the output file
 */
void writefile(int outputArray[], int outputArray_size, string file);

//Main
/*
 * Merge the numbers in two specified files and write all the numbers
 * to a specified third file sorted in ascending order.
 *
 * Return: 1 Program completed successfully. (int)
 */
int main() {
    cout << "*** Welcome to Jess' sorting program\n";
    
    // FIRST FILE
    cout << "Enter the first input file name: ";
    cin >> filename;
    
    if (check_file(filename) == true) {
        stream.open(filename.c_str());
    }
    iArray1_size = readfile(iArray1, stream);
    stream.close();
    
    cout << "The list of " << iArray1_size << " numbers in file " << filename << " is:\n";
    for (int i = 0; i <= iArray1_size; i++) {
        cout << iArray1[i] << endl;
    }
    cout << endl;
    
    // SECOND FILE
    cout << "Enter the second input file name: ";
    cin >> filename2;
        if (check_file(filename2) == true) {
        stream.open(filename2.c_str());
    }
    iArray2_size = readfile(iArray2, stream);
    stream.close();
    cout << "The list of " << iArray2_size << " numbers in file " << filename2 << " is:\n";
    for (int i = 0; i <= iArray2_size; i++) {
        cout << iArray2[i] << endl;
    }
    cout << endl;
    
    // use merge
    outputArray_size = merge(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);
    cout << "The sorted list of " << outputArray_size << " numbers is: ";
    for (int i = 0; i < outputArray_size; i++) {
        cout << outputArray[i] << " ";
    }
    cout << endl;
    
    // use writefile
    writefile(outputArray, outputArray_size, file);
    return 0;
}

int readfile(int inputArray[], ifstream& inStream) {
    int index = 0;
    inStream >> inputArray[index];
    while (!inStream.eof()) {
        index++;
        inStream >> inputArray[index];
    }
    return index;
}

bool check_file(string file) {
    ifstream stream;
    
    stream.open(file.c_str());
    if (stream.fail()) {
        cout << "Input file opening failed." << endl;
    }
    stream.close();
    
    return true;
}

void writefile(int outputArray[], int outputArray_size, string file) {
    /* Output file stream. (ofstream) */
    ofstream outstream;
    string output_filename;
    cout << "Enter the output file name: ";
    cin >> output_filename;
    
    outstream.open((char*)output_filename.c_str());
    for (int i = 0; i < outputArray_size; i++) {
        outstream << outputArray[i] << "\n";
    }
    outstream.close();
    
    cout << "*** Please check the new file - "
    << output_filename << " ***\n"
    << "*** Goodbye. ***";
}

int merge(int inputArray[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
    // counts for array1
    int i = 0;
    // counts for array2
    int o = 0;
    int size = 0;
    /* compares vectors */
    while (i < inputArray1_size && o < inputArray2_size) {
        /* Adds numbers from vector one. */
        if (inputArray[i] < inputArray2[o]) {
            outputArray[size] = inputArray[i];
            i++;
            size++;
        }
        /* Adds any remaining numbers from vector one. */
        else if (inputArray[i] > inputArray2[o]) {
            outputArray[size] = inputArray2[o];
            o++;
            size++;
        }
        /* Adds any remaining numbers from vector two. */
        else if (inputArray[i] == inputArray2[o]) {
            outputArray[size] = inputArray[i];
            i++;
            outputArray[size++] = inputArray2[o];
            o++;
            size+=2;
        }
    }
    while (i < inputArray1_size) {
        outputArray[size] = inputArray[i];
        i++;
        size++;
    }
    while (o < inputArray2_size) {
        outputArray[size] = inputArray2[o];
        o++;
        size++;
    }
    return size;
}
