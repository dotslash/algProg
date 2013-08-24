limit,chances = 8,16
#limit,chances = 2,5
num = [[0 for i in xrange(limit)] for j in xrange(chances)]
num[0][0]=1
for pres in xrange (1,chances):
   num[pres][0]=num[pres-1][0]
   for used in xrange(1,limit):
      num[pres][used] = num[pres-1][used-1]*(pres) + num[pres-1][used]


den = 1
for i in xrange(1,chances+1): den=den*i

print sum(num[-1])
print den
print den/sum(num[-1])
