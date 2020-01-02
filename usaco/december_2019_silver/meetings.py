def run(data):
    N, L = map(int, data[0].split())
    cows = [[int(x) for x in line.split()] for line in data[1:]]
    for w, x, d in cows:
        if d == 1:
            t = -x
        else:
            t = x-L
        

with open('meetings.in', 'r') as ifile:
    with open('meetings.out', 'w') as ofile:
        ofile.write(run(ifile.read().split('\n')))