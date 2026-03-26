import java.io.*;

public class w15q2
{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader r = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(r);

        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++)
        {
            String str = br.readLine();
            int L = 0;
            int con = 0;

            for (int j = 0; j < str.length(); j++)
            {
                if (str.charAt(j) == 'L')
                {
                    con += 1;
                }
                else
                {
                    con = 0;
                }
                if (con > L)
                {
                    L = con;
                }
            }
            System.out.println(L+1);
        }
    }
}
