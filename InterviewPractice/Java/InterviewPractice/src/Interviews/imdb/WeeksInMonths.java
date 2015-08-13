package Interviews.imdb;
import java.util.LinkedList;
import java.util.HashMap;
public class WeeksInMonths extends lesson.Solution{
//	public static final String firstOfJan = "Monday";
	public static final String[] weekdays = {
			"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
		};
	public static int getOffset(String day) {
		for (int i = 0; i<7; ++i) {
			if (weekdays[i] == day)
				return i;
		}
//		throw new System.Exception("Day was invalid");
		return -1;
	}
	static boolean isLeapYear;
	public boolean isLeapYear(int Year) {
		isLeapYear = (Year) % 4 == 0;
		return isLeapYear;
	}
	
	public static HashMap<String, Integer> months = new HashMap<String, Integer> ();
//{
//		{"jan", 31},
//		{"feb", 28},
//		{"mar", 31},
//		{"apr", 30},
//		{"may", 31},
//		{"jun", 30},
//		{"jul", 31},
//		{"aug", 31},
//		{"sep", 30},
//		{"nov", 31},
//		{"dec", 30}
//	} );

	public class Month {

		public int offset = 0;
		public int TrailingDays() {
			return (int) (getDays() - offset) % 7;
		}
		
		public Month(String name, boolean leapYear, int offset) {
			isLeapYear = leapYear;
			this.setName(name);
			this.offset = offset;
		}

		String name;
		public String getName() {
			return name;
		}
		void setName(String name) {
			this.name = name.substring(0, 3).toLowerCase ();
		}

		int days = -1;
		public int getDays() {
				if (days < 28) {
					String mon = this.name.substring(0, 3).toLowerCase ();
					this.days = months.get(mon);
					if (this.name == "feb" && isLeapYear)
						this.days = 29;
				}
				return days;
		}

		public int wholeWeeks() {
			return (int) Math.floor((getDays() - offset )/ 7);
		}
	}

	LinkedList<Month> Months = new LinkedList<Month>();


	public int solution(int Y, String A, String B, String W) {
		boolean leap = isLeapYear (Y);
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

		String firstMonth = A.Substring(0, 3).ToLower ();
		String lastMonth = B.Substring(0, 3).ToLower ();

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
	
	public static void main(String[] args) {
		
		System.out.println("Task2: " + new WeeksInMonths().solution(2014, "April", "May", "Wednesday"));

	}

}


