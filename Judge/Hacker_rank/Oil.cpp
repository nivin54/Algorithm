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
struct node
{
		int l,r;//,weight;
		node()
		{
				l=r;
		}
		node(int i,int j)
		{
				l=i,r=j;
			
		}
};

int main()
{
	
	int r,c,i,j,aux,Max=10e8,R,C;
	int bits[55][55];
	CLR(bits);
	vector<node> ans;
	S(r),S(c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			{
					S(aux);
					if(aux==1)
								ans.push_back(node(i,j));
			}
	int size=ans.size();
	for(int i=1;i<=size;i++)
	{
			int w=0;
			for(int j=1;j<=size;j++)
					if(i!=j)
							w+=max(abs(ans[i].l-ans[j].l),abs(ans[i].r-ans[j].r));
			if(Max>w)
				R=ans[i].l,C=ans[i].r;	
	}
	int mask[55][55];
	CLR(mask);
	queue<pair<int,int > > Q;
	mask[R][C]=1;
	Q.push_back(0);
	while(size)
	{
			
			
		
		
		
	
	}
return 0;	
}
