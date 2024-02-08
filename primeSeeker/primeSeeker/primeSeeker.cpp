#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//Found on internet
bool isPrime(int n)
{
    if (!(n - 1)) return false;
    for (int i = 2;i <= sqrt(n);i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

string primeSeeker(int c, string sep) {
    //List of primes
    std::vector<int> primes;
    primes.resize(c);

    //Prime seeker
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    float percent = 0, j = 2;
    for (int counter = 0; counter < c;) {
        if (isPrime(j)) {
            primes[counter] = j;

            int p = ((counter + 1) * 100 / c);
            if (p != percent) {
                percent = p;
                cout << percent << "% ";
            }

            counter++;
        }
        j++;
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    int seconds = chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000000;
    cout << endl << "Time elapsed: " << seconds % 1000 << " seconds" << endl;


    //Serialize
    string res = "";
    for (int k : primes) {
        res += to_string(k) + sep;
    }

    return res;
}

int main()
{
    //Init
    cout << "Choose an option:" << "\n\n";

    cout << "1. Look for prime numbers" << endl;
    cout << "2. Check prime" << endl;
    string choice;
    cin >> choice;
    cout << endl;

    if (choice == "1") {
        int max; 
        string path;
        string sep;

        cout << "Enter primes amount" << endl;
        cin >> max;
        cout << "Enter seperator" << endl;
        cin >> sep;
        cout << "Enter path" << endl;
        cin >> path;

        string res = primeSeeker(max, sep);

        ofstream out;

        out.open(path);
        out << res;
        out.close();

        cout << "Success!" << endl;
    }
    if (choice == "2") {
        int number;
        cout << "Enter the number: " << endl;
        cin >> number;

        if (isPrime(number)) cout << "Yes, it's prime" << endl;
        else cout << "No, it's composite" << endl;
    }

    system("pause");
    return 0;
}
