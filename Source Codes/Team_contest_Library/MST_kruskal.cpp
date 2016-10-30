/*                     MST_Kruskal - From http://www.shafaetsplanet.com
========================================================================================================================*/

struct edge{
	
    int u,v,w;
    bool operator < ( const edge& p ) const
    {      
        return w < p.w;   
    }
};

int par[MAXN];
vector<edge>e;
int find(int r){
   return (par[r]==r) ? r:  find(par[r]);
}

int mst(int n){
	
    sort(e.begin(),e.end());            
    for(int i=1;i<=n;i++)par[i]=i;
     
    int count=0,s=0;
    for(int i=0;i<(int)e.size();i++){
		
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            s+=e[i].w;
            if(count==n-1) break;
        }
    }
    
    return s;
}
