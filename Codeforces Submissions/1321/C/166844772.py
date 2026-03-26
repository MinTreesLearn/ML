from sys import stdin
input = stdin.readline
#// - remember to add .strip() when input is a string

n = int(input())

word = list(input())

alpha = "abcdefghijklmnopqrstuvwxyz"[::-1]

popcount = 0
counter = 0

for i in alpha:

  cur_letter = i

  popcount = 0
  while True:
    popcount = 0
    popl=[]
    
    for j in range(len(word)):
  
      if word[j] == cur_letter:
        
        if j == 0:
          if ord(word[j]) == ord(word[j+1]) + 1:
            popl.append(j)
            popcount += 1
            counter += 1
            
        elif j == len(word)-1:
          if ord(word[j]) == ord(word[j-1]) + 1:
            popl.append(j)
            popcount += 1
            counter += 1
  
        else:
          if ord(word[j]) == ord(word[j+1]) + 1 or ord(word[j]) == ord(word[j-1]) + 1:
            popl.append(j)
            popcount += 1
            counter += 1

    
    for u,y in enumerate(popl):
      word.pop(y-u)

    if popcount == 0:
      break

print(counter)