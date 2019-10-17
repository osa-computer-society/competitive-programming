for i in range(int(input())):
    w, g, h, r = map(int, input().split())
    if g == h and g == r:
        print(w, w)
        continue
    smallest = ((g - h) ** 2 + w ** 2) ** .5
    x = (-w*r + w*g) / (h + g - 2*r)
    largest = (x**2 + (g-r)**2) ** .5 + ((w-x)**2 + (h-r)**2) ** .5
    print(smallest, largest)
    