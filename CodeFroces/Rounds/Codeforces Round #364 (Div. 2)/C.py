

if __name__=='__main__':
    n = int(raw_input())
    string = raw_input()
    Map={}
    for ch in range(ord('a'),ord('z')+1):
        #print  ch
        Map[chr(ch)]=0
    for ch in range(ord('A'),ord('Z')+1):
        Map[chr(ch)]=0
    #print  Map
    count=0
    for ch in string:
        if Map[ch]==0:
            count+=1
            Map[ch]=1
    #print count
    i=0
    res=n
    Map[string[0]]=1
    while i <n:
        for ch in range(ord('a'), ord('z') + 1):
            # print  ch
            Map[chr(ch)] = 0
        for ch in range(ord('A'), ord('Z') + 1):
            Map[chr(ch)] = 0
        #print  Map
        j=i
        cc=0
        while j<n:
            if Map[string[j]]==0:
                cc+=1
            Map[string[j]]+=1
            j += 1
            if cc == count: break

        #print Map
        while i<n:
             #print i
             if Map[string[i]]>1:
                 Map[string[i]]-=1
                 i+=1
             else: break
        print  cc, " ", i, " ", j
        if cc==count:
            res=min(res,j-i)
        i=j-1
    print  res
