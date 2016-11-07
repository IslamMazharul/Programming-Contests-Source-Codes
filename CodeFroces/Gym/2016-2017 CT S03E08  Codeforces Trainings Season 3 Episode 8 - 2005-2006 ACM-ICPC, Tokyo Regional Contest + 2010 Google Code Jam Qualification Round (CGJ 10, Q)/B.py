if __name__=='__main__':
	(m,c,n) = map(int,raw_input().split())
	a = []
	total = 0
	for i in range(n):
		k = int(raw_input())
		ids = map(int,raw_input().split())
		a.append(ids)
		total+=len(ids)

	#print a
	#print total
	main_queue=[]
	cur=0
	idx=0
	while total>0:

		if idx<len(a[cur]):
			main_queue.append(a[cur][idx])
			total -= 1


		cur+=1
		#print  cur," ",idx
		if cur==n:
			idx+=1
			cur=0

	#print main_queue
	desk= [ []]
	for i in range(len(main_queue)):
		cur = main_queue[i]
		# try to process this iteam
	
