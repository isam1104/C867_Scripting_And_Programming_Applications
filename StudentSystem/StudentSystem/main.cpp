#include "roster.h"


std::string trim(std::string &str) {
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

int main() {
    const string studentData[] = {
            "A1, John, Smith, John1989@gmail.com, 20, 30, 35, 40,  SECURITY",
            "A2, Suzan, Erickson, Erickson_1990@gmail.com, 19, 50, 30, 40,  NETWORK",
            "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 40, 40, 33,  SOFTWARE",
            "A4, Erin, Black, Eric.black@comcast.com, 22, 50, 58, 40,  SECURITY",
            "A5, Isam, Elder, isam.elder@wgu.edu, 23, 50, 58, 40,  SOFTWARE"
    };

    Roster classRoster;
    for (const auto &line: studentData) {
        string student_id, first_name, last_name, email_address;
        int age, daysInCourse1, daysInCourse2, daysInCourse3;
        DegreeProgram degree_program;
        string degree_program_str;

        size_t comma1 = line.find(',');
        student_id = line.substr(0, comma1);
        size_t comma2 = line.find(',', comma1 + 1);
        first_name = line.substr(comma1 + 1, comma2 - comma1 - 1);
        size_t comma3 = line.find(',', comma2 + 1);
        last_name = line.substr(comma2 + 1, comma3 - comma2 - 1);
        size_t comma4 = line.find(',', comma3 + 1);
        email_address = line.substr(comma3 + 1, comma4 - comma3 - 1);
        // remove leading and trailing white spaces
        email_address = trim(email_address);
        size_t comma5 = line.find(',', comma4 + 1);
        stringstream age_stream(line.substr(comma4 + 1, comma5 - comma4 - 1));
        age_stream >> age;
        size_t comma6 = line.find(',', comma5 + 1);
        stringstream course1_stream(line.substr(comma5 + 1, comma6 - comma5 - 1));
        course1_stream >> daysInCourse1;
        size_t comma7 = line.find(',', comma6 + 1);
        stringstream course2_stream(line.substr(comma6 + 1, comma7 - comma6 - 1));
        course2_stream >> daysInCourse2;
        size_t comma8 = line.find(',', comma7 + 1);
        stringstream course3_stream(line.substr(comma7 + 1, comma8 - comma7 - 1));
        course3_stream >> daysInCourse3;
        degree_program_str = line.substr(comma8 + 1);

        degree_program_str = trim(degree_program_str);

        degree_program = degree::to_degree_program(degree_program_str.c_str());
        classRoster.add(
                student_id,
                first_name,
                last_name,
                email_address,
                age,
                daysInCourse1,
                daysInCourse2,
                daysInCourse3,
                degree_program);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    auto classRosterArray = classRoster.get_classRosterArray();
    for (const auto &student: classRosterArray) {
        auto current_student_id = student->get_student_id();
        classRoster.printAverageDaysInCourse(current_student_id);
    }

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}