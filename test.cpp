#include "std.h"
#include <ctime>
#include "windows.h"
int main()
{
int x=5;
 while(5>0)
 {
     time_t temps;
  struct tm datetime;
  char  format[32];

  time(&temps);
  datetime = *localtime(&temps);
  strftime(format, 32, "%d-%m-%Y %Hh:%Mmin:%Ssec", &datetime);


    cout<<" Hello oumar on est le "<<format;
    Sleep(1000);
    system("cls");

 }

}
