import sys

 
def get_vals(n, arr, rev):
    if rev:
        arr.reverse()
 
    st = []
    vals = [0 for i in range(n)]
    for i in range(n):
        while len(st) != 0 and arr[st[-1]] >= arr[i]:
            st.pop()
        vals[i] = (i + 1) * arr[i] if len(st) == 0 else (i - st[-1]) * arr[i] + vals[st[-1]]
        st.append(i)
 
    if rev:
        arr.reverse()
        vals.reverse()
 
    return vals
 
def main():
    # for future
    n = int(input())
    arr = list(map(int, input().split()))
 
    lf = get_vals(n, arr, False)
    rf = get_vals(n, arr, True)
 
    val, pos = max(((lf[i] + rf[i] - arr[i], i) for i in range(n)))
    for i in range(pos - 1, -1, -1):
        arr[i] = min(arr[i], arr[i + 1])
    for i in range(pos + 1, n):
        arr[i] = min(arr[i], arr[i - 1])
 
    print(" ".join(map(str, arr)) + "\n")
 
main()