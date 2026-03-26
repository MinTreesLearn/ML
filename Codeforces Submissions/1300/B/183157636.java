//By the name of Almighty Allah, the most Beneficent
import java.util.*;
import java.lang.*;
import java.io.*;
import java.applet.*;
import java.awt.*;
import java.net.*;
import java.time.*;
import java.sql.*;
import java.math.*;
import java.text.*;
import javax.xml.*;
import javax.swing.*;


public class code{

  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    Scanner sn=new Scanner(System.in);

    int t;
    t=sc.nextInt();
    for(int i=0;i<t;i++)
    {
      int n;
      n=sc.nextInt();
      int ar[]=new int[2*n];
      for(int j=0;j<2*n;j++)
        ar[j]=sc.nextInt();

      Arrays.sort(ar);

      System.out.println(ar[n]-ar[n-1]);  

      
    }
  }
}