#include "Staff.hpp"

Staff::Staff(std::string p_name) : Person(p_name){};

Headmaster::Headmaster(std::string p_name) : Staff(p_name){};

Secretary::Secretary(std::string p_name) : Staff(p_name){};

Professor::Professor(std::string p_name) : Staff(p_name){};