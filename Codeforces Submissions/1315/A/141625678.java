import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t =in.nextInt();
        while(t--!=0){
            int a = in.nextInt();
            int b = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();

            // the numbers are in 0 indexed so we need to increse x and y for easy calcuation
            x = x+1;
            y = y+1;

            //now the areas
            int area1 = a*(b-y);
            int area2 = b*(a-x);
            int area3 = a*(y-1);
            int area4 = b*(x-1);

            int ans = Math.max(area1,Math.max(area2,Math.max(area3,area4)));
            System.out.println(ans);
        }
        //while(t--!=0) {

        //int n = in.nextInt();

//        int[] dep = new int[n + 1];
//        int[] tm = new int[n + 1];
        //String reg = "//+";
        //String[] arr = str1.split("\\+");
        //Arrays.sort(arr);
        //String str2 = str1.substring(0,1).toUpperCase() + str1.substring(1);
    }
}