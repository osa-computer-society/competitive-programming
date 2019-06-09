a = [int(input()) for x in range(3)]
b = [int(input()) for x in range(3)]

at = a[0] * 3 + a[1] * 2 + a[2]
bt = b[0] * 3 + b[1] * 2 + b[2]

if at > bt:
  print("A")
elif bt > at:
  print("B")
else:
  print("T")