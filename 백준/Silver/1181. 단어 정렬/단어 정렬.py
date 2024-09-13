N=int(input())
Wlist=list(input() for _ in range(N))
Wlist=sorted(list(set(Wlist)))

cnt=0
for i in range(1,51):
  for j in Wlist:
    if len(j)==i:
      print(j)
      cnt+=1
  if cnt==len(Wlist):break