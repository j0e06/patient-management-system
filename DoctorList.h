// #ifndef DOCTORQUEUE_H
// #define DOCTORQUEUE_H

// #include <bits/stdc++.h>
// #include "Patient.h"
// #include "Doctor.h"
// using namespace std;

// class Node
// {
// private:
//     Doctor doctor;
//     Node *next;

// public:
//     QueueNode() {}
//     QueueNode(Doctor &d) : doctor(d), next(NULL) {}
// };

// class DoctorList
// {
// private:
//     Node *head;
//     Node *tail;
//     // add doctor count method to know the size
//     int size;

//     public:

// }



#include "ListNode.h"
// #include "PatientQueue.h"

#ifndef DOCTORLIST_H
#define DOCTORLIST_H


class DoctorList
{
private:
    ListNode* head;
    ListNode* tail;
    int DoctorsCount; //number of doctors

public:
    DoctorList() : head(nullptr), tail(nullptr), DoctorsCount(0) {}
    ~DoctorList()
    {
        clear();
    }

    void addDoctor(const Doctor& doctor)
    {
        ListNode* newNode = new ListNode(doctor);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        DoctorsCount++;
    }

    PatientQueue SearchById( int DoctorId ) // This function returns the queue of the doctor.
    {
        ListNode *Start = head ;
        while ( Start != nullptr )
        {
            if ( Start->doctor.getId() == DoctorId )
            {
                return Start->Patients ;
            }
            Start = Start->next ;
        }
        cout << "Doctor Id not found!\n" ;
        PatientQueue Null ;
        return Null ;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    int count() const
    {
        return DoctorsCount;
    }

    void clear()
    {
        while (head != nullptr)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        DoctorsCount = 0;
    }


};

#endif
