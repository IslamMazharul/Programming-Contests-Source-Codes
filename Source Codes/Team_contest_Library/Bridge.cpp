#include <bits/stdc++.h>
#define MAXN 1007
using namespace std ;
int n,m ;
vector<int>to[MAXN];
int dfsn[MAXN],low[MAXN],tm;
vector<pair<int,int> >ans;
void dfs(int u,int p){
	
    dfsn[u]=low[u]=++tm;
    for(int i=0;i<(int)to[u].size();i++){
        
        int v=to[u][i];
        if(!dfsn[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfsn[v])
                ans.push_back(make_pair(u,v));
        }else if(v!=p) low[u]=min(low[u],dfsn[v]);

    }
}

int main(){
	
    
    int u,v ;
    while(cin>>n>>m){
		
        if(!n && !m) break ;
        for(int i=0 ;i<n;i++) to[i].clear();
        for(int i=0;i<m;i++){
			cin>>u>>v ;
			to[u].push_back(v) ;
			to[v].push_back(u) ;
		}

        tm=0 ;
        ans.clear() ; 
        
        memset(dfsn,0,sizeof(dfsn)) ;
        memset(low,0,sizeof(low)) ;

        for(int i=0;i<n;i++){
        	if(!dfsn[i])   dfs(i,-1);
        }

       for(int i=0;i<(int)ans.size();i++)
           if(ans[i].first>ans[i].second)
              swap(ans[i].first,ans[i].second);
        sort(ans.begin(),ans.end());
        printf("%d",int(ans.size()));
        for(int i=0;i<(int)ans.size();i++)
			printf(" %d %d",ans[i].first,ans[i].second);
        cout<<"\n" ;
    }
    
    return 0;
}
