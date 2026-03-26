//********************(Writer-Aagam)*******************************
//*******************(User-getlost01)******************************

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

//------------------------Main_class-------------------------------

public class Codechef
{
static AagamReader ar=new AagamReader();
   
//----------------------Main_Function------------------------------

public static void main (String[] args) throws java.lang.Exception
{
// long start=System.currentTimeMillis();

int t=ar.nextInt();
while(t-->0)
{
int a=ar.nextInt();
int b=ar.nextInt();
int i=ar.nextInt();
int j=ar.nextInt();
int temp1=i*b;
int temp2=j*a;
int temp3=(a-i-1)*b;
int temp4=(b-j-1)*a;
System.out.println(Math.max(temp1,Math.max(temp2,Math.max(temp3,temp4))));
        }
// long end=System.currentTimeMillis();
// System.out.println(end-start+" Millisec");
}

//--------------------Solving_Function---------------------------

static void solve(String s)
{


System.out.println(s);
}
//------------------------Reverse----------------------------------

public static int[] reverses(int data[], int left, int right)
{
while (left < right) 
{
int temp = data[left];
data[left++] = data[right];
data[right--] = temp;
}
return data;
}

//----------------------------Swap-----------------------------------

public static int[] swap(int data[], int left, int right) 
{
int temp = data[left];
data[left] = data[right];
data[right] = temp;
return data;
}

//--------------------------Factorial---------------------------------

public static long factorials(long n)
{
if(n==0) return 1; 

return n*factorials(n-1);
}

//-------------------------G.C.D---------------------------------------

public static long gcd(long a,long b)
{
if(b==0) return a;

return gcd(b,a%b);
}

//-------------------------ModularG.C.D-------------------------------

static long gcd(long a,long b,long n,long mod)
{
if(a==b)
return (mod_expo(a,n,mod)+mod_expo(b,n,mod))%mod;

long c=1;long diff=a-b;

for(long i=1;i<=Math.sqrt(diff);i++)
{
if(diff%i==0)
{
long temp=(mod_expo(a,n,i)+mod_expo(b,n,i))%i;
if(temp==0)
c=Math.max(c,i);

temp=(mod_expo(a,n,diff/i)+mod_expo(b,n,diff/i))%(diff/i);
if(temp==0)
c=Math.max(c,diff/i);
}
}
return c%mod;
}

//------------------------ l.C.M--------------------------------------
public static long lcm(long a,long b)
{
return (a*b)/gcd(a,b);
}
//---------------------------Prime-----------------------------------

public static boolean[] seive(int n)
{
boolean isPrime[]=new boolean[n+1];
Arrays.fill(isPrime,true);
isPrime[0]=false;
isPrime[1]=false;
for(int i=2;i*i<=n;i++)
{
for(int j=2*i;j<=n;j+=i)
{
isPrime[j]=false;
}
}
return isPrime;
}

//----------------------Modular_Exponentiation-------------------------

static long mod_expo(long a,long b,long n)
{
long res=1;
while(b>0)
{
if((b&1)!=0)
{res=(res*a%n)%n;}

a=(a%n*a%n)%n;
b=b>>1;
}
return res;
}

//-------------------------Power-----------------------------------------

static int fastpower(int a,int b)
{
int res=1;
while(b>0)
{
if((b&1)!=0)
res=res*a;

a=a*a;
b=b>>1;
}
return res;
}

//---------------------Modular_Arithmetic---------------------------------

public long modularSubtraction(long a,long b,long MOD)    // Modular Subtraction
{ return (a%MOD-b%MOD+MOD)%MOD; }

public long modularMultiplication(long a,long b,long MOD) // Modular Multiplication
{ return ((a%MOD)*(b%MOD))%MOD; }

public long modularAddition(long a,long b,long MOD)       // Modular Addition
{ return (a%MOD+b%MOD)%MOD; }	

//-----------------------Binary_Searching-----------------------------------

public static int binarySearch(int arr[], int first, int last, int num)
{
int mid = (first + last) / 2;
while (first <= last)
{
if (arr[mid] < num) {first = mid + 1;} 
else if (arr[mid] == num) {return mid;}
else {last = mid - 1;}
mid = (first + last) / 2;
}
return -1;
}

//-------------------------------------Node-------------------------------- 

static class Node<E>             
{
protected E data;
protected Node link;  //link====>next/linked address

public Node() {data=null; link=null;}

public Node(E d,Node n) {data=d; link=n;}  

public void setLink(Node n) {link=n;}

public void setData(E d) {data=d;}

public Node getLink() {return link;}

public E getData() {return data;}
}

//--------------------------------------Aaagmlist-----------------------------

static class aagamList<E>
{
protected Node start;
protected Node end;
public int size;

public aagamList() {start=null;end=null;size=0;}

public boolean isEmpty() {return start==null;}

public int size() {return size;}

public E get(int pos)
{ Node<E> curr=start; int c=0;
  while(curr!=null) {if(c==pos) return curr.data; c++; curr=curr.link;}
  return null;}

public void push_lr(E val) { Node<E> cnode=new Node<>(val,null); cnode.link=start; start=cnode;}

public void prepend(E val)
{ Node<E> cnode=new Node<E>(val,null); size++;
  if(start==null) {start=cnode;end=start;} 
  else {cnode.setLink(start);start=cnode;}
}

public void append(E val)
{ Node<E> cnode=new Node<E>(val,null); size++;
  if(start==null) {start=cnode;end=start;} 
  else {end.setLink(cnode);end=cnode;}
}

public void insert(E val,int pos)
{ Node<E> cnode=new Node<>(val,null); Node temp=start; --pos;
  for(int i=1;i<size;i++)
  { if(i==pos) {Node tmp=temp.getLink(); temp.setLink(cnode); cnode.setLink(tmp); break;}
    temp=temp.getLink(); } size++;
}

public void remove(int pos)
{ if(pos==1) {start=start.getLink(); size--; return;}
  if(pos==size) {Node s=start; Node t=start; while(s!=end) {t=s; s=s.getLink();}
  end=t; end.setLink(null); size--; return;}
  Node temp=start; --pos;
  for(int i=0;i<size-1;i++) 
  { if(i==pos) {Node tmp=temp.getLink(); tmp=tmp.getLink(); temp.setLink(tmp); break;}
  temp=temp.getLink(); }size--; 
}

public void display()
{ if(size==0) {System.out.println(" "); return;}
  if(start.getLink()==null) {System.out.println(start.getData()); return;}
  Node<E> temp=start; System.out.print(temp.getData()+" ");
  temp=start.getLink();
  while(temp.getLink()!=null) {System.out.print(temp.getData()+" "); temp=temp.getLink();}
  System.out.print(temp.getData()+"\n");
}
}

//----------------------------------------Stack------------------------------

static class Astack<E>
{
aagamList<E> a=new aagamList<>();
public void push(E val) {a.append(val); return;}
public void pop() {a.remove(a.size()-1); return;}
public void display() {a.display(); return;}
}

//---------------------------------------Dequeue------------------------------

static class Adequeue<E>
{
aagamList<E> a=new aagamList<>();
public void push_f(E val) {a.prepend(val); return;}
public void push_b(E val) {a.append(val); return;}
public void pop_f() {a.remove(0); return;}
public void pop_b() {a.remove(a.size()-1); return;}
public void display() {a.display(); return;}
}

//-----------------------AagamReader_class------------------------------------

public static class AagamReader 
{
BufferedReader br;
StringTokenizer st;

public AagamReader()
{
br = new BufferedReader(new InputStreamReader(System.in));
}

String next()                                           //ReadNextToken
{
while (st == null || !st.hasMoreElements()) 
{
try 
{
st = new StringTokenizer(br.readLine());
}
catch (IOException e) {e.printStackTrace();}
}
return st.nextToken();
}

int nextInt() { return Integer.parseInt(next()); }        //ReadInt

long nextLong() { return Long.parseLong(next()); }        //ReadLong

double nextDouble() { return Double.parseDouble(next());} //ReadDouble

int[] get_arr(int n)                                      //ReadArray
{
int arr[]=new int [n];
for(int i=0;i<n;i++)
arr[i]= Integer.parseInt(next());
return arr;
}

String nextLine()                                         //Readline
{
String str = "";
try 
{ 
str = br.readLine(); 
}
catch (IOException e) 
{
e.printStackTrace();
}
return str;
}
}
}
//=>->->->-->->->-[>>>>>>ENDING_WITH_HAPPY_CODING<<<<<<]-<-<-<-<-<-<-<-<-<-<=

