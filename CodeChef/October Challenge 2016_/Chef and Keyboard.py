if __name__=='__main__':
    testcases  = int(raw_input())
    while testcases > 0 :
        testcases-=1
        (n,m,c) = map(int,raw_input().split())
        res = 0
        for p in range(1,n+1):
            q = c/p
            if q == 0 : break
            if p*q == c  and q<=m:
                res+=1
        print res

