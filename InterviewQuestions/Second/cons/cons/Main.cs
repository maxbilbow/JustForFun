using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace cons
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.WriteLine("Soln: " + new TapeEquilibrium().solution(new int[] {
				2,3,1,5
			}));

			Console.WriteLine("Soln: " + new PermMissingElem().solution(new int[] {
				2,3,1,5
			}));

			Console.WriteLine("Soln: " + new FrogJump().solution(10,85,30));
//			Console.WriteLine("Task1: " + new Task1().solution("a0Ba7Haaa"));
//			Console.WriteLine("Task1: " + new Task1().solution("a0bb"));
			Console.WriteLine("Task2: " + new Task2().solution(2014, "April", "May", "Wednesday"));


		}
	}
}

class Task2 {


	class Month {
		public static string firstOfJan = "Monday";
		static int getOffset() {
			for (int i = 0; i<7; ++i) {
				if (weekdays[i] == firstOfJan)
					return i;
			}
			throw new System.Exception("Day was invalid");
		}
		bool IsLeapYear;

		public static bool isLeapYear(int Year) {
			return (Year) % 4 == 0;
		}
		public static Dictionary<string, int> months = new Dictionary<string, int>() {
			{"jan", 31},
			{"feb", 28},
			{"mar", 31},
			{"apr", 30},
			{"may", 31},
			{"jun", 30},
			{"jul", 31},
			{"aug", 31},
			{"sep", 30},
			{"nov", 31},
			{"dec", 30}
		};

		public static string[] weekdays = {
			"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
		};
		
		public int Offset = 0;
		public int TrailingDays {
			get {
				return (int) (Days - Offset) % 7;
			}
		}
		public Month(string name, bool leapYear, int offset = 0) {
			this.IsLeapYear = leapYear;
			this.Name = name;
			if (Name == "jan")
				Offset = getOffset();
			else
				Offset = offset;
		}

		string name;
		public string Name {
			get {
				return name;
			} set {
				this.name = value.Substring (0, 3).ToLower ();
			}
		}

		int days = -1;
		public int Days {
			get {
				if (days < 28) {
					string mon = this.name.Substring (0, 3).ToLower ();
					this.days = months [mon];
					if (this.name == "feb" && IsLeapYear)
						this.days = 29;
				}
				return days;
			}
		}

		public int wholeWeeks {
			get {
				return (int) Math.Floor(((double) Days - Offset )/ 7);
			}
		}
	}
	
	LinkedList<Month> Months = new LinkedList<Month>();


	public int solution(int Y, string A, string B, string W) {
		bool leap = Month.isLeapYear (Y);
		Month.firstOfJan = W;
		Console.WriteLine (Y+ " isLeapYear: " + leap);

		foreach (KeyValuePair<string, int> month in Month.months) {
			if (Months.Count == 0)
				Months.AddLast(new Month(month.Key, leap));
           	else {
				var nextMonth = new Month(month.Key, leap, Months.Last.Value.TrailingDays);
				Months.AddLast(nextMonth);
			}
		}
		int totalWeeks = 0;
		int countableDays = 0;

		string firstMonth = A.Substring (0, 3).ToLower ();
		string lastMonth = B.Substring (0, 3).ToLower ();

		LinkedListNode<Month> current = Months.First;
		while (current.Value.Name != firstMonth) {
			Console.WriteLine(current.Value.Name + " is not the first month");
			Console.WriteLine(current.Value.Name + " contains " + current.Value.Days + " days, " + current.Value.wholeWeeks + " weeks, offset " + current.Value.Offset + " and " +current.Value.TrailingDays + " trailing days.");

			current = current.Next;
		}
		countableDays = -current.Value.Offset;
		do {
			countableDays += current.Value.Days;
			totalWeeks += current.Value.wholeWeeks;
			Console.WriteLine (current.Value.Name + " contains " + current.Value.Days + " days, " + current.Value.wholeWeeks + " weeks, offset " + current.Value.Offset + " and " + current.Value.TrailingDays + " trailing days.");
			current = current.Next;
		} while (current != null && current.Previous.Value.Name != lastMonth);

		// write your code in C# 6.0 with .NET 4.5 (Mono)
		return (int) Math.Floor((float)countableDays / 7);
	}
}

class Task1 {
//	string pwd;
//	string[] texts;
	int result = 0;
	void findPasswords(string text, int length) {

		if (isValid (text)) {
			Console.WriteLine (text + " is valid");
			result++;
			int newLength = length -1;
			for (int i = 0; i < newLength; ++i) {
				string sub = text.Substring (i, newLength);
				findPasswords (sub, newLength);
			}
		}


	}

	bool isValid(string text) {
		return Regex.IsMatch (text, "[A-Z]");
	}


	public int solution(string S) {

		string[] texts = Regex.Split(S, @"\d+");
		for(int i = 0; i < texts.Length; ++i)
		{
			findPasswords(texts[i], texts[i].Length);
		}

		return result == 0 ? -1 : result;
	}
}



class FrogJump {
	public int solution(int X, int Y, int D) {
		// write your code in C# 6.0 with .NET 4.5 (Mono)
		return (int) Math.Ceiling((double)(Y - X) / D);
		 
	}
}

class PermMissingElem {

//	Dictionary<int, bool> 


	public int solution(int[] A) {

		bool[] exists = new bool[A.Length + 2];// = new Dictionary<int, bool> ();
		foreach (int a in A) {
			exists[a] = true;
		}
		for (int i = 1; i < exists.Length; ++i) {
			if (!exists[i])
				return i;
		}
		return -1;

	}
}

class TapeEquilibrium {
	int lhs = 0;
	int rhs;
	int[] A;

	int Abs(int lhs, int rhs) {
		return Math.Abs (lhs - rhs);;
	}

 	int getDiff(int P) {
		rhs -= A [P];
		lhs += A [P];

		return Abs (lhs,rhs);
	}

	int first () {
		lhs = A [0];
		for (int i = 1; i < A.Length; ++i) {
			rhs += A[i];
		}
		return Abs (lhs,rhs);
	}

	public int solution(int[] A) {
		// write your code in C# 6.0 with .NET 4.5 (Mono)

		this.A = A;
		int diff = first ();

		for (int p = 1; p < A.Length-1; p++) {
			int thisDiff = getDiff(p);
			if (thisDiff < diff){
				diff = thisDiff;
			}
		}

		return diff;
	}
}
