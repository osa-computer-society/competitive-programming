heights = [int(x) for x in input().split(" ")]
h1 = heights[6]
h2 = heights[7]
del heights[6]
del heights[6]

t1 = None
t2 = None

for i in range(len(heights)):
    for j in heights[i+1:]:
        for k in heights[i+2:]:
            theight = heights[i] + j + k 
            if theight == h1 and t1 == None:
                t1 = [heights[i], j, k]
            elif theight == h2 and t2 == None:
                t2 = [heights[i], j, k]

result = ""

for i in sorted(t1)[::-1]:
    result += str(i) + " "
for i in sorted(t2)[::-1]:
    result += str(i) + " "

print(result)
