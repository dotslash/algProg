from itertools import permutations,combinations
import operator
oper = [operator.mul, operator.add, operator.sub, operator.div]

def ans(ops,lst,ind):
    try:
       if(ind==1):
         v1,v2,v3 = ops[0](lst[0],lst[1]),lst[2],lst[3]
         u1,u2 = ops[1](v1,v2),v3
         return ops[2](u1,u2)
       elif(ind==2):
         v1,v2,v3 = ops[0](lst[0],lst[1]),lst[2],lst[3]
         u1,u2 = v1,ops[2](v2,v3)
         return ops[1](u1,u2)

       elif(ind==3):
         v1,v2,v3 = lst[0],ops[1](lst[1],lst[2]),lst[3]
         u1,u2 = ops[0](v1,v2),v3
         return ops[2](u1,u2)

       elif(ind==4):
         v1,v2,v3 = lst[0],ops[1](lst[1],lst[2]),lst[3]
         u1,u2 = v1,ops[2](v2,v3)
         return ops[0](u1,u2)

       elif(ind==5):
         v1,v2,v3 = lst[0],lst[1],ops[2](lst[2],lst[3])
         u1,u2 = ops[0](v1,v2),v3
         return ops[1](u1,u2)

       elif(ind==6):
         v1,v2,v3 = lst[0],lst[1],ops[2](lst[2],lst[3])
         u1,u2 = v1,ops[1](v2,v3)
         return ops[0](u1,u2)
    except ZeroDivisionError: return 0
   

def solve(lst,s):
   for i in xrange(64):
      ops=oper[i/16],oper[(i/4)%4],oper[i%4]
      s.add(ans(ops,lst,1))
      s.add(ans(ops,lst,2))
      s.add(ans(ops,lst,3))
      s.add(ans(ops,lst,4))
      s.add(ans(ops,lst,5))
      s.add(ans(ops,lst,6))

best=0,None #[0]=>val [1]=>
for it in combinations(map(float,range(10)),4):
   s=set()
   for p in permutations(it): solve(p,s)
   p,s=0,sorted(s)
   n = it[0]*1000+it[1]*100+it[2]*10+it[3]
   s=[int(i) for i in s if i>0 and int(i)==i]
   for x in s:
      if(x!= p+1): break
      p+=1
   best = max(best,(p,n))

print best

