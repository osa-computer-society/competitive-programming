for _ in range(int(input())):
    recording = input().split()
    sounds = []
    while True:
        s = input()
        if s == 'what does the fox say?': break
        animal, sound = s.split(' goes ')
        sounds.append(sound)
    fox = []
    for sound in recording:
        if sound not in sounds:
            fox.append(sound)
    print(' '.join(fox))
        
