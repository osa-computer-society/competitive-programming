word = input()

longest = 0

for i in range(len(word)):
  for j in range(i, len(word)+1):
    if word[i:j] == word[i:j][::-1] and longest < j - i:
      longest = j - i

print(longest)