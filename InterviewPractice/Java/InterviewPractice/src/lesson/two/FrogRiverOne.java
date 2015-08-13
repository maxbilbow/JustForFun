package lesson.two;

/**
 * @author Max Bilbow
 * @status Complete
 */
public class FrogRiverOne extends lesson.Solution {
	
	
    public int solution(int X, int[] A) {
    	boolean[] leaves = new boolean[X+1];
    	int needed = X;
    	for (int i = 0; i < A.length; ++i) {
    		if (A[i] <= X && leaves[A[i]] == false) {
    			leaves[A[i]] = true;
    			needed--;
    			if (needed == 0)
    				return i;
    		}
    	}
		return -1;
        // write your code in Java SE 8
    }
    
    public static void main(String [] args){
    	int[] A = {
    		1,3,1,4,2,3,5,4	
    	};
    	FrogRiverOne s = new FrogRiverOne();
    	System.out.println("Soln: " + s.solution(3, A));
    }
}