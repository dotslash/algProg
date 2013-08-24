def P3(n):return n*(n+1)/2	 	
def P4(n):return n*n	 	
def P5(n):return n*(3*n-1)/2	 	
def P6(n):return n*(2*n-1)	 	
def P7(n):return n*(5*n-3)/2	 	
def P8(n):return n*(3*n-2)	 	
def iden(x): return x

funcArr = [P3,P4,P5,P6,P7,P8]

numbs = []
for f in funcArr:
   s=set()
   for i in xrange(10000):
      number = f(i)
      if(number>=10000): break
      if(number<1000 or number%100<10): continue
      s.add(number)
   numbs.append(s)
   
print map(len,numbs)

def recurse(bm,lst):
   nxt = 0
   if(len(lst)==6):
      return lst[0]/100==lst[-1]%100,lst

   for nxt in xrange(6):   
      if((1<<nxt)&bm): continue
      prev = lst[-1]
      end = prev%100
      '''
      print map(lambda x: ((1<<x)&bm),range(6))
      print nxt
      print lst
      '''
      #raw_input()
      for n in numbs[nxt]:
         if(n/100==end):
            r,l = recurse((bm+(1<<nxt)),lst+[n])
            if(r): return r,l
   return False,None
   
   
for n in numbs[0]:  
   r,l = recurse(1<<0,[n])
   if(r): 
      print l
      print sum(l)
      break
   print "fail",n
