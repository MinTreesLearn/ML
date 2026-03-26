lst= []
n = int(input())
read = input().split()
nums = [int(read[i])-i for i in range(n)]
dic = {}
for i in range(n):
    dic[nums[i]] = dic.get(nums[i],0)+nums[i]+i
print(max(dic.values()))
 		 	  	 	  	 			  	 		  	