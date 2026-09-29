#include <iostream>
#include "clsDate.h" 

using namespace std;

int main() {
    // 1. اختبار الـ Constructors المختلفة
    cout << "\n================ [1. Constructors & Basic Print] ================\n";
    clsDate Date1; // تاريخ اليوم الحالي
    cout << "Date1 (Default - Today): ";
    Date1.Print();

    clsDate Date2(15, 8, 2024); // تاريخ محدد
    cout << "Date2 (Parameterized): ";
    Date2.Print();

    clsDate Date3("31/12/2023"); // من نص (String)
    cout << "Date3 (From String): ";
    Date3.Print();

    clsDate Date4(60, 2024); // ترتيب اليوم في السنة (اليوم الـ 60 في سنة 2024)
    cout << "Date4 (From Day Order in Year): ";
    Date4.Print();

    // 2. اختبار الـ Properties والـ Getters/Setters
    cout << "\n================ [2. Properties & Getters/Setters] ================\n";
    Date1.Year = 2026;
    Date1.Month = 5;
    Date1.Day = 10;
    cout << "Updated Date1 using properties: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    // 3. اختبار معلومات السنة والشهر (ثابتة وعادية)
    cout << "\n================ [3. Year & Month Info] ================\n";
    cout << "Is 2024 a leap year? " << (clsDate::IsLeapYear(2024) ? "Yes" : "No") << endl;
    cout << "Total days in Year 2024: " << Date2.GetTotalDaysInYear() << endl;
    cout << "Total hours in Year 2024: " << Date2.GetTotalHoursInYear() << endl;
    cout << "Total minutes in Year 2024: " << Date2.GetTotalMinutesInYear() << endl;
    cout << "Total seconds in Year 2024: " << Date2.GetTotalSecondsInYear() << endl;

    cout << "Total days in Month 2 (Feb, 2024): " << clsDate::GetTotalDaysInMonth(2024, 2) << endl;
    cout << "Total hours in current Month: " << Date2.GetTotalHoursInMonth() << endl;
    cout << "Total minutes in current Month: " << Date2.GetTotalMinutesInMonth() << endl;
    cout << "Total seconds in current Month: " << Date2.GetTotalSecondsInMonth() << endl;

    // 4. اختبار أيام الأسبوع والأشهر
    cout << "\n================ [4. Weekdays & Month Names] ================\n";
    short dayOrder = Date2.GetDayOfWeekOrder();
    cout << "Day of week order for Date2: " << dayOrder << endl;
    cout << "Day of week order (Static version 2): " << clsDate::GetDayOfWeekOrder2(Date2) << endl;
    cout << "Week day name: " << clsDate::GetWeekDayName(dayOrder) << endl;
    cout << "Month short name: " << Date2.GetMonthShortName() << endl;

    // 5. طباعة التقويم (Calendar)
    cout << "\n================ [5. Calendars] ================\n";
    cout << "Printing Month Calendar (August 2024):\n";
    clsDate::PrintMonthCalendar(8, 2024);

    cout << "\nPrinting Year Calendar (2024 - first month snippet or full):\n";
     Date2.PrintYearCalendar(2024); 

    // 6. التحقق من صحة التواريخ ونهايات الشهور والأسبوع
    cout << "\n================ [6. Validation & Status Checks] ================\n";
    cout << "Is Date2 valid? " << (Date2.IsValid() ? "Yes" : "No") << endl;
    cout << "Is Date2 last day in month? " << (Date2.IsLastDayInMonth() ? "Yes" : "No") << endl;
    cout << "Is Month 12 last month in year? " << (clsDate::IsLastMonthInYear(12) ? "Yes" : "No") << endl;
    cout << "Is Date2 end of week? " << (Date2.IsEndOfWeek() ? "Yes" : "No") << endl;
    cout << "Is Date2 weekend? " << (Date2.IsWeekEnd() ? "Yes" : "No") << endl;
    cout << "Is Date2 business day? " << (Date2.IsBusinessDay() ? "Yes" : "No") << endl;
    cout << "Days until end of week: " << Date2.GetDaysUntilEndOfWeek() << endl;
    cout << "Days until end of month: " << Date2.GetDaysUntilEndOfMonth() << endl;
    cout << "Days until end of year: " << Date2.GetDaysUntilEndOfYear() << endl;

    // 7. مقارنة التواريخ
    cout << "\n================ [7. Date Comparisons] ================\n";
    clsDate Date5(10, 1, 2023);
    clsDate Date6(15, 1, 2023);

    cout << "Is Date5 before Date6? " << (Date5.IsBefore(Date6) ? "Yes" : "No") << endl;
    cout << "Is Date5 equal to Date6? " << (Date5.IsEqual(Date6) ? "Yes" : "No") << endl;
    cout << "Is Date6 after Date5? " << (Date6.IsAfter(Date5) ? "Yes" : "No") << endl;

    clsDate::enDateCompare comparison = clsDate::CompareDates(Date5, Date6);
    cout << "Comparison result (-1: Before, 0: Equal, 1: After): " << comparison << endl;

    // 8. تعديل وزيادة التواريخ (Increase Methods)
    cout << "\n================ [8. Increase Date Methods] ================\n";
    clsDate TestDate(1, 1, 2024);
    cout << "Original TestDate: "; TestDate.Print();

    TestDate.IncreaseDateByOneDay();
    cout << "After +1 Day: "; TestDate.Print();

    TestDate.IncreaseDateByXDays(5);
    cout << "After +5 Days: "; TestDate.Print();

    TestDate.IncreaseDateByOneWeek();
    cout << "After +1 Week: "; TestDate.Print();

    TestDate.IncreaseDateByXWeeks(2);
    cout << "After +2 Weeks: "; TestDate.Print();

    TestDate.IncreaseDateByOneMonth();
    cout << "After +1 Month: "; TestDate.Print();

    TestDate.IncreaseDateByXMonths(3);
    cout << "After +3 Months: "; TestDate.Print();

    TestDate.IncreaseDateByOneYear();
    cout << "After +1 Year: "; TestDate.Print();

    TestDate.IncreaseDateByXYears(2);
    cout << "After +2 Years: "; TestDate.Print();

    TestDate.IncreaseDateByOneDecade();
    cout << "After +1 Decade: "; TestDate.Print();

    TestDate.IncreaseDateByXDecades(1);
    cout << "After +1 Decade (X): "; TestDate.Print();

    TestDate.IncreaseDateByOneCentury();
    cout << "After +1 Century: "; TestDate.Print();

    TestDate.IncreaseDateByXCenturies(1);
    cout << "After +1 Century (X): "; TestDate.Print();

    TestDate.IncreaseDateByOneMillennium();
    cout << "After +1 Millennium: "; TestDate.Print();

    // 9. حساب الفروقات والإجازات
    cout << "\n================ [9. Differences & Vacations] ================\n";
    clsDate StartDate(1, 1, 2024);
    clsDate EndDate(10, 1, 2024);

    cout << "Difference in days between StartDate and EndDate: "
        << StartDate.GetDiffInDaysBetWeenTwoDates(EndDate, true) << " days (including end day)\n";

    clsDate VacStart(1, 8, 2024);
    clsDate VacEnd(15, 8, 2024);
    cout << "Business vacation days between 1/8/2024 and 15/8/2024: "
        << VacStart.GetVacationDays(VacEnd) << endl;

    clsDate ReturnDate = VacStart.CalculateVacationReturnDate(10);
    cout << "Vacation return date after 10 business days starting 1/8/2024: ";
    ReturnDate.Print();

    // 10. تحويل ونصوص (String & Formatting)
    cout << "\n================ [10. String & Formatting] ================\n";
    string dateStr = Date2.DateToString();
    cout << "Date2 to string: " << dateStr << endl;

    cout << "Formatted Date (default): " << Date2.FormatDate() << endl;
    cout << "Formatted Date (yyyy/mm/dd): " << Date2.FormatDate("yyyy - mm - dd") << endl;

    return 0;
}