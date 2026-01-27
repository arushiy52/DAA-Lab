// Given the following set of 16 points in a two-dimensional plane: [(9,3), (2,6), (15,3), (5,1), (1,2), (12,4), (7,2), (4,7), (16,5), (3,3), (10,5), (6,4), (14,6), (8,6), (11,1), (13,2)], find the
// closest pair of points and the minimum Euclidean distance between them using the Divide and Conquer approach

# include <iostream>
using namespace std;
# include <vector>



// CAlculate Euclidean Distance
double Distance(vector<int> p1, vector<int> p2) {
    return sqrt( (pow(p1[0] - p2[0] , 2)) +  (pow(p1[1] - p2[1] , 2)) );
}


// BRUTE FORCE Approach 1
// Time Complexity = O(n^2)
// Calculate distance betweeen all points and return minimum
// REturns the two points
pair<vector<int>, vector<int> > Minimum_Distance1(vector<vector<int> > pts) {
    double min_dist = INT_MAX;
    vector<int> min_p1, min_p2;
    int n = pts.size();

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            double dist = Distance(pts[i], pts[j]);

            if (dist<min_dist) {
                min_dist = dist;
                min_p1 = pts[i];
                min_p2 = pts[j];
            }
        }
    }


    pair<vector<int>, vector<int> > result(min_p1, min_p2);
    return result;
}




// Divide and Conquer Approach

bool CompareX(vector<int> p1, vector <int> p2) {
    return p1[0]<p2[0];
}

bool CompareY(vector<int> p1, vector <int> p2) {
    return p1[1]<p2[1];
}




// Finding MinDist in strip
double Strip_Min(vector<vector<int> > strip, double d) {
    double ds=d;
    sort(strip.begin(), strip.end(), CompareY);

    for (int i=0; i<strip.size(); i++) {
        for (int j=i+1; j<strip.size() && (strip[i][1]-strip[j][i])<=d; j++) {
            ds = min(ds, Distance(strip[i], strip[j]));
        }
    }

    return ds;

}




double MinDistRec(vector<vector <int> > pts, int l, int r) {
    // Base Case 
    if (r-l < 3) {
        // Two points
        if (r-l==2) return Distance(pts[l], pts[r-1]);
        return INT_MAX;
    }
    int mid = (l+r)/2;
    double midX = pts[mid][0];

    double dl = MinDistRec(pts, l, mid);
    double dr = MinDistRec(pts, mid, r);

    // Halves ka minimum
    double d = min(dl,dl);

    // Try the strip
    vector<vector<int> > strip;
    for (int i=l; i<r; i++) {
        if (abs(midX - pts[i][0]) < d) {
            strip.push_back(pts[i]);
        }
    }

    double ds = Strip_Min(strip,d);
    d = min(d,ds);

    return d;
}





double Minimum_Distance2(vector<vector<int> > pts) {
    
    // Sort wrt x values
    sort(pts.begin(), pts.end(), CompareX);
    return MinDistRec(pts, 0, pts.size());
}








int main()
{
    int arr[][2] = {{9,3}, {2,6}, {15,3}, {5,1}, {1,2}, {12,4}, {7,2}, {4,7},{16,5}, {3,3}, {10,5}, {6,4}, {14,6}, {8,6}, {11,1}, {13,2}};
    int len = 16;
    
    vector<vector<int> > points;
    
    // Convert array to vector
    for (int i = 0; i < len; i++) {
        vector<int> temp;
        temp.push_back(arr[i][0]);
        temp.push_back(arr[i][1]);
        points.push_back(temp);
    }
    
    // for (int i = 0; i < points.size(); i++) {
    //     cout << "(" << points[i][0] << ", " << points[i][1] << ")" << endl;
    // }


    pair<vector<int>, vector<int> > result = Minimum_Distance1(points);
    vector<int> p1 = result.first;
    vector<int> p2 = result.second;
    cout << "Points : " ;
    cout << "(" << p1[0] << ", " << p1[1] << ")" << " & (" << p2[0] << ", " << p2[1] << ")" << endl;
    

    cout << "Minimum Distance = " << Distance(p1,p2) << endl;

    cout << Minimum_Distance2(points);
    
}