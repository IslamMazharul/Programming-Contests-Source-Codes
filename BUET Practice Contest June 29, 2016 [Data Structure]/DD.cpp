/*
 * Mazharul Islam , BUET
 * Problem Link:http://acm.hust.edu.cn/vjudge/contest/view.action?cid=120288#problem/I
 */
using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define endl "\n"
typedef long long  Long;
typedef unsigned long long uint;
typedef string ST;
typedef vector<int> vi;
typedef vector<ST> vs;
typedef map<int,int> mii;
typedef map<ST,int> msi;
typedef set<int> si;
typedef set<ST> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define deb(x) cerr << #x << " = " << x << endl;
#define MAXN 200007
int par[MAXN] ,arr[MAXN],edg[MAXN];
int Find(int u){
    if(par[u]==u) return u ;
    else{
        int ret=Find(par[u]) ;
        par[u]=ret ;
        return ret ;
    }

}

int main(void){

    int n,root;
    cin>>n;
    rep(i,1,n+1){
        par[i]=i ;
    }
    rep(i,1,n+1){
        cin>>edg[i] ;
        if(edg[i]==i) root=i ;
    }
    set<int>SCC ;
    queue<int>loopEdge ;
   // cout<<root<<endl ;
    rep(i,1,n+1){
        if(i==root) continue ;
        int U = Find(i) ;
        int V = Find(edg[i]) ;
        if(U!=V){
            par[U]=V ;
        }else{
            cout<<i<<" "<<edg[i]<<endl ;
            loopEdge.push(i) ; // this edge creates a loop
        }
    }

    rep(i,1,n+1){
        SCC.insert(par[i]) ;
    }
    set<int>::iterator it ;
    int res=0 ;
    while(!loopEdge.empty()){
            int U = edg[loopEdge.front()] ; loopEdge.pop() ;
            int V = Find(U) ;
            if(V!=root){
                res++ ;
                edg[V]=root ;
                par[V]=root ;
            }
    }
   // /*
    printf("%d\n",res) ;
    rep(i,1,n+1){
        printf("%d ",edg[i]) ;
    }
   // */
    return 0;
}
