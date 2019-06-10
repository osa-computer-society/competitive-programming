num = int(input())
total = 0
for i in range(num):
    addend = input()
    base = int(addend[:-1])
    exponent = int(addend[-1])
    total += base ** exponent
print(total)
