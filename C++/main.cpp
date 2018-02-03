//Preston Peck
//CS 323
//October 29, 2016
//Project 4

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

class Point {
    private:
	    int X;
	    int Y;
	    int cluster;
	    double distance;
	    bool changeLabel;
    public:
        Point();
        void printPoint(ofstream& outFile);

    friend class Kmean;
};

struct xyCoord {
    private:
	    int X = 0;
	    int Y = 0;
	    int count = 0;

    public:
        xyCoord();

    friend class Kmean;
};

class Kmean {
    private:
	    int K;
	    xyCoord** Kcentroids;
	    int numPts;
	    Point** pointSet;
	    int numRow;
	    int numCol;
	    int** imageArray;

    public:
        Kmean();
        void loadPointSet(ifstream& inFile);
        void assignLabel();
        void mapPoint2Image();
        void kMeanClustering(ifstream& inFile, ofstream& outFile1, ofstream& outFile2);
        double dist(Point* p, xyCoord* k);
        void printPointSet(ofstream& outFile);
        void displayImage(ofstream& outFile);
};

int main(int argc, char *argv[]) {
    ifstream inFile;
	ofstream outFile1;
    ofstream outFile2;
    inFile.open(argv[1]);
        if (!inFile.is_open()) {
        cerr<<"File failed to open!"<<endl;
        return 0;
    }
    outFile1.open(argv[2]);
    outFile2.open(argv[3]);

    Kmean* k = new Kmean();
    k->kMeanClustering(inFile, outFile1, outFile2);

    inFile.close();
    outFile1.close();
    outFile2.close();
}



Point::Point() {
	X = 0;
	Y = 0;
	cluster = 0;
	distance = 0;
}
		
void Point::printPoint(ofstream& outFile) {
	outFile << X << " " << Y << " " << cluster;
}



xyCoord::xyCoord() {
    X = 0;
	Y = 0;
	count = 0;
}



Kmean::Kmean() {
	K = 0;
	Kcentroids = new xyCoord*[K];
    for (int i = 0; i < K; i++) {
        Kcentroids[i] = new xyCoord();
    }
	numPts = 0;
	pointSet = new Point*[numPts];
    for (int i = 0; i < numPts; i++) {
        pointSet[i] = new Point();
    }
	numRow = 0;
	numCol = 0;
	imageArray = new int*[numRow];
    for (int i = 0; i < numRow; i++) {
        imageArray[i] = new int[numCol];
    }
}

void Kmean::loadPointSet(ifstream& inFile) {
	for (int i = 0; i < numPts; i++) {
		inFile >> pointSet[i]->X;
		inFile >> pointSet[i]->Y;
	}
}

void Kmean::assignLabel() {
	int counter = 1;
	
	for (int i = 0; i < numPts; i++) {
		pointSet[i]->cluster = counter;
		counter++;
		
		if (counter > K) {
			counter = 1;
		}
	}
}

void Kmean::mapPoint2Image() {
	for (int i = 0; i < numPts; i++) {
		imageArray[pointSet[i]->X][pointSet[i]->Y] = pointSet[i]->cluster;
	}
}

void Kmean::kMeanClustering(ifstream& inFile, ofstream& outFile1, ofstream& outFile2) {
	inFile >> K;
	inFile >> numPts;
	inFile >> numRow;
	inFile >> numCol;
	
	pointSet = new Point*[numPts];
	for (int i = 0; i < numPts; i++) {
		pointSet[i] = new Point();
	}
	
    imageArray = new int*[numRow];
    for (int i = 0; i < numRow; i++) {
        imageArray[i] = new int[numCol];
    }
	
	loadPointSet(inFile);
	assignLabel();
	
	bool labelChange;
	
	do {
		labelChange = false;
		mapPoint2Image();
		displayImage(outFile2);
		
		Kcentroids = new xyCoord*[K];
		for (int i = 0; i < K; i++) {
			Kcentroids[i] = new xyCoord();
		}
		
		for (int i = 0; i < numPts; i++) {
			Kcentroids[pointSet[i]->cluster - 1]->X += pointSet[i]->X;
			Kcentroids[pointSet[i]->cluster - 1]->Y += pointSet[i]->Y;
			Kcentroids[pointSet[i]->cluster - 1]->count++;
		}
	
		for (int i = 0; i < K; i++) {
			Kcentroids[i]->X = Kcentroids[i]->X / Kcentroids[i]->count;
			Kcentroids[i]->Y = Kcentroids[i]->Y / Kcentroids[i]->count;
		}
	
		for (int i = 0; i < numPts; i++) {
			int label = 0;
			double min_i = 0;
			
			for (int j = 0; j < K; j++) {
				if (min_i == 0) {//if never initialized, can't compare
					min_i = dist(pointSet[i], Kcentroids[j]);
					label = j + 1;
				}
			
				else if (dist(pointSet[i], Kcentroids[j]) < min_i) {
					min_i = dist(pointSet[i], Kcentroids[j]);
					label = j + 1;
				}
			}
			
			if (label != pointSet[i]->cluster) {
				pointSet[i]->cluster = label;
				labelChange = true;
			}
		}
	} while (labelChange == true);
	
	printPointSet(outFile1);
}

double Kmean::dist(Point* p, xyCoord* k) {
	return pow((pow(((double) (p->X - k->X)), 2.0) 
			 + (pow(((double) (p->Y - k->Y)), 2.0))), 0.5);
}

void Kmean::printPointSet(ofstream& outFile) {
	for (int i = 0; i < numPts; i++) {
		pointSet[i]->printPoint(outFile);
        outFile << endl;
	}
}
	
void Kmean::displayImage(ofstream& outFile) {//direct translation
	for (int i = 0; i < numRow; i++) {
		for (int j = 0; j < numCol; j++) {
			if (imageArray[i][j] == 0) {
				outFile << " ";
			}
			else {
				outFile << (imageArray[i][j]);
			}
		}
		outFile << endl;
	}
	outFile << endl;
}