#include <bits/stdc++.h>
const int maxn =  220000 ;
const int inf =  220000 ;
using namespace std ;
int a[maxn],b[maxn],I[maxn] ,n ,Sequence[maxn] ;
int LCS(){

    int i ;
    I[0] = -inf ;
    for(i=1;i<=n;i++) I[i] = inf ;
    int LisLength =0  ;
    for(i=0;i<n;i++){

        int low ,high,mid ;
        low = 0 ;
        high = LisLength ;
        while(low<=high){
            mid = (low+high)/2 ;
            if(I[mid]<Sequence[i]){
                low = mid+1 ;
            }else high = mid-1 ;
        }
        I[low] = Sequence[i] ;
        if(LisLength<low) {
            LisLength = low ;
        }
    }
    return LisLength ;
}
int main(void){
    //freopen("in.txt","r",stdin) ;
    //stack<int>s ;
    int tc ,ct=1,val,maxi;
    scanf("%d",&tc) ;
    while(tc--){
        scanf("%d",&n) ;
        maxi = 0 ;

        for(int i=0;i<n;i++) {
            scanf("%d",&val) ;
            a[val] = i ;
        }

        for(int i=0;i<n;i++) {
            scanf("%d",&val) ;
          //  cout<<val<<endl ;
            Sequence[i] =  a[val] ;
        }

       // for(int i=0;i<n;i++) cout<<Sequence[i]<<" : "  ;
        int lcs = LCS() ;
       // cout<<lcs<<endl ;
        int res = 2*(n-lcs);
        printf("Case %d: %d\n",ct++,res) ;
        //while(!s.empty()) s.pop() ;
    }

    return 0 ;
}
