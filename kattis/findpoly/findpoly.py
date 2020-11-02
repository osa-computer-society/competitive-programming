from sys import stdin
for line in stdin:
    coords = ''.join(line.split()).split(';')[:-1] # Remove whitespace
    print(coords)
    parsed = [[y.replace('(', '').replace(')', '').split(',') for y in x.split('),(')] for x in coords]
    print(parsed)
