Prime List

class Solution {
  public:
    vector<bool> sieve;
    vector<int> primes;

    // Sieve of Eratosthenes to generate all primes up to 20000
    void generatePrimes(int maxLimit) {
        sieve.assign(maxLimit + 1, true);
        sieve[0] = sieve[1] = false;

        for (int i = 2; i * i <= maxLimit; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxLimit; j += i) {
                    sieve[j] = false;
                }
            }
        }

        for (int i = 2; i <= maxLimit; ++i) {
            if (sieve[i]) {
                primes.push_back(i);
            }
        }
    }

    // Helper to find nearest prime to a number
    int nearestPrime(int num) {
        if (sieve[num]) return num;

        // Binary search for nearest prime
        int idx = lower_bound(primes.begin(), primes.end(), num) - primes.begin();

        int lower = (idx > 0) ? primes[idx - 1] : INT_MAX;
        int upper = (idx < primes.size()) ? primes[idx] : INT_MAX;

        if (abs(num - lower) <= abs(upper - num))
            return lower;
        else
            return upper;
    }

    Node *primeList(Node *head) {
        generatePrimes(20000);  // Precompute primes up to 20000

        Node* temp = head;
        while (temp != nullptr) {
            temp->val = nearestPrime(temp->val);
            temp = temp->next;
        }

        return head;
    }
};
