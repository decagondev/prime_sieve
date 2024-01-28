#include <iostream>
#include <vector>

std::vector<int> sieve_of_eratosthenes(int A) {
    std::vector<bool> is_prime(A + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= A; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= A; j += i) {
                is_prime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int num = 2; num <= A; ++num) {
        if (is_prime[num]) {
            primes.push_back(num);
        }
    }

    return primes;
}

int main() {
    int A = 1000;
    std::vector<int> result = sieve_of_eratosthenes(A);

    std::cout << "Prime numbers less than or equal to " << A << ": ";
    for (int prime : result) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
