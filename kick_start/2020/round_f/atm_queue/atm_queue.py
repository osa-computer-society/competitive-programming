import sys
input = sys.stdin.readline

numCases = int(input())

for case in range(numCases):
    # e.g. input:
    # 5 6
    # 9 10 4 7 2

    # This takes the next line of `input()`, `split()`s it by spaces, and
    # `map()`s each value to an `int`
    # Then we unpack the value so that numPeople is the first element (5) and
    # maxWithdraw is the second element (6)
    numPeople, maxWithdraw = map(int, input().split())
    
    # Once again, we take the next line of input, split it up into
    # ["9", "10", "4", "7", "2"], turn these into integers ("9" => 9), and
    # enumerate them so that they get packed into tuples as follows: people:
    # [(1, 9), (2, 10), (3, 4), (4, 7), (5, 2)]
    people = enumerate(map(int, input().split()), 1)
    
    # Now here's the part that's crucial to solving the problem: the number of
    # times the person needs to line up again is equal to the amount of money he
    # wants to withdraw divided by the maximum withdrawal amount. We subtract
    # one because if the amount they want to withdraw is divisible by the max
    # withdrawal rate, they'll finish one round earlier. Then, we sort the list
    # of people people by the number of times they're going to line up,
    # resulting in:
    # [(3, 4), (5, 2), (1, 9), (2, 10), (4, 7)]
    # We don't need to worry about the ordering of people who line up the same
    # number of times, because the algorithm `sorted()` uses is "stable", which
    # means that if two elements are equal according to the key, they'll stay in
    # the same order they were in in the original list.
    people = sorted(people, key=lambda person: (person[1]-1) // maxWithdraw)
    
    # Finally, for each tuple (aka pair) from the list above, we take the first
    # element, which was the person's original number, from each, and turn it
    # into a string so that we can print it out.
    # The below syntax, known as a list comprehension, is the same as writing:
    # final_list = []
    # for person in people:
    #     final_list.append(str(person[0]))
    people = [str(person[0]) for person in people]

    # Finally we print out our answer. You could also use the new formatted
    # string (f-string) syntax:
    # print(f"Case #{case + 1}: {' '.join(people)}")
    # However, it's very new and isn't supported by Google Kick Start yet.
    print("Case #{}: {}".format(case+1, ' '.join(people)))
