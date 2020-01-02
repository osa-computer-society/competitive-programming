with open('moobuzz.in', 'r') as ifile:
    n = int(ifile.read())
    with open('moobuzz.out', 'w') as ofile:
        approx = n * 15 // 8
        for i in range(approx - 15, approx + 15):
            if i - i // 3 - i // 5 + i // 15 == n:
                ofile.write(str(i))
                break
