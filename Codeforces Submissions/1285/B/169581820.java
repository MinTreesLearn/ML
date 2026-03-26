/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */


import java.util.*;

/**
 *
 * @author Caio
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            long tastinessYasser = 0;
            int n = sc.nextInt();
            int[] a = new int[n];
            boolean flag = true;
            for(int i=0; i<n; i++){
                a[i] = sc.nextInt();
            }
            for(int i=0; i < n; i++){
                tastinessYasser += a[i];
                if(tastinessYasser<=0) flag = false;
            }
            tastinessYasser = 0;
            for(int i=a.length - 1; i>=0; i--){
                tastinessYasser += a[i];
                if(tastinessYasser<=0) flag = false;
            }
            System.out.println(flag ? "YES":"NO ");
        }
    }
}
