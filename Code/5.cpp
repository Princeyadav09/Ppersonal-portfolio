/*


            >>-------<< Author : Prince Yadav >>-------<<              


*/
#include<bits/stdc++.h>


#define RUN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238462
#define inf 1e18
#define all(v) v.begin(),v.end()
#define pb  push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define lp(n) for(int i=0;i<n;i++)
#define nl "\n"
#define lp1(n) for(int i=1;i<=n;i++)
#define mod 1000000007
#define MOD1 998244353
#define in(v)            for(auto &item : v) cin>>item;
#define int long long
using namespace std;

//typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
//void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



int isprime(int n)
{
  if(n==2  || n==3 || n==5 || n==7  ) 
  {
    return 1;
  }
  else
  {
    if(n%2==0)return 0;
    for(int i=3;i<=sqrt(n);i+=2)
    {
      if(n%i==0)
      {
        return 0;
      }
    }
  }
  return 1;
}

 

  bool isprftsq(int n)
  {
    int k=sqrt(n);
    if(k*k==n)return true;
    else return false;
  }

  bool is_palindrom(string s)
  {
    int l=0,r=s.length()-1;
    while(l<=r)
    {
      if(s[l]!=s[r])return false;
      l++;
      r--;
    }
    return true;
  }

vector<int> vprime;
void sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int i=2; i*i<=n; i++)
    {
        if (prime[i] == true)
        {
            for (int j=i*i; j<=n; j+= i)
                prime[j] = false;
        }
    }
    for (int x=2; x<=n; x++)
       if (prime[x])
          vprime.push_back(x);
}

int lcm(int a,int b){ return (a*b)/__gcd(a,b); }

bool cmp(pair<int,int>&p1,pair<int,int>&p2)
{
  if(p1.first<p2.first)return true;
  else if(p1.first==p2.first)
  {
    if(p1.second>p2.second)return true;
  }
  return false;
}

// disjoint set union

const int size_of_dsu=1e4+10;
int parent[size_of_dsu];
int sizes[size_of_dsu];
int cnt=1;
void make(int v){
    parent[v]=v;
    sizes[v]=1;
}

int find(int v){
    if(v==parent[v])return v;
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
      if(sizes[a]<sizes[b])swap(a,b);
       parent[b]=a;
       sizes[a]+=sizes[b];
    } 
}





////////////////////////////////////////////////////////////////////////////////////////

 void solve(){
   int n;cin>>n;
    vector<int> arr(n+1);
    lp1(n)cin>>arr[i];


    vector<int> dp(n+2 , 0);
    int ans = n/2;
    // vi 
    dp[n+1] = 0;

    for(int i = n ; i>=1 ; i--){
        int curr = arr[i];
        dp[curr] = dp[curr+1] + 1;

        if(curr + dp[curr]-1 >= n-curr+1){
            ans = min(ans , curr-1);
        }
    }
    debug(dp)
    cout<<ans<<endl;
 } 
 
////////////////////////////////////////////////////////////////////////////////////////
int32_t main()
{ 
  #ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  #endif
  RUN;
  int t; t=1;
  cin>>t;
  while(t--)
  {
    solve();
  }
}   