n,k=map(int,raw_input().split())
a=map(int,raw_input().split())
a.sort()
lenth=1
pos=0
j=0
s=0
for i in range(n):
    s+=a[i]
    while (i-j+1)*a[i]>k+s:
        s-=a[j]
        j+=1
    if i-j+1>lenth:
        lenth=i-j+1
        pos=i
print lenth,a[pos]
