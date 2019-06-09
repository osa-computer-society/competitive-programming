rules = [input().split() for i in range(3)]
s, i, f = input().split()

maxdepth = int(s)

def recurse(rep, depth): # We work backwards, trying to obtain a result
  global f 
  depth += 1
  if depth > maxdepth:
    return False
  
  s = rep[2]
  for i in range(len(rules)): # For each of the rules
    ind = s.find(rules[i][0]) # See if it applies to the string
    while ind >= 0: # While it does
      new = s[:ind] + rules[i][1] + s[ind + len(rules[i][0]):] # We create the replacement
      replacement = [i + 1, ind + 1, new] # Put in the formatting of the question

      if new == f: # If this replacement works
        return [replacement] # We return it in an array

      k = recurse(replacement, depth) # Otherwise, we go further down one level
      if k: # If that one works
        return [replacement] + k # We return it, going back through the previous recursions until we return the correct value

      ind = s.find(rules[i][0], ind + len(rules[i][0])) # Otherwise we see if the rule appears again

[print(' '.join(map(str, step))) for step in recurse([0, 0, i], 0)]
