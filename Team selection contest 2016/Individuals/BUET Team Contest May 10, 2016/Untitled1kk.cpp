#include <bits/stdc++.h>
using namespace std ;
#define MAXN 1007
bool broken[MAXN][MAXN] ;
int main(void){

    int n,TC,CT=1,m,o,r,c ;
    cin>>TC ;
    while(TC--){
        cin>>n>>m>>o;
        memset(broken,0,sizeof(broken)) ;
        for(int i=0;i<o;i++){
            cin>>r>>c ;
            broken[r][c]=1 ;
        }
        m++ ;
        for(int i=0;i<n;i++) broken[i][m-1]=1 ;
        int res1=0,res2=0 ;
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<broken[i][j]<<" " ;
            }
            cout<<endl ;
        }
        */
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int k=j;
                while(!broken[i][j]) j++ ;
               // cout<<j<<" "<<k<<endl ;
                res1 += (j-k+1)/2 ;
                res2 += (j-k+2)/3 ;
            }
        }
        cout<<"Case #"<<CT++<<": " ;
        cout<<res1<<" "<<res2<<endl ;
    }
    return 0 ;
}
