
from collections import defaultdict


def isLayoutPossible(password: str) -> None:
    
    leaf_letters = 0
    
    adjacents = defaultdict(set)
    for index, letter in enumerate(password):
        if len(adjacents[letter]) == 1:
            leaf_letters -=1
        
        # adding neighbors of current letter 
        if index > 0 and password[index-1] != letter:
            adjacents[letter].add(password[index-1])
        if index < len(password)-1 and password[index+1] != letter:
            adjacents[letter].add(password[index+1])
        
        if len(adjacents[letter]) > 2:
            print('NO')
            return
        
        if len(adjacents[letter]) == 1:
            leaf_letters +=1
        
    if leaf_letters != 2 and len(password) > 2:
        print('NO')
        return
    
    print('YES')
    keyboard_layout = []
    start_letter = None
    
    for letter, neighbors in adjacents.items():
        if len(neighbors) == 1:
            start_letter = letter
            break
        
    stack = []
    if start_letter:    stack.append(start_letter)
    used = set()

    while stack:
        curr_letter = stack.pop()
        keyboard_layout.append(curr_letter)
        used.add(curr_letter)
        
        for adjacent_letter in adjacents[curr_letter]:
            if adjacent_letter in used: continue
            
            stack.append(adjacent_letter)
    
    alphabets = 26
    for i in range(alphabets):
        char = chr(i+97)
        if char in used:    continue
        keyboard_layout.append(char)
        
    final_keyboard_layout = "".join(keyboard_layout)
    print(final_keyboard_layout)


test_cases = int(input())
for _ in range(test_cases):
    password = input()
    isLayoutPossible(password)