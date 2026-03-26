import java.util.*;

public class Solution {
    static int zeroCount=0,oneCount=0;
    static int dp[][][][]=new int[101][51][51][3];

    public static void main(String[] args) {

        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        int a[]=new int[n];
        int tempzero=0,tempone=0;

        for (int i = 0; i <=100 ; i++) {
            for (int j = 0; j <51 ; j++) {
                for (int k = 0; k <51 ; k++) {
                    for (int l = 0; l <3; l++) {


                    dp[i][j][k][l]=-1;
                }}
            }
        }

        for (int i = 0; i <n ; i++) {
            a[i]=input.nextInt();
            if (a[i]==0){
                a[i]=-1;
            }else {
              a[i]=a[i]%2;
              if (a[i]==0){
                  tempzero++;
              }else {
                  tempone++;
              }
            }
        }
        if (n%2==0){
            zeroCount=(n/2)-tempzero;
            oneCount=(n/2)-tempone;
        }else {
            oneCount=((n/2)+1)-tempone;
            zeroCount=(n/2)-tempzero;
        }


       min=getresult(a,0,2,zeroCount,oneCount);
        System.out.println(min);






    }
    static int min=Integer.MAX_VALUE;

    private static int getresult(int[] a, int i,int pre,int zer,int one) {
        if (i==a.length){

            return 0;
        }
        if (dp[i][zer][one][pre]!=-1){
            return dp[i][zer][one][pre];

        }


        int tempzer=0;
        if (a[i]!=-1){
            if (i < a.length - 1 ) {
                if (a[i+1]!=-1) {
                    tempzer += a[i + 1] ^ a[i];
                }
            }



            return dp[i][zer][one][pre]=tempzer+getresult(a,i+1,a[i],zer,one);
        }


        //0
        int tempreszer0=Integer.MAX_VALUE;

         tempzer=0;
        if (zer>0) {
            if (pre==1){
                tempzer++;
            }

            if (i < a.length - 1) {
                if (a[i + 1] != 0 && a[i+1]!=-1) {
                    tempzer++;
                }
            }


            tempreszer0=Math.min(tempreszer0,tempzer+getresult(a, i+1,0,zer-1,one));
        }
        //1
        tempzer=0;
        int tempresone=Integer.MAX_VALUE;
        if (one>0){
            if (pre==0){
                tempzer++;
            }

            if (i < a.length - 1) {
                if (a[i + 1] != 1 && a[i+1]!=-1) {
                    tempzer++;
                }
            }


            tempresone=Math.min(tempresone,tempzer+getresult(a, i+1,1,zer,one-1));

        }

        dp[i][zer][one][pre]=Math.min(tempresone,tempreszer0);
        return dp[i][zer][one][pre];

    }

}