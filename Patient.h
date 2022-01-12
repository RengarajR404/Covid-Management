//
// Created by Meghadharsan on 13-01-2022.
//

#ifndef COVID_MANAGEMENT_PATIENT_H
#define COVID_MANAGEMENT_PATIENT_H
#include<string.h>
#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include"Covid.h"

using namespace std;

class Patient {
private:
    std::string pname;
    Covid covid;
public:
    Patient(string pname, Covid covid){
        this->pname = pname;
        this->covid = covid;
    }
    Patient()
    {

    }

    string getPname() const {
        return pname;
    }

    void setPname(string pname) {
        Patient::pname = pname;
    }



};


#endif //COVID_MANAGEMENT_PATIENT_H
