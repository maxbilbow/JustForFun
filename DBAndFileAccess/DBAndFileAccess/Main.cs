using System;

using System.Collections.Generic;

namespace DBAndFileAccess
{
	class MainClass
	{
		public const float variation = 0.2f;
		public const int csv_time = 2;
		public const int csv_text = 1;
		public static string file = "../../Pro-crastinate - Form responses 1.csv";

		public static float TimeHMSToFloat(string time, char parser) {
			string[] hms = {"","",""};
			int i = 0;
			foreach (char c in time) {
				if (!char.IsDigit(c)) { //c == parser) {
					++i;
				} else {
//					char.IsDigit
					hms[i] += c;
				}
			}
			float seconds = 0;
			try {
				seconds  = float.Parse (hms [2]);
				seconds += float.Parse(hms [1]) * 60;
				seconds += float.Parse(hms [0]) * 60 * 60;
			} catch (Exception e) {
				throw e;//Console.WriteLine(e.Message);//TODO: Change to Debug.Log
			}
			return seconds;

		}

//		private static float Min(float time) {
//			return time * 0.9f;
//		}
//
//		private static float Max(float time) {
//			return time + 1.1f;
//		}

		public static bool IsWithinTime(string time, float withinTime) {
			try {
				var seconds = TimeHMSToFloat (time, ':');
				var min = withinTime * (1 - variation);
				var max = withinTime * (1 + variation);
//				Console.Write ("\n" + time + ", seconds: " + seconds + ", ");
				return seconds >= min && seconds < max;
			} catch (Exception e) {
				throw e;
			} 
		}

		public static List<CsvReader.CsvRecord> GetActivities(float inTime) {
			var reader = CsvReader.Read (file);

			var list = reader.FindAll(match => {
				try {
					return IsWithinTime(match[csv_time], inTime);
				} catch (Exception e) {
					Console.WriteLine(e.Message + ": " + match[csv_time]);
					return false;
				}
			});
			return list;
		}

		public static void TestCsv ()
		{
			float[] testTimes = { 10f, 20f, 30f, 45f, 60f, 120f, 3000f, 6000f, 80000f };
			foreach (float time in testTimes) {
				Console.WriteLine("\n\n--------- Testing: " + time + "---------");
				var list = GetActivities (time);
				foreach (CsvReader.CsvRecord thing in list) {
					Console.WriteLine (thing);
				}
			}

		}

		public static void Main(string[] args) {
			
		}
	}
}
