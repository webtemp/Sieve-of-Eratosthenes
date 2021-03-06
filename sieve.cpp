// For the std namespace
#include <iostream>
// For the low-memory container
#include <bitset>
// For the vector itself
#include <vector>
// For the sqrt function 
#include <cmath>

// I'm lazy to write std:: every time
using namespace std;

typedef unsigned long long int ull;

// The largest number "up-to" we find primes
#define PRIME_MAX 10000000
#define DEFAULT_LIMIT 200

// Generate primes up to "TO".
vector<ull> sieve(const ull TO) {
    // UP to how much we count
    ull upperLimit = sqrtl(TO);
    // Fix off by one errors
    upperLimit++;

    // Can't fill of them in the stack so go with the heap
    bitset<PRIME_MAX> *allPrimes = new bitset<PRIME_MAX>();

    // Make all the numbers in the bitset primes
    allPrimes[0].flip();

    // This can be changed to some other data structure if needed
    vector<ull> primes;
    // Reserve TO/4 for better vector performance
    primes.reserve(upperLimit);
    // 2 is the first and only even prime
    primes.push_back(2);

    // We'll need this for cleaning up later
    ull i = 3, j;
    for(i = 3; i < upperLimit; i += 2) {
        // If the item is a prime
        if(allPrimes[0][i] == 1) {
            // i was a prime !
           primes.push_back(i);
            // Remove the rest non-primes
            for(j = i + i; j < TO; j += i ) {
                // There is no point to go any further
                if( j > TO) { break; }
                // Say that's not a prime
                allPrimes[0][j] = 0;
            }
        }
    }

    // Remember, we are skipping evens
    for(ull k = i; k < TO; k += 2) {
        // If the item is a prime
        if(allPrimes[0][k] == 1) {
            // Add it to the container
            primes.push_back(k);
        }
    }

    return primes;
}

// The main entry point of the program
int main(int argc, char * argv[]) {
    ull limit = DEFAULT_LIMIT;

    // If a arg was passed, use it
    if(argc > 1){
        limit = strtoull(argv[1], NULL, 10);
    }

    // If the user's passed a bigger value fall back to the original;
    if(limit > PRIME_MAX) {
        cout << limit << " is too big for this program. Lowering it to: " << PRIME_MAX << "\n";
        limit = PRIME_MAX;
    }

    // We'll keep all primes we find in here
    vector<ull> primes;
    primes = sieve(limit);

    // If any primes are generated, show them to stdout 
    if(primes.size() > 0) {
        // Unsigned int to avoid compiler notices
        for(unsigned int it = 0; it < primes.size(); it++) {
            cout << primes[it] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "No primes generated.";
        return 1;
    }

    return 0;
}

