#include<cstdio>
#include<algorithm>
using namespace std;
struct V
{
    int x,y,l,r;
    bool operator<(const V &a) const
    {
        return l<a.l;
    }
} c[3005];
int u[1005];
void init()
{
    for(int i=0; i<1005; ++i)
        u[i]=i;
}
int find(int x)
{
    if(u[x]!=x)
        u[x]=find(u[x]);
    return u[x];
}
void merge(int x,int y)
{
    u[find(x)]=find(y);
}
int main()
{
    int n,m,ans=-1;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
        scanf("%d%d%d%d",&c[i].x,&c[i].y,&c[i].l,&c[i].r);
    sort(c,c+m); //Sorting done based on .l .
    
    for(int i=0; i<m; ++i) //M is number of edges 
    {
        init();			//Each time you intialize and try to find a 
        for(int j=0; j<m; ++j)
        {
            if(c[j].l>c[i].r)	//Because it's sorted already :).
                break;
            if(c[j].r<c[i].r)	//Here you continue Because already in the range.
                continue;	
            merge(c[j].x,c[j].y);
            if(find(1)==find(n))
            {
                ans=max(ans,c[i].r-c[j].l+1);
                break;
            }
        }
    }
    ans<0?printf("Nice work, Dima!"):printf("%d",ans);
}
