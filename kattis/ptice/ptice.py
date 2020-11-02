n = int(input())
s = list(input())

a = ["A", "B", "C"]
b = ["B", "A", "B", "C"]
c = ["C", "C", "A", "A", "B", "B"]

strs = [[], [], []]
for i in range(n):
    strs[0].append(a[i % 3])
    strs[1].append(b[i % 4])
    strs[2].append(c[i % 6])

matches = [0, 0, 0]
for i in range(n):
    if strs[0][i] == s[i]:
        matches[0] += 1
    if strs[1][i] == s[i]:
        matches[1] += 1
    if strs[2][i] == s[i]:
        matches[2] += 1

m = max(matches)
print(m)
if matches[0] == m:
    print("Adrian")
if matches[1] == m:
    print("Bruno")
if matches[2] == m:
    print("Goran")
