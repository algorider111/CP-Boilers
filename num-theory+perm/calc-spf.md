# 🌟 Smallest Prime Factor (SPF) – Complete Guide for Beginners

## 1️⃣ What is Smallest Prime Factor (SPF)?

* For any integer `x > 1`, its **Smallest Prime Factor (SPF)** is the **smallest prime number that divides `x`**.
* If `x` is prime → SPF of `x` is `x` itself.

**Examples:**

| Number | SPF |
| ------ | --- |
| 2      | 2   |
| 3      | 3   |
| 4      | 2   |
| 6      | 2   |
| 15     | 3   |
| 35     | 5   |

> SPF is useful for **prime factorization**, **divisor counting**, and **number-theory problems** in competitive programming.

---

## 2️⃣ Why SPF is Useful in CP

1. **Fast prime factorization:** You can factor any number ≤ n quickly if SPF is precomputed.
2. **Divisor-related problems:** Counting divisors, sum of divisors, gcd/lcm, multiples.
3. **Efficient algorithms:** Factorization using SPF is O(log n) per query.
4. **Common in contests:** Divisor counting, prime queries, and number-theory puzzles.

---

## 3️⃣ Different Efficient Ways to Calculate SPF

We’ll go from **simplest to most efficient** methods.

---

### **Method 1: Trial Division (Naive, for understanding)**

**Idea:**

* For each number x, check all primes ≤ √x and pick the smallest divisor.

**Steps:**

1. For number `x` ≥ 2:
2. Check all `i = 2 to √x`
3. If `i` divides `x`, `i` is SPF.
4. If no divisor → x is prime → SPF = x

**Complexity:**

* O(√n) per number
* Slow for large n, mainly for small numbers or learning.

**C++ Code:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int smallest_prime_factor(int x) {
    if (x <= 1) return -1;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return i;
    }
    return x; // prime
}

int main() {
    int x;
    cin >> x;
    cout << "SPF of " << x << " = " << smallest_prime_factor(x) << "\n";
}
```

---

### **Method 2: Sieve of Eratosthenes (O(n log log n))**

**Idea:**

* Like the classic sieve for primes, but we **store the smallest prime factor** instead of just marking primes.

**Steps:**

1. Create array `spf[0..n]`, initialize `spf[i] = i`
2. For `i = 2 to n`:

   * If `spf[i] == i` → i is prime
   * For multiples of i (`j = i*i, i*i+i, ...`):

     * If `spf[j] == j` → set `spf[j] = i` (smallest prime factor)

**Why it works:**

* The first prime to reach a number is its smallest prime factor. Later primes are bigger → we don’t overwrite.

**Complexity:**

* Time: O(n log log n)
* Memory: O(n)

**C++ Code:**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int spf[N+1];

void sieve_spf() {
    for (int i = 1; i <= N; i++) spf[i] = i;
    spf[1] = 1;

    for (int i = 2; i*i <= N; i++) {
        if (spf[i] == i) { // prime
            for (int j = i*i; j <= N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main() {
    sieve_spf();
    int x;
    cin >> x;
    cout << "SPF of " << x << " = " << spf[x] << "\n";
}
```

---

### **Method 3: Linear Sieve (Fastest, O(n))**

**Idea:**

* Each number is updated **exactly once** by its smallest prime factor.
* Maintain a **list of primes** to help update multiples efficiently.

**Steps:**

1. Initialize `spf[1] = 1` and all others = 0
2. Maintain a list `primes = []`
3. Loop `i = 2 to n`:

   * If `spf[i] == 0` → i is prime → spf[i] = i → add i to primes
   * For each prime p in `primes`:

     * If p > spf[i] or i*p > n → break
     * Set spf[i*p] = p

**Why it works:**

* Guarantees **smallest prime factor is assigned first**.
* Each number is updated exactly once → linear time.

**Complexity:**

* Time: O(n)
* Factorization query: O(log n) per number
* Memory: O(n)

**C++ Code:**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int spf[N+1];
vector<int> primes;

void linear_sieve() {
    spf[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 0) { // prime
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || i * p > N) break;
            spf[i * p] = p;
        }
    }
}

// Factorization
vector<int> factorize(int x) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main() {
    linear_sieve();
    int x;
    cin >> x;
    vector<int> factors = factorize(x);
    cout << "Prime factors of " << x << ": ";
    for (int f : factors) cout << f << " ";
    cout << "\n";
}
```

**Example Output:**

```
Input: 84
Prime factors of 84: 2 2 3 7
```

---

## 4️⃣ Summary Table of Methods

| Method                 | Time Complexity  | Space Complexity | Use Case                                |
| ---------------------- | ---------------- | ---------------- | --------------------------------------- |
| Trial Division         | O(√n) per number | O(1)             | Learning, small numbers                 |
| Sieve of Eratosthenes  | O(n log log n)   | O(n)             | Precompute SPF for n ≤ 1e6              |
| Linear Sieve (Fastest) | O(n)             | O(n)             | Large n, multiple factorization queries |

---

## 5️⃣ Key Points for Beginners

1. SPF helps **factorize numbers quickly**.
2. **Linear Sieve** is the **fastest method** for CP.
3. After SPF is computed, **factorization is O(log n)** per number.
4. Useful in: **divisor counting, gcd/lcm, multiples, probability, number theory**.
5. Always remember:

   * Each composite number is updated **only once** by its **smallest prime factor** in linear sieve.
   * Factorization using SPF → repeatedly divide by spf[x] until x = 1.

---

✅ **Takeaway:**
If you’re preparing for **competitive programming**, learn **linear sieve for SPF**, because it’s fast, versatile, and a fundamental number-theory tool. You can factorize any number ≤ 1e6 instantly and use it in various problems.

---

If you want, I can also make a **single compact CP template** that has:

* Linear Sieve for SPF
* Prime factorization function
* Divisor counting function
* Precomputed arrays ready for contests

It will be **ready-to-copy-paste for CP**.

Do you want me to make that?
