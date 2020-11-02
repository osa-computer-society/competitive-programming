while True:
    nx, ny, w = input().split()
    nx = int(nx)
    ny = int(ny)
    w = float(w)

    if nx == ny and ny == w and w == 0:
        break
    xs = sorted(map(float, input().split()))
    ys = sorted(map(float, input().split()))

    xbroke = xs[0] - w / 2 > 0 or xs[-1] + w / 2 < 75
    ybroke = ys[0] - w / 2 > 0 or ys[-1] + w / 2 < 100

    if xbroke or ybroke:
        print("NO")
        continue

    for i in range(1, nx):
        if xs[i-1] + w / 2 < xs[i] - w / 2:
            xbroke = True
            break

    for i in range(1, ny):
        if ys[i-1] + w / 2 < ys[i] - w / 2:
            ybroke = True
            break

    print("NO" if (xbroke or ybroke) else "YES")
