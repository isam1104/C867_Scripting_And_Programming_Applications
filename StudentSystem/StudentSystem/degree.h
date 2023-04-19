#pragma once

#include  <cstring>

enum DegreeProgram {
    SECURITY,
    NETWORK,
    SOFTWARE
};

namespace degree {
    inline const char *to_string(DegreeProgram degree_program) {
        switch (degree_program) {
            case SECURITY:
                return "SECURITY";
            case NETWORK:
                return "NETWORK";
            case SOFTWARE:
                return "SOFTWARE";
        }
    }

    inline DegreeProgram to_degree_program(const char *degree_program) {
        if (!strcmp(to_string(SECURITY), degree_program)) {
            return SECURITY;
        } else if (!strcmp(to_string(NETWORK), degree_program)) {
            return NETWORK;
        } else {
            return SOFTWARE;
        }
    }
}
