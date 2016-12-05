if __name__=='__main__':
    (n,m) = map(int,raw_input().split())
    col = [0 for i in range(0,n)]
    row = [0 for i in range(0,n)]
    c=n
    r=n
    while m>0:
        m-=1
        (x,y)=map(int,raw_input().split())
        if row[x-1]==0:
            row[x-1]=1
            r-=1
        if col[y-1]==0:
            col[y-1]=1
            c-=1

        print r*c