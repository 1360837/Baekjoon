import sys
input=sys.stdin.readline

def Fac(num):
  result=1
  for i in range(1,num+1):
    result*=i
  return result

T=int(input())
for _ in range(T):
  N,M=map(int,input().split())
  print(Fac(M)//(Fac(M-N)*Fac(N)))