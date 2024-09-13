N=int(input())

A=list(map(int,input().split()))
B=list(map(int,input().split()))
S=[]

for _ in range(N):
  S.append(min(A[:])*max(B[:]))
  A.remove(min(A[:]))
  B.remove(max(B[:]))
print(sum(S))