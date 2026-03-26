# Python program for the above approach
# Function to find the number of
# M-length sorted arrays possible
# using numbers from the range [1, N]
def countSortedArrays(n, m):

	# Create an array of size M+1
	dp = [0 for _ in range(m + 1)]
	
	# Base cases
	dp[0] = 1

	# Fill the dp table
	for i in range(1, n + 1):
		for j in range(1, m + 1):
		
			# dp[j] will be equal to maximum
			# number of sorted array of size j
			# when elements are taken from 1 to i
			dp[j] = (dp[j - 1] + dp[j])%(10**9+7)

		# Here dp[m] will be equal to the
		# maximum number of sorted arrays when
		# element are taken from 1 to i

	# Return the result
	return dp[m]

# for _ in range(int(input())):
n,m=map(int,input().split())
print(countSortedArrays(n,2*m))



