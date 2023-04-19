#include "roster.h"

#include <utility>

void
Roster::add(string student_id, string first_name, string last_name, string email_address, int age, int daysInCourse1,
            int daysInCourse2, int daysInCourse3, DegreeProgram degree_program) {
    auto *student = new Student(
            std::move(student_id),
            std::move(first_name),
            std::move(last_name),
            std::move(email_address),
            age,
            {daysInCourse1, daysInCourse2, daysInCourse3},
            degree_program
    );
    classRosterArray.emplace_back(student);
}


void Roster::remove(const string &student_id) {
    std::vector<Student *> temp_classRosterArray;
    for (const auto &student: classRosterArray) {
        if (student->get_student_id() != student_id) {
            temp_classRosterArray.emplace_back(student);
        }
    }
    if (temp_classRosterArray.size() == classRosterArray.size()) {
        std::cerr << "Error: invalid student id: " << student_id << std::endl;
    } else {
        classRosterArray.clear();
        classRosterArray = temp_classRosterArray;// clear and replace with new array
    }
}

void Roster::printAll() {
    for (const auto &student: classRosterArray) {
        std::cout << student->print() << std::endl;
    }
}

void Roster::printAverageDaysInCourse(const string &student_id) {
    for (const auto &student: classRosterArray) {
        auto id = student->get_student_id();
        if (id == student_id) {
            cout << id << ": ";
            auto sum = 0;
            auto days_to_completion = student->get_days_to_completion();
            for (const auto &day_to_completions: days_to_completion) {
                sum += day_to_completions;
            }
            auto avg = sum / student->get_days_to_completion().size();
            std::cout << "Average Days to completion: " << avg << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (const auto student: classRosterArray) {
        auto student_email = student->get_email_address();
        if (student_email.find('@') == string::npos ||
            student_email.find('.') == string::npos ||
            student_email.find(' ') != string::npos) {
            std::cout << student->get_student_id() << " : " << student->get_email_address() << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degree_program) {
    for (const auto student: classRosterArray) {
        if (student->get_degree_program() == degree_program) {
            std::cout << student->print() << std::endl;
        }
    }
}