/*******************************************************************************
 * Name    : sqrt.cpp
 * Author  : Pramukh Nadig
 * Version : 1.0
 * Date    : September 8, 2021
 * Description : Computes the square root of the command-line argument.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

using namespace std;

double sqrt(double num, double epsilon)
{
    double last_guess = num;
    double next_guess = 1.0;
    if (num < 0)
    {
        return numeric_limits<double>::quiet_NaN();
    }
    if (num == 1 || num == 0)
    {
        return num;
    }

    while (abs(last_guess - next_guess) >= epsilon)
    {
        //cout << next_guess << endl;
        last_guess = next_guess;
        next_guess = ((last_guess + (num / last_guess)) / 2.0);
    }

    return next_guess;
}

int main(int argc, char *argv[])
{
    double m, epsilon = 1e-7;
    if (argc != 2 && argc != 3)
    {
        cerr << "Usage: ./sqrt <value> [epsilon]";
        return 1;
    }

    istringstream iss;

    if (argc == 3)
    {
        iss.str(argv[2]);
        if (!(iss >> epsilon) || epsilon <= 0)
        {
            cerr << "Error: Epsilon argument must be a positive double.";
            return 1;
        }
        iss.clear();
    }
    iss.str(argv[1]);
    if (!(iss >> m))
    {
        cerr << "Error: Value argument must be a double.";
        return 1;
    }

    cout << fixed << setprecision(8) << sqrt(m, epsilon);
}
