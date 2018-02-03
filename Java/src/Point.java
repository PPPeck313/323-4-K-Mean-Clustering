public class Point {
	int X;
	int Y;
	int cluster;
	double distance;
	boolean changeLabel;
	
	Point() {
		X = 0;
		Y = 0;
		cluster = 0;
		distance = 0;
	}
		
	String printPoint() {
		return Integer.toString(X) + " " 
				+ Integer.toString(Y) + " " 
				+ Integer.toString(cluster);
	}
}
