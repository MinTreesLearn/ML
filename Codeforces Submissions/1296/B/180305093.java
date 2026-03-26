import java.util.Scanner;

public class FoodBuying {
    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        int t= scn.nextInt();
        int spend=0;
        int remaining=0;
        int cashback=0;
        for (int k = 0; k <t ; k++) {
            int n= scn.nextInt();
            spend=0;
            remaining=n;
            cashback=0;
            while (n!=0){
                if (n<10){
                    spend+=n;
                    n=0;
                }
                else {
                    cashback=n/10;
                    spend+=(n/10)*10;
                    n=n-((n/10)*10)+cashback;
                }
            }
            System.out.println(spend);
        }
    }
}
