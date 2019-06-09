wildcard = 0
cnt = {}
for i in range(26):
  cnt[chr(i + ord('a'))] = 0
in1 = list(input())
in2 = list(input())

for i in range(len(in1)):
  cnt[in1[i]] += 1

  if in2[i] == '*':
    wildcard += 1
  else:
    cnt[in2[i]] -= 1

s = 0
for k in cnt:
  s += abs(cnt[k])

print('A' if s <= wildcard else 'N')