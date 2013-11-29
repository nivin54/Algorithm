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
#define MAXN 10000
#define LOGN 20 //IT IS APPROX EQUAL VALUE 13
#define SQT  1055
using namespace std;
//int sqt=sqrt(MAXN);
int QUERY[MAXN][MAXN],A[MAXN],Q[SQT],QS[MAXN][LOGN];
/*--------------------------------------------------------------------------------------------------------------------------------*/
//1 DYNAMIC APPROACH
/*--------------------------------------------------------------------------------------------------------------------------------*/
int CONSTRUCT_Navie(int N)//THIS IS ALGORITHM BASED ON DYNAMIC PROGRAMMING.
{
		for(int i=1;i<=N;i++)
				QUERY[i][i]=i;		
		for(int i=1;i<=N;i++) //WHAT I DO IS I START FROM EACH INDEX THEN TRY TO COMPUTE THE MINIMUM VALUE
			for(int j=i+1;j<=N;j++) // YOU ALREDY COMPUTED THE MINIMUM VALUE FOR THE INDEX J-1 THEN CHECK IF THE CURREENT IS SMALLER OR GREATER.
				{
						
						if(A[QUERY[i][j-1]]<A[j])	// ABOVE MENTIONED IDEA IS IMPLIMENTED HERE
									QUERY[i][j]=QUERY[i][j-1];	
						else
									QUERY[i][j]=j;
				}
		return 1; //SUCESS CONTRUCTION OF SOLUTION .		
}
/*--------------------------------------------------------------------------------------------------------------------------------*/
//2 SQRT(N) IDEA
/* -------------------------------------------------------------------------------------------------------------------------------*/
void Construct_Sqrt(int N)
{
		int i=1,ptr=1,sqt;
		sqt=sqrt(N);
		while(i<=N)		//YOU THE START THE LOOP FROM I 1 N RUN THE LOOP TO N.
		{
				for(int j=i;j<min(N+1,i+sqt);j++)	//NOW WHAT YOU DO IS START J = I N RUN THE LOOP TO J<I+SQRT(N) N KEEP INCREMENTING FOR THE NEXT J
				{
						if(j==i)
							 Q[ptr]=j;	//INTIALLY YOU DECLARE THE PTR TO J
						else if(A[Q[ptr]]>A[j])
								Q[ptr]=j;	//IF THE NEW ELEMENT IS GREATER THEN CHANGE THE Q[PTR] TO J.
				}
				ptr+=1;
				i+=sqt;
		}
}
int Find_Min(int idx,int Min) //I WROTE A SEPARATE MODULE TO FIND THE MINIMUM OF TWO INDEX.
{
		if(A[idx]<A[Min])
				return idx;
		return Min;	
}
int Sqrt_Query(int l,int r,int N)
{
		int sqt=sqrt(N),Min,start,end;
		Min=l;//NOW YOU HAVE DECLARED THE MINIMUM INDEX.
		start=l/sqt+1;end=r/sqt;//YOU HAVE STARTING AND THE ENDING. WE NEED TO INCEREMENT THE START INDEX
		if(l!=start*sqt-(sqt-1)||start>end)//IF THE START AND THE MULTIPLE ARE MATCHING OR WHEN START > END THIS OCCURS WHEN 	
		{						//L IS NOT A MULIPLE AND EVEN END IS NOT A MULTIPLE 
			for(int i=l;i<=min(start*sqt,r);i++)
						Min=Find_Min(i,Min);	
			start++;	//ONCE I HAVE COME HERE IT MEANS I CANNOT USE THE CURRENT START INDEX
		}
		while(start<=end)
		{
				Min=Find_Min(Q[start],Min);
				start++;
		}
		if(end)
		for(int i=end*sqt;i<=r;i++)
				Min=Find_Min(i,Min);
		return A[Min];
}
/*--------------------------------------------------------------------------------------------------------------------------------*/
//(3) Sparse Table (ST) Algorithm
/*--------------------------------------------------------------------------------------------------------------------------------*/
void Construct_Sparse(int N) //BULIDING MY OWN SPARSE TABLE CONCEPT IS AWESOME WORKS LIKE BIT TREE NEED TO UNDERSTAND HOW IT IS ABLE TO FILL THE RANGE 
{							//WISELY NOW TO GO WITH THE PROBLEM.IMPLEMENTATION STARTS FROM HERE.	
	
		for(int i=1;i<=N;i++)	//THIS COVERS ALL THE ELEMENTS WHOES R-L+1 IS OF LENGTH 1
				QS[i][0]=i;
			
		for(int j=1;1<<j <= N;j++)
			for(int i=1; (i + (1<<j) -1) <=N;i++)
			{
						if(A[QS[i][j-1]]<A[QS[i+(1<<(j-1))][j-1]])
								QS[i][j]=QS[i][j-1];
						else
								QS[i][j]=QS[i+(1<<(j-1))][j-1];
			}
}
//NOW WE HAVE CONSTRUCTED THE SPARESE TREE NOW QUERY PART IS OBVIOUSLY EASY ONE. :)
int Query_Sparse(int l,int r,int N)
{
		int k=log(r-l+1); //NUMBER OF BITS NOW WE NEED TO FIND THE RANGE IN IT FALLS.
		if(A[QS[l][k]]<=A[QS[r-(1<<k)+1][k]])
				return A[QS[l][k]];
		return A[QS[r-(1<<k)+1][k]];
}

/*--------------------------------------------------------------------------------------------------------------------------------*/
//4) Segment Tree Approach
/*--------------------------------------------------------------------------------------------------------------------------------*/
//BEST TO USE SEGMENT TREE BECAUSE IT ALWAYS GIVES US LOG(N) FOR ALL SOLUTION. 
//WE PREFER SEGMENT TREE FROM OTHERS BECAUSE EVEN THE UPADTION OF TREE BECAUSE EASIER.
//SO IN LCA PROBLEM EVEN IF THE ANCESTER GETS CHANGED THEN WE CAN DO A LOG(N) UPDATE AND DO A QUERY PROCESS TO THE GET RESULT.









/*---------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	cin>>m;
	Construct_Sqrt(n);
	Construct_Sparse(n);
	for(int i=1;i<=m;i++)
	{
			int l,r;
			cin>>l>>r;
			cout<<Sqrt_Query(l,r,n)<<endl;
			cout<<Query_Sparse(l,r,n)<<endl;
	}	
return 0;	
}
