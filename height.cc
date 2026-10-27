// Copyright 2026 lkeenan
#include<string>
#include"height.h"
// height value - a non-negative real number (a double)
// height units - allow for feet, inches, meters, and
// centimeters only (a string)
// The class should ensure that the data members always remain
// in a consistent state.
// -------- INITIALIZATION -----------
// If the first argument value is invalid, the height value should be
// initialized to 0. If the second argument is invalid, the height units
// should be initialized to feet.
Height::Height(double v, string u) {
// validating height values
  if (v >= 0) {
    value = v;
  } else {
    value = 0;
  }
  if (u == "feet" || u == "centimeters" ||
      u == "inches" || u == "meters") {
    units = u;
  } else {
    units = "feet";
  }
}
// ------- GETTERS ---------
// Add accessor functions GetValue and GetUnits that return
// a copy of the value of the corresponding data member.
double Height::GetValue() const {
  return value;
}
string Height::GetUnits() const {
  return units;
}
// -------- SETTERS -----------
// Add mutator functions SetValue, and SetUnits that
// set the data member if the argument is valid,
// and leave the data member unchanged if the argument
// is invalid.
void Height::SetValue(double v) {
  if (v >= 0) {
    value = v;
  }
}
void Height::SetUnits(string u) {
  if (u == "feet" || u == "centimeters" ||
      u == "inches" || u == "meters") {
    units = u;
  }
}
// If the argument is valid, the object's value and
// units should be updated to the equivalent height in the new units. For
// example, if the Height object h has a value of 2 and units of "feet"
// then after the function call h.ConvertUnits("inches"); h should have a
// value of 24 and units of "inches"
// If the argument sent to the function is not "feet" "inches" "meters"
// or "centimeters" then the function should leave the object unchanged.
void Height::ConvertUnits(string newUnits) {
  if (newUnits != "feet" && newUnits != "centimeters" &&
      newUnits != "meters" && newUnits != "inches") {
  return;
  }
  double meters;
  // converting current value to meters
  if (units == "feet") {
    meters = value * 0.3048;
  } else if (units == "inches") {
    meters = value * 0.0254;
  } else if (units == "centimeters") {
    meters = value / 100.0;
  } else {
    meters = value;
  }
  // Convert meters to the requested units
  if (newUnits == "feet") {
    value = meters / 0.3048;
  } else if (newUnits == "inches") {
    value = meters / 0.0254;
  } else if (newUnits == "centimeters") {
    value = meters * 100.0;
  } else {
    value = meters;
  }
  units = newUnits;
}
bool Height::operator<=(const Height& other) const {
  double h1;
  double h2;
  // Convert this height to inches.
  if (units == "feet") {
    h1 = value * 12.0;
  } else if (units == "meters") {
    h1 = value * 100.0 / 2.54;
  } else if (units == "centimeters") {
    h1 = value / 2.54;
  } else {
    h1 = value;
  }
  // Convert the other height to inches.
  if (other.units == "feet") {
    h2 = other.value * 12.0;
  } else if (other.units == "meters") {
    h2 = other.value * 100.0 / 2.54;
  } else if (other.units == "centimeters") {
    h2 = other.value / 2.54;
  } else {
    h2 = other.value;
  }
  return h1 <= h2;
}
// Overloaded stream insertion operator to output
// a height's value and units
ostream& operator<<(ostream& os, const Height& h) {
  os << h.GetValue() << " " << h.GetUnits();
  return os;
}
