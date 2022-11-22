LEFT = 0
RIGHT = 1
prev = None
while True:
    s = input()
    if s == '99999':
        break
    direction = int(s[0]) + int(s[1])
    steps = int(s[2:])
    if direction % 2 == 1:
        print('left', steps)
        prev = LEFT
    elif direction == 0:
        print('left' if prev == LEFT else 'right', steps)
    else:
        print('right', steps)
        prev = RIGHT
