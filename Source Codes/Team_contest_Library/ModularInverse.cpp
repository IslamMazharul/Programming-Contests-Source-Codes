/*
ax = 1 mod(n)
ax-1 = y*n ;
ax-y*n = 1 ;
so calling Extended Euclid with (a,n) will return (x,-y) from that we only need x :)
*/

//Using Extended Euclid
int modularInverse(int a,int b){


    pii ret = extendedEuclid(a,n) ;
    return (ret.first%n + n )%n ;

}
//using fermet works only when n is prime ( most of the time it is )
// a^(p-1) = 1 mod p
//so a^(p-2) * a = 1 modp ;
// we only need to calculate a^(p-2) using bigMod
int modularInverse(int a,int b){
    return bigMod(a,p-2) ;
}
