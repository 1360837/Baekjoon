N,K=map(int,input().split())
p=[i for i in range(1,N+1)]

result=[]
cnt=0

for _ in range(N):
  cnt+=K-1
  if cnt>=len(p):
    cnt%=len(p)
  result.append(str(p.pop(cnt)))

print("<",", ".join(result),">",sep="")