#include <bits/stdc++.h>
using namespace std ;
#define MAXN 100000+7
char str[MAXN] ;
int countt[200][MAXN],n;
bool F(int Len){
    //bool ret=0;
    if(Len>=n) return 1 ;
    for(int i=0;i<(int)strlen(str);i++){
        if(i+Len>n) break ;
        bool ok=1 ;
        for(int ch=1;ch<200;ch++){
                if(countt[ch][n]==0 || countt[ch][i+Len]-countt[ch][i]>0){

                }else{
                    //cout<<countt[ch][n]<<endl ;
                    ok=0 ;
                   // cout<<ch<<endl ;
                    break ;

                }
        }
        if(ok){
          //  printf("%d\n",i) ;
            return 1 ;
        }
    }
    return 0 ;
}
int BS(){
    int lo=0;
    int hi=n ;
    int mid ;
    while(lo<hi){
        int mid=(lo+hi)/2 ;
      //  cout<<mid<<endl ;
        if(F(mid)){
            hi=mid ;
        }else{
            lo=mid+1 ;
        }
    }

    return lo ;
}

int main(void){
 //   freopen("in.in","r",stdin) ;
    scanf("%d %s",&n,str+1) ;
    str[0]='0' ;
    //printf("%d\n",strlen(str)) ;
    for(int i=1;i<(int)strlen(str);i++){
        countt[str[i]][i]++ ;
    }
    for(int ch=0;ch<200;ch++){
        for(int i=1;i<(int)strlen(str);i++){
            countt[ch][i]+=countt[ch][i-1] ;
        }
    }
  //  printf("%d\n",F(5)) ;
    int res= BS() ;
    printf("%d\n",res) ;
    return 0 ;
}
