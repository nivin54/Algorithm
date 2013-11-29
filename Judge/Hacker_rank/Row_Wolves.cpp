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
int state=0;
pair<long long int,long long int> giventimet(long long int t)
{
	long long int sx=0,sy=0;
	if(t%2==0)
	{
			t/=2;
			if(t%2==0)	//It is in segment number 4
				{sy=-t/2,sx=-t/2;state=4;}
			else //It is in segment number 2
			{sy=t/2+1,sx=t/2+1;state=2;}				
	}
	else
	{
			if((t-1)%4==0) //It is in segment number 1
			{t/=2,sx=((t/2)+1),sy=-t/2;state=1;}
			else   //It is in segment number 3
			{t/=2,sx=-((t/2)+1),sy=(t/2)+1;state=3;}
	}		
	return pair<long long int,long long int>(sx,sy);
}
int main()
{
	long long int q,type,x,y,t;
	scanf("%lld",&q);
	while(q--)
	{
			
		scanf("%lld",&type);
		if(type)
		{
				scanf("%lld%lld",&x,&y);
				long long int ans=0;	
				if(x>=-y && x<y) ans=4*y-2;
				if(y>=x && y<-x) ans=-4*x-1;
				if(x>y && x<=-y+1) ans=-y*4;
				if(y>-x+1 && y<=x) ans=4*x-3;
				ans=ans+1;
				long long int time=0;
				long long int q1=ans/2;
				time=(q1*(q1+1));
				if(ans%2!=0)
				{time+=(ans/2+1);}
				pair<long long int,long long int> co=giventimet(ans);
				time-=(abs(co.first-x)+abs(co.second-y));
				printf("%lld\n",time);
				
		}
		else
		{
				scanf("%lld",&t);	
				long long int sqt,sx=0,sy=0,ans=0,total;
				if(t==0)
					cout<<0<<" "<<0<<endl;
				else
				{
					sqt=sqrt(t)-1;
					while(sqt*sqt+2*sqt+1<t)
						sqt++;
					if(sqt*sqt+sqt>=t)
						{ans=2*sqt;total=sqt*sqt+sqt;}
					else
						{ans=2*sqt+1;total=sqt*sqt+2*sqt+1;}
					pair<long long int ,long long int> co=giventimet(ans);
					if(state==1)
					{sy=co.second;sx=co.first-(total-t);}
					else if(state==2)
					{sx=co.first;sy=co.second-(total-t);}
					else if(state==3)
					{sy=co.second;sx=co.first+(total-t);}
					else
					{sx=co.first;sy=co.second+(total-t);}	
					cout<<sx<<" "<<sy<<endl;
				}
		}		
	}
return 0;	
}
