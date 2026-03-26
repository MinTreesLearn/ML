import java.util.*;

public class _1286A_garland {

    static int solve(int[] nums) {
        int n = nums.length;
        Set<Integer> existing = new HashSet<>();
        int ans = 0;
        existing.add(nums[0]);
        for (int i = 1; i < n; i++) {
            existing.add(nums[i]);
            if (nums[i - 1] != 0 && nums[i] != 0 && nums[i] % 2 != nums[i - 1] % 2) {
                ans++;
            }
        }
//        System.out.println("init ans: " + String.valueOf(ans));
        int[] counts = new int[2];
        for (int i = 1; i <= n; i++) {
            if (!existing.contains(i)) {
                counts[i % 2]++;
            }
        }
//        System.out.println(Arrays.toString(counts));
        // type, count, odd/even
        List<int[]> spans = new ArrayList<>();
        int pre = 0;
        for (int i = 0; i < n; ) {
            while (i < n && nums[i] != 0) {
                i++;
                pre = i;
            }
            while (i < n && nums[i] == 0) {
                i++;
            }
            if (pre == 0) {
                // left side: type = 1
                spans.add(new int[]{1, i, i == n ? 0 : nums[i] % 2});
            } else if (i == n) {
                // right side type = 1
                if (i > pre) {
                    spans.add(new int[]{1, i - pre, nums[pre - 1] % 2});
                }
            } else if (nums[pre - 1] % 2 != nums[i] % 2) {
                // different  type = 2
                spans.add(new int[]{2, i - pre, 0});
            } else {
                // same  type = 0
                spans.add(new int[]{0, i - pre, nums[pre - 1] % 2});
            }
        }

        Collections.sort(spans, (int[] a, int[] b) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });

        for (int i = 0; i < spans.size(); i++) {
            int[] span = spans.get(i);
            if (span[1] == 0) continue;
            int type = span[0];
            if (span[1] > counts[span[2]] && type == 0) {
                // find type 1 first
                for (int j = i+1; j < spans.size(); j++) {
                    if (spans.get(j)[0] == 1 && spans.get(j)[2] == span[2] && spans.get(j)[1] <= counts[span[2]]) {
                        counts[span[2]] -= spans.get(j)[1];
                        spans.get(j)[1] = 0;
                    }
                }
            }
            int toFill = Math.min(span[1], counts[span[2]]);
            span[1] -= toFill;
            counts[span[2]] -= toFill;
            if (span[1] > 0) {
                counts[(span[2] + 1) % 2] -= span[1];
                if (type == 0) {
                    ans += 2;
                }
                if (type == 1) {
                    ans++;
                }
            }
            if (type == 2) {
                ans++;
            }
        }

        return ans;


    }

    public static void main(String[] args) {

//        int res = _1286A_garland.solve(new int[]{0, 5, 0, 2, 3});
//        System.out.println(res);

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        if (n == 1) {
            System.out.println(0);
        } else {
            int res = _1286A_garland.solve(nums);
            System.out.println(res);
        }
    }

}