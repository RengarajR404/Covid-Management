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
    bool status = true;
    int severity;
    double symptom_score[3];
    double symptom_avg =0.0;
    string symptoms[3]={"Fever","Breathing","Cold"};


public:
    Covid()
    {
        this->status = false;
        this ->severity =0;
    }

    Covid(bool status, double a[]){
        this->status=status;
        for(auto i=0 ;i<3;i++)
        {
            symptom_score[i]=a[i]  ;
        }
    }

    bool isStatus() const {
        return status;
    }

    void setStatus(bool status) {
        Covid::status = status;
    }

    int getSeverity() {
        return severity;
    }

    void setSeverity(int severity) {
        Covid::severity = severity;
    }

    double getSymptomScore()  {
        return *symptom_score;
    }

    void setsymp(double a[])
    {
        for(int i=0 ;i<3;i++)
        {
            symptom_score[i]=a[i];
        }
    }
    string getSymptoms() {
        return *symptoms;
    }

    void calcavg()
    {
        for( auto i=0; i<3; i++  )
        {
            symptom_avg=symptom_avg+symptom_score[i];
        }
        symptom_avg=(symptom_avg)/3;

    }
    double getSymptomavg()
    {
        return this ->symptom_avg;
    }

    void findSeverity(){
        if (this->symptom_avg < 5) {
            setSeverity(0);
        } else {
            if (symptom_avg >= 5 || symptom_avg < 10) {
                setSeverity(1);
            } else if (symptom_avg >= 10) {
                setSeverity(2);
            }
        }
    }

};




#endif //COVID_MANAGEMENT_COVID_H
