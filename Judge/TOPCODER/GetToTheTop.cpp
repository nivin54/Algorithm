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

#define ll unsigned long long
#define MOD 1000000000+7

template< class T > T abst(const T &n) { return (n < 0 ? -n : n); }
template< class T > T max3(const T &a, const T &b, const T &c) { return max2(a, max2(b, c)); }
template< class T > T min3(const T &a, const T &b, const T &c) { return min2(a, min2(b, c)); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T sq(const T &x) { return x * x; }

using namespace std;
class GetToTheTop {
	public:
	int collectSweets(int K, vector <int> sweets, vector <int> x, vector <int> y, vector <int> stairLength);
};
int size,k;
class Get
{
				public:
				int x1,x2,y1,y2,sw;
				
}S[100];
bool check(Get &a,Get &b)
{
					if((a.x1<=b.x1&&a.x2>=b.x1&&abs(a.y1-b.y1)<=k)||(a.x1<=b.x2&&a.x2>=b.x2&&abs(a.y1-b.y1)<=k)||(a.x1>b.x1&&b.x2>a.x2))
							return true;					
					int sqt=(pow(b.x2-a.x1,2)+pow(b.y2-a.y1,2));
					if(b.x2<a.x1&&sqt<=k*k)
							return true;
					sqt=(pow(b.x1-a.x2,2)+pow(b.y2-a.y1,2));
					if(b.x1>a.x2&&sqt<=k*k)
							return true;
					return false;
}	
int dp[100];
bool cmp(Get a,Get b)
{
				if(a.y1==b.y1){
						if(a.x1==b.x1)
								return a.x2<b.x2;
						return a.x1<b.x1;}
				return a.y1<b.y1;	
}
int memo(int idx)
{
		if(idx==size)
				return 0;
		if(dp[idx]!=-1)
				return dp[idx];
		int sum=dp[idx];
		for(int i=idx-1;i>=0;i--)
			if( (S[i].y1==S[i+1].y1) && check(S[i],S[i+1]) )
					sum+=S[i].sw;
		for(int i=idx+1;i<size;i++)
				if( (S[i].y1==S[i-1].y1) && check(S[i],S[i+1]) )
						sum+=S[i].sw;
		dp[idx]=0; //Important because this marks the elements and it's is not revisited again :).
		for(int i=0;i<size;i++)
		{		
				if(S[idx].y1<S[i].y1&&check(S[idx],S[i]))
						dp[idx]=max(dp[idx],memo(i)+sum);
				else if(i!=idx&&S[idx].y1==S[i].y1&&check(S[idx],S[i]))
						dp[idx]=max(dp[idx],memo(i));
		}
		dp[idx]=max(dp[idx],sum);
		return dp[idx];	
}

int GetToTheTop::collectSweets(int K,vector<int> sweets,vector<int> x,vector<int> y,vector<int> stairLength)
{
					
		SET(dp);
		k=K;
		unsigned int i,sz;
		int ret=0;
		size=sz=x.size();
		LOOP(i,sz)
		{
				S[i].x1=x[i];S[i].y1=y[i];
				S[i].x2=x[i]+stairLength[i];S[i].y2=y[i];		
				S[i].sw=sweets[i];
		}
		sort(S,S+sz,cmp);
		for(i=0;i<sz;i++)
			if(dp[i]==-1)
					ret=max(ret,memo(i));
		return ret;
	
}
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing GetToTheTop (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1384001378;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GetToTheTop _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 2;
				int sweets[] = {1, 2, 3, 4, 3, 5};
				int x[] = {1, 1, 1, 4, 5, 5};
				int y[] = {1, 3, 4, 1, 2, 3};
				int stairLength[] = {2, 1, 1, 2, 1, 1};
				_expected = 13;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 1:
			{
				int K = 4;
				int sweets[] = {2, 8, 7, 4, 1, 4, 7, 5, 11, 4};
				int x[] = {2, 9, 4, 6, 10, 5, 2, 8, 1, 10};
				int y[] = {1, 1, 3, 3, 3, 5, 6, 6, 8, 9};
				int stairLength[] = {2, 2, 1, 2, 2, 2, 4, 3, 2, 2};
				_expected = 47;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 2:
			{
				int K = 10;
				int sweets[] = {1, 3, 5, 7};
				int x[] = {1, 6, 2, 8};
				int y[] = {2, 4, 1, 2};
				int stairLength[] = {4, 1, 7, 4};
				_expected = 16;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 3:
			{
				int K = 3;
				int sweets[] = {80, 20, 15, 13, 10, 7, 8, 9, 1, 4, 3, 15, 14, 19, 22, 12, 6, 15, 10, 30, 1, 1};
				int x[] = {2, 8, 11, 17, 20, 14, 10, 16, 8, 14, 19, 6, 6, 6, 6, 15, 15, 15, 14, 20, 20, 20};
				int y[] = {1, 2, 3, 2, 1, 4, 6, 7, 8, 8, 8, 9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11};
				int stairLength[] = {2, 2, 2, 2, 2, 2, 3, 2, 3, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 129;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 4:
			{
				int K = 10;
				int sweets[] = {0, 10, 11, 2, 0};
				int x[] = {1, 26, 29, 22, 3};
				int y[] = {1, 83, 88, 22, 5};
				int stairLength[] = {11, 1, 23, 15, 8};
				_expected = 0;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 5:
			{
				int K = 5;
				int sweets[] = {2, 0, 5};
				int x[] = {1, 8, 9};
				int y[] = {6, 6, 1};
				int stairLength[] = {3, 6, 3};
				_expected = 7;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			case 6:
			{
				int K = 2;
				int sweets[] = {2, 9, 9, 1, 9, 9, 8};
				int x[] = {10, 8, 6, 6, 8, 7, 3};
				int y[] = {6, 7, 5, 4, 5, 2, 5};
				int stairLength[] = {1, 1, 1, 1, 1, 1, 1};
				_expected = 47;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}
			/*case 7:
			{
				int K = ;
				int sweets[] = ;
				int x[] = ;
				int y[] = ;
				int stairLength[] = ;
				_expected = ;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int K = ;
				int sweets[] = ;
				int x[] = ;
				int y[] = ;
				int stairLength[] = ;
				_expected = ;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int K = ;
				int sweets[] = ;
				int x[] = ;
				int y[] = ;
				int stairLength[] = ;
				_expected = ;
				_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
