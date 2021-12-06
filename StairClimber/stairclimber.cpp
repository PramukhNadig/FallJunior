/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Pramukh Nadig
 * Date        : 10/2/2021
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I've abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;


vector<vector<int>> total;
vector<int> thisOne;
vector< vector<int> > get_ways(int num_stairs) {
    if(num_stairs <= 0 ){
        total.push_back(thisOne);
    }

    if(num_stairs >= 1){
        thisOne.push_back(1);
        get_ways(num_stairs-1);
        thisOne.pop_back();
    }

    if(num_stairs >= 2){
        thisOne.push_back(2);
        get_ways(num_stairs-2);
        thisOne.pop_back();
    }

    if(num_stairs >= 3){
        thisOne.push_back(3);
        get_ways(num_stairs-3);
        thisOne.pop_back();
    }

    return total;
    }

void display_ways(const vector< vector<int> > &ways) {
    auto size = ways.size();
    int width = 0;
    if(size >= 10 && size < 100){
        width = 2;
    }else if(size >= 100){
        width = 3;
    }else{
        width = 1;
    }
    if(size == 1){
        cout << "1 way to climb 1 stair." << endl;
    }

    else{
        cout << size << " ways to climb " << ways[0].size() << " stairs." << endl;
    }

    for(size_t i = 0; i < size; i++){
        cout  << setw(width) << i+1 << ". [";

		for(size_t j = 0; j < ways[i].size(); j++){
            if( j == ways[i].size()-1){
				cout << ways[i][j] << "]";
			}
			else{
			cout << ways[i][j] << ", ";
			}        
            }
            if(i != size-1){
            cout << endl;
            }else{
                cout << "";
            }
    }

}

int main(int argc, char * const argv[]) {

    int m;
if (argc != 2 )
    {
        cerr << "Usage: ./stairclimber <number of stairs>";
        return 1;
    }

    istringstream iss;


    iss.str(argv[1]);
    if (!(iss >> m))
    {
        cerr << "Error: Number of stairs must be a positive integer.";
        return 1;
    }

    if(m <= 0){
        cerr << "Error: Number of stairs must be a positive integer.";
        return 1;
    }

    display_ways(get_ways(m));
}
