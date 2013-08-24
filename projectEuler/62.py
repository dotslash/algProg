from collections import defaultdict as dd
def transform(num):
   num = sorted(str(num),reverse=True)
   ret = 0
   for i in num: ret = ret*10+(ord(i)-ord('0'))
   return ret



cubes = [i**3 for i in range(10000)]
tr = map(transform,cubes)
count = dd(lambda:0)
for t in tr: count[t]+=1


for c in xrange(len(cubes)):
   if(count[tr[c]]>=5):
      print cubes[c],c
      break

