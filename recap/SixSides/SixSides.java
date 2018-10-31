import java.util.*;
public class SixSides {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int[] a = new int[6];
		int[] b = new int[6];
		for(int i = 0; i < 6; i++) {
			a[i] = scan.nextInt();
		}
		for(int i = 0; i < 6; i++) {
			b[i] = scan.nextInt();
		}
		int w = 0;
		int l = 0;
		for(int x: a) {
			for(int y: b) {
				if(x > y) {
					w++;
				}
				else if(x < y) {
					l++;
				}
			}
		}
		System.out.printf("%.5f\n", w * 1.0 / (w+l));
	}
}

