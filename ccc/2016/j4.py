hours, minutes = map(int, input().split(':'))

start = hours * 60 + minutes
end = start

t1, t2, t3, t4 = 7 * 60, 10 * 60, 15 * 60, 19 * 60

for i in range(start, start + 120):
  if (t1 <= end and end < t2) or (t3 <= end and end < t4):
    end += 2
  else:
    end += 1
  end %= 24 * 60

print(str(end // 60).zfill(2) + ':' + str(end % 60).zfill(2))
