import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

/**
 * Solution to Barbells
 * 
 * @author vanb
 */
public class Barbells_Vanb2
{
    private static Scanner sc;
    private static PrintStream ps;
    
    private int bars[], plates[];
    
    private int halftotal;
    
    private HashMap<Integer, List<Integer>> bitmaps = new HashMap<Integer, List<Integer>>();
    
    private void subsets( int level, int bitmap, int sum )
    {
        if( sum <= halftotal )
        {
            if( level==0 )
            {
                List<Integer> maps = bitmaps.get( sum );
                if( maps==null )
                {
                    maps = new ArrayList<Integer>();
                    bitmaps.put( sum, maps );
                }
                
                maps.add( bitmap );
            }
            else
            {
                --level;
                subsets( level, bitmap, sum );
                subsets( level, bitmap|(1<<level), sum+plates[level] );
            }
        }
    }
    
    private void doit()
    {
        int b = sc.nextInt();
        int p = sc.nextInt();
        
        bars = new int[b];
        for( int i=0; i<b; i++ ) bars[i] = sc.nextInt();
        
        plates = new int[p];
        for( int i=0; i<p; i++ )  halftotal += (plates[i] = sc.nextInt());
        halftotal /= 2;
        
        subsets( plates.length, 0, 0 );

        HashSet<Integer> weights = new HashSet<Integer>();
        
        for( int wt : bitmaps.keySet() )
        {
            boolean found = false;
            List<Integer> maps = bitmaps.get( wt );
            for( int b1 : maps ) for( int b2 : maps )
            {
                if( (b1 & b2) == 0 ) found = true;
            }
            
            if( found )
            {
                for( int bar : bars ) weights.add( wt + wt + bar );
            }
        }
        
        Integer wts[] = (Integer[])weights.toArray( new Integer[weights.size()] );
        Arrays.sort( wts );
        for( int wt : wts ) ps.println( wt );
    }
        
    public static void main( String[] args ) throws Exception
    {
        sc = new Scanner( System.in );
        ps = System.out;
        
        new Barbells_Vanb2().doit();
    }

}
