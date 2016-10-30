#include <bits/stdc++.h>
using namespace std ;
#define MAXN 2*100000+7
#define LL long long
LL a[MAXN] ,b[MAXN],n,m ;
LL F(LL val){

    LL tot = 0 ;
    for(int i=0;i<n;i++){
        if(a[i]<=val) tot+=2 ;
        else tot+=3 ;
    }
    for(int i=0;i<m;i++){
        if(b[i]<=val) tot-=2 ;
        else tot-=3 ;
    }

    return tot ;
}

int main(void){
 //   freopen("in.txt","r",stdin) ;


    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%I64d",&a[i]) ;
    scanf("%d",&m) ;
    for(int i=0;i<m;i++) scanf("%I64d",&b[i]) ;
    LL lo =0 , hi=2*1000000007,mid ;
    while(lo<hi){
        mid = (lo+hi)/2 ;
     //   cout<<lo<<" "<<hi<<endl ;
        if(F(hi)>F(mid)){
            lo = mid+1 ;
        }else hi = mid-1 ;
    }

    LL tot1 = 0 ,tot2=0,val=lo;
    for(int i=0;i<n;i++){
        if(a[i]<=val) tot1+=2 ;
        else tot1+=3 ;
    }

    for(int i=0;i<m;i++){
        if(b[i]<=val) tot2+=2 ;
        else tot2+=3 ;
    }

    printf("%I64d:%I64d",tot1,tot2) ;


    return 0 ;
}
