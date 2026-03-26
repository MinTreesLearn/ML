n = int(input())
s = str(input())
stack = []
counter = {'(': 0, ')': 0}
res = 0
for i in range(n):
    if len(stack) > 0:
        if s[stack[-1]] == '(' and s[i] == ')':
            stack.pop()
            counter['('] -= 1
            continue

    stack.append(i)
    counter[s[i]] += 1

    if counter['('] == counter[')'] and len(stack) >= 2:
        res += stack[-1] - stack[0] + 1
        stack = []
        counter = {'(': 0, ')': 0}

if counter['('] != 0 or counter[')'] != 0:
    print(-1)
else:
    print(res)
  	   	   	  	  			 			  	 				