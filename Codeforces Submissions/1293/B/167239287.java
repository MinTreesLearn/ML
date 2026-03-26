import java.util.Scanner;
public class Main{
    public static void main(String args[]){
        Scanner dp=new Scanner(System.in);
        int x,y;double sum=0;
        int n=dp.nextInt();
        for(int i=n;i>=1;i--){
			sum+=1/(double)i;
		}
        System.out.println(String.format("%.12f",sum));
    }
}