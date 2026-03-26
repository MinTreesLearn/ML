//package com.company;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long ind=2;
        // write your code here
        int n=s.nextInt();
        int m=s.nextInt();StringBuilder sb=new StringBuilder();
        long [] ans=new long[n];ans[0]=1;if(n>1)ans[1]=2;
        sb.append(1+" ");
        if(n>1) sb.append(2+" ");
        for(int i=2;i<n;i++){
            if(m==0){

                ans[i]=ans[i-1]+ind+1;
                if(ans[i]>1000000000) m= Integer.MAX_VALUE;
                sb.append(ans[i]+" ");continue;

            }
            for(int k=i;k>=0;k--){
                if(k/2<=m){
                    m-=k/2;
                    ans[i]=ans[i-1]+ans[i-k];
                    ind=ans[i];
                    if(ans[i]>1000000000) m= Integer.MAX_VALUE;

                    sb.append(ans[i]+" ");
                    break;
                }
            }
        }
        //  System.out.println(m);
        //  System.out.println(sb.toString());
     /*    for(int i=1;i<=n;i++){
             if(m==0) {sb.append((100000000-(n-i))+" ");continue;}
             if(i%2==0){
                 if((i-1)/2*(4+((i-1)/2-1)*2)/2<m){
                     sb.append(i+" ");
                   //  ans[i]=i;
                 }else if((i-1)/2*(4+((i-1)/2-1)*2)/2==m) {
                       m=0;
                       sb.append(i+" ");

                 }
                 else{
                     if(m>((i-1)/2)*((2+((i-1)/2-1)*2))/2)
                         m-=((i-1)/2)*((2+((i-1)/2-1)*2))/2;
                     m--;
                     sb.append((i-1+i-2)+" ");
                 }
                 }else{
                 if((i/2)*((2+(i/2-1)*2))/2<m){
                     sb.append(i+" ");
                     //  ans[i]=i;
                 }else if((i/2)*((2+(i/2-1)*2))/2==m) {
                     m=0;

                     sb.append(i+" ");

                 }
                 else{
                     if((i-2)/2*(4+((i-2)/2-1)*2)/2<m) m-=(i-2)/2*(4+((i-2)/2-1)*2)/2;
                         m--;
                     sb.append((i-1+i-2)+" ");
                 }
             }
         }*/
        //   System.out.println(m+" " +sb.toString());
        if(m>0) System.out.println(-1);else
            System.out.println(sb.toString() );
    }
}