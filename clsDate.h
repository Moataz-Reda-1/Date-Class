#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class clsDate
{
private:
	short _Year;
    short _Month;
    short _Day;

public:

    void SetYear(short Year)
    {
        _Year = Year;
    }
    short GetYear()
    {
        return _Year;
    }
    __declspec(property(get = GetYear, put = SetYear)) short Year;


    void SetMonth(short Month)
    {
        _Month = Month;
    }
    short GetMonth()
    {
        return _Month;
    }
    __declspec(property(get = GetMonth, put = SetMonth)) short Month;
    void SetDay(short Day)
    {
        _Day = Day;
    }
    short GetDay()
    {
        return _Day;
    }
    __declspec(property(get = GetDay, put = SetDay)) short Day;

    clsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Year = now->tm_year + 1900;
        _Month = now->tm_mon + 1;
        _Day = now->tm_mday;
    }

    clsDate(short Day, short Month, short Year)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(string Date)
    {
        *this = StringToDate(Date);
    }

    clsDate(short NumberOfDays, short Year)
    {
        *this = GetDateFromDayOrderInYear(NumberOfDays, Year);
    }

    void Print()
    {
        cout << _Day << "/" << _Month << "/" << _Year << endl;
    }


    enum enDateCompare { Before = -1, Equal = 0, After = 1 };

    static bool IsLeapYear(short year)
    {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }


    static short GetTotalDaysInYear(short year)
    {
        return IsLeapYear(year) ? 366 : 365;
    }
    short GetTotalDaysInYear()
    {
        return GetTotalDaysInYear(_Year);
    }


    static int GetTotalHoursInYear(short year)
    {
        return GetTotalDaysInYear(year) * 24;
    }
    int GetTotalHoursInYear()
    {
        return GetTotalHoursInYear(_Year);
    }


    static long GetTotalMinutesInYear(short year)
    {
        return GetTotalHoursInYear(year) * 60;
    }
    long GetTotalMinutesInYear()
    {
        return GetTotalMinutesInYear(_Year);
    }


    static long long GetTotalSecondsInYear(short year)
    {
        return GetTotalMinutesInYear(year) * 60;
    }
    long long GetTotalSecondsInYear()
    {
       return GetTotalSecondsInYear(_Year);
    }


    static short GetTotalDaysInMonth(short year, short month)
    {
        short DaysInMonths[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (month == 2 && IsLeapYear(year)) ? 29 : DaysInMonths[month];
    }
    short GetTotalDaysInMonth()
    {
       return GetTotalDaysInMonth(_Year, _Month);
    }


    static int GetTotalHoursInMonth(short year, short month)
    {
        return GetTotalDaysInMonth(year, month) * 24;
    }
    int GetTotalHoursInMonth()
    {
        return GetTotalHoursInMonth(_Year, _Month);
    }



    static int GetTotalMinutesInMonth(short year, short month)
    {
        return GetTotalHoursInMonth(year, month) * 60;
    }
    int GetTotalMinutesInMonth()
    {
        return GetTotalMinutesInMonth(_Year, _Month);
    }



    static int GetTotalSecondsInMonth(short year, short month)
    {
        return GetTotalMinutesInMonth(year, month) * 60;
    }
    int GetTotalSecondsInMonth()
    {
        return GetTotalSecondsInMonth(_Year, Month);
    }


    static short GetDayOfWeekOrder(short year, short month, short day = 1)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + (12 * a) - 2;
        return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
    short GetDayOfWeekOrder()
    {
        return GetDayOfWeekOrder(_Year, _Month, _Day);
    }


    static short GetDayOfWeekOrder2(clsDate Date)
    {
        return GetDayOfWeekOrder(Date.Year, Date.Month, Date.Day);
    }
    short GetDayOfWeekOrder2()
    {
        return GetDayOfWeekOrder2(*this);
    }


    static string GetWeekDayName(short DayOfWeekOrder)
    {
        string arrWeekDaysName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        return arrWeekDaysName[DayOfWeekOrder];
    }
    string GetWeekDayName()
    {
        return GetWeekDayName(_Day);
    }


    static string GetMonthShortName(short Month)
    {
        string Months[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return Months[Month];
    }
    string GetMonthShortName()
    {
        return GetMonthShortName(_Month);
    }



    static void PrintMonthCalendar(short Month, short Year)
    {
        int NumberOfDays = GetTotalDaysInMonth(Year, Month);
        int current = GetDayOfWeekOrder(Year, Month, 1);

        printf("\n  _______________%s_______________\n\n", GetMonthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n  _________________________________\n");
    }
    void PrintMonthCalendar()
    {
        PrintMonthCalendar(_Month, Year);
    }


    static void PrintYearCalendar(int Year)
    {
        printf("\n  ---------------------------------\n");
        printf("           Calendar - %d           \n", Year);
        printf("  ---------------------------------\n");

        for (int i = 1; i <= 12; i++)
        {
            PrintMonthCalendar(i, Year);
        }
    }
    void PrintYearCalendar()
    {
        PrintYearCalendar(_Year);
    }

    static short GetNumberOfDaysFromTheBeginingOfTheYear(short year, short month, short day)
    {
        short TotalDays = 0;
        for (short i = 1; i < month; i++)
        {
            TotalDays += GetTotalDaysInMonth(year, i);
        }
        return TotalDays + day;
    }
    short GetNumberOfDaysFromTheBeginingOfTheYear()
    {
        return GetNumberOfDaysFromTheBeginingOfTheYear(_Year, _Month, _Day);
    }


    static short GetNumberOfDaysFromTheBeginingOfTheYear2(clsDate Date)
    {
        return GetNumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day);
    }
    short GetNumberOfDaysFromTheBeginingOfTheYear2()
    {
        return GetNumberOfDaysFromTheBeginingOfTheYear2(*this);
    }


    static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short year)
    {
        short DaysInCurrentMonth = 0;
        for (short Month = 1; Month <= 12; Month++)
        {
            DaysInCurrentMonth = GetTotalDaysInMonth(year, Month);

            if (DayOrderInYear <= DaysInCurrentMonth)
            {
                return { DayOrderInYear, Month, year };
            }

            DayOrderInYear -= DaysInCurrentMonth;
        }
        return { 0, 0, year };
    }

    static bool IsValid(clsDate Date)
    {
        if (Date.Month < 1 || Date.Month > 12)
            return false;

        short DaysInMonth = GetTotalDaysInMonth(Date.Year, Date.Month);
        if (Date.Day < 1 || Date.Day > DaysInMonth)
            return false;

        return true;
    }
    bool IsValid()
    {
        return IsValid(*this);
    }


    static bool IsLastDayInMonth(clsDate Date)
    {
        return (Date.Day == GetTotalDaysInMonth(Date.Year, Date.Month));
    }
    bool IsLastDayInMonth()
    {
        return IsLastDayInMonth(*this);
    }


    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }
    bool IsLastMonthInYear()
    {
        return IsLastMonthInYear(_Month);
    }




    static bool IsBefore(clsDate Date1, clsDate Date2)
    {
        return (Date1.Year < Date2.Year) ? true :
            (Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true :
                (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false)
            : false;
    }
    bool IsBefore(clsDate Date)
    {
        return IsBefore(*this, Date);
    }

    static bool IsEqual(clsDate Date1, clsDate Date2)
    {
        return ((Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day));
    }
    bool IsEqual(clsDate Date)
    {
        return IsEqual(*this, Date);
    }


    static bool IsAfter(clsDate Date1, clsDate Date2)
    {
        return (!IsBefore(Date1, Date2) && !IsEqual(Date1, Date2));
    }
    bool IsAfter(clsDate Date)
    {
        return IsAfter(*this, Date);
    }


    static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
    {
        if (IsBefore(Date1, Date2))
            return enDateCompare::Before;

        if (IsEqual(Date1, Date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }
    enDateCompare CompareDates(clsDate Date)
    {
        return CompareDates(*this, Date);
    }


    static clsDate IncreaseDateByOneDay(clsDate& Date)
    {
        if (IsLastDayInMonth(Date))
        {
            Date.Day = 1;
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Month = 1;
                Date.Year++;
            }
            else
            {
                Date.Month++;
            }
        }
        else
        {
            Date.Day++;
        }
        return Date;
    }
    void IncreaseDateByOneDay()
    {
        IncreaseDateByOneDay(*this);
    }


    static clsDate IncreaseDateByXDays(clsDate& Date, short DaysToAdd)
    {
        for (short i = 1; i <= DaysToAdd; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    void IncreaseDateByXDays(short DaysToAdd)
    {
        IncreaseDateByXDays(*this,DaysToAdd);
    }


    static clsDate IncreaseDateByOneWeek(clsDate& Date)
    {
        for (short i = 1; i <= 7; i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    void IncreaseDateByOneWeek()
    {
        IncreaseDateByOneWeek(*this);
    }


    static clsDate IncreaseDateByXWeeks(clsDate& Date, short WeeksToAdd)
    {
        for (short i = 1; i <= WeeksToAdd; i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }
    void IncreaseDateByXWeeks(short WeeksToAdd)
    {
        IncreaseDateByXWeeks(*this, WeeksToAdd);
    }



    static clsDate IncreaseDateByOneMonth(clsDate& Date)
    {
        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }

        short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    void IncreaseDateByOneMonth()
    {
        IncreaseDateByOneMonth(*this);
    }


    static clsDate IncreaseDateByXMonths(clsDate& Date, short MonthsToAdd)
    {
        for (short i = 1; i <= MonthsToAdd; i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }
    void IncreaseDateByXMonths(short MonthsToAdd)
    {
        IncreaseDateByXMonths(*this, MonthsToAdd);
    }


    static clsDate IncreaseDateByOneYear(clsDate& Date)
    {
        Date.Year++;
        short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    void IncreaseDateByOneYear()
    {
        IncreaseDateByOneYear(*this);
    }


    static clsDate IncreaseDateByXYears(clsDate& Date, short YearsToAdd)
    {
        Date.Year += YearsToAdd;
        short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    void IncreaseDateByXYears(short YearsToAdd)
    {
        IncreaseDateByXYears(*this, YearsToAdd);
    }


    static clsDate IncreaseDateByOneDecade(clsDate& Date)
    {
        return IncreaseDateByXYears(Date, 10);
    }
    void IncreaseDateByOneDecade()
    {
        IncreaseDateByOneDecade(*this);
    }


    static clsDate IncreaseDateByXDecades(clsDate& Date, short DecadesToAdd)
    {
        Date.Year += DecadesToAdd * 10;
        short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    void IncreaseDateByXDecades(short DecadesToAdd)
    {
       IncreaseDateByXDecades(*this, DecadesToAdd);
    }


    static clsDate IncreaseDateByOneCentury(clsDate& Date)
    {
        return IncreaseDateByXDecades(Date, 10);
    }
    void IncreaseDateByOneCentury()
    {
       IncreaseDateByOneCentury(*this);
    }


    static clsDate IncreaseDateByXCenturies(clsDate& Date, short CenturiesToAdd)
    {
        Date.Year += CenturiesToAdd * 100;
        short NumberOfDaysInCurrentMonth = GetTotalDaysInMonth(Date.Year, Date.Month);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    void IncreaseDateByXCenturies(short CenturiesToAdd)
    {
        IncreaseDateByXCenturies(*this, CenturiesToAdd);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate& Date)
    {
        return IncreaseDateByXCenturies(Date, 10);
    }
    void IncreaseDateByOneMillennium()
    {
        IncreaseDateByOneMillennium(*this);
    }

    static bool IsEndOfWeek(clsDate Date)
    {
        return GetDayOfWeekOrder2(Date) == 6;
    }
    bool IsEndOfWeek()
    {
        return IsEndOfWeek(*this);
    }

    static bool IsWeekEnd(clsDate Date)
    {
        short DayOfWeekOrder = GetDayOfWeekOrder2(Date);
        return (DayOfWeekOrder == 5 || DayOfWeekOrder == 6);
    }
    bool IsWeekEnd()
    {
        return IsWeekEnd(*this);
    }

    static bool IsBusinessDay(clsDate Date)
    {
        return !IsWeekEnd(Date);
    }
    bool IsBusinessDay()
    {
        return IsBusinessDay(*this);
    }

    static short GetDaysUntilEndOfWeek(clsDate Date)
    {
        return 6 - GetDayOfWeekOrder2(Date);
    }
    short GetDaysUntilEndOfWeek()
    {
        return GetDaysUntilEndOfWeek(*this);
    }


    static void SwapTwoDates(clsDate& Date1, clsDate& Date2)
    {
        clsDate Temp = Date1;
        Date1 = Date2;
        Date2 = Temp;
    }
    void SwapTwoDates(clsDate Date)
    {
        SwapTwoDates(*this, Date);
    }


    static int GetDiffInDaysBetWeenTwoDates(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
    {
        short SwapFlagValue = 1;
        if (!IsBefore(Date1, Date2) && !IsEqual(Date1, Date2))
        {
            SwapTwoDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        int DaysDiff = 0;
        while (IsBefore(Date1, Date2))
        {
            DaysDiff++;
            Date1 = IncreaseDateByOneDay(Date1);
        }

        return IncludeEndDay ? (DaysDiff + 1) * SwapFlagValue : DaysDiff * SwapFlagValue;
    }
    int GetDiffInDaysBetWeenTwoDates(clsDate Date, bool IncludeEndDay = false)
    {
        return GetDiffInDaysBetWeenTwoDates(*this, Date, IncludeEndDay);
    }


    static short GetDaysUntilEndOfMonth(clsDate Date)
    {
        clsDate EndOfMonthDate = Date;
        EndOfMonthDate.Day = GetTotalDaysInMonth(Date.Year, Date.Month);
        return GetDiffInDaysBetWeenTwoDates(Date, EndOfMonthDate, true);
    }
    short GetDaysUntilEndOfMonth()
    {
        return GetDaysUntilEndOfMonth(*this);
    }


    static short GetDaysUntilEndOfYear(clsDate Date)
    {
        clsDate EndOfYearDate = { 31, 12, Date.Year };
        return GetDiffInDaysBetWeenTwoDates(Date, EndOfYearDate, true);
    }
    short GetDaysUntilEndOfYear()
    {
        return GetDaysUntilEndOfYear(*this);
    }

    static short GetVacationDays(clsDate VacationStart, clsDate VacationEnd)
    {
        short Counter = 0;
        while (IsBefore(VacationStart, VacationEnd))
        {
            if (IsBusinessDay(VacationStart))
            {
                Counter++;
            }
            VacationStart = IncreaseDateByOneDay(VacationStart);
        }
        return Counter;
    }
    short GetVacationDays(clsDate VacationEnd)
    {
        return GetVacationDays(*this, VacationEnd);
    }


    static clsDate CalculateVacationReturnDate(clsDate VacationStart, short VacationDays)
    {
        short WeekEndCounter = 0;
        while (IsWeekEnd(VacationStart))
        {
            VacationStart = IncreaseDateByOneDay(VacationStart);
        }

        for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
        {
            if (IsWeekEnd(VacationStart))
                WeekEndCounter++;

            VacationStart = IncreaseDateByOneDay(VacationStart);
        }

        while (IsWeekEnd(VacationStart))
        {
            VacationStart = IncreaseDateByOneDay(VacationStart);
        }

        return VacationStart;
    }
    clsDate CalculateVacationReturnDate(short VacationDays)
    {
        return CalculateVacationReturnDate(*this, VacationDays);
    }


    static vector<string> SplitString(string S1, string Delim)
    {
        vector<string> vString;
        size_t pos = 0;
        string sWord;

        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());
        }

        if (S1 != "")
        {
            vString.push_back(S1);
        }

        return vString;
    }

    static clsDate StringToDate(string DateString)
    {
        clsDate Date;
        vector<string> vDate = SplitString(DateString, "/");
        Date.Day = stoi(vDate[0]);
        Date.Month = stoi(vDate[1]);
        Date.Year = stoi(vDate[2]);
        return Date;
    }

    static string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
    {
        size_t pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
            pos = S1.find(StringToReplace);
        }
        return S1;
    }


    static string DateToString(clsDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }
    string DateToString()
    {
        return DateToString(*this);
    }


    static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
    {
        string FormattedDateString = "";
        FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
        FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
        FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));
        return FormattedDateString;
    }
    string FormatDate(string DateFormat = "dd/mm/yyyy")
    {
        return FormatDate(*this, DateFormat);
    }

};

