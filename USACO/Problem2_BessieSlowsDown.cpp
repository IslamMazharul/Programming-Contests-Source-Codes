#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std ;
#define maxn 10001
double T[maxn],D[maxn] ;
int main(void){
    freopen("slowdown.in","r",stdin) ;
    freopen("slowdown.out","w",stdout) ;
    int n,data,cnt1,cnt2 ;
    char type ;
    while(scanf("%d",&n)==1){
        cnt1 = cnt2 = 0  ;
        scanf("%c %d\n",&type,&data) ;
        if(type=='D'){
            D[cnt1++] = data ;
        }
        else T[cnt2++] = data ;
        int e1 = 0 ,e2 = 0  ;
        sort(T,T+cnt2) ;
        sort(D,D+cnt1) ;
        double curTime = 0 ,curDis = 0,timeEvent ;
        double speed = 1;
        double curSpeed = 1 ;
        while(1){
            if(e1<cnt1) {
                timeEvent = (D[e1]-curDis)*curSpeed ;
            }
            else timeEvent = 10000000000 ;
            if(timeEvent<T[e2]){
                curDis = D[e1] ;
                e1++ ;
                speed++ ;
                curSpeed = (1/speed) ;
            }











        }







    }

    return 0 ;
}
