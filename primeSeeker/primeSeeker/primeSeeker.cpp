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

string primeSeeker(int c) {
    //List of primes
    std::vector<int> primes;
    primes.resize(c);

    //Prime seeker
    int j = 2;
    for (int counter = 0; counter < c;) {
        if (isPrime(j)) {
            primes[counter] = j;
            counter++;
        }
        j++;
    }

    //Serialize
    string res = "";
    for (int k : primes) {
        res += to_string(k) + " ";
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

        cout << "Enter primes amount" << endl;
        cin >> max;
        cout << "Enter path" << endl;
        cin >> path;
        string res = primeSeeker(max);

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
