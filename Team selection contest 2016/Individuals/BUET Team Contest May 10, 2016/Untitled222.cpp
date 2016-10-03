#include<bits/stdc++.h>
using namespace std ;
string arr[100000] ;
int call(int cur){
    if(arr[cur]=='.'){
            return call(cur+1) ;
    }
    return max(call(cur+1)+1,call(cur+2)) ;
}
int main(void){




    return 0 ;
}
