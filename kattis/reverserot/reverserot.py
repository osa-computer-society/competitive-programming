alph = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ_.")
while True:
    try:
        n, mes = input().split(" ")
        n = int(n)
    except ValueError:
        break
    mes = list(mes[::-1])
    for i in range(len(mes)):
        ind = alph.index(mes[i])
        mes[i] = alph[(ind + n) % len(alph)]
    final = ""
    for char in mes:
        final += char
    print(final)
