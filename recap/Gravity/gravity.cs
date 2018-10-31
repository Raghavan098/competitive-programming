using System;
using System.Collections.Generic;
 
 
public class Solution {
 
    public static void Main(string[] args) {
        int rows = nextInt();
        int cols = nextInt();

        char[][] grid = new char[rows][];

        for(int i=0; i < rows; i++) {
            grid[i] = next().ToCharArray();
        }

        for (int k=0; k<= 60; k++) {
            for(int j=0; j < cols; j++) {
                for(int i=rows-1; i >= 0; i--) {
                    if (grid[i][j] == '.' && i-1 >= 0 && grid[i-1][j] == 'o') {
                        grid[i][j] = grid[i-1][j];
                        grid[i-1][j] = '.';
                    }
                }
            }
        }
 
        for(int i=0; i < rows; i++) {
            for(int j=0; j< cols; j++) {
              Console.Write(grid[i][j]);
            }
           Console.WriteLine();
        }
        //Console.WriteLine(n+m);
    }
 
 
    private static string[] __tokens;
    private static int __tidx;
    public static int nextInt() {
        return int.Parse(next());
    }
 
    public static string next() {
        if (__tokens == null || __tidx == __tokens.Length) {
            __tidx = 0;
            __tokens = Console.ReadLine().Split(' ');
        }
        return __tokens[__tidx++];
    }
}