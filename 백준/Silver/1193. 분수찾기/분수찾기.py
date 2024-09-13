X=int(input())
sum=0
i=1
while sum<X:
  sum+=i
  i+=1
if i%2==1:
  print(i-sum+X-1,"/",sum-X+1,sep="")
else:
  print(sum-X+1,"/",i-sum+X-1,sep="")