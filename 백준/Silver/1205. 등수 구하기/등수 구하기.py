N,new,P=map(int,input().split())

if N>0:
  scoreList=list(map(int,input().split()))
  if N==P and scoreList[N-1]>=new:
    print(-1)
  else:
    rank=N+1
    for i in range(N):
      if new>=scoreList[i]:
        rank=i+1
        break
    print(rank)
else:
  print(1)