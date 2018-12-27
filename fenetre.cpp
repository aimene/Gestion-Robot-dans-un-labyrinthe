
#include<cmath>
#include"fenetre.h"
#include"graphics.h"
#include"fenetreAffichage.h"

using geom::point;
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
    if (d_winopen)
    {
        close();
    }
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

void fenetre::repeteJusquaBouton()
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
void fenetre::dessineSegment(const point& point1,const point& point2) const
{
    line(pixelx(point1.x()),pixely(point1.y()),pixelx(point2.x()),pixely(point2.y()));
}
void fenetre::dessineRectangle(const point& basGauche, const point& hautDroit) const
{
    rectangle(pixelx(basGauche.x()),pixely(basGauche.y()),pixelx(hautDroit.x()),pixely(hautDroit.y()));
}

void fenetre::dessineRectanglePlein(const point& basGauche, const point& hautGauche,const point& hautDroit,const point& basDroit) const
{
    int tab []= {pixelx(basGauche.x()),pixely(basGauche.y()),pixelx(hautGauche.x()),pixely(hautGauche.y()),
                 pixelx(hautDroit.x()),pixely(hautDroit.y()),pixelx(basDroit.x()),pixely(basDroit.y()),
                 pixelx(basGauche.x()),pixely(basGauche.y())
                };

    fillpoly(5,tab);
}

void fenetre::dessinePolyPleinEst(const point& basGauche, const point& hautGauche,const point& hautDroit,const point& basDroit, const point& direction)
{
    int tab []= {pixelx(basGauche.x()),pixely(basGauche.y()),pixelx(hautGauche.x()),pixely(hautGauche.y()),
                 pixelx(hautDroit.x()),pixely(hautDroit.y()),pixelx(direction.x()),pixely(direction.y()),pixelx(basDroit.x()),pixely(basDroit.y()),
                 pixelx(basGauche.x()),pixely(basGauche.y())
                };
    fillpoly(6,tab);

}


void fenetre::dessinePolyPleinNord(const point& basGauche, const point& hautGauche,const point& hautDroit,const point& basDroit, const point& direction)
{
    int tab []= {pixelx(basGauche.x()),pixely(basGauche.y()),pixelx(hautGauche.x()),pixely(hautGauche.y()),
                 pixelx(direction.x()),pixely(direction.y()),pixelx(hautDroit.x()),pixely(hautDroit.y()),pixelx(basDroit.x()),pixely(basDroit.y()),
                 pixelx(basGauche.x()),pixely(basGauche.y())
                };
    fillpoly(6,tab);

}

void fenetre::dessinePolyPleinOuest(const point& basGauche, const point& hautGauche,const point& hautDroit,const point& basDroit, const point& direction)
{
    int tab []= {pixelx(basGauche.x()),pixely(basGauche.y()),pixelx(direction.x()),pixely(direction.y()),pixelx(hautGauche.x()),pixely(hautGauche.y()),
                 pixelx(hautDroit.x()),pixely(hautDroit.y()),pixelx(basDroit.x()),pixely(basDroit.y()),
                 pixelx(basGauche.x()),pixely(basGauche.y())
                };
    fillpoly(6,tab);

}
void fenetre::dessinePolyPleinSud(const point& basGauche, const point& hautGauche,const point& hautDroit,const point& basDroit, const point& direction)
{
    int tab []= {pixelx(basGauche.x()),pixely(basGauche.y()),pixelx(hautGauche.x()),pixely(hautGauche.y()),
                 pixelx(hautDroit.x()),pixely(hautDroit.y()),pixelx(basDroit.x()),pixely(basDroit.y()),
                 pixelx(direction.x()),pixely(direction.y()),pixelx(basGauche.x()),pixely(basGauche.y())
                };
    fillpoly(6,tab);

}


}

