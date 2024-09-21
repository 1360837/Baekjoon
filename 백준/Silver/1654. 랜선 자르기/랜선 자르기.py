K,N=map(int,input().split())
Klen=list(int(input()) for _ in range(K))

start,end=1,max(Klen)

while start<=end:
  mid=(start+end)//2
  cnt=0
  for i in Klen:
    cnt+=i//mid
  if cnt>=N:start=mid+1
  else:end=mid-1
print(end)