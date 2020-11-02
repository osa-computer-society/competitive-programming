n = int(input())

inp = [int(input()) for i in range(n)]

correct = True
for i in range(1, inp[-1]):
    if i not in inp:
        print(i)
        correct = False

if correct: print("good job")
