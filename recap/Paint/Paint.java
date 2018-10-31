import java.io.*;
import java.util.*;
public class Paint {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long n = Long.parseLong(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		Event[] l = new Event[k];
		for(int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			l[i] = new Event(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken()));
		}
		Arrays.sort(l);
		TreeMap<Long, Long> dp = new TreeMap<Long, Long>();
		long bestSeen = 0;
		for(Event currEvent: l) {
			while(!dp.isEmpty() && dp.firstKey() < currEvent.l) {
				bestSeen = Math.max(bestSeen, dp.remove(dp.firstKey()));
			}
			if(!dp.containsKey(currEvent.r)) {
				dp.put(currEvent.r, 0L);
			}
			dp.put(currEvent.r, Math.max(dp.get(currEvent.r), currEvent.r - currEvent.l + 1 + bestSeen));
		}
		long ret = 0;
		for(long key: dp.keySet()) {
			ret = Math.max(ret, dp.get(key));
		}
		pw.println(n - ret);
		pw.close();
	}
	
	static class Event implements Comparable<Event> {
		public long l, r;
		public Event(long a, long b) {
			l=a;
			r=b;
		}
		public int compareTo(Event e) {
			return Long.compare(l, e.l);
		}
	}
	
}

