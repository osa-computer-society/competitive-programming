import sys
data = sys.stdin.read().split('\n')
R = int(data[0])
L = int(data[1])

results = set()

high = [int(''.join(data[2].split()), 2)]
for k in [int(''.join(x.split()), 2) for x in data[3:2+R]]:
    low = set([k] + [k ^ j for j in high])
    high = low
print(len(high))