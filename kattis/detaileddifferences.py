for i in range(int(input())):
    s1 = input()
    s2 = input()
    diff = ""
    for i in range(len(s1)):
        if s1[i] == s2[i]:
            diff += "."
        else:
            diff += "*"
    
    print(s1 + '\n' + s2 + '\n' + diff, end='\n\n')
        
