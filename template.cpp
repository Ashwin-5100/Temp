#include <bits/stdc++.h>

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;


typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
// find by order returns poller to the element

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif

#define ll long long
#define pb(x) push_back(x)
const ll mod = 1e6+10;
vector<bool> isprime(mod, 1);
vector<int> ans;
void seive()
{
     isprime[0] = isprime[1] = 0;
     for (ll  i = 2; i * i < mod; i++)
     {
        if (isprime[i] == 1)
        {
           for (ll j = 2 * i; j < mod; j += i)
           {
              isprime[j] = 0;
           }
        }
     }  
}

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
                  res = (res * a) % m;
                  // res = mod_mul(res, a, m);
               }
              a = (a * a) % m;
              // a = mod_mul(a, a, m);
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

inline ll power(ll a, ll b)
         {
             ll x = 1;
             while (b)
             {
                 if (b & 1)
                     x = (x % mod * a % mod) % mod;
                 a = (a % mod * a % mod) % mod;
                 b >>= 1;
             }
             return x % mod;
         }

long long lcm(long long a, long long b)
         {
             return a * b / __gcd(a, b);
         }

bool customSort(const pair<ll, ll> &a, const pair<ll, ll> &b)
         {
             return (a.first < b.first)|| (a.first == b.first && a.second > b.second);
         }
inline bool cash(pair<ll, double> x, pair<ll, double> y)
         {
             if(x.second==y.second)
             {
               return x.first<y.first;
             }
             return x.second > y.second;
         }

ll mex(vector<ll> &arr)
{
    ll n = arr.size();
    unordered_map<ll,ll> mp;   
    for (ll i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (ll i = 0; i <= n + 1; i++)
    {
        if (mp[i] == 0)
        {
            return i;
        }
    }
    return n + 1;
}



vector<ll> segTree;

ll merge(ll a, ll b)
{
    return (a+b);
} 

void build(vector<int> &v, ll start, ll end, ll index)
{
    if(start == end)
    {
        segTree[index] = v[start];
        return; 
    }   
    ll mid = (start + end) /2;
    build(v, start, mid, index*2);
    build(v, mid+1, end, index*2+1);
    segTree[index] = merge(segTree[index*2] , segTree[index*2+1]);
}
void update(vector<int> &v, ll start, ll end, ll index, ll pos, ll val)
{
    if(start == end)
    {
        v[pos] = val;
        segTree[index] = v[pos];
        return;
    }
    int mid = (start + end)/2;
    if(pos <= mid)
    {
        update(v, start, mid, index*2, pos, val);
    }
    else
    {
        update(v, mid+1, end, index*2+1, pos, val);
    }
     
     segTree[index] = merge(segTree[index*2] , segTree[index*2+1]);
}

 ll query(ll start, ll end, ll index, ll l ,ll r)
{
    if(start >= l && end <= r)
    {
        return segTree[index];
    }
    if(end < l || r < start)
    {
        return 0;
    }
    ll mid = (start+end)/2;
    ll leftans = query(start, mid, index*2, l, r);
    ll rightans = query(mid+1, end, index*2+1, l, r);
    return merge(leftans , rightans);
}

vector<ll> spf(100,-1);
void pre()
{
    int d = 100;
    for(int i=0;i<d;i++)
    {
        spf[i] = i; 
    }
    for(int i=2;i<=d;i++)
    {
        if(spf[i]==i)
        {
            for(int j=2*i; j<=d;j+=i)
            {
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

map<ll,ll> factors(ll x)
{
    map<ll,ll> mp;
    while(x!=1)
    {
        mp[spf[x]]++;
        x/=spf[x];
    }   
    return mp;
}

pair<ll,ll> reduced_comp(ll a, ll k)
{
    ll red = 1;
    ll comp = 1;
    map<ll,ll> mp = factors(a);
    for(auto x: mp)
    {
        if(x.second%k==0)
        {

        }
        else
        {
            ll rem = x.second%k;
            ll act_rem = (k - x.second%k);
            red*=power(x.first, rem);
            comp *= power(x.first, act_rem);
        }
    }
    return {red, comp};
}

void solve()
{   
   string a,b;
    cin >> a >> b;
    int n = a.size();
    int front=0;
    int j=n-1;
    int ans=0;
    vector<int> v(26, 0);
    for(int i=0;i<n;)
    {
        while(a[i] == b[front])
        {
            front++;
            i++;
        }
        while(i<=j && j >= 0 && v[b[front] - 'a']==0)
        {
            v[a[j]-'a']++;
            j--;
            front++;
            ans++;
        }
        i++;
        
    }
    cout << ans << endl;
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
   ll test = 1;
   // cin >> test;
   int c=0;
   // seive();
   cout << fixed << setprecision(10);  
   while (c < test)  
   {
         debug(test, c + 1);   
         c++;
         // cout<<"Case "<<c<<": ";
         solve();
         crndl; 
   }
    return 0;
}
