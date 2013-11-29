#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define FOR(a,b,c) for(a=b;a<=c;a++)
#define ROF(a,b,c) for(a=b;a>=c;a--)
#define ii pair < int , int >
#define st first
#define nd second
#define inf 1000000000
#define LL long long
#define mp make_pair
#define pb push_back
#define int LL

using namespace std;

int N,M,mx;
int ans[5005];
int res[5005];
int V[5005];
int K[5005];
int A[5005];
int B[5005];
int D[5005];

void read()
{
	register int i,j,a,b,v,k;

	cin >> N >> M;

	FOR(i,1,N)
		ans[i] = inf;

	FOR(i,1,M)
	{
		scanf("%lld %lld %lld %lld",&k,&a,&b,&v);
		K[i] = k;
		A[i] = a;
		B[i] = b;
		D[i] = v;

		if(k == 1)
			FOR(j,a,b)
				V[j] += v;
		else
			FOR(j,a,b)
				ans[j] = min ( ans[j] , v-V[j]);
	}

	FOR(i,1,N)
	{
		if(ans[i] == inf)
			res[i] = 0;
		else
			res[i] = ans[i];
	}

	FOR(i,1,M)
	{
		if(K[i] == 1)
			FOR(j,A[i],B[i])
				ans[j] += D[i];
		else
		{
			mx = -inf;
			FOR(j,A[i],B[i])
				mx = max( mx, ans[j]);

			if(mx != D[i])
			{
				printf("NO\n");
				return ;
			}
		}
	}

	printf("YES\n");

	printf("%lld",res[1]);
	FOR(i,2,N)
	{
		if(res[i] > inf) while(1);
		printf(" %lld",res[i]);
	}
	printf("\n");
}
main()
{
	read();
}
