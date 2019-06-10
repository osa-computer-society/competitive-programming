x, y, n = [int(x) for x in input().split(" ")]
for i in range(n):
    i += 1
    if (i % x == 0) and (i % y == 0):
        print("FizzBuzz")
    elif i % x == 0:
        print("Fizz")
    elif i % y == 0:
        print("Buzz")
    else:
        print(i)
