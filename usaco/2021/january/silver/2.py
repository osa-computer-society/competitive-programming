import re
import sys
input = sys.stdin.readline

n, q = map(int, input().split())

s = input().strip()

for i in range(26):
    c = chr(ord('A')+i)
    print(c)
    replaced = re.sub(f"[{c}-Z]", c, s)
    print(replaced)
    print(len(re.findall(f"{c}+", replaced)))

for i in range(q):
    a, b = map(int, input().split())

