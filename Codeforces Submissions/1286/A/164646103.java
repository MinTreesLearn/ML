import java.io.*;
import java.util.*;
 
public class Solution
{
    static class Pair
    {
        int beg;
        int end;
        boolean isEven;
        Pair(int beg, int end, boolean isEven)
        {
            this.beg = beg;
            this.end = end;
            this.isEven = isEven;
        }
    }
 
    static Scanner scan = new Scanner(System.in);
    static BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out)); 
 
    static void tc() throws Exception
    {
    int n = scan.nextInt();
    int[] a = new int[n];
    int i, j, k;
 
    int even = 0;
    int odd = 0;
    for(i=0;i<n;++i)
        {
        a[i] = scan.nextInt();
        if(a[i] == 0)
            continue;
 
        if(a[i] % 2 == 0)
            ++even;
        else
            ++odd;
        }
 
    even = n / 2 - even;
    odd = n / 2 + (n % 2) - odd; 
 
    if(even + odd == n)
        {
        if(n > 1)
            output.write("1\n");
        else    
            output.write("0\n");
        output.flush();
        return;
        }
 
    List<Pair>[] list = new ArrayList[n + 1];
    for(i=1;i<=n;++i)   
        list[i] = new ArrayList<Pair>();
 
    boolean _new = true;
    for(i=0;i<n;++i)   
        {
            if(a[i] != 0)
                {
                _new = true;
                continue;
                }
 
            if(!_new)
                continue;
 
            _new = false;
 
            int beg = -1;
            int end = -1;
            for(j=i;j>=0;--j)
                {
                if(a[j] == 0)
                    beg = j;
                else    
                    break;
                }
 
            for(j=i;j<n;++j)
                {
                if(a[j] == 0)
                    end = j;
                else    
                    break;
                }
                    
            if(beg - 1 >= 0 && end + 1 < n && (a[beg - 1] % 2) == (a[end + 1] % 2))
                {
                int len = end - beg + 1;
                list[len].add(new Pair(beg, end, (beg - 1 >= 0) ? (a[beg - 1] % 2 == 0) : (a[end + 1] % 2 == 0)));
                }
        }  
 
    for(i=1;i<=n;++i)
        {
            int size = list[i].size();
            for(j=0;j<size;++j)
                {
                    Pair pair = list[i].get(j);
                    int beg = pair.beg;
                    int end = pair.end;
                    boolean isEven = pair.isEven;
 
                    if(isEven && end - beg + 1 <= even)
                        {
                            even -= end - beg + 1;
                            for(k=beg;k<=end;++k)
                                a[k] = 2;
                        }
                    else if(!isEven && end - beg + 1 <= odd)
                        {
                            odd -= end - beg + 1;
                            for(k=beg;k<=end;++k)
                                a[k] = 1;
                        }
                }
        }
 
    for(i=0;i<n;++i)
        if(a[i] != 0)
            {
            if(i == 0)
                break;
 
            if(a[i] % 2 == 1 && i <= odd)
                {
                    j = i - 1;
                    while(j >= 0)
                        {
                            a[j--] = 1;
                            --odd;
                        }
                }
            else if(a[i] % 2 == 0 && i <= even)
                {
                    j = i - 1;
                    while(j >= 0)
                        {
                            a[j--] = 2;
                            --even;
                        }
                }
 
            break;
            }
 
    for(i=n-1;i>=0;--i)
        if(a[i] != 0)
            {
            if(i == n - 1)
                break;
 
            if(a[i] % 2 == 1 && n - 1 - i <= odd)
                {
                    j = i + 1;
                    while(j < n)
                        {
                            a[j++] = 1;
                            --odd;
                        }
                }
            else if(a[i] % 2 == 0 && n - 1 - i <= even)
                {
                    j = i + 1;
                    while(j < n)
                        {
                            a[j++] = 2;
                            --even;
                        }
                }
            break;
            }
 
 
    for(i=0;i<n;++i)
        if(a[i] != 0)
            {
            if(i == 0)
                break;
 
            if(a[i] % 2 == 1)
                {
                    j = i - 1;
                    while(j >= 0 && odd > 0)
                        {
                            a[j--] = 1;
                            --odd;
                        }
 
                    while(j >= 0)
                        {
                            a[j--] = 2;
                            --even;
                        }
                }
            else if(a[i] % 2 == 0)
                {
                    j = i - 1;
                    while(j >= 0 && even > 0)
                        {
                            a[j--] = 2;
                            --even;
                        }
 
                    while(j >= 0)
                        {
                            a[j--] = 1;
                            --odd;
                        }
                }
 
            break;
            }
 
    for(i=n-1;i>=0;--i)
        if(a[i] != 0)
            {
            if(i == n - 1)
                break;
 
            if(a[i] % 2 == 1)
                {
                    j = i + 1;
                    while(j < n && odd > 0)
                        {
                            a[j++] = 1;
                            --odd;
                        }
 
                    while(j < n)
                        {
                            a[j++] = 2;
                            --even;
                        }
                }
            else if(a[i] % 2 == 0)
                {
                    j = i + 1;
                    while(j < n && even > 0)
                        {
                            a[j++] = 2;
                            --even;
                        }
 
                    while(j < n)
                        {
                            a[j++] = 1;
                            --odd;
                        }
                }
            break;
            }
 
    int ans = 0;
    for(i=1;i<n;++i)
        if(a[i] > 0 && a[i - 1] > 0 && (a[i] % 2) != (a[i - 1] % 2))
            ans += 1;
 
    _new = true;
    for(i=0;i<n;++i)   
        {
            if(a[i] != 0)
                {
                _new = true;
                continue;
                }
 
            if(!_new)
                continue;
 
            _new = false;
 
            int beg = -1;
            int end = -1;
            for(j=i;j>=0;--j)
                {
                if(a[j] == 0)
                    beg = j;
                else    
                    break;
                }
 
            for(j=i;j<n;++j)
                {
                if(a[j] == 0)
                    end = j;
                else    
                    break;
                }
                    
            if(beg - 1 >= 0 && end + 1 < n && (a[beg - 1] % 2) == (a[end + 1] % 2))
                ans += 2;
            else    
                ans += 1;
        }  
 
    output.write(ans + "");
    output.write("\n");
    output.flush();
    }
 
    public static void main(String[] args) throws Exception
    {
    int t = 1;
    // t = scan.nextInt();
    while(t-- > 0)
        tc();
    }
}