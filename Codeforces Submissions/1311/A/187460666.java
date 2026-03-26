import java.util.Scanner;

public class AddOddOrSubtractEven {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int testCases = input.nextInt();

        for (int i = 0; i < testCases; i++)
        {
            int startNum = input.nextInt();
            int desiredNum = input.nextInt();

            if (desiredNum == startNum)
                System.out.println("0");
            else if (desiredNum > startNum)
            {
                if ((desiredNum-startNum)%2 == 1)
                {
                    System.out.println("1");
                }
                else
                {
                    System.out.println("2");;
                }
            }
            else
            {
                if ((startNum-desiredNum)%2 == 0)
                {
                    System.out.println("1");;
                }
                else
                {
                    System.out.println("2");
                }
            }
            
        }
    }
}
