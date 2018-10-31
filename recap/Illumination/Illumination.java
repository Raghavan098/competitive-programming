import java.io.*;
import java.util.*;
public class Illumination {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());
		st.nextToken();
		int radius = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		State[] list = new State[n];
		Map<State, Integer> revMap = new HashMap<State, Integer>();
		Map<Integer, ArrayList<Integer>> xToY = new HashMap<Integer, ArrayList<Integer>>();
		Map<Integer, ArrayList<Integer>> yToX = new HashMap<Integer, ArrayList<Integer>>();
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			list[i] = new State(x, y);
			revMap.put(new State(x, y), i);
			insert(xToY, x, y);
			insert(yToX, y, x);
		}
		init2SAT(n);
		for(int row: xToY.keySet()) {
			ArrayList<Integer> yCoords = xToY.get(row);
			Collections.sort(yCoords);
			for(int i = 0; i < yCoords.size(); i++) {
				int j = i+1;
				while(j < yCoords.size() && yCoords.get(j) - yCoords.get(i) <= 2 * radius) {
					j++;
				}
				for(int k = i+1; k < j; k++) {
					int firstLamp = revMap.get(new State(row, yCoords.get(i)));
					int secondLamp = revMap.get(new State(row, yCoords.get(k)));
					addClause(firstLamp, false, secondLamp, false);
				}
			}
		}
		for(int col: yToX.keySet()) {
			ArrayList<Integer> xCoords = yToX.get(col);
			Collections.sort(xCoords);
			for(int i = 0; i < xCoords.size(); i++) {
				int j = i+1;
				while(j < xCoords.size() && xCoords.get(j) - xCoords.get(i) <= 2 * radius) {
					j++;
				}
				for(int k = i+1; k < j; k++) {
					int firstLamp = revMap.get(new State(xCoords.get(i), col));
					int secondLamp = revMap.get(new State(xCoords.get(k), col));
					addClause(firstLamp, true, secondLamp, true);
				}
			}
		}
		pw.println(valid() ? "YES" : "NO");
		pw.close();
	}

	public static void insert(Map<Integer, ArrayList<Integer>> m, int k, int v) {
		if(!m.containsKey(k)) {
			m.put(k, new ArrayList<Integer>());
		}
		m.get(k).add(v);
	}
	
	static class State {
		public int x, y;
		public State(int a, int b) {
			x=a;
			y=b;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
		
	}
	
	public static void init2SAT(int n) {
		edges = new ArrayList[2*n];
		for(int i = 0; i < edges.length; i++) {
			edges[i] = new ArrayList<Integer>();
		}
		components = new int[2*n];
		Arrays.fill(components, -1);
		indices = new int[2*n];
		Arrays.fill(indices, -1);
		lowLink = new int[2*n];
		Arrays.fill(lowLink, -1);
		indicesIndex = 0;
		componentsIndex = 0;
		tarjanStack = new Stack<TarjanState>();
		sccStack = new Stack<Integer>();
		inStack = new boolean[2*n];
	}

	public static boolean valid() {
		for(int i = 0; i < components.length; i++) {
			if(components[i] == -1) {
				tarjan(i);
			}
		}
		int n = edges.length/2;
		for(int i = 0; i < n; i++) {
			if(components[i] == components[i+n]) return false;
		}
		return true;
	}

	private static int _get2SATValue(int index, boolean pos1) {
		if(!pos1){
			index += edges.length/2;
		}
		return index;
	}

	public static void addClause(int i1, boolean pos1, int i2, boolean pos2) {
		edges[_get2SATValue(i1, !pos1)].add(_get2SATValue(i2, pos2));
		edges[_get2SATValue(i2, !pos2)].add(_get2SATValue(i1, pos1));
	}

	static ArrayList<Integer>[] edges;
	static int[] components;
	static int[] indices;
	static int[] lowLink;
	static int indicesIndex;
	static int componentsIndex;
	static Stack<TarjanState> tarjanStack;
	static Stack<Integer> sccStack;
	static boolean[] inStack;

	static class TarjanState {
		public int index;
		public int edgeNum;
		public boolean checkEarlier;
		public TarjanState(int index, int edgeNum, boolean checkEarlier) {
			super();
			this.index = index;
			this.edgeNum = edgeNum;
			this.checkEarlier = checkEarlier;
		}
	}

	public static void tarjan(int start) {    
		tarjanStack.push(new TarjanState(start, 0, false));
		while(!tarjanStack.isEmpty()) {
			TarjanState now = tarjanStack.pop();
			if(now.edgeNum == 0) {
				if(indices[now.index] >= 0) {
					continue;
				}
				inStack[now.index] = true;
				indices[now.index] = indicesIndex;
				lowLink[now.index] = indicesIndex;
				indicesIndex++;
				sccStack.push(now.index);
			}
			if(now.checkEarlier) {
				lowLink[now.index] = Math.min(lowLink[now.index], lowLink[edges[now.index].get(now.edgeNum-1)]);
			}
			if(now.edgeNum < edges[now.index].size()) {
				int next = edges[now.index].get(now.edgeNum);
				if(indices[next] == -1) {
					tarjanStack.push(new TarjanState(now.index, now.edgeNum + 1, true));
					tarjanStack.push(new TarjanState(next, 0, false));
				}
				else {
					tarjanStack.push(new TarjanState(now.index, now.edgeNum + 1, false));
					if(inStack[next]) {
						lowLink[now.index] = Math.min(lowLink[now.index], indices[next]);
					}
				}
			}
			else {
				if(lowLink[now.index] == indices[now.index]) {
					while(true) {
						int rem = sccStack.pop();
						inStack[rem] = false;
						components[rem] = componentsIndex;
						if(rem == now.index) {
							break;
						}
					}
					componentsIndex++;
				}
			}
		}
	}

}

