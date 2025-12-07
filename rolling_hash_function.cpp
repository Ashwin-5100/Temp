#include <bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif


#define ll long long
#define pb(x) push_back(x)
#define mod 1e9 + 7
#define sz(x) ((int)(x).size())


 
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
 
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
 
ll expo(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            // res = (res * a) % mod;
            res = mod_mul(res, a, m);
        }
        // a = (a * a) % mod;
        a = mod_mul(a, a, m);
        b = b >> 1;
    }
    return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
 
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
 
inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
 
struct Hashing
{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 1000000007};
    const ll base = 51;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversepowersofbase;
    Hashing(string a)
    {
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversepowersofbase.resize(primes);
        s = a;
        n = s.length();
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            powersOfBase[i].resize(n + 1);
            inversepowersofbase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            inversepowersofbase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
                if (j == 1)
                {
                    inversepowersofbase[i][j] = expo(base, hashPrimes[i] - 2, hashPrimes[i]);
                }
                else
                {
                    inversepowersofbase[i][j] = (inversepowersofbase[i][j - 1] * inversepowersofbase[i][1]) % hashPrimes[i];
                }
            }
            // debug(inversepowersofbase[i])
        }
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    void addCharacter(char ch)
    {
        s += ch;
        n = sz(s);
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            while (sz(powersOfBase[i]) < sz(s))
            {
                powersOfBase[i].pb((powersOfBase[i].back() * base) % hashPrimes[i]);
            }
        }
        for (int i = 0; i < sz(hashPrimes); i++)
        {
            while (sz(hashValues[i]) < sz(s))
            {
                if (sz(hashValues[i]) == 0)
                {
                    hashValues[i].pb((s[0] - 'a' + 1LL) % hashPrimes[i]);
                }
                else
                {
                    ll extraHash = hashValues[i].back() + ((s.back() - 'a' + 1LL) * powersOfBase[i][sz(s) - 1]) % hashPrimes[i];
                    hashValues[i].pb((extraHash + hashPrimes[i]) % hashPrimes[i]);
                }
            }
        }
    }
    vector<ll> substringHash(int l, int r)
    { // extra O(log) factor
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversepowersofbase[i][l], hashPrimes[i]);
        }
        return hash;
    }
    bool compareSubstrings(int l1, int r1, int l2, int r2)
    { // use this for comparing strings faster
        if (l1 > l2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        for (int i = 0; i < primes; i++)
        {
            ll val1 = mod_sub(hashValues[i][r1], (l1 > 0 ? hashValues[i][l1 - 1] : 0LL), hashPrimes[i]);
            ll val2 = mod_sub(hashValues[i][r2], (l2 > 0 ? hashValues[i][l2 - 1] : 0LL), hashPrimes[i]);
            if (mod_mul(val1, powersOfBase[i][l2 - l1], hashPrimes[i]) != val2)
                return false;
        }
        return true;
    }
};
void solve()
{
    string s;
    cin >> s;
    dbg(s);
    Hashing r(s);
    ll n = s.size();
    ll c = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (r.compareSubstrings(0, i, n - i - 1, n - 1))
        {
            // c++;
            cout << i + 1 << " ";
        }
    }
    // cout << c << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
 
    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
