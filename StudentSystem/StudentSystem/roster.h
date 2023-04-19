#pragma once

#include "student.h"

class Roster {
public:
    Roster() = default;

    ~Roster() = default;

    void add(string student_id, string first_name, string last_name, string email_address, int age, int daysInCourse1,
             int daysInCourse2, int daysInCourse3, DegreeProgram degree_program);

    void remove(const string &student_id);

    void printAll();

    void printAverageDaysInCourse(const string &student_id);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degree_program);

    auto get_classRosterArray() { return classRosterArray; }

private:
    std::vector<Student *> classRosterArray;
};