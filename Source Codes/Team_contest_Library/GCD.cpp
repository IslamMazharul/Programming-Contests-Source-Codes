int GCD(int a,int b){

    while(b>0){
         a  = a%b ;
         a ^=b ;   b^=a ; a^=b ;
    }

    return a ;
}

int GCD(int a,int b){
    return b==0?a:GCD(b,a%b) ;
}
