#ifndef FENETREAFFICHAGE_H
#define FENETREAFFICHAGE_H


namespace affichage
{

class fenetreAffichage {
/**
  Class for mapping source coordinates in [srcmin,srcmax]
  to destination coordinate in [destmin,destmax]
*/
public:
  ///viewport [0,1] -> [0,1]
  fenetreAffichage();
  ///viewport [srcmin,srcmax] -> [0,1]
  fenetreAffichage(double srcmin, double srcmax);
  ///viewport [srcmin,srcmax] -> [destmin,destmax]
  fenetreAffichage(double srcmin, double srcmax, double destmin, double destmax);
  /**
  Convert source coordinate to destination coordinate
  @param src source coordinate
  @return corresponding destination coordinate
  */
  double destFromSrc(double src) const;
  /**
  Convert destination coordinate to source coordinate
  @param dest destination coordinate
  @return corresponding source coordinate
  */
  double srcFromDest(double dest) const;
  /**
  @return source delta, that is when source changes by delta
  destination changes by 1
  */
  double deltaSrc() const;
  /**
  Change minimum value of source interval
  @param srcmin the new minimum value of source interval
  */
  fenetreAffichage& changeSrcMin(double srcmin);
  /**
  Change maximum value of source interval
  @param srcmax the new maximum value of source interval
  */
  fenetreAffichage& changeSrcMax(double srcmax);
  /**
  Change source interval
  @param srcmin the new minimum value of source interval
  @param srcmax the new maximum value of source interval
  */
  fenetreAffichage& changeSrc(double srcmin, double srcmax);
  /**
  Change minimum value of destination interval
  @param destmin the new minimum value of destination interval
  */
  fenetreAffichage& changeDestMin(double destmin);
  /**
  Change maximum value of destination interval
  @param destmax the new maximum value of destination interval
  */
  fenetreAffichage& changeDestMax(double destmax);
  /**
  Change destination interval
  @param destmin the new minimum value of destination interval
  @param destmax the new maximum value of destination interval
  */
  fenetreAffichage& changeDest(double destmin, double destmax);
private:
  double d_srcmin, d_srcmax;
  double d_destmin, d_destmax;
  double d_delta;
  void computeDelta();
};

}
#endif

