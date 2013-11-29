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
int b[2*100000+5],m;
vector< vector<pair<int,int > > > list;
int find_diff(int j,int i)
{
	cout<<"Find last "<<endl;
	vector<int> a,b;
	for(int k=i;k<i+m;k++)
	{
		//cout<<k<<endl;
			a.push_back(list[j][k].second);
	}
	sort(a.begin(),a.end());
	int diff=0;
	for(int i=0;i<m;i++)
	{
		if(b[i]==a[i])
				diff+=1;
				
	}
return m-diff;	
}
int main()
{
	int n,p;
	S(n),S(m),S(p);
	int a[n+1];
	LOOP(i,n)
		S(a[i]);
	LOOP(i,m)
		S(b[i]);
	sort(b,b+m);
	for(int i=0;i<p;i++)
	{
			vector< pair<int,int> > ans;
			for(int j=i;j<n;j+=p)
						ans.push_back(pair<int,int>(j+1,a[j]));				
			
			list.push_back(ans);	
	}
	int size=list.size();
	cout<<size<<endl;
	vector<int> result;
	for(int j=0;j<size;j++)
	{
		int size1=list[j].size();		
		if(size1>=m)
		for(int i=0;i<size1;)
		{	
			int sum=size1;
			if(i+m<size1)
					sum=find_diff(j,i);	
			if(sum==0)
						result.push_back(list[j][i].first);		
			if(sum==0)
					sum=1;
			i+=sum;
		}	
	}	
	cout<<result.size()<<endl;
	for(unsigned int i=0;i<result.size();i++)
			cout<<result[i]<<" ";
return 0;	
}
