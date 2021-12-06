/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Pramukh Nadig  
 * Version     : 1.0
 * Date        : 10/30/2021
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I've abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

static long mergesort(int array[], int scratch[], int low, int high);

long count_inversions_slow(int array[], int length) {
    long count = 0;
    long inversions = 0;
    for (long i = 0; i < length; i++)
        for (long j = i + 1; j < length; j++)
            if (array[i] > array[j])
                inversions++;
 
    return inversions;

}

long count_inversions_fast(int array[], int length) {

	long inversions = 0;
	int *scratch = new int[length];
	inversions = mergesort(array, scratch, 0, length-1);

	delete[]scratch;

	return inversions;
}

static long mergesort(int array[], int scratch[], int low, int high) {
    long inversions = 0;
    
    if(low == high){
        return 0;
    }

    long mid = (low+high) >> 1;

    inversions = inversions+mergesort(array, scratch, low, mid);
    inversions = inversions+mergesort(array, scratch, mid+1, high);

    long lo = low;
    long hi = mid+1;

    for(long i = low; i <= high; i++){
        if(lo <= mid && (hi > high || array[lo] <= array[hi])){
            scratch[i] = array[lo];
            lo++;
            }else{
                inversions = inversions + (mid + 1) - lo;
                scratch[i] = array[hi];
                hi++;
        }
    }
    for(long i = low; i <= high; i++){
        array[i] = scratch[i];
    }
    return inversions;
    
}

int main(int argc, char *argv[]) {
	if (argc > 2) { 
		cerr  << "Usage: " << argv[0] << " [slow]" << endl;
		return 1;
	}

	if (argc == 2 && strcmp(argv[1], "slow") != false) { 
		cerr << "Error: Unrecognized option '" << argv[1] << "'." << endl;
		return 1;
	}
    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                         << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }

        if (values.size() == 0) {
z


    cout << "Number of inversions: ";
    if (argc == 2) {
    	cout << count_inversions_slow(&values[0], values.size()) << endl;
    } else {
    	cout << count_inversions_fast(&values[0], values.size()) << endl;
    }
    return 0;
}
