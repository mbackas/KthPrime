#include <vector>
#include <iostream>
using namespace std;

unsigned long long nextPrime(vector<unsigned long long>*& primes, vector<unsigned long long>::iterator& it, unsigned long long query){
    it = primes->begin();
    for(; it != primes->end(); it++){
        if(query % (*it) == 0){
            return(nextPrime(primes, it, query+2));
        }
    }
    return query;
}
vector<unsigned long long>* genPrimes(int M){
    vector<unsigned long long>* primes = new vector<unsigned long long>;
    primes->push_back(1);
    int kth = 1;
    vector<unsigned long long>::iterator it;
    while(kth < M){
        kth = nextPrime(primes, it, kth+2);
        primes->push_back(kth);
    }
    return primes;
}
