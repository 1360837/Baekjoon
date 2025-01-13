import sys
input=sys.stdin.readline

n=int(input())
idx=1
cnt=0
stack=[]
result=[]
nums=[int(input()) for _ in range(n)]

for num in nums:
  while idx<=num:
    stack.append(idx)
    result.append("+")
    idx+=1
  if num==stack[-1]:
    stack.pop()
    result.append("-")
    cnt+=1
  else :break
if cnt==n: 
  for i in result:print(i)
else:print("NO")