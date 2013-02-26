from math import *

array = [0]*101;
vals =  [];
for i in xrange(101):
	vals.append([0]*200)

def solve(num):
	presLeft=0;
	presNum =num;
		
	for i in xrange(100):
		j=-1
		presSum=0
		for k in xrange(1,11):
			j=k
			if(presNum < (presLeft*10+j)*j): break
		
		presSum+=(j-1)
		presNum = (presNum - (j-1)*(presLeft*10+(j-1)))*100
		presLeft=presLeft*10+2*(j-1)
		vals[num][i]=(j-1)

	
	presSum = sum(vals[num][0:100])
	print "sqrt of",num,"=",str(vals[num][0])+"."+str(vals[num][1:101]).replace(',','').replace(' ','')[1:-1]
	array[num]=presSum
	print "sum=",presSum
	return presSum

result=0

for i in xrange(1,101):
	x = int(sqrt(i));
	if(x*x!=i):result+=solve(i);

print result

