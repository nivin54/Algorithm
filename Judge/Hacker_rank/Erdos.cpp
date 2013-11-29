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
vector<int > node[10015];
int main()
{
	int p,n,i;
	while(scanf("%d%d",&p,&n)&&p+n)
	{
			map<string,int> hash;
			getchar();
			int key=1;
			string line,need,temp;
			LOOP(i,p)
			{
				getline(cin,line);
				cout<<line<<endl;
				stringstream ss(line);
				getline(ss,need,':');
				cout<<need<<endl;
				vector<int> graph;
				int bit=0;
				for(unsigned int i=0;i<=need.length();i++)
				{
					if(need[i]==','||i==need.length())
					{	
							bit+=1;
							if(bit==2)
							{	
								if(hash[temp]==0&&temp!="Erdos, P.")
								{
									hash[temp]=key;key++;
									
								}
								//cout<<temp<<" "<<hash[temp]<<endl;
								graph.push_back(hash[temp]);
								temp.clear();
								bit=0;
								i++;
								continue;
							}
					}
					temp+=need[i];
				}
				temp.clear();	
				for(unsigned int i=0;i<graph.size();i++)
						for(unsigned int j=1;j<graph.size();j++)
							{
								node[graph[i]].push_back(graph[j]);
								node[graph[j]].push_back(graph[i]);
							}
			
			}
		
	}
  return 0;
}
