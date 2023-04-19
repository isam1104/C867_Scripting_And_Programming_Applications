#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include "degree.h"

using namespace std;

class Student {
public:
    Student(string student_id, string first_name, string last_name, string email_address, int age,
            vector<int> days_to_completion, DegreeProgram degree_program);

    string print();

    // getters for class attributes
    auto get_student_id() { return student_id; }

    auto get_first_name() { return first_name; }

    auto get_last_name() { return last_name; }

    auto get_email_address() { return email_address; }

    auto get_age() { return age; }

    auto get_days_to_completion() { return days_to_completion; }

    auto get_degree_program() { return degree_program; }

    // setters for class variables
    void set_student_id(string student_id_) { this->student_id = std::move(student_id_); }

    void set_first_name(string first_name) { this->first_name = std::move(first_name); }

    void set_last_name(string last_name) { this->last_name = std::move(last_name); }

    void set_email_address(string email_address) { this->email_address = std::move(email_address); }

    void set_age(unsigned int age) { this->age = age; }

    void set_days_to_completion(int day_to_completion) { days_to_completion.emplace_back(day_to_completion); }

    void set_degree_program(DegreeProgram degree_program) { this->degree_program = degree_program; }

    ~Student() = default;

private:
    string student_id;
    string first_name;
    string last_name;
    string email_address;
    int age;
    std::vector<int> days_to_completion{};
    DegreeProgram degree_program;
};