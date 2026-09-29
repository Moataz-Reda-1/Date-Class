# clsDate

A C++ date utility class built with Object-Oriented Programming (OOP) principles.

> **Note:** This is one of my **first projects using OOP**. I built it while learning the core concepts (classes, encapsulation, static and non-static members, overloading, properties), so feedback and suggestions are very welcome.

## Features

**Creating dates**
- Today's date (default constructor)
- Day, month, and year
- From a string such as `"31/12/2023"`
- From the day number in a year (for example, day 60 of 2024)

**Year and month information**
- Leap year check
- Total days, hours, minutes, and seconds in a year
- Total days, hours, minutes, and seconds in a month

**Weekdays and names**
- Day of the week order and name
- Month short name
- Print a month calendar or a full year calendar

**Validation and checks**
- Is the date valid
- Is it the last day of the month / the last month of the year
- Is it the end of the week, a weekend, or a business day
- Days until the end of the week, month, and year

**Comparison**
- Is before, is equal, is after
- `CompareDates` (returns Before, Equal, or After)

**Adding time**
- Days, weeks, months, years
- Decades, centuries, millennium

**Calculations**
- Difference in days between two dates
- Vacation days between two dates (business days only)
- Vacation return date after a number of business days

**Formatting**
- Convert to string
- Custom format such as `dd/mm/yyyy` or `yyyy-mm-dd`

## OOP concepts used

- **Encapsulation:** day, month, and year are private members accessed through properties.
- **Static and non-static versions:** every function can be called on the class (`clsDate::IsLeapYear(2024)`) or on an object (`Date.IsValid()`).
- **Function overloading:** the same function name is used for the static and the object versions.
- **Multiple constructors:** four different ways to create a date.
- **Enumeration:** `enDateCompare` for comparison results.

## Usage

```cpp
#include <iostream>
#include "clsDate.h"
using namespace std;

int main()
{
    clsDate Date(15, 8, 2024);
    Date.Print();                                   // 15/8/2024

    Date.IncreaseDateByXDays(20);
    Date.Print();                                   // 4/9/2024

    cout << Date.FormatDate("yyyy - mm - dd") << endl;

    cout << clsDate::IsLeapYear(2024) << endl;      // 1

    clsDate Start(1, 8, 2024);
    cout << Start.GetVacationDays(clsDate(15, 8, 2024)) << endl;

    clsDate::PrintMonthCalendar(8, 2024);

    return 0;
}
```

## Project structure

```
clsDate/
├── clsDate.h      # the class
├── main.cpp       # a test program that uses every section of the class
└── README.md
```

## Requirements

- Visual Studio (the class uses `__declspec(property)`, which is a Microsoft extension)
- C++11 or later

## Notes

- The week starts on **Sunday** (order 0).
- The weekend is **Friday and Saturday**.
- The vacation calculation counts business days only and does not include the end date.

## How to run

1. Clone the repository.
2. Open the files in a Visual Studio C++ project.
3. Build and run `main.cpp`.

## What I learned

- Designing a class with private data and public methods
- Providing both static and instance versions of the same functionality
- Working with dates, leap years, and calendars
- Testing a library through a separate `main` file

## Future improvements

- Pass objects and strings by `const` reference
- Validate the date inside the constructors
- Handle invalid strings in `StringToDate`
- Make the code portable to GCC and Clang by replacing `__declspec(property)` with plain getters and setters

## License

Free to use for learning purposes.
