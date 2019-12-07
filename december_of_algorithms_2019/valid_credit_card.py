def valid_credit_card(n):
    s = str(n)[::-1]
    s1 = sum(map(int, s[::2]))
    s2 = sum(sum(map(int, str(k))) for k in (int(i) * 2 for i in s[1::2]))
    return (s1 + s2) % 10 == 0
