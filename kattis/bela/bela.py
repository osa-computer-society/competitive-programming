hands, domsuit = input().split(" ")
dominant = {
    "A": 11,
    "K": 4,
    "Q": 3,
    "J": 20,
    "T": 10,
    "9": 14,
    "8": 0,
    "7": 0}
nondominant = {
    "A": 11,
    "K": 4,
    "Q": 3,
    "J": 2,
    "T": 10,
    "9": 0,
    "8": 0,
    "7": 0}

total = 0
for i in range(int(hands)):
    for n in range(4):
        number, suit = list(input())
        if suit == domsuit:
            total += dominant[number]
        else:
            total += nondominant[number]
print(total)
        
