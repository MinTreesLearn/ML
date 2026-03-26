import java.util.Scanner;
public class radio {
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        byte n = input.nextByte();
        int[] robot1 = new int[n];
        int[] robot2 = new int[n];

        for(int i=0;i<n;i++){
            robot1[i] = input.nextInt();
        }
        for(int i=0;i<n;i++){
            robot2[i] = input.nextInt();
        }
        input.close();

        int p1=0,p2=0,count=0;
        for(int i=0;i<n;i++){
            if(robot1[i]==robot2[i]){
                count++;
            }
            else{
                if(robot1[i]==1){
                    p1++;
                }
                if(robot2[i]==1){
                    p2++;
                }
            }
        }
        if((count==n) || (p1==0)){
            System.out.println(-1);
        }
        else{
            System.out.println((p2/p1)+1);
        }
    }
}
