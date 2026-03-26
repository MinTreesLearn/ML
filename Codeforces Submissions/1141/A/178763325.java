import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;
import java.util.*;
import java.util.ArrayList;

public class Main{
    
    public static void main(String[] args){
        
        Scanner in = new Scanner(System.in);
        
        int t;
        // t = in.nextInt();
        t = 1;
        
        while(t>0){
        
            int n,m;
            n = in.nextInt();
            m = in.nextInt();
            
            if(n==m){
                System.out.println(0);
                t--;
                continue;
            }
            
            HashMap<Integer,Integer> mp1 = new HashMap<>();
            HashMap<Integer,Integer> mp2 = new HashMap<>();
            
            double x2 = Math.sqrt(n);
            int val1 = (int)x2;
            
            for(int i=2;i<=val1;i++){
                
                while(n%i==0){
                    n /= i;
                    if(mp1.containsKey(i)){
                        
                        int x = mp1.get(i);
                        mp1.put(i,++x);
                    }
                    else{
                        mp1.put(i,1);
                    }
                }
            }
            
            if(n!=1){
                if(mp1.containsKey(n)){
                        
                    int x = mp1.get(n);
                    mp1.put(n,++x);
                }
                else{
                    mp1.put(n,1);
                }
            }
            
            x2 = Math.sqrt(m);
            int val2 = (int)x2;
            for(int i=2;i<=val2;i++){
                
                while(m%i==0){
                    m /= i;
                    if(mp2.containsKey(i)){
                        
                        int x = mp2.get(i);
                        mp2.put(i,++x);
                    }
                    else{
                        mp2.put(i,1);
                    }
                }
            }
            
            if(m!=1){
                if(mp2.containsKey(m)){
                        
                    int x = mp2.get(m);
                    mp2.put(m,++x);
                }
                else{
                    mp2.put(m,1);
                }
            }
            
            Boolean flag = false;
            for (Integer key: mp1.keySet()) {
            
                int value = mp1.get(key);
                
                if(mp2.containsKey(key)==false){
                    System.out.println(-1);
                    flag = true;
                    break;
                }
            }
            
            if(flag==false){
                for (Integer key: mp2.keySet()) {
            
                int value = mp2.get(key);
                
                if(mp1.containsKey(key)==false && key!=2 && key!=3){
                    System.out.println(-1);
                    flag = true;
                    break;
                }
            }
            }
            
            if(flag==false){
                
                val1 = 0;
                val2 = 0;
                if(mp1.containsKey(2)){
                    val1 = mp1.get(2);
                }
                if(mp2.containsKey(2)){
                    int x = mp2.get(2);
                    val1 = x - val1;
                }
                if(mp1.containsKey(3)){
                    val2 = mp1.get(3);
                }
                if(mp2.containsKey(3)){
                    int x = mp2.get(3);
                    val2 = x - val2;
                }
                
                if(mp1.containsKey(2)==true && mp2.containsKey(2)==false){
                    System.out.println(-1);
                }
                else if(mp1.containsKey(3)==true && mp2.containsKey(3)==false){
                    System.out.println(-1);
                }
                else if(val1<0 || val2<0){
                    System.out.println(-1);
                }
                else{
                    val1 += val2;
                    System.out.println(val1);
                }
            }
            t--;
        }
    }
}