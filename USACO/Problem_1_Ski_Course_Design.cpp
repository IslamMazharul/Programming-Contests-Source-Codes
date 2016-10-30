/*
TASK:skidesign
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std ;
int main(void){

    freopen("skidesign.in","r",stdin) ;
    freopen("skidesign.out","w",stdout) ;
    int n,lo=1000000,hi=0,val,p ;
    while(scanf("%d",&n)==1){
        while(n--){
            scanf("%d",&val) ;
            lo = min(lo,val) ;
            hi = max(hi,val) ;
        }
        int res = 0 ;
        if(hi-lo>17){
                p = (hi-lo-17)/2 ;
                res +=(p*p) ;
                p = (hi-lo-17-p) ;
                res +=(p*p) ;
        }

        printf("%d\n",res) ;

    }

    return 0 ;
}
