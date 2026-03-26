    //import java.io.IOException;

    import java.io.IOException;
    import java.io.InputStream;
    import java.io.PrintWriter;
    import java.util.*;

    public class DColoredBoots {
        static InputReader inputReader=new InputReader(System.in);
        static void solve()
        {
            int n=inputReader.nextInt();
       //     int m=inputReader.nextInt();
            String str1=inputReader.readString();
            String str2=inputReader.readString();
            //HashMap<Character,Stack<Integer>>str1set=new HashMap<>();
            HashMap<Character,Stack<Integer>>str2set=new HashMap<>();
            for (char c='a';c<='z';c++)
            {
                str2set.put(c,new Stack<>());
            }
            str2set.put('?',new Stack<>());
            for (int i=0;i<n;i++)
            {
                str2set.get(str2.charAt(i)).add(i+1);
            }
            List<String>answer=new ArrayList<>();
            boolean visited[]=new boolean[n];
            boolean visited2[]=new boolean[n];
            for (int i=0;i<n;i++) {
                if (str1.charAt(i)=='?')
                {
                    continue;
                }
                if (str2set.get(str1.charAt(i)).size() > 0) {
                    int popind=str2set.get(str1.charAt(i)).pop();
                    String str = (i+1)+" "+(popind);
                    answer.add(str);
                    visited[i]=true;
                    visited2[popind-1]=true;
                }
            }
            int ind=0;
            for (int i=0;i<n;i++)
            {
                if (ind==n)
                {
                    break;
                }
                if (str1.charAt(i)=='?')
                {
                    while (ind<n&&(visited2[ind]==true||str2.charAt(ind)=='?'))
                    {
                        ind++;
                    }
                    if (ind<n)
                    {
                        visited[i]=true;
                        visited2[ind]=true;
                        answer.add((i+1)+" "+(ind+1));
                    }
                }
            }
             ind=0;
            for (int i=0;i<n;i++)
            {
                if (str2.charAt(i)=='?'&&!visited2[i])
                {
                    while (ind<n&&visited[ind]==true)
                    {
                        ind++;
                    }
                    if (ind<n)
                    {
                        answer.add((ind+1)+" "+(i+1));
                        visited[ind]=true;
                        visited2[i]=true;
                    }
                }
            }
            out.println(answer.size());
            for (String ele:answer)
            {
                out.println(ele);
            }
        }
        static PrintWriter out=new PrintWriter((System.out));
        public static void main(String args[])throws IOException
        {

                solve();

            out.close();
        }
        static void Sort(int arr[])
        {
            List<Integer>list=new ArrayList<>();
            for (int ele:arr)
            {
                list.add(ele);
            }
            Collections.sort(list);
            for (int i=0;i<list.size();i++)
            {
                arr[i]=list.get(i);
            }
        }
        static void sortDec(int arr[])
        {
            int len=arr.length;
            List<Integer>list=new ArrayList<>();
            for(int ele:arr)
            {
                list.add(ele);
            }
            Collections.sort(list,Collections.reverseOrder());
            for(int i=0;i<len;i++) {
                arr[i] = list.get(i);
            }
        }
        static class InputReader {

            private InputStream stream;
            private byte[] buf = new byte[8192];
            private int curChar, snumChars;
            private SpaceCharFilter filter;

            public InputReader(InputStream stream) {
                this.stream = stream;
            }

            public int snext() {
                if (snumChars == -1)
                    throw new InputMismatchException();
                if (curChar >= snumChars) {
                    curChar = 0;
                    try {
                        snumChars = stream.read(buf);
                    } catch (IOException e) {
                        throw new InputMismatchException();
                    }
                    if (snumChars <= 0)
                        return -1;
                }
                return buf[curChar++];
            }

            public int nextInt() {
                int c = snext();
                while (isSpaceChar(c))
                    c = snext();
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = snext();
                }
                int res = 0;
                do {
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    res *= 10;
                    res += c - '0';
                    c = snext();
                } while (!isSpaceChar(c));
                return res * sgn;
            }

            public long nextLong() {
                int c = snext();
                while (isSpaceChar(c))
                    c = snext();
                int sgn = 1;
                if (c == '-') {
                    sgn = -1;
                    c = snext();
                }
                long res = 0;
                do {
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    res *= 10;
                    res += c - '0';
                    c = snext();
                } while (!isSpaceChar(c));
                return res * sgn;
            }

            public int[] nextIntArray(int n) {
                int a[] = new int[n];
                for (int i = 0; i < n; i++)
                    a[i] = nextInt();
                return a;
            }

            public String readString() {
                int c = snext();
                while (isSpaceChar(c))
                    c = snext();
                StringBuilder res = new StringBuilder();
                do {
                    res.appendCodePoint(c);
                    c = snext();
                } while (!isSpaceChar(c));
                return res.toString();
            }

            public boolean isSpaceChar(int c) {
                if (filter != null)
                    return filter.isSpaceChar(c);
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
            }

            public interface SpaceCharFilter {
                public boolean isSpaceChar(int ch);
            }
        }
    }
