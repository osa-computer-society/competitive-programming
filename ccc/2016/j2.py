square = [[int(x) for x in input().split()] for i in range(4)]
s = sum(square[0])
result = 'magic'

i = 0
while i < 4 and result == 'magic':
  if sum(square[i]) != s:
    result = 'not magic'

  if sum([row[i] for row in square]) != s:
    result = 'not magic'
  i += 1
print(result)