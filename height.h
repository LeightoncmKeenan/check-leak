// Copyright 2026 lkeenan
#ifndef _USERS_LEIGHTONKEENAN_ADVANCED_PROGRAM_HEIGHT_H_
#define _USERS_LEIGHTONKEENAN_ADVANCED_PROGRAM_HEIGHT_H_
#include<string>
using std::string;
#include<iostream>
using std::ostream;
// Define a Height class that has private integer data members for the
class Height {
 private:
  double value;
  string units;
  // Add a constructor to allow the user to initialize the value and units, in
  // that order, with default arguments of 0 and "feet"
 public:
  explicit Height(double v = 0, string units = "feet");
  // Add mutator functions SetValue, and SetUnits that set the data member if
  // the argument is valid, and leave the data member unchanged if the argument
  // is invalid.
  void SetValue(double v);
  void SetUnits(string u);
  // Add accessor functions GetValue and GetUnits that return
  // a copy of the value of the corresponding data member.
  double GetValue() const;
  string GetUnits() const;
  // Add a ConvertUnits function that takes a string parameter for units to
  // convert the Height to. If the argument is valid, the object's value and
  // units should be updated to the equivalent height in the new units. For
  // example, if the Height object h has a value of 2 and units of "feet"
  // then after the function call h.ConvertUnits("inches"); h should have a
  // value of 24 and units of "inches"
  // If the argument sent to the function is not "feet" "inches" "meters"
  // or "centimeters" then the function should leave the object unchanged.
  // Please see testheight2.cc for more examples.
  void ConvertUnits(string newUnits);
  bool operator<=(const Height& other) const;
};
// overload the stream insertion operator to display the height range in the
// format smallest height - largest height
ostream& operator<<(ostream& os, const Height& h);
#endif  // _USERS_LEIGHTONKEENAN_ADVANCED_PROGRAM_HEIGHT_H_
