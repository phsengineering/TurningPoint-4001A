#include "main.h"
#include "subsystems.hpp"
void on_center_button() {
	if(auton > 5) {
		auton = 0;
	}
	else {
		auton++;
	}


	if (auton == 1) {
		pros::lcd::set_text(2, "Blue autonomous");
	}
	else if (auton == 2) {
		pros::lcd::set_text(2, "Back autonomous");
	}
	else if (auton == 3) {
		pros::lcd::set_text(2, "Red Low flag autonomous");
	}
	else if(auton == 4) {
		pros::lcd::set_text(2, "Blue Low flag autonomous");
	}
	else if(auton == 5) {
		pros::lcd::set_text(2, "Programming skills");
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	auton = 0;
	pros::lcd::set_text(2, "Red autonomous");
	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
