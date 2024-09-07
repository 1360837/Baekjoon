import sys
input=sys.stdin.readline

T=int(input())
for _ in range(T):
  N=int(input())
  if N==0:print(1,0)
  elif N==1:print(0,1)
  else:
    li=[0]*(N+1)
    li[0],li[1]=0,1
    for i in range(2,N+1):
      li[i]=li[i-1]+li[i-2]
    print(li[N-1],li[N])