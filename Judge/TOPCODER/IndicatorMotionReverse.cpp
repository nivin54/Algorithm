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
class IndicatorMotionReverse {
	public:
	string getMinProgram(vector <string> actions) {
		
		
		
		return "1";
		
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
		cout << "Testing IndicatorMotionReverse (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1385447600;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		IndicatorMotionReverse _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string actions[] = {"-|-|/-/|//////-/"};
				_expected = "F03R02L02R01S05R01L01";
				_received = _obj.getMinProgram(vector <string>(actions, actions+sizeof(actions)/sizeof(string))); break;
			}
			case 1:
			{
				string actions[] = {"N"};
				_expected = "";
				_received = _obj.getMinProgram(vector <string>(actions, actions+sizeof(actions)/sizeof(string))); break;
			}
			case 2:
			{
				string actions[] = {"||||||||||||||||||||||||||||||||||||||||||||||||||",
				                    "||||||||||||||||||||||||||||||||||||||||||||||||||",
				                    "||||||||||||||||||||||||||||||||||||||||||||||||||"};
				_expected = "S50S99";
				_received = _obj.getMinProgram(vector <string>(actions, actions+sizeof(actions)/sizeof(string))); break;
			}
			case 3:
			{
				string actions[] = {"N",
				                    "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
				                    "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
				                    "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
				                    "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
				                    "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
				                    "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
				                    "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N",
				                    "-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N-N"};
				_expected = "L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L01R01L...";
				_received = _obj.getMinProgram(vector <string>(actions, actions+sizeof(actions)/sizeof(string))); break;
			}
			/*case 4:
			{
				string actions[] = ;
				_expected = ;
				_received = _obj.getMinProgram(vector <string>(actions, actions+sizeof(actions)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string actions[] = ;
				_expected = ;
				_received = _obj.getMinProgram(vector <string>(actions, actions+sizeof(actions)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string actions[] = ;
				_expected = ;
				_received = _obj.getMinProgram(vector <string>(actions, actions+sizeof(actions)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
