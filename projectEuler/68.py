import itertools
def index_min(values):
    return min(xrange(len(values)),key=values.__getitem__)

def convert(arr):
   if(arr[5]==10 or arr[6]==10 or arr[7]==10) : return 0
   if(arr[8]==10 or arr[9]==10) : return 0
   
   r1=arr[0]+arr[5]+arr[6]
   r2=arr[1]+arr[6]+arr[7] 
   if(r1!=r2): return 0
   
   r3=arr[2]+arr[7]+arr[8] 
   if(r1!=r3): return 0
   
   r4=arr[3]+arr[8]+arr[9] 
   if(r1!=r4): return 0
   
   r5=arr[4]+arr[9]+arr[5] 
   if(r1!=r5): return 0
   
   ind = index_min((arr[0],arr[1],arr[2],arr[3],arr[4]))
   
   ret = [arr[0],arr[5],arr[6],arr[1],arr[6],arr[7],arr[2],arr[7],arr[8],arr[3],arr[8],arr[9] ,arr[4],arr[9],arr[5]]
   ret = ret[3*ind:]+ret[:3*ind]
   ret =  map(str,ret)
         
   return int(''.join(ret))



print max(map(convert,itertools.permutations(range(1,11))))

