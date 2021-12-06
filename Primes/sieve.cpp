/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Pramukh Nadig
 * Date        : 09/15/2021
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I've abided by the Stevens honor code.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <iterator>
#include <algorithm>
using namespace std;

class PrimesSieve
{
public:
    PrimesSieve(int limit);

    ~PrimesSieve()
    {
        delete[] is_prime_;
    }

    int num_primes() const
    {
        return num_primes_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool *const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) : is_prime_{new bool[limit + 1]}, limit_{limit}
{
    sieve();
}

void PrimesSieve::display_primes() const
{
    const int max_prime_width = num_digits(max_prime_);
    const int primes_per_row = 80 / (max_prime_width + 1);
    int counter = 0;

    if (num_primes_ > primes_per_row)
    {
        for (int i = 2; i != max_prime_; ++i)
        {
            if (is_prime_[i])
            {
                cout << setw(max_prime_width) << i << " ";
                counter++;

                if (counter == primes_per_row)
                {

                    counter = 0;
                    cout  << endl;
                }
            }
        }
        cout << max_prime_;
    }
    else
    {
        for (int i = 2; i != max_prime_; ++i)
        {
            if (is_prime_[i])
            {
                cout << i << " ";
            }
        }

        cout << max_prime_;
    }
}

int PrimesSieve::count_num_primes() const
{
    int count = 0;
    for (int p = 2; p <= limit_; ++p)
    {
        if (is_prime_[p])
        {
            count++;
        }
    }

    return count;
}

void PrimesSieve::sieve()
{
    for (int i = 0; i <= limit_; i++)
    {
        is_prime_[i] = true;
    }
    int n = limit_;
    int i = 2;
    while (i <= sqrt(n))
    {

        if (is_prime_[i] == true)
        {
            max_prime_ = i;
            int j = pow(i, 2);
            while (j <= n)
            {
                is_prime_[j] = false;
                j += i;
            }
        }
        i++;
    }

    for (int i = 2; i <= limit_; i++)
    {
        if (is_prime_[i])
        {
            num_primes_++;
            max_prime_ = i;
        }
    }
    cout << endl
         << "Number of primes found: " << num_primes_ << endl;
    cout << "Primes up to " << limit_ << ":" << endl;
    display_primes();
}

int PrimesSieve::num_digits(int num)
{
    int counter = 0;
    while (num > 1)
    {
        num /= 10;
        counter++;
    }
    return counter;
}

int main()
{
    cout << "**************************** "
         << "Sieve of Eratosthenes"
         << " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if (!(iss >> limit))
    {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2)
    {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    PrimesSieve sieve(limit);
    return 0;
}
