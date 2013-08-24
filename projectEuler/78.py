p,n=[1],1
def next():
   pres,fct,res=1,-1,0
   while(True):
      s1=(3*pres*pres - pres)/2
      s2=s1+pres
      fct*=(-1)
      if(s1>n): return res
      res+= (fct*p[n-s1])
      if(s2>n): return res
      res+= (fct*p[n-s2])
      pres+=1
   pass

while(True):
   res = next()
   if(n%10000==0): print n
   p.append(res)
   if(res%1000000==0): 
      print res,n
      break
   n+=1
