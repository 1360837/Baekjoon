import sys
input=sys.stdin.readline

N=int(input())
cnt=0
for i in range(1,N+1):
  J=list(map(int,str(i)))
  if len(J)%2==0:
    if sum(J)/len(J)==(J[len(J)//2-1]+J[len(J)//2])/2:cnt+=1
  else:
    if sum(J)/len(J)==J[len(J)//2]:cnt+=1
print(cnt)