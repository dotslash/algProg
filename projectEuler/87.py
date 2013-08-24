limit = 50000000
l2,l3,l4 = map(int,[limit**0.5,limit**(0.3333333333333333),limit**(0.25)])
print l3*l3*l3

primes=set()
bm=[False for i in xrange(limit+1)]
for i in xrange(2,limit+1):
   if(bm[i]): continue
   primes.add(i)
   start=i*i
   if(start>=limit): continue
   for j in xrange(start,limit+1,i):
      bm[j]=True

print len(primes),"primes found"
sq = [i**2 for i in xrange(1,l2+1) if (i in primes)]
cu = [i**3 for i in xrange(1,l3+1) if (i in primes)]
fr = [i**4 for i in xrange(1,l4+1) if (i in primes)]

print "squares:{0} cubes:{1} fours:{2}".format(len(sq),len(cu),len(fr))

final = [False for i in xrange(limit+1)]
for s in sq:
   for c in cu:
      for f in fr:
         sm=s+c+f
         if(sm<=limit): 
            final[sm]=True

print final.count(True)
