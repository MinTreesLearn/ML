
import java.util.Scanner;

public class AngryStudents {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int t=scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n=scanner.nextInt();
            scanner.nextLine();
            String st=scanner.nextLine();
            char[] x=st.toCharArray();
            int r=-1;
            for (int i1 = 0; i1 < x.length; i1++) {
                if (x[i1]=='A') {
                    r=i1;
                    break;
                }
            }
            if (r==-1) {
                System.out.println(0);
                continue;
            }
            int num=0;
            int max=0;
            for (int i1 = r; i1 < x.length; i1++) {

                  if (x[i1]=='P') num++;
                  else if (num>max) {max=num;num=0;}
                  else if (x[i1]=='A') num=0;
                  if (i1==x.length-1 && num>max) max=num;
            }

            System.out.println(max);
        }

    }
}
