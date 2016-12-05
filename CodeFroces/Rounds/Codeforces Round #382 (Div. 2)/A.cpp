#include <bits/stdc++.h>
using namespace std ;
int arr[101] ;
int n,k,start=-1 ;
string str ;
void dfs(int cur){
    if(cur>=n || cur<0) return  ;
    if(arr[cur]==1 || str[cur]=='#') return ;
    arr[cur]=1 ;
    dfs(cur-k) ;
    dfs(cur+k) ;
}
int main(void){
    //freopen("in.in","r",stdin) ;
    int en ;
    cin>>n>>k>>str ;
    for(int i=0;i<str.length();i++){
        if(str[i]=='G'){
            start=i ;
        }
        if(str[i]=='T'){
            en  = i ;
        }
    }
    dfs(start) ;
    if(arr[en]==1) puts("YES") ;
    else puts("NO") ;
    return 0 ;
}
