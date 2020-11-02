board = []
possiblemoves = 0

for n in range(7):
    board.append(list(input()))
    
for y in range(7):
    for x in range(7):
        if board[y][x] == 'o':
            #up
            if y > 1:
                if board[y-1][x] == 'o' and board[y-2][x] == '.':
                    possiblemoves += 1
            #down
            if y < 5:
                if board[y+1][x] == 'o' and board[y+2][x] == '.':
                    possiblemoves += 1
            #left
            if x > 1:
                if board[y][x-1] == 'o' and board[y][x-2] == '.':
                    possiblemoves += 1
            #right
            if x < 5:
                if board[y][x+1] == 'o' and board[y][x+2] == '.':
                    possiblemoves += 1
    
print(possiblemoves)
                            
