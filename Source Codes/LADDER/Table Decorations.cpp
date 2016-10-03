#include <bits/stdc++.h>
using namespace std ;
#define LL long long
LL a[3] ;
bool F(LL tables){

    LL x  = a[2] ;
    LL y  = a[1] ;
    LL z  = a[0] ;
    LL t1  = x/2 ;
    LL t2  = min(y/2,tables-t1) ;
       t2  = max(t2,0) ;

    x-=2*t1 ;
    y-=2*t2 ;
    LL t3,t4 ;
    t3 = min(t1,z) ;
    z-=t3 ;
    t1-=t3 ;
    t4 = min(t1,y) ;
    y-=t4 ;
    t1-=t4 ;
    //////////////
    t3 = min(t2,z) ;
    z-=t3 ;
    t2-=t3 ;
    t4 = min(t2,x) ;
    x-=t4 ;
    t2-=t4 ;
    ///////////////





    return 0 ;
}
int main(void){

    for(int i=0;i<3;i++)
    {
        scanf("%I64d",&a[i]) ;
    }
    sort(a,a+3) ;


    return 0 ;
}
