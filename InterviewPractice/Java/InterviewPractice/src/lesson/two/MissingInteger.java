package lesson.two;

import java.util.HashMap;
import java.lang.Integer;
import java.lang.Boolean;
/**
 * @author Max Bilbow
 * @status Complete
 */
public class MissingInteger extends lesson.Solution {
	
	int smallestMissing = 1;
	HashMap<Integer,Boolean> isFound;
	
	void nextSmallestMissing() {
		Integer key = ++this.smallestMissing;
		if (isFound.getOrDefault(key, false)) { 
			this.nextSmallestMissing();
		}
	}
	
	void recursiveNextSmallest() {
		try {
			this.nextSmallestMissing();
		} catch (StackOverflowError e) {
			this.log("\n" + this.smallestMissing + " => ERROR: " + e);
			--this.smallestMissing;
			this.recursiveNextSmallest();
		}
	}
	
	public int solution(int[] A) {
		this.smallestMissing = 1;
		isFound = new HashMap<Integer,Boolean>(A.length);
		for (int i = 0; i < A.length; ++i) {
			int n = A[i];
			if (n >= smallestMissing) {;
				if(!isFound.getOrDefault(n, false)) {
					isFound.put(n, true);
					if (n == this.smallestMissing) {
						this.recursiveNextSmallest();
					}		
				}
			}
		}
		return this.smallestMissing;
	}

	
	public static void main(String[] args) {
		MissingInteger s = new MissingInteger();
		int[] A = {
				1,3,6,4,1,2
		};
		int[] B = {
				4, 1, 3, 1, 2, 6, 5, 8
		};
		
		int[] C = {
				-1, 4, 3, 2, 6, 5, 8
		};
		
		int j = 100000;
		int[] D = new int[j];
		for (int i = 0; i < 100000; ++i) {
			D[i] = j--;
		}
		
		shuffleArray(D);
		D[90253] = 1;
//		System.out.print("[ " + D[0]);
//		for (int i = 1; i < D.length; ++i)
//			System.out.print(", " + D[i]);
//		System.out.println(" ]");
		
		System.out.println("Soln A: " + s.solution(A));
		System.out.println("Soln B: " + s.solution(B));
		System.out.println("Soln C: " + s.solution(C));
		System.out.println("Soln D: " + s.solution(D));
		System.out.println(s);
	}

}
