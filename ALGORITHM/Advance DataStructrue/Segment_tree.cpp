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
#define MAXN 10000
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
/* Simple Segment tree Version 1 */
int tree[4*MAXN],array[MAXN];

/* Bulid the segment tree */
void build(int v,int tl,int tr)
{
		if(tl==tr)
			tree[v]=array[tl];		//Ok this is where I try to save the current element
		else
		{
			int mid=(tl+tr)/2;		//Now you form two segments.
			build(v*2,tl,mid);		//V element has the corresponding index 
			build(v*2+1,mid+1,tr);	//Now open up the segment.
			tree[v]=tree[v*2]+tree[v*2+1];	//Now you cummulative find the sum for two previous segments.
		}
}

/* Query tree */
int query(int v,int l,int r,int tl,int tr)
{
		//When the limits of l & r is not in the boundary of tl & tr it's not checked properly .
		//Need to take of care of it.
		if(l>r)
				return 0;
		if(l==tl&&r==tr)
				return tree[v];
		int mid=(tl+tr)/2;
		return (query(v*2,l,min(r,mid),tl,mid)+query(v*2+1,max(l,mid+1),r,mid+1,tr));
}
int main()
{
	int n,l,r;
	S(n);
	LOOP(i,n)
		S(array[i+1]);
	build(1,1,n);
	while(1)
	{
			S(l),S(r);
			cout<<query(1,l,r,1,n)<<endl;
	}	
return 0;	
}
