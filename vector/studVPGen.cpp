#include "studVPGen.h"

using std::string;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::vector;
using std::map;
using std::mt19937;

using hrClock = std::chrono::high_resolution_clock; 

void gen_map(Studentas &A){

  mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
  int_distribution dist(100, 109);
  int_distribution dist2(200, 209);
  string vardas, pavarde;

  map<int, string> vardai, pavardes_m, pavardes_v;
  
  vardai[100]="Irma";
  vardai[101]="Alma";
  vardai[102]="Irena";
  vardai[103]="Egle";
  vardai[104]="Jolanta";
  vardai[105]="Petras";
  vardai[106]="Jonas";
  vardai[107]="Ignas";
  vardai[108]="Darius";
  vardai[109]="Simas";

  pavardes_m[200]="Pavardaite1";
  pavardes_m[201]="Pavardaite2";
  pavardes_m[202]="Pavardaite3";
  pavardes_m[203]="Pavardaite4";
  pavardes_m[204]="Pavardaite5";
  pavardes_m[205]="Pavardaite6";
  pavardes_m[206]="Pavardaite7";
  pavardes_m[207]="Pavardaite8";
  pavardes_m[208]="Pavardaite9";
  pavardes_m[209]="Pavardaite10";

  pavardes_v[300]="Pavardenis1";
  pavardes_v[301]="Pavardenis2";
  pavardes_v[302]="Pavardenis3";
  pavardes_v[303]="Pavardenis4";
  pavardes_v[304]="Pavardenis5";
  pavardes_v[305]="Pavardenis6";
  pavardes_v[306]="Pavardenis7";
  pavardes_v[307]="Pavardenis8";
  pavardes_v[308]="Pavardenis9";
  pavardes_v[309]="Pavardenis10";
  
  vardas=vardai[dist(mt)];
  
  switch(*vardas.rbegin()){
    case 's': 
      pavarde=pavardes_v[200 +dist(mt)];
      break;
    default: 
      pavarde=pavardes_m[100+dist(mt)];
      break;  
  };
  A.setVardas(vardas);
  A.setPavarde(pavarde);
}