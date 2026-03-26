import java.io.*;
import java.util.*;

public class C {
    static FastReader f = new FastReader();

    public static void main(String[] args) {
        int n = f.nextInt();
        if(n == 1) {
            System.out.println(0);
            return;
        }
        int[] arr = new int[n];
        for(int i=0;i<n;i++) {
            arr[i] = f.nextInt();
        }

        int even = n/2, odd = n/2 + (n&1);
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0;i<n;i++) {
            if(arr[i] == 0) {
                int cnt = 1;
                i++;
                while (i<n && arr[i] == 0) {
                    i++;
                    cnt++;
                }
                i--;
                list.add(-cnt);
            } else {
                list.add(arr[i]);
                if((arr[i] & 1) == 0) {
                    even--;
                } else {
                    odd--;
                }
            }
        }

        if(even+odd == n) {
            System.out.println(1);
            return;
        }

        ArrayList<Integer> evenList = new ArrayList<>();
        ArrayList<Integer> oddList = new ArrayList<>();

        int pos = 0;
        if(list.get(0) < 0) {
            pos++;
        }

        int ans = 0;
        for(;pos<list.size()-1;pos++) {
            if(list.get(pos+1) < 0) {
                if(pos+2 < list.size()) {
                    if(list.get(pos) % 2 == list.get(pos+2) % 2) {
                        if(list.get(pos) % 2 == 0) {
                            evenList.add(-list.get(pos+1));
                        } else {
                            oddList.add(-list.get(pos+1));
                        }
                    } else {
                        ans++;
                    }
                    pos++;
                } else {
                    break;
                }
            } else {
                if(list.get(pos) % 2 != list.get(pos+1) % 2) {
                    ans++;
                }
            }
        }

        Collections.sort(evenList);
        Collections.sort(oddList);

        for(int i : evenList) {
            if(even >= i) {
                even -= i;
            } else {
                ans += 2;
            }
        }

        for(int i : oddList) {
            if(odd >= i) {
                odd -= i;
            } else {
                ans += 2;
            }
        }


        if(list.get(0) < 0) {
            if(list.get(1) % 2 == 0) {
                if(even >= -list.get(0)) {
                    even -= list.get(0);
                } else {
                    ans++;
                }
            } else {
                if(odd >= -list.get(0)) {
                    odd += list.get(0);
                } else {
                    ans++;
                }
            }
        }

        if(list.get(list.size()-1) < 0) {
            if(list.get(list.size()-2) % 2 == 0) {
                if(even >= -list.get(list.size()-1)) {
                    even += list.get(list.size()-1);
                } else {
                    ans++;
                }
            } else {
                if(odd >= -list.get(list.size()-1)) {
                    odd += list.get(list.size()-1);
                } else {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }



    //fast input reader
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}
