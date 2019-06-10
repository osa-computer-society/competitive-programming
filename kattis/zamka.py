l = int(input())
d = int(input())
x = int(input())

n = l
m = d

while sum([int(i) for i in str(n)]) != x:
    n += 1
while sum([int(i) for i in str(m)]) != x:
    m -= 1
print(n)
print(m)
