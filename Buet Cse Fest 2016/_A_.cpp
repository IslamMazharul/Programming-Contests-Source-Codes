#include <bits/stdc++.h>

using namespace std;

#define si(a) scanf("%d",&a)
#define f first
#define s second
#define mp(a,b) make_pair(a,b)

int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};

int R,C,N,vis[105][105],explosive[105][3];

int dist2(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

bool check(int x,int y)
{
    int i;
    for(i=0;i<N;i++)
        if(dist2(x,y,explosive[i][0],explosive[i][1])<=explosive[i][2]*explosive[i][2])return false;
    return true;
}

void bfs(int stx,int sty)
{
    memset(vis,0,sizeof(vis));
    if(!check(stx,sty))return ;
    queue<pair<int,int> > q;
    q.push(mp(stx,sty));
    vis[stx][sty]=1;
    while(!q.empty()){
        pair<int,int> now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tox=now.f+X[i],toy=now.s+Y[i];
            if(tox<0 || tox>R || toy<0 || toy>C || !check(tox,toy) || vis[tox][toy])
                continue;
            vis[tox][toy]=1;
            q.push(mp(tox,toy));
        }
    }
    return ;
}

int dragon[3][2];

void solve(int ca)
{
    si(R);si(C);si(N);
    int i;
    for(i=0;i<N;i++){
        si(explosive[i][0]);
        si(explosive[i][1]);
        si(explosive[i][2]);
    }
    for(i=0;i<3;i++){
        si(dragon[i][0]);si(dragon[i][1]);
    }
    int cx,cy;si(cx);si(cy);
    bfs(cx,cy);
    cout<<"Case No "<<ca++<<" : " ;
    for(i=0;i<3;i++){
        if(vis[dragon[i][0]][dragon[i][1]]){
            printf("YES\n");
            return ;
        }
    }
    printf("NO\n");
    return ;
}

int main()
{
    freopen("in.in","r",stdin) ;
    freopen("out2.txt","w",stdout) ;
    int t;
    si(t);
    for(int ca=1;ca<=t;ca++)
        solve(ca);
    return 0;
}
