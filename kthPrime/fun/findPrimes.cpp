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
unsigned long long kthPrime(int k){
    int count =  1;
    unsigned long long kth = 2;
    vector<unsigned long long>* primes = new vector<unsigned long long>;
    primes->push_back(kth);
    kth = 1;
    vector<unsigned long long>::iterator it;
    while(count < k){
        kth = nextPrime(primes, it, kth+2);
        primes->push_back(kth);
        count ++;
    }
    delete primes;
    return kth;
}
