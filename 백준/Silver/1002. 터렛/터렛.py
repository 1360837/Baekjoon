T=int(input())
for _ in range(T):
  x1,y1,r1,x2,y2,r2=map(int,input().split())
  if x1==x2 and y1==y2:
    if r1==r2==0:print(1)
    elif r1==r2:print(-1)
    elif r1!=r2:print(0)
  else:
    dis=((x1-x2)**2+(y1-y2)**2)**0.5
    if (r1+r2)<dis:print(0)
    elif (r1+r2)==dis:print(1)
    else:
      if dis<abs(r1-r2):print(0)
      elif dis==abs(r1-r2):print(1)
      else:print(2)