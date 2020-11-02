deck = input()
deck = [deck[i:i+3] for i in range(len(deck)) if i % 3 == 0]
P, K, H, T = [13 for x in range(4)]
if len(set(deck)) == len(deck):
    for card in deck:
        if card[0] == "P":
            P -= 1
        elif card[0] == "K":
            K -= 1
        elif card[0] == "H":
            H -= 1
        elif card[0] == "T":
            T -= 1
    print(" ".join([str(x) for x in [P, K, H, T]]))
else:
    print("GRESKA")
