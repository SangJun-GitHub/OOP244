// Final Project Milestone 5
//
// Name:Sang Jun Park Date:2018.04.16
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

#define NO_ERROR   0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR  3
#define DAY_ERROR  4


namespace AMA {

   const int min_year = 2000;
   const int max_year = 2030;

  class Date 
  {
  private:
     int m_year;
     int m_month;
     int m_day;
     int m_check;
     int comparetor() const;
     bool valid();
     int mdays(int, int)const;
     void errCode(int errorCode);
 
  public:
     Date();
     Date(int year, int month, int day);
     bool operator==(const Date& rhs) const;
     bool operator!=(const Date& rhs) const;
     bool operator<(const Date& rhs) const;
     bool operator>(const Date& rhs) const;
     bool operator<=(const Date& rhs) const;
     bool operator>=(const Date& rhs) const;
     int errCode() const;
     bool bad() const;
     std::istream& read(std::istream& istr);
     std::ostream& write(std::ostream& ostr) const;
  };
  std::ostream& operator<<(std::ostream& out, const Date& ar);
  std::istream& operator>>(std::istream& in, Date& ar);
}
#endif