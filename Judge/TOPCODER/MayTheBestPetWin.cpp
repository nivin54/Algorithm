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
class MayTheBestPetWin {
	public:
	bool memo[51][10001*51];
	void solve(int index,int mtx,int mtm,int msx,int msm) //mtx denotes the maximum summation value t can have mtm denote the minimum summation value tat in can have
	{
				int v1=mtx-msm; //Two possiblity like the one said in editorial you can choose minimum for t and maxmimum for s
				int v2=mtm-msx; // Vice-versa
				if(index==-1) //Base case
				{
					return ans=min(ans,max(abs(v1),abs(v2)));
						
				}
				int &r=memo[at][max(abs(v1),abs(v2))];
				if(r)	
						return;
				solve(index-1,mtx+B[index],mtm+A[index],msx,msm);
				solve(index-1,mtx,mtm,msx+B[index],msm+A[index]);
				r=true;
				return;
	}
	}
	
	int calc(vector <int> A, vector <int> B) {
		
		
		
		
	}
};
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
		cout << "Testing MayTheBestPetWin (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1385462432;
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
		MayTheBestPetWin _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {3,4,4,7};
				int B[] = {3,4,4,7};
				_expected = 2;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {1,3,5,4,5};
				int B[] = {2,5,6,8,7};
				_expected = 5;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015};
				int B[] = {7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574};
				_expected = 52873;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 3:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
