#include <bits/stdc++.h>
using namespace std ;
const int MAXN=10001;
int n;
vector<int>g[MAXN];
int dfsn[MAXN],low[MAXN],tim ;
vector<pair<int,int> >ans ;

void dfs(int u,int p){
    dfsn[u]=low[u]=++tim ;
    for(int i=0;i<(int)g[u].size();i++){
        int v=g[u][i];
        if(!dfsn[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfsn[v])
                ans.push_back(make_pair(u,v));
        }else if(v!=p)low[u]=min(low[u],dfsn[v]);

    }
}
int main(){
	// freopen("//home//mazhar//Deskgp//in.txt","r",stdin) ;
    int tc;
    scanf("%d",&tc);
    for(int kase=1;kase<=tc;kase++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++){
            int u,k;
            scanf("%d (%d)",&u,&k);

            while(k--){
                int v;
                scanf("%d",&v);
                g[u+1].push_back(v+1);
            }
        }

        tim=0;
        ans.clear();
        memset(dfsn,0,sizeof(dfsn)) ;
        memset(low,0,sizeof(low)) ;

        for(int i=1;i<=n;i++){
        	if(!dfsn[i])   dfs(i,0);
        }

       for(int i=0;i<(int)ans.size();i++)
           if(ans[i].first>ans[i].second)
              swap(ans[i].first,ans[i].second);
        sort(ans.begin(),ans.end());
        printf("Case %d:\n",kase);
        printf("%d critical links\n",int(ans.size()));

        for(int i=0;i<(int)ans.size();i++)

        	printf("%d - %d\n",ans[i].first-1,ans[i].second-1);
    }
    return 0;
}
