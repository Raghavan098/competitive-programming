using System;
using System.Collections.Generic;
 
 
public class Solution {
 
    public static void Main(string[] args) {
        int n = nextInt();
        int k = nextInt();

        long[] pos = new long[10000001];
        long[] neg = new long[10000001];

        for(int i=0; i < n; i++) {
            long addr = nextLong();
            long cnt = nextLong();
            if(addr < 0) 
                neg[-addr] += cnt;
            else
                pos[addr] += cnt;
        }

        long ans = minDist(pos, k) + minDist(neg, k);
 
        Console.WriteLine(ans);
    }

    private static long minDist(long[] arr, long k) {
        long carry = 0;
        long total = 0;
        for(int i=10000000; i > 0; i--) {
            if (arr[i] == 0)
                continue;
            if (carry != 0 && arr[i] >= (k-carry)) {
                arr[i] -= (k-carry);
                carry = 0;
                i++;
                continue;
            }
            if (arr[i] >= k && carry == 0) {
                total += (arr[i] / k) * i * 2;
                arr[i] = arr[i] % k;
                i++;
                continue;
            }
            if (carry == 0)
                total += i * 2;
            carry += arr[i];
            arr[i] = 0;
        }
        return total;
    }
 
 
    private static string[] __tokens;
    private static int __tidx;
    public static int nextInt() {
        return int.Parse(next());
    }
    public static long nextLong() {
        return long.Parse(next());
    }
 
    public static string next() {
        if (__tokens == null || __tidx == __tokens.Length) {
            __tidx = 0;
            __tokens = Console.ReadLine().Split(' ');
        }
        return __tokens[__tidx++];
    }
}