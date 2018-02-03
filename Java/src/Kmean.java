import java.util.Scanner;
import java.io.PrintWriter;
import static java.lang.Math.pow;

public class Kmean {
	int K;
	
	class xyCoord {
		int X;
		int Y;
		int count;
		
		xyCoord() {
			X = 0;
			Y = 0;
			count = 0;
		}
	}

	xyCoord Kcentroids[];
	int numPts;
	Point pointSet[];
	int numRow;
	int numCol;
	int imageArray[][];

	Kmean() {
		K = 0;
		Kcentroids = new xyCoord[K];
		numPts = 0;
		pointSet = new Point[numPts];
		numRow = 0;
		numCol = 0;
		imageArray = new int[numRow][numCol];
	}
	
	void loadPointSet(Scanner inFile) {
		for (int i = 0; i < pointSet.length; i++) {
			pointSet[i].X = inFile.nextInt();
			pointSet[i].Y = inFile.nextInt();
		}
	}

	void assignLabel() {
		int counter = 1;
		
		for (int i = 0; i < pointSet.length; i++) {
			pointSet[i].cluster = counter;
			counter++;
			
			if (counter > K) {
				counter = 1;
			}
		}
	}

	void mapPoint2Image() {
		for (int i = 0; i < pointSet.length; i++) {
			imageArray[pointSet[i].X][pointSet[i].Y] = pointSet[i].cluster;
		}
	}

	void kMeanClustering(Scanner inFile, PrintWriter outFile1, PrintWriter outFile2) {
		K = inFile.nextInt();
		numPts = inFile.nextInt();
		numRow = inFile.nextInt();
		numCol = inFile.nextInt();
		
		pointSet = new Point[numPts];
		for (int i = 0; i < pointSet.length; i++) {
			pointSet[i] = new Point();
		}
		
		imageArray = new int[numRow][numCol];
		
		loadPointSet(inFile);
		assignLabel();
		
		boolean labelChange;
		
		do {//don't forget to zero everything!!!
			labelChange = false;
			mapPoint2Image();
			displayImage(outFile2);
			
			Kcentroids = new xyCoord[K];
			for (int i = 0; i < Kcentroids.length; i++) {
				Kcentroids[i] = new xyCoord();
			}
			
			for (int i = 0; i < pointSet.length; i++) {
				Kcentroids[pointSet[i].cluster - 1].X += pointSet[i].X;
				Kcentroids[pointSet[i].cluster - 1].Y += pointSet[i].Y;
				Kcentroids[pointSet[i].cluster - 1].count++;
			}
		
			for (int i = 0; i < Kcentroids.length; i++) {
				Kcentroids[i].X = Kcentroids[i].X / Kcentroids[i].count;
				Kcentroids[i].Y = Kcentroids[i].Y / Kcentroids[i].count;
			}
		
			for (int i = 0; i < pointSet.length; i++) {
				int label = 0;
				double min_i = 0;
				
				for (int j = 0; j < Kcentroids.length; j++) {
					if (min_i == 0) {//if never initialized, can't compare
						min_i = dist(pointSet[i], Kcentroids[j]);
						label = j + 1;
					}
				
					else if (dist(pointSet[i], Kcentroids[j]) < min_i) {
						min_i = dist(pointSet[i], Kcentroids[j]);
						label = j + 1;
					}
				}
				
				if (label != pointSet[i].cluster) {
					pointSet[i].cluster = label;
					labelChange = true;
				}
			}
		} while (labelChange == true);
		
		printPointSet(outFile1);
	}
	
	double dist(Point p, xyCoord k) {
		return pow((pow(((double) (p.X - k.X)), 2.0) 
				 + (pow(((double) (p.Y - k.Y)), 2.0))), 0.5);
	}
	
	void printPointSet(PrintWriter outFile) {
		for (int i = 0; i < pointSet.length; i++) {
			outFile.println(pointSet[i].printPoint());
		}
	}
		
	void displayImage(PrintWriter outFile) {//direct translation
		for (int i = 0; i < imageArray.length; i++) {
			for (int j = 0; j < imageArray[i].length; j++) {
				if (imageArray[i][j] == 0) {
					outFile.print(" ");
				}
				else {
					outFile.print(imageArray[i][j]);
				}
			}
			outFile.println();
		}
		outFile.println();
	}
}
