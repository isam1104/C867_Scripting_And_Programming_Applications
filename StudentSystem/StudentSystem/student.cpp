#include <utility>

#include "Student.h"


Student::Student(string student_id, string first_name, string last_name,
                 string email_address, int age, vector<int> days_to_completion, DegreeProgram degree_program) :
        student_id(std::move(student_id)), first_name(std::move(first_name)), last_name(std::move(last_name)),
        email_address(std::move(email_address)), age(age),
        days_to_completion(std::move(days_to_completion)), degree_program(degree_program) {}

string Student::print() {
    // include  the course name in the count
    string days_to_completion_str = " { ";
    for (int i = 0; i < days_to_completion.size() - 1; i++) {
        auto index_str = std::to_string(days_to_completion[i]);
        days_to_completion_str += index_str + " , ";
    }
    days_to_completion_str += std::to_string(days_to_completion[days_to_completion.size() - 1]) + "}";

    return
            student_id +
            "\tFirst Name: " + first_name +
            "\tLast Name: " + last_name +
            "\tEmail Address: " + email_address +
            "\tAge: " + std::to_string(age) +
            "\tDays to completion: " + days_to_completion_str +
            "\tDegree Program: " + degree::to_string(degree_program) +
            "\n";
}