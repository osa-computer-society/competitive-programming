st = 1200
D = None
cnt = None
ans = 0
digit = []

D = int(input())

for i in range(D % 720):
  st += 1
  st += 1
  m = st % 100
  h = st // 100
  if(m >=60 ):
    m-=60
    h += 1

  if(h > 12):
    h-=12

  st = h*100 + m

  if st < 1000:
    a=st//100
    b=st%100//10
    c=st%10
    if(a-b == b-c):
        ans += 1
  else:
    a=st//1000
    b=st%1000//100
    c=(st%100)//10
    d=st%10
    if(a-b == b-c and b-c==c-d):
        ans += 1

ans += 31*(D//720)
print(ans)