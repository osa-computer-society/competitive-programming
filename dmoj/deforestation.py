# DMOPC '14 Contest 2 P4 - Deforestation
# By Alexander Cai 2019-11-30

import sys

input = sys.stdin.readline

nums = [int(input()) for i in range(int(input()))]

for i in range(int(input())):
    a, b = map(int, input().split())
    print(sum(nums[a:b+1]))

