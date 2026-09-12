#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

/*
==========================================================
1. FAST EXPONENTIATION (BINARY EXPONENTIATION)
==========================================================

Calculates:

    (a ^ b) % mod

Time Complexity: O(log b)

Example:
    binpow(2, 10, MOD) = 1024

Useful for:
    - Large powers
    - Modular arithmetic
    - Matrix exponentiation
    - Modular inverse

ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;

    a %= mod;

    while (b > 0) {
        // If current bit of b is set
        if (b & 1) {
            res = res * a % mod;
        }

        // Square the base
        a = a * a % mod;

        // Divide exponent by 2
        b >>= 1;
    }

    return res;
}

*/

/*
==========================================================
2. MODULAR INVERSE
==========================================================

For a number a, modular inverse is a number x such that:

    (a * x) % MOD = 1

Using Fermat's Little Theorem:

    a^(-1) = a^(MOD - 2) % MOD

Works when:
    - MOD is prime
    - a is not divisible by MOD

Time Complexity: O(log MOD)

Example:
    modinv(2) = 500000004

Because:
    2 * 500000004 % MOD = 1

ll modinv(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

*/

/*
==========================================================
3. MODULAR MULTIPLICATION
==========================================================

Calculates:

    (a * b) % MOD

Useful when a and b are large.

For MOD = 1e9 + 7, normal long long multiplication
is safe because:

    (MOD - 1)^2 < LLONG_MAX

For larger mod values, use __int128.

Time Complexity: O(1)

ll modmul(ll a, ll b, ll mod = MOD) {
    return (__int128)a * b % mod;
}
*/


/*
==========================================================
4. FACTORIAL AND INVERSE FACTORIAL
==========================================================

Precomputes:

    fact[i] = i! % MOD

    invfact[i] = (i!)^(-1) % MOD

Useful for:
    - nCr
    - nPr
    - Combinatorics
    - Counting problems

Precomputation:
    O(n + log MOD)

Each query:
    O(1)

Important:
    MAXN must be at least the maximum n you will use.

const int MAXN = 1000000;

ll fact[MAXN + 1];
ll invfact[MAXN + 1];

void init_factorials() {

    // fact[0] = 0! = 1
    fact[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    // Inverse factorial of MAXN
    invfact[MAXN] = modinv(fact[MAXN]);

    // Calculate inverse factorials backwards
    for (int i = MAXN - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
}
*/


/*
==========================================================
5. nCr MODULO A PRIME
==========================================================

Formula:

    nCr = n! / (r! * (n-r)!)

Under modulo:

    nCr = fact[n] * invfact[r] * invfact[n-r] % MOD

Time Complexity:
    Precomputation: O(n + log MOD)
    Each query: O(1)

Example:
    nCr(5, 2) = 10

Conditions:
    - 0 <= r <= n
    - n <= MAXN
    - MOD must be prime

ll nCr(int n, int r) {

    if (r < 0 || r > n) {
        return 0;
    }

    return fact[n] * invfact[r] % MOD
                  * invfact[n - r] % MOD;
}
*/


/*
==========================================================
EXAMPLE USAGE
==========================================================
*/

void solve() {

    /* Fast exponentiation
    cout << binpow(2, 10) << '\n';

    // Modular inverse
    cout << modinv(2) << '\n';

    // Modular multiplication
    cout << modmul(1000000000LL, 1000000000LL) << '\n';

    // Initialize factorials once
    init_factorials();

    // 5C2 = 10
    cout << nCr(5, 2) << '\n';
    */
   return;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve();

    return 0;
}