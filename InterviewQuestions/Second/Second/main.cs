using System;
// you can also use other imports, for example:
// using System.Collections.Generic;

// you can use Console.WriteLine for debugging purposes, e.g.
// Console.WriteLine("this is a debug message");

class Solution {

	public int getDiff(int P) {
		int lhs = 0; int rhs = 0;
		int i = 0;
		foreach (int a in A) {
			if (i < P)
				lhs += a;
			else
				rhs += a;
		}
		int diff = Math.Abs (lhs - rhs);
		return diff;
	}

	public int solution(int[] A) {
		// write your code in C# 6.0 with .NET 4.5 (Mono)
		int diff;
		int s = getDiff(0);
		for (int p = 1; p < A.Length; p++) {
			int thisDiff = getDiff(p);
			if (thisDiff < diff){
				diff = thisDiff;
			}
		}
		Console.WriteLine (diffs [s]);
		return diff;
	}
}
