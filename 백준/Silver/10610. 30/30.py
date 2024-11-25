N=input()
N=sorted(N,reverse=True)
N_sum=0

for i in N:
  N_sum+=int(i)
if N[-1]!='0':print(-1)
elif N_sum%3!=0:print(-1)
else:print(''.join(N))