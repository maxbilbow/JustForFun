package lesson.two;
/**
 * @author Max Bilbow
 * @status Complete
 */
public class PermCheck {
	public static final int IS_PERM = 1;
	public static final int MISSING_VALUE = 0;
	public static final int REPEATED_VALUE = 0;
	
	  public int solution(int[] A) {
	        // write your code in Java SE 8
		  boolean[] perm = new boolean[A.length+1];
		  int needed = A.length;
		  for (int i = 0; i < A.length; ++i) {
			  if (A[i] > A.length)
				  return MISSING_VALUE;
			  else if (perm[A[i]] == true)
				  return REPEATED_VALUE; 
			  else {
				  perm[A[i]] = true;
				  needed--;
				  if (needed == 0)
					  return IS_PERM;
			  }
		  }
		  return -1;
	  }

	  public static void main(String[] args) {
		  PermCheck s = new PermCheck();
		  int[] A = {
				  4, 1, 3, 2
		    	};
		  
		  int[] B = {
				  4, 1, 3
		    	};
		  System.out.println("Soln: " + s.solution(A));
		  System.out.println("Soln: " + s.solution(B));
	  }
}
