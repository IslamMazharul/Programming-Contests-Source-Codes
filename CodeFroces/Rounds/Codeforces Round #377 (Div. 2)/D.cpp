#include <bits/stdc++.h>
using namespace std ;
#define MAXN 100000
int n , m,arr[MAXN+7],days[MAXN+7];
bool flag[MAXN+7] ;
bool F(int Len){
    memset(flag,0,sizeof(flag)) ;
    flag[0]=1 ;
    vector<int>vec ;
    int takedays=Len ;
    for(int i=Len-1;i>=0;i--){
            if(!flag[arr[i]]){
                flag[arr[i]]=1 ;
                vec.push_back(i) ;
            }
    }
    reverse(vec.begin(),vec.end()) ;
    int idx=0 ,take=0;
    for(int i=0;i<Len;i++){
        if(vec[idx]==i){
            if(take<days[arr[i]]){
                return 0 ;
            }
            take-=days[arr[i]] ;
            idx++ ;
            if(idx==vec.size()) return 1 ;
        }
        else{
            take++ ;
        }
    }
    return 1 ;
}

int BS(){
    int lo=0 ;
    int hi=n ;
    int mid ;
    if(!F(hi)){
        return -1 ;
    }
    while(lo<=hi){
        mid=(lo+hi)/2 ;
        if(F(mid)){
            hi=mid-1 ;
        }else{
            lo=mid+1 ;
        }
    }
    return lo ;
}

int main(void){
  //  freopen("in.in","r",stdin) ;
    scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]) ;
    }

    for(int i=1;i<=m;i++){
        scanf("%d",&days[i]) ;
    }
  //  printf("%d\n",F(6)) ;
    int res=BS() ;
    printf("%d\n",res) ;
    return 0 ;
}
