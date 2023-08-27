import sys
import math
input = sys.stdin.readline

n = int(input())
ans = []
while n > 1:
	ans.append(n)
	if n % 2 == 0:
		n /= 2
	else:
		n = 3*n+1
ans.append(n)
print(*ans)
	