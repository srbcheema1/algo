#include<bits/stdc++.h>
using namespace std;

// manual.begin
/* sqrt(1e9) is 31623
 * primes till 32000 are 3432 remember 4000
 * so we can check is_prime in 3432 steps only, instread of 31623 steps
 *
 * primes till 1e6 are < 80,000
 *
 * a number can have max log2(n) factors.
 * 32 bit int can have max 32 prime factors, and max 8 unique prime factors remember 10
 * 32 bit int can have max 8 unique prime factors
 * 32 bit number cant have more than root(n) factors, except numbers below 100
 *
 * 32 bit number cant have more than 2300 divisors
 * maximum divisors are found of 6,983,776,800 which are 2304
 * it is not 32bit number though
 *
 */

/* https://primes.utm.edu/howmany.html
 * https://primes.utm.edu/
 *
 *
 */

/* primes till
1   10                  4
2   100                 25
3   1,000               168
4   10,000              1,229
5   100,000             9,592
6   1,000,000           78,498
7   10,000,000          664,579
8   100,000,000         5,761,455
9   1,000,000,000       50,847,534
10  10,000,000,000      455,052,511
11  100,000,000,000     4,118,054,813
12  1,000,000,000,000   37,607,912,018
13  10,000,000,000,000  346,065,536,839
*/

signed main(){
    long long int primes_till[] = {0,4,25,168,1229,9592,78498,664579,5761455,50847534,455052511,4118054813};
    int n;
    cin>>n;
    if(n < (int)sizeof primes_till)
        cout << primes_till[n] << endl;
    else
        cout << "enter number below" << sizeof primes_till << endl;

}
//manual.end

/* TAGS
 *
 */
