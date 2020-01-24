n = int(input())
k = int(input())

visited = [[[0 for kk in range(n+1)] for j in range(k+1)] for i in range(n+1)]

def pi(n,k,min):
  if visited[n][k][min] == 0:
    if n == k:
      visited[n][k][min] = 1
    elif k == 1:
      visited[n][k][min] = 1
    else:
      t = 0
      for i in range(min, (n // k)+1):
          t = t + pi(n-i, k-1, i)
      visited[n][k][min] = t
  return visited[n][k][min]

print(pi(n,k,1))
