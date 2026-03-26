import java.io.*;
import java.util.*;

// THIS COMMENT IS FOR SPEED
public class E
{
    short[][][] dp;
    int n, m;
    char[] s, t;

    short max(short a, short b)
    {
        return a > b ? a : b;
    }

    short go(int i, int j, int k)
    {
        if (i == n)
            return (short)(k == m ? j : -1);

        if (j == m && k == m)
            return (short)j;

        if (dp[i][j][k] != -2)
            return dp[i][j][k];

        short val = go(i+1, j, k);

        if (j != m && s[i] == t[j])
            val = max(val, go(i+1, j+1, k));
            
        if (k != m && s[i] == t[k])
            val = max(val, go(i+1, j, k+1));

        return dp[i][j][k] = val;
    }

    void solve(BufferedReader in, PrintWriter out) throws Exception
    {
        String a = in.readLine();
        String b = in.readLine();

        n = a.length();
        m = b.length();

        s = a.toCharArray();
        t = b.toCharArray();

        dp = new short[n][m+1][m+1];

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= m; j++)
                Arrays.fill(dp[i][j], (short)(-2));

        for (int i = n-1; i >= 0; i--)
            for (int j = m; j >= 0; j--)
                for (int k = m; k >= 0; k--)
                    go(i, j, k);
                    
        for (int k = 0; k < m; k++)
            if (go(0, 0, k) >= k)
            {
                out.println("YES");
                return;
            }
        
        out.println("NO");
    }

    public static void main(String[] args) throws Exception
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine());

        for (int i = 0; i < t; i++)
            new E().solve(in, out);

        out.close();
    }
}

