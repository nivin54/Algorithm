#include <cstdio>
#include <cmath>
#define MAXN 100
int M[MAXN]; 
/* M[i] = the index of the minimum element from A[i*sqrt(N)] to A[i*sqrt(N)+sqrt(N)-1] */
int size_m; // stores the size of the M array

void RMQ_SPLIT(int A[],int N){
	size_m =0;
	for(int i=0;i<N;){
		int minindex = i;
		for(int j=0;j<(int)sqrt(N) && i<N;j++){
			if(A[i]<A[minindex])
				minindex=i;
			i++;
		}
		M[size_m++]=minindex;
	}
}
int RMQ(int A[],int s,int e,int N){
	int start = s/(int)sqrt(N); // this will compute the starting index of the M array 
	int ans = A[M[start]]; 
	int end = e/(int)sqrt(N); // ending index of the M array
	for(int i=start;i<end;i++){
		if(A[M[i]]<ans)
			ans=A[M[i]];
	}
	for(int i=end*sqrt(N);i<=e;i++){
		if(A[i]<ans)
			ans = A[i];
	}
	return ans;
}
// driver programme
int main(){
	int A[10] = {3,1,2,-1,5,4,6,0,9,8};
	RMQ_SPLIT(A,10);
	printf("\n");
	int s,e;
	scanf("%d %d",&s,&e);
	printf("%d\n",RMQ(A,s,e,10));
	return 0;
}
