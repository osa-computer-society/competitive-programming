word = input()

consonant =     "bcdfghjklmnpqrstvwxyz"
closestVowel =  "aaeeeiiiiooooouuuuuuu"

newWord = ""
for i in range(len(word)):
  j = consonant.find(word[i])
  newWord += word[i]
  if j > -1:
    newWord += closestVowel[j] + consonant[min(j+1, 20)]

print(newWord)