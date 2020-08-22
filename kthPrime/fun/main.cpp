#include "findPrimes.cpp"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    istringstream ss(argv[1]);
    int x;
    if (!(ss >> x))
        cerr << "Invalid number " << argv[1] << '\n';
    vector<unsigned long long>* ans = genPrimes(x);
    cout << x << "th prime is " << ans->back() << endl;
}
