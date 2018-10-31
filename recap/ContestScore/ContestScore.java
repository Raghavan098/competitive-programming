import java.util.*;
public class ContestScore {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		long ret = 0;
		long curr = 0;
		for(int i = 0; i < n; i++) {
			list.add(scan.nextInt());
			if(list.size() == k) {
				Collections.sort(list);
				ret += curr += list.remove(0);
			}
		}
		for(int left: list) {
			ret += curr += left;
		}
		System.out.println(ret);
	}
}

