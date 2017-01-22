//
//  main.cpp
//  Assignment 4.1
//
//  Created by Aman Lohia on 2014-05-25.
//  Copyright (c) 2014 Aman Lohia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("/Users/amanlohia/Desktop/Assignment 4/Assignment 4.1/Assignment 4.1/taxiDir.txt");
    char di1, di2;
    double x1, x2, y1, y2, tripdist=0, totdist=0, tripcost, totcost;
    int i, noOfTrips=1;
    
    int noOfStops;
    if(!fin)
    {
        cout << "File Not Read";
        return -1;
    }
    ofstream fout("/Users/amanlohia/Desktop/Assignment 4/Assignment 4.1/Assignment 4.1/tabulated_results.txt");
    fout<<"# Stops"<<setw(18)<<"Distance"<<setw(19)<<"Cost"<<setw(24)<<"Total Dist"<<setw(22)<<"Total Cost"<<endl;
    fout<<fixed<<setprecision(2);
    
    while(fin>>noOfStops)
    {

        
        fin>>x1>>di1>>y1>>di2;
        
        if (di1=='W')
            x1=-x1;
        
        if (di2=='S')
            y1=-y1;
        
        tripdist+=sqrt(x1*x1+y1*y1);
        
        for (i=1;i<noOfStops;i++)
        {
            
            x2=x1;
            y2=y1;
            
            fin>>x1>>di1>>y1>>di2;
            
            if (di1=='W')
                x1=-x1;
        
            if (di2=='S')
                y1=-y1;
            
            tripdist+=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
            
                
            
        }
        
        tripdist+=sqrt(x1*x1+y1*y1);
    
        tripcost=tripdist*2.1+noOfStops*15;
        
        
        totdist+=tripdist;
        totcost+=tripcost;
        
        
        
        if (noOfTrips<4||noOfTrips%10==4) {
        
        fout<<noOfStops<<setw(22)<<tripdist<<setw(22)<<tripcost<<setw(22)<<totdist<<setw(21)<<totcost<<endl;
        }
        tripdist=0;
        tripcost=0;
        
        noOfTrips++;
        
        
    }
    
    fout<< "\n\nThe Total distance covered: "<<totdist<<"\nTotal money collected: "<<totcost<<endl;
    
    return 0;
}

