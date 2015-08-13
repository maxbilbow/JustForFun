package lesson.two;

import java.util.Random;
/**
 * @author Max Bilbow
 * @status 70%
 */
public class MaxCounters extends lesson.Solution {
//	int getMax(int[] array) {
//		int max = array[0];
//		for (int i=1;i<array.length;++i) {
//			if (array[i]>max) {
//				max = array[i];
//			}
//		}
//		return max;
//	}
	protected void log(String log) {
		this.log += "\n" + log;
	}
	int max = 0;

	//TODO make faster with large sets
	public int[] solution(int N, int[] A) {
		int[] counters = new int[N];
		for (int i=0; i<A.length; ++i) {
			int n = A[i];
			if (n < N+1) {
				int newVal = ++counters[n-1];
				if (newVal> max)
					max = newVal;
			} else if (n == N + 1) {
				for (int j=0; j<N; ++j)
					counters[j] = max;
			} 
//			else 
//				log("WARNING: n was too big! " + n);
		}
		return counters;
    }
	public static void main(String[] args) {
		MaxCounters s = new MaxCounters();
		int[] A = {
				3,4,4,6,1,4,4
		};
		int[] B = {
				4, 1, 3, 1, 2, 6, 5, 8
		};
		
		int[] C = {
				4, 3, 2, 6, 5, 8
		};
		
		int j = 10000; int N = 10000;
		int[] D = new int[j];
		Random rnd = new Random();
		for (int i = 0; i < j; ++i) {
			D[i] = rnd.nextInt(N) + 1;
		}
		
		shuffleArray(D);
		D[900] = 1;
//		System.out.print("[ " + D[0]);
//		for (int i = 1; i < D.length; ++i) 
//			System.out.print(", " + D[i]);
//		System.out.println(" ]");
		
		System.out.println("Soln A: " + ToString(s.solution(5, A)));
		System.out.println("Soln B: " + ToString(s.solution(5, B)));
		System.out.println("Soln C: " + ToString(s.solution(5, C)));
		System.out.println("Soln D: " + ToString(s.solution(N, D)));
//		System.out.println(ToString(D));
//		System.out.println("Soln D: " + ToString(s.solution(5, D));
//		System.out.println(s);
	}

}
