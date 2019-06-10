t = int(input())
for i in range(t):
    years = [int(x) for x in input().split(" ")]
    imports = 0
    for i in range(len(years)):
        if i != 0:
            if years[i] > years[i-1] * 2:
                imports += years[i] - years[i-1] * 2
    print(imports)
