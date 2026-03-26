import java.io.* ;
public class Main
{
    public static void main( String[] args)  throws Exception
    {
        BufferedReader br  = new BufferedReader ( new InputStreamReader( System.in ) );
        PrintWriter out =  new PrintWriter ( System.out );
    
        int t = Integer.parseInt( br.readLine() ) ;
        
        int[] arr = new int [ t ] ;
 
        for( int i   = 0 ; i != t  ; ++i )
            arr[ i ] =Integer.parseInt( br.readLine() ) ;
        
        for( int item : arr )
            out.println( "1 " + ( item-1 ) );
        out.flush(); 
            
        return  ;
        
    }
}