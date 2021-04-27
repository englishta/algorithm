"""
https://zenn.dev/m193h/articles/20210425sun231336m193hahc002
AHC002 貪欲法

"""
def move_adjacent_max(y:int, x:int, score:int, history: list):


    if tile[y][x] in seen:
        history.pop()
        score-=points[y][x]
        return score, history
    
    seen.add(tile[y][x])
    can = (-1, -1, 0, "")

    for dy, dx, move in ((-1, 0, "U"), (1, 0, "D"), (0, -1, "L"), (0, 1, "R")):
        ny = y+dy
        nx = x+dx
        if ny<0 or ny>=H or nx<0 or nx>=W or tile[ny][nx] in seen:
            continue
        if can[2] < points[ny][nx]:
            can = (ny, nx, points[ny][nx], move)

H, W = 50, 50
sy, sx = map(int, input().split())
tile = [list(map(int, input().split())) for _ in range(H)]
points = [list(max(int, input().split())) for _ in range(W)]

seen = set()
score, history = move_adjacent_max(sy, sx, points[sy][sx], [])

print("".join(str(x)) for x in history)