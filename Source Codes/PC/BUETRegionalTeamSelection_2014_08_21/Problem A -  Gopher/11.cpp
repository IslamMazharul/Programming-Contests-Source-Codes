#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#define EPS 1e-9
using namespace std;
/*points from 0 to n denotes gophers,and n+1 to n+m denotes holes*/
int link[210];
bool vis[210];
vector<int>adj[210];
double D;
struct point{
    double x,y;
};
point arr[210];
inline double sqdist(int i,int j)
{
    return ((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)+(arr[i].y-arr[j].y)*(arr[i].y-arr[j].y));
}
bool DFS(int u)
{
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        if(!vis[v]){
            vis[v]=true;
            if(link[v]==-1||DFS(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}
int main (){

    freopen("gopher.in","r",stdin) ;
    int j,i,n,m,s,v,cnt;
    while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
    {
        for(i=0; i<n; i++) scanf("%lf%lf",&arr[i].x,&arr[i].y);
        for(i=n; i<m+n; i++) scanf("%lf%lf",&arr[i].x,&arr[i].y);

        D=(double)(s*v);

        for(i=0; i<n+m; i++)  adj[i].clear();
        for(i=0; i<n; i++){
            for(j=n; j<n+m; j++){
                double dist=sqdist(i,j);
                if(dist>D*D+EPS)  continue;
				//edge exists when distance<=D
                adj[i].push_back(j);
                adj[j].push_back(i);
                //printf("%d %d\n",i,j);
            }
        }
        for(i=0; i<n+m; i++)  link[i]=-1;
		//finding maximum matching
        for(cnt=0,i=0; i<n; i++)
        {
            for(j=0; j<n+m; j++)  vis[j]=false;
            if(DFS(i))  cnt++;
        }
        printf("%d\n",n-cnt);
    }
    return 0;

}
