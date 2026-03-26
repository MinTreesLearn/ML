//package com.company;
import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static char[] str;
    static int cnt[][];
    static int n;

    static boolean Get(int l, int r) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            int cur = cnt[r][i] - (l > 0 ? cnt[l - 1][i] : 0);
            if (cur > 0)
                count++;
        }
        return count >= 3;
    }

    static boolean Solve(int l, int r) {
        if (l == r)
            return true;
        if (str[l - 1] != str[r - 1])
            return true;
        return Get(l - 1, r - 1);
    }

    public static void main(String[] args) {
        str = sc.next().toCharArray();
        n = str.length;

        cnt = new int[n][26];
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                for (int j = 0; j < 26; j++)
                    cnt[i][j] = cnt[i - 1][j];
            cnt[i][str[i] - 'a']++;
        }

        int q = sc.nextInt();
        for (int i = 0; i < q; i++)  {
            int l = sc.nextInt(), r = sc.nextInt();
            if (Solve(l, r))
                System.out.println("Yes");
            else
                System.out.println("No");
        }
    }
}
