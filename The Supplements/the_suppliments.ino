
#include <ArduinoUnit.h>
// the setup routine runs once when you press reset:
bool is_a_leap_year(int year)
{
  return (year % 4 == 0) and (year % 100 != 0);
}

test(a_typical_common_year_return_false)
{
  assertFalse(is_a_leap_year(2001));
}

test(a_typical_leap_year_return_true)
{
  assertTrue(is_a_leap_year(1996));
}

test(is_an_atypical_common_year_return_true)
{
  assertFalse(is_a_leap_year(1900));
}

test(is_an_atypical_leap_year_return_false)
{
  assertFalse(is_a_leap_year(2000));
}
void setup() {
  // declare pin 9 to be an output:
  Serial.begin(115200);
  
  if (1 == 2) {
    Serial.write("1 is equal to 1\n\n");
  }

  else {
    Serial.write("Nope.\n\n");
  }
  

}


// the loop routine runs over and over again forever:
void loop() {
  Test::run();
  
}
