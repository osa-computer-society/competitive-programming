def foo(result):
  result['a'] += 1
  print(result)
  foo(result)

result = {'a': 1}
foo(result)
print(result)
