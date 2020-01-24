import sys
data = sys.stdin.read().split('\n')
n = int(data[0])
ans = [1] * (n+1) # num ways to remove nodes beneath index
for i in range(1, n):
    j = int(data[i])
    # person j (parent) can either remove child (1), or include it and there are ans[i] ways to exclude under it
    ans[j] = ans[j] * (ans[i] + 1)

print(ans[n])