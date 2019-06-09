n = int(input())

cities = [0 for i in range(n)]
neighborhoods = [0 for i in range(n)]

for i in range(n):
    cities[i] = int(input())

cities.sort()

for i in range(1, n-1):
    neighborhoods[i] = (cities[i] - cities[i-1] + cities[i+1] - cities[i]) / 2

print(min(neighborhoods[1:-1]))