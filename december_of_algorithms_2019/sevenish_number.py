def sevenish_number(n):
    s = bin(n)[2:][::-1]
    return sum(int(s[i]) * 7 ** i for i in range(len(s)))
