#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

void default_auto();
void skills_auto();
void match_auto();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();