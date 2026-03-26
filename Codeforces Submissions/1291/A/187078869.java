import java.util.Scanner;

public class Ebne {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int cases = input.nextInt();
        while(cases-- > 0)
        {
            int sze = input.nextInt();
            String str = input.next();
            if(sze < 2)
            {
                System.out.println(-1);
            }
            else
            {
                char[] temp = str.toCharArray();
                String answer = "";
                boolean two = false;
                int counter = 0;
                for (int i = 0; i < temp.length; i++) {
                    char c = temp[i];
                    int cin = Character.getNumericValue(c);
                    if(cin % 2 == 1)
                    {
                        answer += cin;
                        counter++;
                        if(counter >= 2)
                        {
                            two = true;
                            break;
                        }
                    }
                }
                if(two)
                {
                    System.out.println(answer);
                }
                else
                    System.out.println(-1);
            }
        }
        input.close();
    }
}
