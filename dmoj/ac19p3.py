import sys
inp = sys.stdin.readline()

print(sum([int(x) for x in inp.replace(")", "").replace("(+ ", "").split()]))
