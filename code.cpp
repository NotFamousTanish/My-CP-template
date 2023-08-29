/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define F first 
#define S second
#define pb push_back
#define pp pop_back
#define nl endl
#define um unordered_map
#define mm multimap
#define MP make_pair
#define f front 
#define ps push
#define li list<int>
#define qi queue<int>
#define pf push_front
#define ub upper_bound
#define pi pair<int,int>
#define mxpqi priority_queue<int>
#define mnpqi priority_queue<int>
#define inps string s; cin>>s
#define inpn ll n; cin>>n
#define inpv(a,n) for(int i=0; i<n; i++)cin>>a[i];
#define inpc char c; cin>>c
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a) for(auto it: a)cout<<it<<" ";cout<<endl;
#define print1(a) for(auto it: a)cout<<it.F<<" "<<it.S<<" "<<endl;
#define print2(a,x,y) for(int i=x; i<y; i++)cout<<a[i]<<" "<<endl;
#define vi vector<int>
#define mll map<ll,int>
#define vll vector<long long>
#define pll pair<long long, long long>
#define mi map<int,int>
using namespace std;
using namespace __gnu_pbds;


//Policy Based Data Structure starts
typedef tree<int,null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>pbds;
//Policy Based Data Structure Ends

//bug catcher starts
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
//bug catcher ends

class Compare {
public:
     bool operator()(pair<int, int> below, pair<int, int> above)
     {
          if (below.first > above.first) {
               return true;
          }
          else if (below.first == above.first
                    && below.second < above.second) {
               return true;
          }

          return false;
     }
};

bool isPrime(int &n) {

    if (n < 2) { return false; }
    if (n == 2) { return true; }

    for (int i=2; i <= n / 2; ++i)
        if (n % i == 0)
            return false;

    return true;
}

bool sorted(vi &v){
	for(int i=1; i<v.size(); i++){
		if(v[i]<v[i-1]){return false;}
	}
	return true;
}

long long _pow(long long a, long long b, long long xmod) {
     long long ans = 1;
     for (long long i = 0; i < 63; ++i) {
          if (((1ll << i)&b)) {
               ans = (ans * a) % xmod;
          }
          a = (a * a) % xmod;
     }
     return ans;
}

long long mmul(long long a, long long b, long long xmod) {
     a = a % xmod;
     b = b % xmod;
     return ((a * b) % xmod);
}

long long minv(long long a, long long xmod) {
     return (_pow(a, xmod - 2, xmod));
}

long long madd(long long a, long long b, long long xmod) {
     a %= xmod;
     b %= xmod;
     return ((a + b) % xmod);
}

long long msub(long long a, long long b, long long xmod) {
     a %= xmod;
     b %= xmod;
     return ((a - b + xmod) % xmod);
}

void print2d(vector<vll>& v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}

long long gcd(long long a, long long b) {
     if (a == 0 || b == 0)
          return max(a, b);
     return gcd(b, a % b);
}

ll min(ll a, ll b){
	if(a>b){return b;}
	else{return a;}
}

void printPrimes(ll e, vll &v){
     vll p(e+10,0);
     p[0]=p[1]=0;
     p[2]=1;
     //all possible odd marked as prime
     for(int i=3; i<=e; i+=2){
          p[i]=1;
     }

     //sieve starts
     for(int i=3; i<=e; i++){
          if(p[i]==1){
               for(int j=i*i; j<=e; j+=i){
                    p[j]=0;
               }
          }
     }

     for(int i=0; i<=e; i++){
          if(p[i]==1){
               v.pb(i);
          }
     }
}

bool allsame(vll &v){
	for(int i=1; i<v.size(); i++){
		if(v[i]!=v[i-1]){return false;}
	}
	return true;
}

bool cmp(int a, int b){
	return a>b;
}

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}

int fibo(int dp[], int n){
     if(n<=1){return n;}
     if(dp[n]!=-1){return dp[n];}
     bug(n,dp[n]);
     return dp[n]=fibo(dp,n-1)+fibo(dp,n-2);
}

ll gcd(ll a, ll  b){
     if(b==0){return a;}
     return gcd(b,a%b);
}

ll lcm(ll a, ll b){
     ll g = gcd(a,b);
     return (a*b)/g;
}

void solve(){
     
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#endif
	clock_t z = clock();
	//code starts
	int t=1;
	cin>>t;
	while(t--)solve();
	//code ends
	cerr<<"Run Time: "<<((double)(clock()-z)/CLOCKS_PER_SEC);
	//return 0;
}
