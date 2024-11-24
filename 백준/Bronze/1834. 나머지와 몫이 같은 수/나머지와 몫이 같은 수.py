n=int(input())
sum=0

for i in range(n+1,n**2,n+1):
  sum+=i
print(sum)