// https://github.com/dotnet/runtime/blob/main/src/libraries/System.Private.CoreLib/src/System/Collections/HashHelpers.cs

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#define HASH_PRIME 101
#define PRIMES 72

/**
 * Table of prime numbers to use as hash table sizes.
 * 
 * A typical resize algorithm would pick the smallest prime number in this array
 * that is larger than twice the previous capacity.
 * 
 * Suppose our Hashtable currently has capacity x and enough elements are added
 * such that a resize needs to occur. Resizing first computes 2x then finds the
 * first prime in the table greater than 2x, i.e. if primes are ordered
 * p_1, p_2, ..., p_i, ..., it finds p_n such that p_n-1 < 2x < p_n.
 * 
 * Doubling is important for preserving the asymptotic complexity of the
 * hashtable operations such as add.  Having a prime guarantees that double
 * hashing does not lead to infinite loops.  IE, your hash function will be
 * h1(key) + i*h2(key), 0 <= i < size.  h2 and the size must be relatively prime.
 * 
 * We prefer the low computation costs of higher prime numbers over the increased
 * memory allocation of a fixed prime number i.e. when right sizing a HashSet.
 */
static int primes[PRIMES] = {3, 7, 11, 17, 23, 29, 37, 47, 59, 71, 89, 107,
                             131, 163, 197, 239, 293, 353, 431, 521, 631, 761,
                             919, 1103, 1327, 1597, 1931, 2333, 2801, 3371,
                             4049, 4861, 5839, 7013, 8419, 10103, 12143, 14591,
                             17519, 21023, 25229, 30293, 36353, 43627, 52361,
                             62851, 75431, 90523, 108631, 130363, 156437,
                             187751, 225307, 270371, 324449, 389357, 467237,
                             560689, 672827, 807403, 968897, 1162687, 1395263,
                             1674319, 2009191, 2411033, 2893249, 3471899,
                             4166287, 4999559, 5999471, 7199369};

static bool isPrime(int candidate)
{
    if (!(candidate % 2))
    {
        return candidate == 2;
    }

    int limit = sqrt(candidate);

    for (int divisor = 3; divisor <= limit; divisor += 2)
    {
        if (!(candidate % divisor))
        {
            return false;
        }
    }

    return true;
}

int hash_helpers_get_prime(int min)
{
    for (int i = 0; i < PRIMES; i++)
    {
        if (primes[i] >= min)
        {
            return primes[i];
        }
    }

    // Outside of our predefined table. Compute the hard way.

    for (int i = min | 1; i < INT_MAX; i += 2)
    {
        if (!isPrime(i))
        {
            continue;
        }

        if ((i - 1) % HASH_PRIME)
        {
            continue;
        }

        return i;
    }

    return min;
}
