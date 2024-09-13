import sys
input=sys.stdin.readline

N=int(input())
M=int(input())
L=[]
if M:L=list(input().split())
ans=abs(N-100)

for i in range(1000001):
  for j in str(i):
    if j in L:break
  else:ans=min(ans,len(str(i))+abs(N-i))
print(ans)