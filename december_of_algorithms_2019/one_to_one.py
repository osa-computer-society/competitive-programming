def one_to_one(s1, s2, op):
  s2 = s2.copy()
  for n in s1:
    try:
      s2.remove(op(n))
    except KeyError:
      return False
  return True

def surjective(s1, s2, op):
  done = {x: False for x in s2}
  for j in s1:
    done[op(j)] = True
  return not any([not d for d in done.values()]) 

def bijective(s1, s2, op):
  return one_to_one(s1, s2, op) and surjective(s1, s2, op)

sq = lambda x: x ** 2
for s1 in ({1, 2, 3, 4}, {1,-1,2,-2,3,-3,4,-4}):
  for s2 in ({1,4,9,16}, {1,4,9,16, 25}):
    print('s1 =', s1)
    print('s2 =', s2)
    if one_to_one(s1, s2, sq):
      print("It is one-one.")
    else:
      print("It is not one-one.")
    
    if surjective(s1, s2, sq):
      print("It is surjective.")
    else:
      print("It is not surjective.")

    if bijective(s1, s2, sq):
      print("It is bijective")
    else:
      print("It is not bijective")

    print()