#include <bits/stdc++.h>
using namespace std ;
int n ,l ,pos[22],finish_time[22][2] ;
char dir[22] ;

int tmp[22] ;
int main(void){

    //freopen("in.txt","r",stdin) ;

    while(scanf("%d %d",&n,&l)==2){
        if(!n && !l) break ;
        int index = -1 ,val=-10;
        for(int i=0;i<n;i++){
            scanf(" %c %d",&dir[i],&pos[i]) ;
        }
        int tim = 0 ,out=0;
     //   memset(tmp,0,sizeof(tmp)) ;
        while(out!=n){

           for(int i=0;i<n;i++){
                if(pos[i]==-1) continue ; // out
                if(dir[i]=='R') pos[i]++ ;
                else pos[i]-- ;
                if(pos[i]==0 || pos[i]==l){
                    finish_time[i][0] = tim ;
                    finish_time[i][1] = pos[i] ;
                    out++ ;
                }
           }

           for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(pos[i]==-1) continue ;
                    if(pos[i]!=pos[j]) continue ;
                    if(dir[i]=='R') dir[i] = 'L' ;
                    else dir[i] = 'R' ;
                    if(dir[j]=='R') dir[j] = 'L' ;
                    else dir[j] = 'R' ;
                   // cout<<i<<" "<<j<<endl ;
                   tmp[i] = tmp[j] = 1 ;
                }
           }
           tim++ ;
        }
        printf("%d ",tim) ;
        for(int i=0;i<n;i++){
            if(val<finish_time[i][0]){
                index = i ;
                val = finish_time[i][0] ;
            }
            else if(val==finish_time[i][0] && finish_time[i][1]==0){
                index = i ;
            }
        }
        printf("%d\n",index+1) ;
    }



}
