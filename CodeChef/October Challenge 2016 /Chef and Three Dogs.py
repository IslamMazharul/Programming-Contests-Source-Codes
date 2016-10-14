if __name__=='__main__':
    testcases = (int)(raw_input())
    while testcases>0:
        testcases-=1
        (s,v)=map(float,raw_input().split())
        res = (s*2.000)/(v*3.00)
        print "%.13lf" % res


