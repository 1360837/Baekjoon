import sys
input=sys.stdin.readline

def BFS(x,y):
  dx=[0,0,-1,1]
  dy=[1,-1,0,0]
  queue = [(x,y)]
  land[x][y]=0
  
  while queue:
    x,y=queue.pop(0)

    for i in range(4):
      nx=x+dx[i]
      ny=y+dy[i]

      if nx<0 or nx>=M or ny<0 or ny>=N:continue
      if land[nx][ny]==1:
        queue.append((nx,ny))
        land[nx][ny]=0

T=int(input())
for _ in range(T):
  M,N,K=map(int,input().split())
  land=list([0 for _ in range(N)] for _ in range(M))
  cnt=0

  for _ in range(K):
    x,y=map(int,input().split())
    land[x][y]=1
  
  for x in range(M):
    for y in range(N):
      if land[x][y]==1:
        BFS(x,y)
        cnt+=1
  print(cnt)