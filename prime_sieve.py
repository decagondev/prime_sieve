a = []
for i in range(1, 1001):
  a.append(i)

def solution(a):
  is_prime = [True] * (a + 1)
  is_prime[0] = is_prime[1] = False
  for i in range(2, int(a**0.5) + 1):
    if is_prime[i]:
      for j in range(i * i, a + 1, i):
        is_prime[j] = False

  primes = [num for num in range(2, a + 1) if is_prime[num]]
  return primes


def filter_list_for_primes(arr):
  bignum = arr[-1]
  primes = solution(bignum)
  return [num for num in arr if num in primes]


prime_list = filter_list_for_primes(a)
print(prime_list)
