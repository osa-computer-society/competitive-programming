# 9/10

with open('whereami.in', 'r') as ifile:
    s = ifile.readlines()[1].strip()
    n = len(s)
    x = 1
    for i in range(1, n+1):
        curr = s[i-x:i]
        if curr in s[:i-1]:
            x += 1
    with open('whereami.out', 'w') as ofile:
        ofile.write(str(x))
