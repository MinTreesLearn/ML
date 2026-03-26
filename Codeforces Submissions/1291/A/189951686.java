import java.io.*;
import java.util.*;
public class Codeforces
{
    public static void main(String args[])throws IOException
    {
            Scanner sc=new Scanner(System.in);
            int t=sc.nextInt();
            while(t-->0)
            {
                int n=sc.nextInt();
                String num=sc.next();
                String c=num; int sum=0;
                int a[]=new int[n];
                int i=n;
                for(int j=0;j<n;j++)
                {
                    char ch =num.charAt(j);
                    a[j]=ch - '0';
                    sum+=a[j];
                }
                
                int last=n-1;
                if(sum%2==0)
                {
                    if(a[n-1]%2==1)
                    System.out.println(num);
                    else
                    {
                       for(i=n-1;i>=0;i--)
                       {
                          if(a[i]%2==1)
                          {
                              last=i;
                              break;
                          }
                          else
                          {
                              sum-=a[i];
                              a[i]=-1;
                          }
                       }
                       num="";boolean first0=true;
                       for(i=0;i<n;i++)
                       {
                           if(a[i]!=0 && a[i]!=-1 && first0==true)
                           first0=false;
                           if(a[i]!=-1 && first0==false)
                           num+=a[i];
                       }
                       if(a[last]%2==1 && sum%2==0)
                       System.out.println(num);
                       else
                       System.out.println(-1);
                    }
                }
                else
                {
                    if(a[n-1]%2==1)
                    {
                        for(i=0;i<n;i++)
                        {
                            if(a[i]%2==1)
                            {
                                sum-=a[i];
                                a[i]=-1;
                                break;
                            }
                        }
                        num=""; boolean first0=true;
                       for(i=0;i<n;i++)
                       {
                           if(a[i]!=0 && a[i]!=-1 && first0==true)
                           first0=false;
                           if(a[i]!=-1 && first0==false)
                           num+=a[i];
                       }
                       if(a[n-1]!=-1 && a[n-1]%2==1 && sum%2==0)
                       System.out.println(num);
                       else
                       System.out.println(-1);
                    }
                    else
                    {
                        for(i=n-1;i>=0;i--)
                        {
                            if(a[i]%2==1) 
                            {
                                last=i;
                                break;
                            }
                            else
                            {
                                sum-=a[i];
                                a[i]=-1;
                            }
                        }
                        
                        for(i=0;i<n;i++)
                        {
                            if(a[i]%2==1)
                            {
                                sum-=a[i];
                                a[i]=-1;
                                break;
                            }
                        }
                       num="";boolean first0=true;
                       for(i=0;i<n;i++)
                       {
                           if(a[i]!=0 && a[i]!=-1 && first0==true)
                           first0=false;
                           if(a[i]!=-1 && first0==false)
                           num+=a[i];
                       }
                       if(a[last]%2==1 && sum%2==0)
                       System.out.println(num);
                       else
                       System.out.println(-1);
                    }
                }
            }
    }
}