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
#define FOR(i,a,b) for(int i=a;i<b;i++)
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
int main()
{
		int n,Max=0;
		S(n);
		int arr[n+2];
		FOR(i,1,n+1)
			S(arr[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				{
					int aux=abs(i-arr[i])+abs(j-arr[j]);
					cout<<aux<<" ";
					if(Max<aux)
						Max=aux;
				}
		int cnt=0,sum=0;
		int I,J;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				{
					int aux=abs(i-arr[i])+abs(j-arr[j]);
					if(Max==aux)
						{cnt++;I=i,J=j;}
				}
		swap(arr[I],arr[J]);
		for (int i = 2; i <=n; i = i + 1)	
		{
			int j = i; 
			while (j > 1 && arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]); // swap elements a[j] and a[j - 1]
				sum++;	
				j = j - 1;
			}
		}
		cout<<sum<<" "<<cnt<<endl;
					
		
return 0;	
}
