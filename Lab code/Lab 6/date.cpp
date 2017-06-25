#include <iostream>
#include <iomanip>
#include <ctime>
#include "date.h" // include Date class definition
using namespace std;
Date::Date()
{
   struct tm *ptr; 
   time_t t = time( 0 ); 
   ptr = localtime( &t );             
   day = ptr->tm_mday; 
   month = 1 + ptr->tm_mon;
   year = ptr->tm_year + 1900; 
}
Date::Date( int ddd, int yyyy )
{
   year = yyyy;
   setMMDDFromDDD( ddd );
}
Date::Date( int mm, int dd, int yy )
{
   setYYYYFromYY( yy );
   setMonth( mm );
   setDay( dd ); 
}
Date::Date( string monthName, int dd, int yyyy )
{ 
   setMMFromMonth( monthName );
   setDay( dd ); 
   year = yyyy; 
} 
void Date::setDay( int d )
{
   day = checkDay( d );
}
void Date::setMonth( int m )
{
   if ( m > 0 && m <= 12 )
      month = m;
   else{                     
      month = 1;
      cout << "Invalid month (" << m << ") set to 1.\n";
   }
}
void Date::print() const
{
   cout << month << '/' << day << '/' << year << endl; 
}
void Date::printDDDYYYY() const
{
   cout << convertDDToDDD() << ' ' << year << endl;
}
void Date::printMMDDYY() const
{
   cout << setw( 2 ) << setfill( '0' ) << month << '/' 
      << setw( 2 ) << setfill( '0' ) << day << '/' 
      << setw( 2 ) << setfill( '0' ) << convertYYYYToYY() << endl;
}
void Date::printMonthDDYYYY() const
{
   cout << convertMMToMonth( month ) << ' ' << day << ", " << year 
      << endl;
}
Date::~Date()
{ 
   cout << "Date object destructor for date ";
   print();
   cout << endl;
}
int Date::checkDay( int testDay ) const
{
   if ( testDay > 0 && testDay <= daysInMonth( month ) )
      return testDay;
   if ( month == 2 && testDay == 29 && isLeapYear() )
      return testDay;
   cout << "Invalid day (" << testDay << ") set to 1.\n";
   return 1;
}
int Date::daysInMonth( int m ) const
{
   if ( isLeapYear() && m == 2 )
      return 29;  
   static const int daysPerMonth[ 13 ] = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   return daysPerMonth[ m ];
}
bool Date::isLeapYear() const
{
   if ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) )
      return true;
   else
      return false;
}
int Date::convertDDToDDD() const
{
   int ddd = 0;
   for ( int i = 1; i < month; i++ ){
        ddd += daysInMonth( i );
        ddd += day;
    }
   return ddd;
}
void Date::setMMDDFromDDD( int ddd )
{
   int dayTotal = 0;
   int m;
   for ( m = 1; m <= 12 && ( dayTotal + daysInMonth( m ) ) < ddd; m++ )
        dayTotal += daysInMonth( m );
        setMonth( m );
        setDay( ddd - dayTotal );
}
string Date::convertMMToMonth( int mm ) const
{
   static const string months[] = 
      { "", "January", "February", "March", "April", "May", "June", 
      "July", "August", "September", "October", "November", "December" };
   return months[ mm ];
}
void Date::setMMFromMonth( string m )
{
   bool matchFound = false;
   for ( int i = 1; i <= 12 && !matchFound; i++ ){
      string tempMonth = convertMMToMonth( i );
      if ( tempMonth == m ){
         setMonth( i );
         matchFound = true;
      }
   }
   if ( !matchFound ){
      cout << "Invalid month name (" << month << "). month set to 1.\n";
      setMonth( 1 );
   }
}
int Date::convertYYYYToYY() const
{
   return ( year >= 2000 ? year - 2000 : year - 1900 );
}
void Date::setYYYYFromYY( int yy )
{
   year = ( yy < 7 ? yy + 2000 : yy + 1900 );
}
