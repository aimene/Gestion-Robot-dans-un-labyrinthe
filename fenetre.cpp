#include<cmath>
#include"fenetre.h"
#include"graphics.h"
#include"fenetreAffichage.h"

namespace affichage
{

fenetre::fenetre(int width, int height, int borderx, int bordery):
               d_width{width}, d_height{height},
               d_borderx{borderx}, d_bordery{bordery},
               d_winopen{false},
               d_vpx{0,d_width,d_borderx,d_width-d_borderx},
               d_vpy{0,d_height,d_height-d_bordery,d_bordery}
{ }

fenetre::~fenetre()
{
  if (d_winopen) { close(); }
}

void fenetre::open()
{
  if (!d_winopen)
  {
    opengraphsize(d_width+2*d_borderx,d_height+2*d_bordery);
    d_winopen = true;
  }
}

void fenetre::close()
{
  if (d_winopen)
  {
    closegraph();
    d_winopen = false;
  }
}

void fenetre::repeatUntilButton()
{
  //getch();
  waituntilbuttonpressed();
}

void fenetre::flush()
{
  kbhit();
}

void fenetre::clear()
{
  cleardevice();
}

int fenetre::pixelx(double x) const
{
  return static_cast<int>(d_vpx.destFromSrc(std::round(x)));
}

int fenetre::pixely(double y) const
{
  return static_cast<int>(d_vpy.destFromSrc(std::round(y)));
}

void fenetre::wait(int ms)
{
  delay(ms);
}
void fenetre::traceLigneDe(const point& point1,const point& point2)
{
    line(point1.x(),point1.y(),point2.x(),point2.y());
}


}

