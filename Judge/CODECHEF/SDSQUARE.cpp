#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<stack>
#include<set>
#include<sstream>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#define FOR(i,a,b) for(i=a;i<b;i++)
#define LOOP(i,a) FOR(i,0,a)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))
#define S(x) scanf("%d",&x)
#define P(x) printf("%d",x)
#define SLL(x) scanf(LL,&x)
#define PLL(x) printf(LL,x)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ll unsigned long long
#define MOD 1000000000+7
#define CLEN(c, P) c=strlen(P)
#define DEBUG
#ifdef DEBUG
#define deb(args...) {dbg,args; cerr<<endl;}
#else
#define deb(args...) // Just strip off all debug tokens
#endif
struct debugger
{
template<typename T> debugger& operator , (const T& v)
{
std::cerr<<v<<" ";
return *this;
}
} dbg;
template< class T > T abst(const T &n) { return (n < 0 ? -n : n); }
template< class T > T max3(const T &a, const T &b, const T &c) { return max2(a, max2(b, c)); }
template< class T > T min3(const T &a, const T &b, const T &c) { return min2(a, min2(b, c)); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T sq(const T &x) { return x * x; }
using namespace std;
int dp[100015];
int find_perfect(long long k)
{
		while(k)
		{
				int mod=k%10;
				k/=10;
				if(mod==1||mod==0||mod==4||mod==9)
					continue;
				return 0;	
		} 
		return 1;	
}
void precompute()
{
		dp[0]=0;
		for(long long i=1;i<=100000;i++)
				dp[i]=dp[i-1]+find_perfect(i*i);	
}
int main()
{
	long long t,a,b;
	cin>>t;
	precompute();
	while(t--)
	{
			cin>>a>>b;
			long long c=sqrt(a);
			cout<<dp[(int)sqrt(b)]-dp[c-((a==c*c)?1:0)]<<endl;	
	
	}
return 0;	
}
