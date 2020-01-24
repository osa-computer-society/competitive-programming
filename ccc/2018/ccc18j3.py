dists = [0]
[dists.append(int(dist)) for dist in input().split(' ')] # [0, city1, city2, etc]

for i in range(len(dists)): # each line 
    result = ''
    dist1 = sum(dists[:i+1]) # the distance from city 1
    for j in range(len(dists)): # For each of the cities
        result += str(abs(dist1 - sum(dists[:j+1]))) + ' '
    print(result[:-1]) # trim off the last value
