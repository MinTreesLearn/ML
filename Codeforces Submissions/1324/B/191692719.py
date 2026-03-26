def is_palindrome(nums):
    #if nums[ : : -1] == nums: return "YES"
    for i in range(1, len(nums) - 1):
        if nums[i - 1] in nums[i + 1 : ]: return "YES"
    
    return "NO"

if __name__ == "__main__":
    
    for _ in range(int(input())):
        input()
        nums = [int(x) for x in input().split()]

        print (is_palindrome(nums))