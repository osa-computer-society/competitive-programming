def main(board):
    rotated = list(zip(*board))[::-1]

    for row in board:
        if row.count('*') != 1:
            print('invalid')
            return
    for i in range(8):
        if [row[i] for row in board].count('*') != 1:
            print('invalid')
            return
    for s in range(1, 14):
        lst = []
        diag_2 = []
        for r in range(s+1):
            if 0 <= r and r < 8 and 0 <= s-r and s-r < 8:
                lst.append(board[r][s-r])
                diag_2.append(rotated[r][s-r])
        if lst.count('*') > 1 or diag_2.count('*') > 1:
            print('invalid')
            return
    print('valid')

main([list(input()) for _ in range(8)])
