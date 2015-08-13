package lesson.one;
/**
 * @author Max Bilbow
 * @status Complete
 */
class TapeEquilibrium {
	int lhs = 0;
	int rhs;
	int[] A;

	int Abs(int lhs, int rhs) {
		return Math.abs (lhs - rhs);
	}

 	int getDiff(int P) {
		rhs -= A [P];
		lhs += A [P];

		return Abs (lhs,rhs);
	}

	int first () {
		lhs = A [0];
		for (int i = 1; i < A.length; ++i) {
			rhs += A[i];
		}
		return Abs (lhs,rhs);
	}

	public int solution(int[] A) {
		// write your code in C# 6.0 with .NET 4.5 (Mono)

		this.A = A;
		int diff = first ();

		for (int p = 1; p < A.length-1; p++) {
			int thisDiff = getDiff(p);
			if (thisDiff < diff){
				diff = thisDiff;
			}
		}

		return diff;
	}

	public static void main(String[] args) {
		int[] A = {
				2,3,1,5	
			};
		System.out.println("Soln: " + new TapeEquilibrium().solution(A));
	}

}
