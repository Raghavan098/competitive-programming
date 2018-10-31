using System;
using System.Collections.Generic;
 
 
public class Solution {
 
    public static void Main(string[] args) {
        int a = nextInt();
        next();
        int b = nextInt();
        next();

        Console.WriteLine(a + b == nextInt() ? "YES" : "NO");
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