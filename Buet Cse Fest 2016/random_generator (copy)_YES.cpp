#include <bits/stdc++.h>
using namespace std ;
#define rep(i,a,n) for(__typeof(n) i=a; i<(n); i++)
#define MAXN 100
#define pii pair<int,int>
#define mp make_pair
bool DP[MAXN][MAXN] ;
int dr[] = {0,0,-1,1},dc[] = {-1,1,0,0};
pii source,des ;
vector<pii>path ;
int sqr_distance(int i,int j,int k,int l){

     int dx = (i-k) ;
     int dy = (j-l) ;
     return dx*dx+dy*dy ;
}
void DFS(int r,int c,int depth){
   // cout<<r<<" "<<c<<" "<<depth<<endl ;
    path.push_back(mp(r,c)) ;
    DP[r][c]=1 ;
    if(depth==0) {
        des=mp(r,c) ;
        return ;
    }
    int cnt=1000 ;
    while(cnt--){
        int R = rand()%4 ;
        if(r+dr[R]>=0 && c+dc[R]>=0 && r+dr[R]<=100 && c+dc[R]<=100 && !DP[r+dr[R]][c+dc[R]]){
            DFS(r+dr[R],c+dc[R],depth-1) ;
            return ;
        }
    }
    if(cnt==0){
        des=mp(r,c) ;
    }
}

int main(void){
    freopen("out.txt","w",stdout) ;
    srand (time(NULL));
    source = mp(3,4) ;
    DFS(3,4,50) ;
    /*
    rep(i,0,MAXN+1){
        rep(j,0,MAXN+1){
            if(DP[i][j]) cout<<i<<" "<<j<<endl ;
        }
    }
    */
    //cout<<source.first<<" "<<source.second<<endl ;
    //cout<<des.first<<" "<<des.second<<endl ;
    /*
    for(int i=0;i<path.size();i++){
        cout<<path[i].first<<" "<<path[i].second<<endl ;
    }
    */
    vector<int>v1,v2,v3 ;
    rep(i,0,100){
        int cx = rand()%101 ;
        int cy = rand()%101 ;
        int radius = rand()%100001 ;
        while(radius--){
            bool     ok=1 ;
            rep(j,0,path.size()){
                int x = path[j].first ;
                int y = path[j].second ;
                 if(sqr_distance(x,y,cx,cy)<= radius*radius){
                        ok=0 ;
                        break ;
                }
            }
            //if(radius) cout<<cx<<" "<<cy<<" "<<radius<<endl ;
        if(ok) {
                v1.push_back(cx) ;
                v2.push_back(cy) ;
                v3.push_back(radius) ;
              //  cout<<cx<<" "<<cy<<" "<<radius<<endl ;
                break ;
        }
        }
    }

    /*
    rep(i,0,path.size()){
        rep(j,0,v1.size()){
            if(sqr_distance(path[i].first,path[i].second,v1[j],v2[j])<=v3[j]*v3[j]){
               cout<<"NO" ;
            }
        }
    }

    */
    cout<<MAXN<<" "<<MAXN<<endl ;
    cout<<v1.size()<<endl ; // circles
    rep(i,0,v1.size()){
            cout<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<endl ;
    }
    cout<<path[0].first<<" "<<path[0].second<<endl  ;
    cout<<path[0].first+1<<" "<<path[0].second+1<<endl ;
    cout<<path[0].first+2<<" "<<path[0].second+2<<endl ;
    cout<<path[path.size()-1].first<<" "<<path[path.size()-1].second<<endl ;
    return 0 ;
}
/*
3 4 50
3 5 49
3 6 48
4 6 47
4 5 46
4 4 45
4 3 44
5 3 43
5 4 42
6 4 41
6 3 40
6 2 39
5 2 38
5 1 37
6 1 36
6 0 35
5 0 34
4 0 33
3 0 32
3 1 31
4 1 30
4 2 29
3 2 28
2 2 27
2 3 26
1 3 25
1 4 24
2 4 23
2 5 22
1 5 21
0 5 20
0 4 19
0 3 18
0 2 17
0 1 16
0 0 15
1 0 14
2 0 13
2 1 12
1 1 11
1 2 10
*/
