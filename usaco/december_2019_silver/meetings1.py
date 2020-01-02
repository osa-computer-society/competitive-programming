import sys

class Cow:
    def __init__(self, w, x, d):
        self.w = w
        self.x = x
        self.d = d
        self.t = None

sign = lambda a: (a>0) - (a<0)

with open('meetings.in', 'r') as ifile:
    with open('meetings.out', 'w') as ofile:
        data = ifile.read().split('\n')
        N, L = map(int, data[0].split())
        cows = sorted([Cow(w, x, d) for w, x, d in [map(int, line.split()) for line in data[1:N+1]]], key=lambda c: c.x)
        for i in range(N):
            l = [c for c in cows[:i] if c.d == 1]
            r = [c for c in cows[i+1:] if c.d == -1]
            df = sign(len(l)-len(r))
            if df == 0 or df == cows[i].d: # if it ends in the same direction
                if cows[i].d == 1:
                    cows[i].t = L - l[-1].x
                else:
                    cows[i].t = r[0].x
            else:
                if cows[i].d == 1:
                    cows[i].t = r[0].x
                else:
                    cows[i].t = L - l[-1].x

        sorted_cows = sorted(cows, key=lambda c: c.t)
        half_weight = sum([c.w for c in cows]) / 2
        tot = 0
        tf = 0
        while tot < half_weight:
            c = sorted_cows.pop(0)
            tot += c.w
            tf = c.t
        
        meetings = 0
        for i in filter(lambda c: c.d == 1, cows):
            for j in filter(lambda c: c.d == -1, cows):
                if (i.x-j.x+2*tf)/2 > 0:
                    meetings += 1
        
        ofile.write(str(meetings))
