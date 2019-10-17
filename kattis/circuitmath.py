n = int(input())
vals = {}
for i, b in enumerate(input().split()):
    vals[chr(ord('A') + i)] = b == 'T'

stack = []

for t in input().split():
    if t in vals:
        stack.append(vals[t])
    else:
        if t == '-':
            stack.append(not stack.pop())
        elif t == '*':
            val = stack.pop()
            stack.append(stack.pop() and val)
        elif t == '+':
            val = stack.pop()
            stack.append(stack.pop() or val)

print(('F', 'T')[stack.pop()])
