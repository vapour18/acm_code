n = map(int, raw_input().split())
a = map(int ,raw_input().split())
s = 0
i = len(a)-1
ans = range(0,100005)
while i >= 0:
    if s < a[i]:
       s= a[i]-s
       ans[i] = 1
    else:
        s-=a[i]
        ans[i] = 0
    i-=1
t = 0
x = []
for i in range(0,len(a)):
    if t^ans[i]==1:
        x.append('+')
    else:
        x.append('-')
    t^=ans[i]
print "".join(x)
#直接用sys.stdout.write("+")也可以,但是要import sys

