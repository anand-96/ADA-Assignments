cache=[]
def FF(seq, k):
    for i in range(0,len(seq)):
        if seq[i] in cache:
            print("cache Hit",seq[i])
            print(cache)
        else:
            print("cache Miss",seq[i])
            
            if len(cache)<k:
                cache.append(seq[i])
                print(cache)
            else:  
                far=0
                dis=[-1 for x in range(len(cache))]
               
                for j in range(0,len(cache)):
                    p=i+1
                    while p<len(seq):
                        if seq[p]!=cache[j]:
                            p+=1
                        else:
                            break
                    if p==len(seq):
                        dis[j]=1e9;
                    else:
                        dis[j]=p-i
                    if dis[j]>dis[far]:
                        far=j
                temp=cache[far]
                cache.pop(far)
                cache.append(seq[i])
                print(temp,"deleted,",seq[i],"inserted")
                print("cache",cache)
                    
FF([1,2,4,1,4,3,2,4,1,2,1,4,3,1,3,2],3)
