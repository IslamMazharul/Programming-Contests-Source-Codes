#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
using namespace std ;
#define eps 1e-9
#define MAXN 500
bool graph[MAXN][MAXN];
bool seen[MAXN] ;
int match[MAXN] ;
int n, m , s ,v ;

bool bpm( int u ) {

    for( int v = 0; v < n+m ; v++ ){
        if( graph[u][v] ){

            if( seen[v] ) continue;
            seen[v] = 1 ;
            if( match[v]==-1 || bpm( match[v] ) ) {
                match[v] = u ;
                return 1 ;
            }
        }
    }

    return 0;
}

double golper[111][2] ,holes[111][2] ;

bool cango(int i,int j){


    double X = golper[i][0] - holes[j][0] ;
    double Y = golper[i][1] - holes[j][1] ;
    double dis = (X*X+Y*Y) ;

    if(dis > s*v*s*v+eps)  return 0 ;
    return 1 ;
}
int main() {


    ios::sync_with_stdio(false) ;

    freopen("gopher.in","r",stdin) ;
   // freopen("out1.txt","w",stdout) ;

    while(cin>>n>>m>>s>>v){
        double D = double (s*v) ;
        FOR(i,0,n-1) cin>>golper[i][0]>>golper[i][1] ;
        FOR(i,0,m-1) cin>>holes[i][0]>>holes[i][1] ;
        memset(graph,0,sizeof(graph)) ;

        FOR(i,0,n-1){
            FOR(j,0,m){

//                double dist = sqrdist(i,j) ;
  //              if(dist<double(s*v*s*v))
                    if(cango(i,j))
                    graph[i][n+j] = graph[n+j][i]= 1 ;
            }
        }


        memset(match,-1,sizeof(match)) ;


        int cnt = 0 ;

        for( int i = 0; i < n; i++ ){

            memset( seen, 0, sizeof( seen ) );
            if( bpm( i ) ) cnt++;
        }

        cout<<n-cnt<<"\n" ;
    }
}

