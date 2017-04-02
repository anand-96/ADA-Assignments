import random
def partition(arr,l,h):
    if h==l:
        return int(arr[l]),int(arr[l])
    if (h-l)==1:
        return int(min(arr[l],arr[h])),int(max(arr[l],arr[h]))
    mid=(l+h)/2
    minL,maxL=partition(arr,l,mid)
    minR,maxR=partition(arr,mid+1,h)

    return int(min(minL,minR)),int(max(maxL,maxR))

n=int(input())
a=[]
for i in range(n):
    a.append(random.randint(1,1000))
print(a)
m1,m2=partition(a,0,n-1)
print(m1,m2)
