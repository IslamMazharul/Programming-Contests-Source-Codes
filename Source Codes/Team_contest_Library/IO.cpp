#include <bits/stdc++.h>
using namespace std ;
int main(void){
    ///////////////////
    char line[1111] ;
    sscanf(line,"%d %d",&a,&b) ;
    ////////////////////////
    scanf("%s",line) ;
    char *tok = strtok(line,",") ;
    while(tok!=NULL){
        printf("%s\n",tok) ;
        tok = strtok(NULL,",") ;
    }
    //////////////////////////////
    return 0 ;
}
