/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

/**
 *
 * @author kacho
 */
public class Codeforce {
    
    static class Reader { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; // line length 
            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    }
    
    static int n;
    static int arr[][][];
    static char res[][];

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        Reader rd = new Reader();
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new
         FileOutputStream(java.io.FileDescriptor.out), "ASCII"), 512);
        n = rd.nextInt();
        arr = new int[n][n][2];
        res = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j][0] = rd.nextInt();
                arr[i][j][1] = rd.nextInt();
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j][0] == -1) {
                    if (res[i][j] != '\u0000') continue;
                    if (i < n - 1 && arr[i + 1][j][0] == -1) {
                        res[i][j] = 'D';
                        res[i + 1][j] = 'U';
                    } else if (j < n - 1 && arr[i][j + 1][0] == -1) {
                        res[i][j] = 'R';
                        res[i][j + 1] = 'L';
                    } else if (i > 0 && arr[i - 1][j][0] == -1) {
                        res[i][j] = 'U';
                        res[i - 1][j] = 'D';
                    } else if (j > 0 && arr[i][j - 1][0] == -1) {
                        res[i][j] = 'L';
                        res[i][j - 1] = 'R';
                    } else {
                        System.out.println("INVALID");
                        return;
                    }
                } else if (i == arr[i][j][0] - 1 && j == arr[i][j][1] - 1) {
                    dfs(arr[i][j][0] - 1, arr[i][j][1] - 1, 'X');
                }
            }
        }
        
        for (char[] charr : res) {
            for (char ch : charr)
                if (ch == '\u0000') {
                    System.out.println("INVALID");
                    return;
                }
        }
        
        System.out.println("VALID");
        
        for (char[] charr : res) {
            for (char ch : charr)
                out.write(ch);
            out.write('\n');
        }
        out.flush();
    }
    
    static void dfs(int i, int j, char ch) {
        if (res[i][j] != '\u0000') return;
        res[i][j] = ch;
        if (i < n - 1 && arr[i + 1][j][0] == arr[i][j][0] && arr[i + 1][j][1] == arr[i][j][1])
            dfs(i + 1, j, 'U');
        if (j < n - 1 && arr[i][j + 1][0] == arr[i][j][0] && arr[i][j + 1][1] == arr[i][j][1])
            dfs(i, j + 1, 'L');
        if (i > 0 && arr[i - 1][j][0] == arr[i][j][0] && arr[i - 1][j][1] == arr[i][j][1])
            dfs(i - 1, j, 'D');
        if (j > 0 && arr[i][j - 1][0] == arr[i][j][0] && arr[i][j - 1][1] == arr[i][j][1])
            dfs(i, j - 1, 'R');
    }
    
}