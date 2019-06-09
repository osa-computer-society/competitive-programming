gamesList = ((0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3))

def winning(games, team):
    scores = [0, 0, 0, 0]
    for i in range(6):
        if games[i] == 'W':
            scores[gamesList[i][0]] += 3
        elif games[i] == 'L':
            scores[gamesList[i][1]] += 3
        else:
            scores[gamesList[i][0]] += 1
            scores[gamesList[i][1]] += 1
    return (max(scores) == scores[team] and scores.count(max(scores)) == 1)

def possibilities(games, depth):
    if depth == 6:
        if winning(games, t):
            global count
            count += 1
        return

    nextGame = games.index('-')
    
    for i in ('W', 'L', 'T'):
        possibilities(games[:nextGame] + i + games[nextGame + 1:], depth + 1)
count = 0

t = int(input()) - 1
g = int(input())

games = '------'

for i in range(g):
    a, b, sa, sb = map(int, input().split())
    a -= 1
    b -= 1
    result = '-'
    if sa > sb:
        result = 'W'
    elif sb > sa:
        result = 'L'
    else:
        result = 'T'

    for i in range(6):
        if a == gamesList[i][0] and b == gamesList[i][1]:
            games = games[:i] + result + games[i+1:]

possibilities(games, g)

print(count)