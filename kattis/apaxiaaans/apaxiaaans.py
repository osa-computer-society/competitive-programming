name = list(input())
i = 0
while True:
    try:
        if name[i] == name[i+1]:
            del name[i+1]
        else:
            i += 1
    except IndexError:
        break
print(''.join(name))
