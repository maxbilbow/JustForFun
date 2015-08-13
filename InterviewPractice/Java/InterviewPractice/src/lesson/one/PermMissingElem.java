package lesson.one;
/**
 * @author Max Bilbow
 * @status Complete
 */
class PermMissingElem {

//	Dictionary<int, bool> 


	public int solution(int[] A) {

		boolean[] exists = new boolean[A.length + 2];// = new Dictionary<int, bool> ();
		for (int a : A) {
			exists[a] = true;
		}
		for (int i = 1; i < exists.length; ++i) {
			if (!exists[i])
				return i;
		}
		return -1;

	}

	public static void main(String[] args) {
		int[] A = {
			2,3,1,5	
		};
		System.out.println("Soln: " + new PermMissingElem().solution(A));
		

	}

}
