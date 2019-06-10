import math

for n in range(int(input())):
    mes = input()
    mesLen = len(mes)
    sqrt = math.ceil(math.sqrt(mesLen))
    message = [["" for x in range(sqrt)] for y in range(sqrt)]

    for i in range(len(mes)):
        message[i // sqrt][i % sqrt] = mes[i]

    encrypted = list(zip(*message[::-1]))
    for y in range(sqrt):
        for x in encrypted[y]:
            print(x, end='')
    print()
            
