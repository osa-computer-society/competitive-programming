coded = input()
vowels = ["a", "e", "i", "o", "u"]
decoded = ""
count = 0
while True:
    try:
        if coded[count] in vowels:
            decoded += coded[count]
            count += 2
        else:
            decoded += coded[count]
        count += 1
    except IndexError:
        break

print(decoded)
