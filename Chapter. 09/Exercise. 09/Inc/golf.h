/* Subject 01 */
#ifndef _GOLF_H_
#define _GOLF_H_

const int Len = 40;
struct golf
{
  char fullname[Len];
  int handicap;
};

void Setgolf(golf &g, const char *name, int hc);
int Setgolf(golf &g);
void Handicap(golf &g, int hc);
void Showgolf(const golf &g);

#endif
