import sys
input=sys.stdin.readline
import re

test=re.compile('(100+1+|01)+')

T=int(input())
for _ in range(T):
    radio=input().rstrip()
    if test.fullmatch(radio):print("YES")
    else:print("NO")