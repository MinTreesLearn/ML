from sys import stdin
import heapq

# input

n = int(stdin.readline())
a = list(map(int, stdin.readline().split(' ')))
t = list(map(int, stdin.readline().split(' ')))

# init

t_at_a = dict()
for i in range(n):
   
   if a[i] not in t_at_a:
      t_at_a[a[i]] = []

   t_at_a[a[i]].append(t[i])


set_a = set(a)
sorted_a = sorted(list(set_a))

max_heap = []


# work

total_time = 0

time_sum = 0

for a_i in sorted_a:
   #print("a_i = {}".format(a_i))
   t_vals = t_at_a[a_i]
   for t_j in t_vals:
      heapq.heappush(max_heap, -t_j)
      time_sum += t_j

   time_sum -= -heapq.heappop(max_heap)

   a_j = a_i + 1

   while len(max_heap) > 0 and (a_j not in set_a):
      
      total_time += time_sum
      time_sum -= -heapq.heappop(max_heap)

      a_j += 1

   if len(max_heap) > 0:
      total_time += time_sum

print(total_time)

