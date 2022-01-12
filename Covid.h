//
// Created by Meghadharsan on 13-01-2022.
//

#ifndef COVID_MANAGEMENT_COVID_H
#define COVID_MANAGEMENT_COVID_H
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class Covid {
private:
    bool status;
    int severity;
    string symptoms[3];
public:
    Covid()
    {
        this->status = false;
        this ->severity =0;
    }
    Covid(bool status, int severity){
        this->status=status;
        this->severity= severity;
    }


};




#endif //COVID_MANAGEMENT_COVID_H
