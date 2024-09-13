import sys
input=sys.stdin.readline

N=int(input())
pay=[[0]*3 for _ in range(N)]

for i in range(N):
  pay[i][0],pay[i][1],pay[i][2]=map(int,input().split())

result=[[0]*3 for _ in range(N)]
result[0]=pay[0]

for i in range(1,N):
  for j in range(3):
    result[i][j]=pay[i][j]+min(result[i-1][j-1],result[i-1][j-2])
print(min(result[N-1]))