for _ in range(int(input())):
    nums = input().split(' ')
    possible = False
    for operator in ('+', '-', '*', '/'):
        if (eval(nums[0] + operator + nums[1]) == int(nums[2])) or (eval(nums[1] + operator + nums[0]) == int(nums[2])):
            possible = True
    if (possible):
        print('Possible')
    else:
        print('Impossible')
