import sys
input=sys.stdin.readline

def Z(N,r,c):
  if N==0:return 0
  k=2**(N-1)
  if r<k and c<k: return Z(N-1,r,c)
  elif r<k and c>=k: return (k**2)+Z(N-1,r,c-k)
  elif r>=k and c<k:return (k**2)*2+Z(N-1,r-k,c)
  elif r>=k and c>=k:return (k**2)*3+Z(N-1,r-k,c-k)

N,r,c=map(int,input().split())
print(Z(N,r,c))