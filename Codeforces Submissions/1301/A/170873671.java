import java.io.BufferedReader;
import java.io.InputStreamReader;
public class App
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine());
        while(t > 0)
        {
            System.out.println(solve(reader) ? "YES" : "NO");
            t -= 1;
        }
        reader.close();
    }
    public static boolean solve(BufferedReader reader) throws Exception
    {
        String a = reader.readLine();
        String b = reader.readLine();
        String c = reader.readLine();
        int n = a.length();
        for (int i = 0; i < n; i++) 
        {
            char currentA = a.charAt(i);
            char currentB = b.charAt(i);
            char currentC = c.charAt(i);
            if(currentC != currentA && currentC != currentB)
            {
                return false;
            }
        }
        return true;
    }
}