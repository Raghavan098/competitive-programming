import java.util.*;
public class Equality {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		scan.next();
		int b = scan.nextInt();
		scan.next();
		int c = scan.nextInt();
		if(a+b == c) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
}

