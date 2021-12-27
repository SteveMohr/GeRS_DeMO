// dependencies
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef map <string, double> strtodbdict;
typedef map <string, string> strtostrdict;



struct production
{
  // nice little struct for the outputs (year, production)
  float year;
  float amount;
};

struct miner
{
   // this is the data needed to determine the production from a mine
   // maximprod               - this is the maximum production of the mine
   // URR                     - URR
   // minelife                - the life of the mine
   // TODO
   double maximprod;
   double URR;
   double minelife;
   double wpremainingres;
   double wptime;
   double lowURRdeterminor;
};

struct cmines
{
   // this is the structure of an individual mine.
   // startyear - year mine commences
   // endyear   - last year of the mine
   // remainres - remaining reserves in the mine
   // upgrade   - integer -1 = hasn't upgraded, otherwise it is the index (aka year) of upgrade occurs
   // mdata     - is the specific data of the mine (used to determine production)
   double startyear;
   miner mdata;
   double endyear;
   double remainres;
   int upgrade; // -1 = false
};


struct cwells
{
   // is the information of a individual field.
   // startyear   - year it commenced
   // endyear     - year it will finish
   // remainres   - remaining recoverable resources
   // initialres  - URR
   double startyear;
   double endyear;
   double remainres;
   double initialres;
};


struct wellpair
{
   // is the breakdown of the fields
   // shutdown  - fields that have shut down, to restart later
   // remaining - fields that are still online
   // fixit     - exists if there is a difference between the number of fields that you want to shutdown, and the number of fields the model can shutdown.
   vector<cwells> shutdown;
   vector<cwells> remaining;
   double fixit;
};


struct wellpainful
{
   // this is all the stuff the field oil or gas production function returns (so production for a place like UK North Sea)
   double maxprod;
   double maybemaxprod;
   vector<double> yearlybasinprodmod;
   double futuretime;
   vector<cwells> oldcurrentwells;
   vector<cwells> currentwells;
   vector<cwells> shutdownwells;
   vector<double> stupid;
   double totalwells;
   double oldtotalwells;
   double cumm_prod;
   int indisruption;
   int oldindisruption;
   double whichdisruption;
   bool backtonormal;
   double predisruptionwells;
   double cummwellsshutdown;
   double oldcummwellsshutdown;
   bool basinlifechecker;
   double maxoffline;
   double oldcumm_prod;
   double wellsy;
   double supply;
   int countingwells;
   int oldcountingwells;
   double oldwellsURR;
   int fixer;
};

struct wellpainfulfields
{
   // This is all the stuff the regions oil or gas production function returns (so production for a place like USA)
   vector<double> maxprod;
   vector<double> maybemaxprod;
   vector<double> yearlybasinprodmod;
   vector<vector<cwells> > oldcurrentwells;
   vector<vector<cwells> > currentwells;
   vector<vector<cwells> > shutdownwells;
   vector<double> totalwells;
   vector<double> oldtotalwells;
   vector<double> stupid;
   vector<double> cumm_prod;
   vector<int> indisruption;
   vector<int> oldindisruption;
   vector<double> whichdisruption;
   vector<int> backtonormal;
   vector<double> predisruptionwells;
   vector<double> cummwellsshutdown;
   vector<double> oldcummwellsshutdown;
   bool basinlifechecker;
   vector<int> fieldlifechecker;
   vector<double> maxoffline;
   vector<double> oldcumm_prod;
   vector<double> wellsy;
   double supply;
   vector<int> countingwells;
   vector<int> oldcountingwells;
   double oldfieldstotal;
   double fieldstotal;
   double fieldsCP;
   vector<int> yearfieldfound;
   vector<double> URR_fields;
   vector<vector<double> > fieldproduction;
   vector<double> fieldtime;
   vector<double> oldwellsURR;
   double fieldsy;
   vector<double> howmanywells;
   vector<double> wellsonlinerate;
   vector<double> oldwellsonlinerate;
   vector<int> fixer;
   bool tripped;
};





struct shutty
{
   // TODO
   double fixit;
   vector<cmines> shutdown;
   double URR;
   vector<cmines> mines;
};


struct disr
{
   // Disruption: this describes a disruption that is inputted
   // startdisr   - is the start year of the disruption
   // enddisr     - is the end year of the disruption
   // intmines    - is the initial number of mines online
   // endmines    - is the final number of mines online
   double startdisr;
   double enddisr;
   double intmines;
   double endmines;
};

struct returningwells
{
   // this is the production of the wells, as a Nx2 vector and a title (that was inputted)
   vector<production> prod;
   string title;
};

struct painful
{
   // TODO
   double maxprod;
   double maybemaxprod;
   vector<double> yearlybasinprodmod;
   double futuretime;
   vector<cmines> oldcurrentmines;
   vector<cmines> currentmines;
   vector<cmines> shutdownmines;
   double totalmines;
   double oldtotalmines;
   double cumm_prod;
   int indisruption;
   int oldindisruption;
   double whichdisruption;
   bool backtonormal;
   double predisruptionURRs;
   double predisruptionmines;
   double cminesize;
   double cummminesshutdown;
   double oldcummminesshutdown;
   bool basinlifechecker;
   double maxoffline;
   double oldcumm_prod;
   double wellsy;
   double supply;
   double mineURR;
   double mineMP;
   int countingmines;
   double upperURR;
   double lowerURR;
   bool fixer;
};


struct chpref
{
   // Change preferences for a mine:
   // so when you inputs that you want things to change:
   // year               - year inputs need to change
   // minesonlinerate    - new minesonlinerate
   // max_capacity       - new max capacity
   double year;
   double minesonlinerate;
   double max_capacity;
};

struct chprefwell
{
   // Change preferences for a field:
   // so when you inputs that you want things to change:
   // year               - year inputs need to change
   // minesonlinerate    - new minesonlinerate
   // max_capacity       - new max capacity
   double year;
   double wellsonlinerate;
   double max_capacity;
};



struct returningdata
{
   // this is the production of the mines, as a Nx2 vector and a title (that was inputted)
   vector<production> prod;
   string title;
};



struct changer
{
   // TODO
   double year;
   double amount;
};

struct reservdata
{
   // TODO
   double founditwhen;
   double Max_prodLOW;
   double Max_prodHIGH;
   double Max_prodCY;
   double Max_prodRATE;
   double MinelifeLOW;
   double MinelifeHIGH;
   double minesonlinerate;
   double ramping_time;
   double URR_basin;
   double max_capacity;
   double abort;
   string title;
   string type;
   vector<disr> disruptions;
   vector<double> overrider;
   double mintime;
   vector<chpref> changedpreferences;
};

struct reservwelldata
{
   // TODO
   double founditwhen;
   double numberwells;
   double whenparity;
   double rampup_time;
   double URR_basin;
   double max_capacity;
   double URRwtoR0;
   double URRwtoURRr;
   double whencross;
   double powernum;
   double maximwell;
   double howmanyfields;
   double fieldsrate;
   double abort;
   string title;
   string type;
   vector<disr> disruptions;
   vector<chprefwell> changedpreferences;
};




double numberwellsonline(double cumm_prod, double wellsonlinerate);
double numberwellsreally(double URR_basin, double wellsonlinerate);
double URRfromwells(double rate,double oldURR, double numwells, double cummwells );
double peakwellprod(double URRwell, double rate);
double URRremaining(double URRwell, double rate);
double cumm_well(double time,double URR_w, double URR_r, double r0, double start_year, double shutoffpercent, double rampup_time);
double well_life(double URR_w, double URR_r, double r0, double start_year, double shutoffpercent, double rampup_time);
//vector<double> prodwellmodel(double URR_w, double URR_r, double r0, double start_year, double shutoffpercent, double rampup_time);
double prodwellattimet(double URR_w, double URR_r, double r0, double start_year, double t, double shutoffpercent, double rampup_time);
bool splitterpercentremain(const cwells& elem1, const cwells& elem2);
wellpair shuttingwells(vector<cwells> currentwells, double howmanyshutdown);
vector<cwells> ordershutwells(vector<cwells> removedwells,double oldcummwellsshutdown,double cummwellsshutdown);
wellpainfulfields fieldsmodel(int& yearfind, int& timedelay,vector<double> & yearlybasinprodmod, vector<vector<cwells> >& currentwells,  vector<vector<cwells> > & oldcurrentwells, double & URRwtoURRr, double & URRwtoR0,  double& shutoffpercent, double& rampup_time, int i, vector<double>& totalwells, vector<double>& oldtotalwells, vector<vector<cwells> > &shutdownwells,vector<double> & maxprod, vector<double> & maybemaxprod, double max_capacity , vector<int> & oldcountingwells, vector<int> & countingwells, vector<double> & oldcummwellsshutdown, vector<double> & cummwellsshutdown, vector<double> & maxoffline, vector<int> &indisruption, vector<int> & oldindisruption, vector<disr>& disruptions, vector<double>& whichdisruption, vector<int>& backtonormal, vector<double>& predisruptionwells, vector<double>& cumm_prod, vector<double> & wellsy, double & numberwells, bool & gonk, vector<double> & oldwellsonlinerate, vector<double> & wellsonlinerate, vector<double> & oldcumm_prod, double & realnumwells, bool & basinlifechecker, double & URR_basin, double & powernum, double & whencross, double & oldfieldstotal, double & fieldstotal, double & fieldsCP, double & totalfields, vector<double> & URR_fields,double & fieldsrate, vector<int> & yearfieldfound, vector<int> & fieldlifechecker, vector<vector<double> > & fieldproduction, vector<double> & fieldtime, double & fieldsy ,double k2gap, double k3smallgap, vector<double> & howmanywells, double & whenparity, vector<int> & fixer, vector<double> & stupid, double & maximwell, vector<double> & oldwellsURR, bool & tripped, double abort);
wellpainful wellmodelproc(int& yearfind, int& timedelay, double& futuretime,vector<double>& yearlybasinprod, vector<cwells>& currentwells,  vector<cwells>& oldcurrentwells, double& URRwtoURRr, double& URRwtoR0,  double& shutoffpercent, double& rampup_time, int i, double& totalwells, double& oldtotalwells, vector<cwells>& shutdownwells,double& maxprod, double& maybemaxprod, double max_capacity , int& oldcountingwells, int& countingwells, double& oldcummwellsshutdown, double& cummwellsshutdown, double& maxoffline,  int &indisruption, int& oldindisruption, vector<disr>& disruptions, double& whichdisruption, int& backtonormal, double& predisruptionwells, double& cumm_prod, double& wellsy, double& numberwells, bool& gonk, double& oldwellsonlinerate, double& wellsonlinerate, double& oldcumm_prod, double& realnumwells, int& basinlifechecker, double& URR_basin, double& powernum, double& whencross ,double& k2gap, double& sup,int& fixer, vector<double>& stupid, int& yearfieldfound, double& maximwell, double& oldwellsURR);
double cumm_mine(double URR, double Max_production, double ramping_time, double start_year, double current_year, vector<double> overrider);
double minelife(double URR_basin, double numberminesreally, double Max_production, double ramping_time, double start_year, vector<double> overrider);
vector<double> prodminemodel(double URR, double Max_production, double ramping_time, double start_year, vector<double> overrider);
double prodmineattimet(double URR, double Max_production, double ramping_time, double start_year, double t, vector<double> overrider);
double numberminesreally_ds(double numbermines, double minesonlinerate);
double numberminesonline_ds(double cumm_prod,double numbermines, double minesonlinerate, double URR_basin);
bool splitteronline(const cmines& elem1, const cmines& elem2);
bool splitterremain(const cmines& elem1, const cmines& elem2);
shutty shuttingmines(vector<cmines> currentmines, double rampingtime, double currentyear, double howmanyshutdowna, vector<double> overrider);
double howmanyminestoremove(vector<cmines> currentmines, double rampingtime, double currentyear, double removeURR, vector<double> overrider);
double shutURR(vector<cmines> currentmines, double rampingtime, double currentyear, double howmanyshutdown, vector<double> overrider);
vector<cmines> removefrommines(vector<cmines> currentmines,vector<cmines> removemines);
vector<double> upgrader(vector<double> oldproduction,double Max_production,double ramping_time,double start_year, vector<double> overrider, double whenupgrade, double runningtime);
double upgradprodattimet(double URR, double remainingres,double Max_production,double ramping_time,double start_year,double t, vector<double> overrider, double whenupgrade, double runningtime);
painful painfulmodelproc(double & maxprod, double & maybemaxprod, vector<double> yearlybasinprodamod, int & futuretime, vector<cmines> & oldcurrentmines, vector<cmines> & currentmines, vector<cmines> & shutdownmines, double & totalmines, double & oldtotalmines, double & cumm_prod, int & indisruption, bool & oldindisruption, double & whichdisruption, bool & backtonormal, double & predisruptionURRs, double & predisruptionmines, double & cummminesshutdown, double & oldcummminesshutdown,  double & minesonlinerate, double ramping_time, double URR_basin, int timedelay, int yearfind,   double max_capacity, vector<disr> & disruptions, vector<double> overrider, double i, bool & basinlifechecker, double & lastdisruptionend, double & maxoffline, double oldminesonlineratea, double & oldcumm_prod, double & wellsy, double mintime, double k3, double smallergap,  double oldminesonlinerateaa, bool & gonk ,int & countingmines ,double k2gap, double & mineURR, double & mineMP, double Max_prodLOW, double Max_prodHIGH, double Max_prodCY, double Max_prodRATE, double ML_LOW, double ML_HIGH, double & upperURR, double & lowerURR, bool & fixer,double PP, double & cminesize ,bool ARGH, double abort);
vector<returningdata> miningmodel_ds(vector<reservdata> reservoirdata,  double timedelay, double initdemand, double kDD, double k1, double k2, double k3, double whenupgrade, double gapdelay, vector<changer> demandchanger);
vector<returningdata> completemodel(vector<reservwelldata> reswelldata, vector<reservdata> resminedata, double shutoffpercent, int timedelay, double initdemand, double kDD,double maxdemand, double k1, double k2, double k3, double k4, double whendisc, double k5, double whenupgrade, double gapdelay, double foil, double fcoal, double fgas  ,double maxpop, double popinit, double poprate, double popmidyear, double popB, double popGamma, double coalmax, double coalmin, double coalrate, double coalmidyear, double coalB, double coalGamma, double gasmax, double gasmin, double gasrate, double gasmidyear , string whichoption, vector<changer> demandchanger ,vector<double> recycler);
vector<string> splitstring(string str,char delim);
bool checkstringvec(vector<string> vecstr, int howmany);
double plateau_time(double URR_w,double URR_r,double r0,double rampup_time);
double end_time(double tp,double start_year,double rampup_time,double shutoffpercent,double URR_r,double r0);


int main(int argc, char *argv[])
{
  // Step 1: initialise variables... lots of variables
  ifstream instuffmodels, prestuff, instuffmod,instuffmod1,instuffmod2;
  ofstream sigh;
  string countrystr, continentstr, mineralstr, worldstr,path,plus, inputstr, Rawout, Summary, mine, field;
  string next, preamble, postamble, filly, brack1, brack2, whichone,output,att,slash,txt,m, input, csv, whichoption;
  string interaction, recycleline, demandline, Mrecycleline, Mdemandline,country, continent, mineral, whichcontinent;
  vector<float> productiontemp, cproductiontemp, Mproductiontemp,recdata, demdata, Mrecdata, Mdemdata;
  float recrate, recyear, demrate, demyear, Mrecrate, Mrecyear, Mdemrate, Mdemyear;
  char inputer[200], outputer[200], cCurrentPath[250];
  char *stopstring;
  bool checkme, firsttime, secondtime, thirdtime, foundit;
  double URRtemp, peakyeartemp,peakratetemp,cURRtemp, cpeakyeartemp, cpeakratetemp,MURRtemp, Mpeakyeartemp, Mpeakratetemp;
  double shutoffpercent, initdemand, kDD, k1, k2, k3, k4, whendisc, k5, whenupgrade;
  double gapdelay, foil, fcoal, fgas, maxdemand, maxpop, popinit, poprate, popmidyear,popB;
  double popGamma, coalmax, coalmin, coalrate, coalmidyear, coalB, coalGamma, prodlife, minrecycle;
  double  maxrecycle, raterecycle, midrecyear, gasmax, gasmin, gasrate, gasmidyear;
  int timedelay,i, tempi, somen, j,loc,ii,z, counter, parity, changcounter, discounter, rupter, tare,intbl,intbr, demcnt;
  set<string> countries, continents, minerals, mintype;
  set<string>::iterator it;
  vector<string> Vcontinent, Vmineral, Mtitle, models, vtempstr;
  disr temper;
  changer tempery;
  reservdata temp1;
  reservwelldata temp11;
  vector<production> proddy;
  vector<double> recycler, demandchg;
  vector<reservdata> reservoirdatamine;
  vector<reservwelldata> reservoirdatawell;
  vector<returningdata> data;
  chpref tempmichelle;
  chprefwell tempmichelle2;
  vector<changer> demandchanger;


  // Current folder path is input no more than 250 characters. would be good to not have a character limit...
  for (i=0;i<250;i++)
  {
   cCurrentPath[i] = '%';
  }
  cout<<argv[1]<<endl;
  strcpy(cCurrentPath,argv[1]);
  // this is the current path to where the inputs are and the ouputs should go to :-)
  preamble = cCurrentPath;


  // Initialise strings
  worldstr = "World";
  mineralstr = "Minerals";
  continentstr = "Continents";
  countrystr = "Countries";
  plus = "+";
  mine = "Mine";
  field = "Field";
  Summary = "Raw_Summary";
  slash = "\\";
  csv = ".csv";
  interaction="Interaction";
  postamble=".txt";
  m="models";
  brack1="[";
  brack2="]";
  output="";
  Rawout = "";
  input="";
  att="attempt\\";
  txt=".txt";
  filly = preamble + slash+input+interaction+csv;
  strcpy(inputer,filly.c_str());

  // the interactions csv file.
  instuffmod.open(inputer);
  j=0;
  while (instuffmod.good())
  {
    // loop over the interaction inputs.
    getline(instuffmod, next, '\n');
    if (next!="")
    {
       vtempstr = splitstring(next,',');
       if (vtempstr.size()>1)
       {
          next = vtempstr.at(1);
       }
       else
       {
          cout<<"There are issues";
       }
    }
    if (j==0)
    {
       shutoffpercent = strtod(next.c_str(), &stopstring);
    }
    if (j==1)
    {
       timedelay=(int) strtod(next.c_str(), &stopstring);
    }
    if (j==2)
    {
       initdemand=strtod(next.c_str(), &stopstring);
    }
    if (j==3)
    {
       kDD = strtod(next.c_str(), &stopstring);
    }
    if (j==4)
    {
       maxdemand = strtod(next.c_str(), &stopstring);
    }
    if (j==5)
    {
       k1 = strtod(next.c_str(), &stopstring);
    }
    if (j==6)
    {
       k2 = strtod(next.c_str(), &stopstring);
    }
    if (j==7)
    {
       k3 = strtod(next.c_str(), &stopstring);
    }
    if (j==8)
    {
       k4 = strtod(next.c_str(), &stopstring);
    }
    if (j==9)
    {
       whendisc = strtod(next.c_str(), &stopstring);
    }
    if (j==10)
    {
       k5 = strtod(next.c_str(), &stopstring);
    }
    if (j==11)
    {
       whenupgrade = strtod(next.c_str(), &stopstring);
    }
    if (j==12)
    {
       gapdelay = strtod(next.c_str(), &stopstring);
    }
    if (j==13)
    {
       maxpop = strtod(next.c_str(), &stopstring);
    }
    if (j==14)
    {
       popinit = strtod(next.c_str(), &stopstring);
    }
    if (j==15)
    {
       poprate = strtod(next.c_str(), &stopstring);
    }
    if (j==16)
    {
       popmidyear = strtod(next.c_str(), &stopstring);
    }
    if (j==17)
    {
       popB = strtod(next.c_str(), &stopstring);
    }
    if (j==18)
    {
       popGamma = strtod(next.c_str(), &stopstring);
    }
    if (j==19)
    {
       prodlife = strtod(next.c_str(), &stopstring);
    }
    if (j==20)
    {
       minrecycle = strtod(next.c_str(), &stopstring);
    }
    if (j==21)
    {
       maxrecycle = strtod(next.c_str(), &stopstring);
    }
    if (j==22)
    {
       raterecycle = strtod(next.c_str(), &stopstring);
    }
    if (j==23)
    {
       midrecyear = strtod(next.c_str(), &stopstring);
    }
    j++;
  }
  // just need to convert the recycler into a list (TODO should be a struc...)
  recycler.push_back(0);//doesn't do anything.
  recycler.push_back(prodlife);
  recycler.push_back(minrecycle);
  recycler.push_back(maxrecycle);
  recycler.push_back(raterecycle);
  recycler.push_back(midrecyear);

  // below are now obsolete, but figured this would be the quickest way to bin it, can revive it easily.
  foil = 1;
  fcoal = 1;
  fgas = 1;
  coalmax = 100;
  coalmin = 29.5;
  coalrate = 0.03;
  coalmidyear = 1966;
  coalB = 10;
  coalGamma = 25;
  gasmax = 27;
  gasmin = 0;
  gasrate = 0.03;
  gasmidyear = 1960;
  whichoption = "all";
  // change back to all ---> work on tidying up!
  // note demandchanger is obsolete.

  // mine inputs file
  filly = preamble + slash+input+mine+csv;
  strcpy(inputer,filly.c_str());
  //cout<<inputer<<endl;
  instuffmod1.open(inputer);
  j=0;
  while (instuffmod1.good())
  {
    getline(instuffmod1, next, '\n');
    if ((j>0)&&(next!=""))
    {
       vtempstr = splitstring(next,',');
       checkme = checkstringvec(vtempstr,16);
       if ((vtempstr.size()>16)&&(checkme))
       {
           temp1.type = "unused"; // type is currently obsolete.
           temp1.title = vtempstr.at(0)+plus+vtempstr.at(1)+plus+vtempstr.at(2)+plus+vtempstr.at(3)+plus+vtempstr.at(4)+plus+vtempstr.at(5);
           temp1.founditwhen = strtod(vtempstr.at(6).c_str(),&stopstring);
           temp1.Max_prodLOW = strtod(vtempstr.at(7).c_str(),&stopstring);
           temp1.Max_prodHIGH = strtod(vtempstr.at(8).c_str(),&stopstring);
           temp1.MinelifeLOW = strtod(vtempstr.at(9).c_str(),&stopstring);
           temp1.MinelifeHIGH = strtod(vtempstr.at(10).c_str(),&stopstring);
           temp1.Max_prodCY = strtod(vtempstr.at(11).c_str(),&stopstring);
           temp1.Max_prodRATE = strtod(vtempstr.at(12).c_str(),&stopstring);
           temp1.minesonlinerate = strtod(vtempstr.at(13).c_str(),&stopstring);
           temp1.ramping_time = strtod(vtempstr.at(14).c_str(),&stopstring);
           temp1.mintime = strtod(vtempstr.at(15).c_str(),&stopstring);
           temp1.URR_basin = strtod(vtempstr.at(16).c_str(),&stopstring);
           temp1.abort = -1;
           if ((vtempstr.at(17)!="NA")&&(vtempstr.at(17)!=""))
           {
             temp1.abort = strtod(vtempstr.at(17).c_str(),&stopstring);
           }
           if (vtempstr.size()>18)
           {
             if ((vtempstr.at(18) != "NA")&&(vtempstr.at(18)!=""))
             {
               temp1.max_capacity = strtod(vtempstr.at(18).c_str(),&stopstring);
             }
             else
             {
               temp1.max_capacity = -1;
             }
           }
           else
           {
              temp1.max_capacity = -1;
           }
           if (vtempstr.size()>21)
           {
             if ((vtempstr.at(19)!="NA")&&(vtempstr.at(19)!=""))
             {
                tempmichelle.year = strtod(vtempstr.at(19).c_str(),&stopstring);
                if ((vtempstr.at(20)!="NA")&&(vtempstr.at(20)!=""))
                {
                  tempmichelle.minesonlinerate = strtod(vtempstr.at(20).c_str(),&stopstring);
                }
                else
                {
                  tempmichelle.minesonlinerate = temp1.minesonlinerate;
                }
                if ((vtempstr.at(21)!="NA")&&(vtempstr.at(21)!=""))
                {
                  tempmichelle.max_capacity = strtod(vtempstr.at(21).c_str(),&stopstring);
                }
                else
                {
                  tempmichelle.max_capacity = -1;
                }
                temp1.changedpreferences.push_back(tempmichelle);
             }
           }
           somen = 22;
           while (somen+2<vtempstr.size())
           {
             if ((vtempstr.at(somen)!="NA")&&(vtempstr.at(somen)!="")&&(vtempstr.at(somen+1)!="NA")&&(vtempstr.at(somen+1)!="")&&(vtempstr.at(somen+2)!="NA")&&(vtempstr.at(somen+2)!=""))
             {
               temper.startdisr = strtod(vtempstr.at(somen).c_str(),&stopstring);
               temper.enddisr = strtod(vtempstr.at(somen+1).c_str(),&stopstring);
               temper.intmines = 1;
               temper.endmines = strtod(vtempstr.at(somen+2).c_str(),&stopstring);
               temp1.disruptions.push_back(temper);
             }
             somen=somen+3;
           }
           reservoirdatamine.push_back(temp1);
           temp1.disruptions.clear();
           temp1.overrider.clear(); // now obsolete.
           temp1.changedpreferences.clear();
       }
       else
       {
         temp1.max_capacity = -1;
       }
    }
    j++;
  }


  // scan over the field inputs
  filly = preamble + slash+input+field+csv;
  strcpy(inputer,filly.c_str());
  //cout<<inputer<<endl;
  instuffmod2.open(inputer);
  j=0;
  while (instuffmod2.good())
  {
    getline(instuffmod2, next, '\n');
    if ((j>0)&&(next!=""))
    {
       vtempstr = splitstring(next,',');
       checkme = checkstringvec(vtempstr,16);
       if ((vtempstr.size()>16)&&(checkme))
       {
           temp11.type = "unused"; // type is currently obsolete.
           temp11.whencross = 0; // whencross is obsolete.
           temp11.title = vtempstr.at(0)+plus+vtempstr.at(1)+plus+vtempstr.at(2)+plus+vtempstr.at(3)+plus+vtempstr.at(4)+plus+vtempstr.at(5);
           temp11.founditwhen = strtod(vtempstr.at(6).c_str(),&stopstring);
           temp11.whenparity = strtod(vtempstr.at(7).c_str(), &stopstring);
           temp11.rampup_time = strtod(vtempstr.at(8).c_str(), &stopstring);
           temp11.URRwtoR0 = strtod(vtempstr.at(9).c_str(), &stopstring);
           temp11.URRwtoURRr = strtod(vtempstr.at(10).c_str(), &stopstring);
           temp11.powernum = strtod(vtempstr.at(11).c_str(), &stopstring);
           temp11.maximwell = strtod(vtempstr.at(12).c_str(), &stopstring);
           temp11.numberwells = strtod(vtempstr.at(13).c_str(), &stopstring);
           temp11.howmanyfields = strtod(vtempstr.at(14).c_str(), &stopstring);
           temp11.fieldsrate = strtod(vtempstr.at(15).c_str(), &stopstring);
           temp11.URR_basin = strtod(vtempstr.at(16).c_str(), &stopstring);
           temp11.abort = -1;
           if ((vtempstr.at(17)!= "NA")&&(vtempstr.at(17)!=""))
           {
             temp11.abort = strtod(vtempstr.at(17).c_str(), &stopstring);
           }
           if (vtempstr.size()>18)
           {
             if ((vtempstr.at(18) != "NA")&&(vtempstr.at(18)!=""))
             {
               temp11.max_capacity = strtod(vtempstr.at(18).c_str(),&stopstring);
             }
             else
             {
               temp11.max_capacity = -1;
             }
           }
           else
           {
              temp11.max_capacity = -1;
           }
           if (vtempstr.size()>21)
           {
             if ((vtempstr.at(19)!="NA")&&(vtempstr.at(19)!=""))
             {
               tempmichelle2.year = strtod(vtempstr.at(19).c_str(),&stopstring);
               if ((vtempstr.at(20)!="NA")&&(vtempstr.at(20)!=""))
               {
                 tempmichelle2.wellsonlinerate = strtod(vtempstr.at(20).c_str(),&stopstring);
               }
               else
               {
                 tempmichelle2.wellsonlinerate = temp11.whenparity;
               }
               if ((vtempstr.at(21)!="NA")&&(vtempstr.at(21)!=""))
               {
                 tempmichelle2.max_capacity = strtod(vtempstr.at(21).c_str(),&stopstring);
               }
               else
               {
                 tempmichelle2.max_capacity = 1;
               }
               temp11.changedpreferences.push_back(tempmichelle2);
             }
           }
           somen = 22;
           while (somen+2<vtempstr.size())
           {
             if ((vtempstr.at(somen)!="NA")&&(vtempstr.at(somen)!="")&&(vtempstr.at(somen+1)!="NA")&&(vtempstr.at(somen+1)!="")&&(vtempstr.at(somen+2)!="NA")&&(vtempstr.at(somen+2)!=""))
             {
               temper.startdisr = strtod(vtempstr.at(somen).c_str(),&stopstring);
               temper.enddisr = strtod(vtempstr.at(somen+1).c_str(),&stopstring);
               temper.intmines = 1;
               temper.endmines = strtod(vtempstr.at(somen+2).c_str(),&stopstring);
               temp11.disruptions.push_back(temper);
             }
             somen=somen+3;
           }
           reservoirdatawell.push_back(temp11);
           temp11.disruptions.clear();
           temp11.changedpreferences.clear();
       }
       else
       {
           cout<<"issues exist"<<endl;
       }
    }
    j++;
  }
  // now the data is inputted, run the model.

  data=completemodel(reservoirdatawell,reservoirdatamine, shutoffpercent, timedelay, initdemand,  kDD, maxdemand,  k1, k2, k3,k4, whendisc,k5,whenupgrade, gapdelay, foil, fcoal, fgas, maxpop, popinit, poprate, popmidyear, popB, popGamma,coalmax, coalmin, coalrate, coalmidyear, coalB, coalGamma, gasmax, gasmin, gasrate, gasmidyear, whichoption, demandchanger, recycler);
  /// model has now finished, everything lives in data
  // from here on in main just creating complex csv files.
  // step 1: produce individual csv files of each run completed.
  ofstream outstuff[(int)(data.size()+1)];
  ofstream outfinal;
  ofstream COUNTRY, COUNTRIES, WORLD, MWORLD;
  vector<float> URRs, Peakyears, Peakrates, firstyears, lastyears;
  float  firstyear, lastyear;
  vector<string> titler;
  firstyear = -1;
  lastyear = -1;
  for (z=1;z<=data.size();z++)
  {
        proddy=data.at(z-1).prod;
        firstyears.push_back(proddy.front().year);
        lastyears.push_back(proddy.back().year);
        if ((firstyear==-1)||(proddy.front().year<firstyear))
        {
           firstyear = proddy.front().year;
        }
        if ((lastyear==-1)||(proddy.back().year>lastyear))
        {
           lastyear = proddy.back().year;
        }
        URRs.push_back(0);
        Peakyears.push_back(0);
        Peakrates.push_back(0);
        for (ii=0;ii<proddy.size();ii++)
        {
          URRs.at(z-1)=URRs.at(z-1) + proddy.at(ii).amount;
          if (proddy.at(ii).amount>Peakrates.at(z-1))
          {
             Peakrates.at(z-1) = proddy.at(ii).amount;
             Peakyears.at(z-1) = proddy.at(ii).year;
          }
        }
    }


    instuffmod.close();
    instuffmod1.close();
    instuffmod2.close();

    //step 2, combine to create one single summary csv file.

    filly = preamble + slash+output+Summary+csv;
    //cout<<filly<<endl;
    strcpy(outputer,filly.c_str());
    outfinal.open(outputer);
    if (outfinal.fail())
    {
       cout<<"doh"<<endl;
       cout<<filly<<endl;
    }
    else
    {
       outfinal<<"Continent,Country,Region,Mineral,Type,Number,URR,Peak Year,Peak Rate";
       for (i=(int)firstyear;i<=(int)lastyear;i++)
       {
           outfinal<<","<<i;
       }
       outfinal<<endl;
       for (z=1;z<=data.size();z++)
       {
           titler = splitstring(data.at(z-1).title,'+');
           if (titler.size() != 6)
           {
              cout<<"odd the title is wrong: "<<data.at(z-1).title<<" "<<titler.size()<<endl;
              outfinal<<"odd,the,title,is,wrong,"<<data.at(z-1).title<<",";
           }
           else
           {
              countries.insert(titler.at(1));
              continents.insert(titler.at(0));
              minerals.insert(titler.at(3));
              mintype.insert(titler.at(3)+"+"+titler.at(4));
              for (i=0;i<titler.size();i++)
              {
                  outfinal<<titler.at(i)<<",";
              }
           }
           outfinal<<URRs.at(z-1)<<","<<Peakyears.at(z-1)<<","<<Peakrates.at(z-1)<<",";
           for (i=0;i<firstyears.at(z-1)-firstyear;i++)
           {
               outfinal<<",";
           }
           proddy=data.at(z-1).prod;
           for (i=0;i<proddy.size();i++)
           {
               outfinal<<proddy.at(i).amount<<",";
           }
           outfinal<<endl;
       }
    }

  return 0;
}







vector<string> splitstring(string str,char delim)
{
  // splits a string based on the deliminator, and returns a vector
  int i,firstone;
  firstone = 0;
  vector<string> vstr;
  int counter;
  counter=0;
  for (i=0;i<str.size();i++)
  {
    if (str.at(i)==delim)
    {
       vstr.push_back(str.substr(firstone,counter));
       counter=0;
       firstone = i+1;
    }
    else
    {
       counter++;
    }
  }
  vstr.push_back(str.substr(firstone,str.size()-firstone));
  return vstr;
};


bool checkstringvec(vector<string> vecstr, int howmany)
{
  // looks at a vectors and makes sure lenght is atleast howmany and there are no "" strings in the range.
  bool checkresult;
  int i;
  checkresult = true;
  if (vecstr.size()>howmany)
  {
    for (i=0;i<=howmany;i++)
    {
      if (vecstr.at(i)=="")
      {
        checkresult = false;
      }
    }
  }
  else
  {
    checkresult=false;
  }
  return checkresult;
};








double numberwellsreally(double URR_basin, double wellsonlinerate)
{
  // TODO
  return ceil(URR_basin*wellsonlinerate+1);
};




double numberwellsonline(double cumm_prod, double wellsonlinerate)
{
  //TODO
  double wells;
  wells = ceil(wellsonlinerate*cumm_prod+1);
  return wells;
};

double URRfromwells(double rate,double oldURR, double numwells, double cummwells )
{
  // returns the URR of the field for that started came online
  double newURR, URRofthewell;
  newURR=rate*log(cummwells+1);
  URRofthewell=(newURR-oldURR)/numwells;
  return URRofthewell;
};

double peakwellprod(double URRwell, double rate)
{
  //TODO
  return rate*URRwell;
};

double URRremaining(double URRwell, double rate)
{
  // TODO
  return rate*URRwell;
};

double plateau_time(double URR_w,double URR_r,double r0,double rampup_time)
{
  // returns the time spent plateauing
  return (URR_w-URR_r)/r0 - 0.5*rampup_time;
};

double end_time(double tp,double start_year,double rampup_time,double shutoffpercent,double URR_r,double r0)
{
  return tp+start_year+rampup_time-log(shutoffpercent)*URR_r/(r0*(1-shutoffpercent));
};

double cumm_well(double time,double URR_w, double URR_r, double r0, double start_year, double shutoffpercent, double rampup_time)
{
  // determines the cumulative production of a well, given the wells characteristics.
  double cumm, tp, t_end;
  if (time<=start_year)
  {
    // hasn't commenced...
    cumm=0;
  }
  if ((time>start_year) && (time<=start_year+rampup_time))
  {
    // in the ramp stage of production.
    cumm=r0*(time*time-2*start_year*time+start_year*start_year)/(2*rampup_time);
  }
  if (time>start_year+rampup_time)
  {
    // is either plateauing, declining or completed.
    // tp is the time spent plateauing
    tp=plateau_time(URR_w,URR_r,r0,rampup_time);

    if (time<=tp+start_year+rampup_time)
    {
      // plateauing. cumulative production is cp in ramp + cp in plateau
      cumm=r0*rampup_time/2.0+r0*(time-start_year-rampup_time);
    }
    if (time>tp+start_year+rampup_time)
    {
      t_end=end_time(tp,start_year,rampup_time,shutoffpercent,URR_r,r0);
      // well shutdown year
      if (time>t_end)
      {
        // well has finished.
        cumm=URR_w;
      }
      else
      {
        // evil equation, well in exponential decline.
        cumm=(URR_w-URR_r)-(URR_r/(1-shutoffpercent))*(exp((-r0*(1-shutoffpercent)/URR_r)*(time-tp-start_year-rampup_time)))+URR_r/(1-shutoffpercent);
      }
    }
  }
  return cumm;
};

double well_life(double URR_w, double URR_r, double r0, double start_year, double shutoffpercent, double rampup_time)
{
  //works out the year the well will shut down.
  double tp, t_end;
  tp=plateau_time(URR_w,URR_r,r0,rampup_time);
  t_end=end_time(tp,start_year,rampup_time,shutoffpercent,URR_r,r0);
  return ceil(t_end+1);
};




double prodwellattimet(double URR_w, double URR_r, double r0, double start_year, double t, double shutoffpercent, double rampup_time)
{
  // calculate the production - determined via cumulative production
  double wellprod;
  wellprod=cumm_well(t+0.5,URR_w,URR_r,r0,start_year,shutoffpercent,rampup_time)-cumm_well(t-0.5,URR_w,URR_r,r0,start_year,shutoffpercent,rampup_time);
  return wellprod;
};





bool splitterpercentremain(const cwells& elem1, const cwells& elem2)
{
  // is the condition to sort remaining fields on.
  // it shutsdown the fields that have used up (as a fraction) the most amount of oil or gas.
  return (elem1.remainres/elem1.initialres)<(elem2.remainres/elem2.initialres);
};






wellpair shuttingwells(vector<cwells> currentwells, double howmanyshutdown)
{
  // shuts down fields as desired.
  int j;
  vector<cwells> shutdownwells, welldata, remainingwells;
  wellpair temp;
  double howmanywells, fixit;
  welldata=currentwells;
  howmanywells=welldata.size();
  if (howmanyshutdown<=howmanywells)
  {
    sort(welldata.begin(),welldata.end(),splitterpercentremain);
    for (j=0;j<howmanyshutdown;j++)
    {
      shutdownwells.push_back(welldata.at(j));
    }
    for (j=int(howmanyshutdown);j<howmanywells;j++)
    {
      remainingwells.push_back(welldata.at(j));
    }
    temp.shutdown=shutdownwells;
    temp.remaining=remainingwells;
    temp.fixit=howmanyshutdown-shutdownwells.size();
  }
  else
  {
    cout<<"you want to shut too many wells "<<currentwells.size()<<" "<<howmanyshutdown<<endl;
    temp.shutdown=welldata;
    temp.remaining=remainingwells;
    temp.fixit=howmanyshutdown-welldata.size();
  }
  return temp;
};



vector<cwells> ordershutwells(vector<cwells> removedwells,double oldcummwellsshutdown,double cummwellsshutdown)
{
  // just returns the removed fields as far as I can tell...
  int i;
  vector<cwells> wells;
  cwells temp2;
  if (removedwells.size()!=cummwellsshutdown-oldcummwellsshutdown)
  {
    cout<<"number disagreement"<<endl;
  }
  for (i=1; i<=removedwells.size();i++)
  {
    temp2.startyear=removedwells.at(i-1).startyear;
    temp2.endyear=removedwells.at(i-1).endyear;
    temp2.remainres=removedwells.at(i-1).remainres;
    temp2.initialres=removedwells.at(i-1).initialres;
    wells.push_back(temp2);
  }
  return wells;
};



wellpainful wellmodelproc(int& yearfind, int& timedelay, double& futuretime,vector<double>& yearlybasinprod, vector<cwells>& currentwells,  vector<cwells>& oldcurrentwells, double& URRwtoURRr, double& URRwtoR0,  double& shutoffpercent, double& rampup_time, int i, double& totalwells, double& oldtotalwells, vector<cwells>& shutdownwells,double& maxprod, double& maybemaxprod, double max_capacity , int& oldcountingwells, int& countingwells, double& oldcummwellsshutdown, double& cummwellsshutdown, double& maxoffline,  int &indisruption, int& oldindisruption, vector<disr>& disruptions, double& whichdisruption, int& backtonormal, double& predisruptionwells, double& cumm_prod, double& wellsy, double& numberwells, bool& gonk, double& oldwellsonlinerate, double& wellsonlinerate, double& oldcumm_prod, double& realnumwells, int& basinlifechecker, double& URR_basin, double& powernum, double& whencross ,double& k2gap, double& sup,int& fixer, vector<double>& stupid, int& yearfieldfound, double& maximwell, double& oldwellsURR)
{
  // this calculates oil or gas production from a specific area (e.g. UK North Sea)
  // step one initialise variable.
  vector<double> maybeprod, reallyoldedata, yearlybasinprodmod;
  vector<cwells> removedwells, oldremovedwells, temporaryshutdownwells,tempwells;
  cwells temper, dataofwell, temp2;
  vector<int> shutplaces;
  double totwell, oldtotwell, wellrnum, lifewell;
  double itnum, cutters, lifeofwell, URRw, HighU, LowU;
  double oldwellsonlinerateb, deltacumm_prod, tempdob, supply, temperybob, counter;
  int yy, iii, jj,a,b, kk;
  bool resetcumm;
  wellpainful returngah;
  wellpair shutter;
  oldwellsonlinerateb=oldwellsonlinerate;
  cutters=0;
  // finally.
  // updating currentwells (so we ditch any well that has shutdown.)
  if (!currentwells.empty())
  {
    oldcurrentwells.clear();
    oldcurrentwells=currentwells;
    currentwells.clear();
    for (iii=1;iii<=oldcurrentwells.size();iii++)
    {
      if ((i<oldcurrentwells.at(iii-1).endyear+1)&&(oldcurrentwells.at(iii-1).remainres>0)) // then its not dead
      {
        temper.startyear=oldcurrentwells.at(iii-1).startyear;
        temper.endyear=oldcurrentwells.at(iii-1).endyear;
        temper.initialres=oldcurrentwells.at(iii-1).initialres;
        temper.remainres=oldcurrentwells.at(iii-1).remainres-prodwellattimet(temper.initialres, temper.initialres*URRwtoURRr, temper.initialres*URRwtoR0, temper.startyear,yearfind+timedelay+ i-1, shutoffpercent, rampup_time);//might be no -1 not sure
        currentwells.push_back(temper);
      }
    }
  }
  if (totalwells>oldtotalwells)
  {
    // bring some wells online
    totwell=totalwells;
    oldtotwell=oldtotalwells;
    if (!shutdownwells.empty())
    {
      // firstly bring back previously shut down wells.
      if (totwell-oldtotwell<shutdownwells.size())
      {
        wellrnum=totwell-oldtotwell;
      }
      else
      {
        wellrnum=shutdownwells.size();
      }
      // this will be the new shutdownwells
      temporaryshutdownwells.clear();
      for (jj=0;jj<shutdownwells.size()-wellrnum;jj++)
      {
        temporaryshutdownwells.push_back(shutdownwells.at(jj));
      }
      shutplaces.clear();
      // put the wells online
      for (jj=1;jj<=(int)(wellrnum);jj++)
      {
        dataofwell=shutdownwells.at((int)(shutdownwells.size()-jj));
        if (dataofwell.remainres<0)
        {
          cout<<"warning remaining reserves are negative, panic if the following is smaller than -1"<<dataofwell.remainres<<endl;
          dataofwell.remainres=0;
        }
        lifewell=well_life(dataofwell.remainres, dataofwell.remainres*URRwtoURRr, dataofwell.remainres*URRwtoR0, yearfind+timedelay+i-1, shutoffpercent, rampup_time);
        if (lifewell>futuretime)
        {
          // so need to extend the size of the vector of production data.
          for (a=(int)futuretime+1; a<=(int)(lifewell);a++)
          {
            yearlybasinprod.push_back(0);
          }
          futuretime=(int)lifewell;
        }
        if (maybeprod.size()<=lifewell-yearfind-timedelay)
        {
          // similarly create more space
          itnum=lifewell-yearfind-timedelay-maybeprod.size()+1;
          for (b=0;b<itnum;b++)
          {
            maybeprod.push_back(0);
          }
        }
        if (lifewell-yearfieldfound+1>=stupid.size())
        {
          // create more space
          itnum=lifewell-yearfieldfound-stupid.size()+2;
          for (b=0;b<itnum;b++)
          {
            stupid.push_back(0);
          }
        }
        if (max_capacity!=-1)
        {
          // so have an upper bound and need to worry about it.
          for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifewell);b++)
          {
            maybeprod.at((int)(b-yearfind-timedelay))=stupid.at((int)(b-yearfieldfound))+prodwellattimet(dataofwell.remainres, dataofwell.remainres*URRwtoURRr, dataofwell.remainres*URRwtoR0, yearfind+timedelay+i-1, b, shutoffpercent, rampup_time);
            if (maybeprod.at((int)(b-yearfind-timedelay))>maybemaxprod)
            {
              maybemaxprod=maybeprod.at((int)(b-yearfind-timedelay));
            }
          }
          if (maybemaxprod<=max_capacity)
          {
            maxprod=maybemaxprod;
            for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifewell);b++)
            {
              yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+prodwellattimet(dataofwell.remainres, dataofwell.remainres*URRwtoURRr, dataofwell.remainres*URRwtoR0, yearfind+timedelay+i-1, b, shutoffpercent, rampup_time); // probably plenty wrong here
              stupid.at((int)(b-yearfieldfound))=stupid.at((int)(b-yearfieldfound))+prodwellattimet(dataofwell.remainres, dataofwell.remainres*URRwtoURRr, dataofwell.remainres*URRwtoR0, yearfind+timedelay+i-1, b, shutoffpercent, rampup_time);
            }
            temper.startyear=yearfind+timedelay+i-1;
            temper.endyear=lifewell;
            temper.initialres=dataofwell.remainres;
            temper.remainres=dataofwell.remainres-prodwellattimet(dataofwell.remainres, dataofwell.remainres*URRwtoURRr, dataofwell.remainres*URRwtoR0, yearfind+timedelay+i-1, (int)(yearfind+timedelay+i-1), shutoffpercent, rampup_time);// might need to axe the ith year production...
            currentwells.push_back(temper);
          }
          else
          {
            maybemaxprod=maxprod;
            cutters=cutters+1;
            shutplaces.push_back(shutdownwells.size()-jj);
          }
        }
        else
        {
          // no upper bound, just add production.
          for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifewell);b++)
          {
            stupid.at((int)(b-yearfieldfound))=stupid.at((int)(b-yearfieldfound))+prodwellattimet(dataofwell.remainres, dataofwell.remainres*URRwtoURRr, dataofwell.remainres*URRwtoR0, yearfind+timedelay+i-1, b, shutoffpercent, rampup_time);
            yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+prodwellattimet(dataofwell.remainres, dataofwell.remainres*URRwtoURRr, dataofwell.remainres*URRwtoR0, yearfind+timedelay+i-1, b, shutoffpercent, rampup_time); // probably plenty wrong here
          }
          temper.startyear=yearfind+timedelay+i-1;
          temper.endyear=lifewell;
          temper.initialres=dataofwell.remainres;
          temper.remainres=dataofwell.remainres-prodwellattimet(dataofwell.remainres, dataofwell.remainres*URRwtoURRr, dataofwell.remainres*URRwtoR0, yearfind+timedelay+i-1, (int)(yearfind+timedelay+i-1), shutoffpercent, rampup_time);// might need to axe the ith year production...
          currentwells.push_back(temper);
        }
      }
      for (jj=shutplaces.size()-1;jj>=0;jj--)
      {
        temporaryshutdownwells.push_back(shutdownwells.at(shutplaces.at(jj)));
      }
      if (totwell<shutdownwells.size()+oldtotwell)
      {
        oldtotwell=totwell;
      }
      else
      {
        oldtotwell=shutdownwells.size()+oldtotwell;
      }
      shutdownwells.clear();
      shutdownwells=temporaryshutdownwells;
    }
    // if not enough shut wells, then we need to put new fields online.
    if (totwell>oldtotwell)
    {
      oldcountingwells=countingwells;
      countingwells = (int)(countingwells + totwell-oldtotwell);
      LowU=oldwellsURR/URR_basin;
      HighU=pow(countingwells/realnumwells,powernum);
      if (URR_basin*(HighU-LowU)/(countingwells-oldcountingwells)<maximwell)
      {
        URRw=URR_basin*(HighU-LowU)/(countingwells-oldcountingwells);
      }
      else
      {
        URRw=maximwell;
      }
      oldwellsURR=oldwellsURR+(countingwells-oldcountingwells)*URRw;
      lifeofwell=well_life(URRw, URRw*URRwtoURRr, URRw*URRwtoR0, yearfind+timedelay+i-1, shutoffpercent, rampup_time);
      if (lifeofwell>futuretime)
      {
        for (a=(int)futuretime+1;a<=(int)(lifeofwell);a++)
        {
          yearlybasinprod.push_back(0);
        }
        futuretime=(int)(lifeofwell);
      }
      if (max_capacity!=-1)
      {
        for (jj=(int)(oldtotwell+1);jj<=(int)(totwell);jj++)
        {
          if (maybeprod.size()<=lifeofwell-yearfind-timedelay)
          {
            itnum=lifeofwell-yearfind-timedelay-maybeprod.size()+1;
            for (b=0;b<=itnum;b++)
            {
              maybeprod.push_back(0);
            }
          }
          if (lifeofwell-yearfieldfound+1>=stupid.size())
          {
            itnum=lifeofwell-yearfieldfound-stupid.size()+2;
            for (b=0;b<itnum;b++)
            {
              stupid.push_back(0);
            }
          }
          for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifeofwell);b++)
          {
            maybeprod.at((int)(b-yearfind-timedelay))=stupid.at((int)(b-yearfieldfound))+yearlybasinprod.at((int)(b-yearfind-timedelay))+prodwellattimet(URRw, URRw*URRwtoURRr, URRw*URRwtoR0, yearfind + timedelay+i-1, b, shutoffpercent, rampup_time);
            if (maybeprod.at((int)(b-yearfind-timedelay))>maybemaxprod)
            {
              maybemaxprod=maybeprod.at((int)(b-yearfind-timedelay));
            }
          }
          if (maybemaxprod<=max_capacity)
          {
            maxprod=maybemaxprod;
            for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifeofwell);b++)
            {
              stupid.at((int)(b-yearfieldfound))=stupid.at((int)(b-yearfieldfound))+prodwellattimet(URRw, URRw*URRwtoURRr, URRw*URRwtoR0, yearfind + timedelay+i-1, b, shutoffpercent, rampup_time);
              yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+prodwellattimet(URRw, URRw*URRwtoURRr, URRw*URRwtoR0, yearfind + timedelay+i-1, b, shutoffpercent, rampup_time);
            }
            temper.startyear=yearfind +timedelay +i-1;
            temper.endyear=lifeofwell;
            temper.remainres=URRw-prodwellattimet(URRw, URRw*URRwtoURRr, URRw*URRwtoR0, yearfind + timedelay+i-1, yearfind + timedelay+i-1, shutoffpercent, rampup_time);
            temper.initialres=URRw;
            currentwells.push_back(temper);
          }
          else
          {
            maybemaxprod=maxprod;
            temper.startyear=yearfind +timedelay +i-1;
            temper.endyear=lifeofwell;
            temper.remainres=URRw;
            temper.initialres=URRw;
            shutdownwells.push_back(temper);
            cutters=cutters+1;
          }
        }
      }
      else
      {
        if (lifeofwell-yearfieldfound+1>=stupid.size())
        {
          itnum=lifeofwell-yearfieldfound-stupid.size()+2;
          for (b=0;b<itnum;b++)
          {
            stupid.push_back(0);
          }
        }
        for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifeofwell);b++)
        {
          stupid.at((int)(b-yearfieldfound))=stupid.at((int)(b-yearfieldfound))+prodwellattimet(URRw, URRw*URRwtoURRr, URRw*URRwtoR0, yearfind + timedelay+i-1, b, shutoffpercent, rampup_time);
          yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+(totwell-oldtotwell)*prodwellattimet(URRw, URRw*URRwtoURRr, URRw*URRwtoR0, yearfind + timedelay+i-1, b, shutoffpercent, rampup_time);
        }
        for (b=1;b<=(int)(totwell-oldtotwell);b++)
        {
          temper.startyear=yearfind+timedelay+i-1;
          temper.endyear=lifeofwell;
          temper.remainres=URRw-prodwellattimet(URRw, URRw*URRwtoURRr, URRw*URRwtoR0, yearfind + timedelay+i-1, yearfind + timedelay+i-1, shutoffpercent, rampup_time);
          temper.initialres=URRw;
          currentwells.push_back(temper);
        }
      }
    }
  }
  // This bit removes some currentwells to shutdown wells
  if (totalwells<oldtotalwells)
  {
    oldcummwellsshutdown=cummwellsshutdown;
    cummwellsshutdown=cummwellsshutdown+(oldtotalwells-totalwells);
    shutter=shuttingwells(currentwells,oldtotalwells-totalwells);
    removedwells=shutter.shutdown;
    totalwells=totalwells+shutter.fixit;
    cummwellsshutdown=cummwellsshutdown-shutter.fixit;
    currentwells=shutter.remaining;
    oldremovedwells=removedwells;
    removedwells.clear();
    reallyoldedata.clear();
    for (iii=1;iii<=oldremovedwells.size();iii++)
    {
      temper.startyear=oldremovedwells.at(iii-1).startyear;
      temper.endyear=oldremovedwells.at(iii-1).endyear;
      temper.initialres=oldremovedwells.at(iii-1).initialres;
      temper.remainres=oldremovedwells.at(iii-1).remainres+prodwellattimet(temper.initialres, temper.initialres*URRwtoURRr, temper.initialres*URRwtoR0, temper.startyear, yearfind+timedelay+i-1, shutoffpercent, rampup_time);
      removedwells.push_back(temper);
    }
    if (removedwells.size()!=cummwellsshutdown-oldcummwellsshutdown)
    {
      cout<<"number disagreement"<<endl;
    }
    for (b=1;b<=(int)(removedwells.size());b++)
    {
      shutdownwells.push_back(removedwells.at(b-1));
    }
    maxoffline=maxoffline+removedwells.size();
    for (iii=1;iii<=removedwells.size();iii++)
    {
      counter=0;
      for (b=(int)(yearfind+timedelay+i-1);b<=(int)(removedwells.at(iii-1).endyear);b++)
      {
        yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))-prodwellattimet(removedwells.at(iii-1).initialres, removedwells.at(iii-1).initialres*URRwtoURRr, removedwells.at(iii-1).initialres*URRwtoR0, removedwells.at(iii-1).startyear, b, shutoffpercent, rampup_time);
        stupid.at((int)(b-yearfieldfound))=stupid.at((int)(b-yearfieldfound))-prodwellattimet(removedwells.at(iii-1).initialres, removedwells.at(iii-1).initialres*URRwtoURRr, removedwells.at(iii-1).initialres*URRwtoR0, removedwells.at(iii-1).startyear, b, shutoffpercent, rampup_time);
        counter=counter+prodwellattimet(removedwells.at(iii-1).initialres, removedwells.at(iii-1).initialres*URRwtoURRr, removedwells.at(iii-1).initialres*URRwtoR0, removedwells.at(iii-1).startyear, b, shutoffpercent, rampup_time);
      }
    }
  }
  if (yearlybasinprod.size()<=i-2)
  {
    yearlybasinprod.push_back(0);
  }
  oldtotalwells=totalwells;
  // has the disruption ended?
  // continue with the -1 from here onwards!! check iii are iii-1 above
  oldindisruption=indisruption;
  if (indisruption)
  {
    if (disruptions.at((int)(whichdisruption-1)).enddisr==yearfind+i-2)
    {
      indisruption=false;
    }
  }
  if (!disruptions.empty())
  {
    for (kk=1;kk<=disruptions.size();kk++)
    {
      if (disruptions.at(kk-1).startdisr==yearfind+i-1)
      {
        indisruption=true;
        backtonormal=false;
        predisruptionwells=totalwells;
        whichdisruption=kk;
      }
    }
  }
  resetcumm=false;
  if (indisruption)
  {
    if (disruptions.at((int)(whichdisruption-1)).enddisr==yearfind+i-2)
    {
      resetcumm=true;
    }
  }
  if (i==1)
  {
    cumm_prod=0;
  }
  else
  {
    cumm_prod=cumm_prod+yearlybasinprod.at((int)(i-2));
  }
  if (cutters>0)
  {
    totalwells=totalwells-cutters;
    oldtotalwells=oldtotalwells-cutters;
    resetcumm=true;
  }
  if (resetcumm)
  {
    wellsy=totalwells; // could be wrong here
  }
  if (gonk)
  {
    cumm_prod=oldwellsonlinerateb*cumm_prod/wellsonlinerate;
    oldcumm_prod=cumm_prod-yearlybasinprod.at((int)(i-2));
  }
  deltacumm_prod=cumm_prod-oldcumm_prod;
  oldcumm_prod=cumm_prod;
  if (!fixer)
  {
    if (!indisruption)
    {
      temperybob=ceil(((wellsy+wellsonlinerate*(deltacumm_prod/URR_basin) ) +k2gap*wellsy));
      if (temperybob<numberwells)
      {
        totalwells=max(temperybob,1.0); // introduced max with 1.0.
      }
      else
      {
        totalwells=numberwells;
      }
      if ((oldtotalwells==numberwells)&&(totalwells==numberwells))
      {
        wellsy=wellsy;
      }
      else
      {
        wellsy= (   (wellsy+wellsonlinerate*(deltacumm_prod/URR_basin) ) +k2gap*wellsy);
      }
    }
  }
  if (indisruption)
  {
    tempdob=ceil(predisruptionwells*(((disruptions.at((int)(whichdisruption-1)).endmines-disruptions.at((int)(whichdisruption-1)).intmines)*(yearfind+i-1-disruptions.at((int)(whichdisruption-1)).startdisr))/(disruptions.at((int)(whichdisruption-1)).enddisr-disruptions.at((int)(whichdisruption-1)).startdisr)+disruptions.at((int)(whichdisruption-1)).intmines));
    if (tempdob<numberwells)
    {
      if (tempdob>=0)
      {
        totalwells=tempdob;
      }
      else
      {
        totalwells=0;
      }
    }
    else
    {
      totalwells=numberwells;
    }
    wellsy=totalwells;// could be wrong here
  }
  if (yearlybasinprod.at((int)(i))==0)
  {
    if (countingwells-shutdownwells.size()==numberwells)
    {
      basinlifechecker=false;
    }
    else
    {
      totalwells=numberwells;
      fixer=true;
    }
  }
  yearlybasinprodmod=yearlybasinprod;
  supply=yearlybasinprod.at((int)i-1);
  returngah.maxprod=maxprod;
  returngah.maybemaxprod=maybemaxprod;
  returngah.yearlybasinprodmod=yearlybasinprodmod;
  returngah.futuretime=futuretime;
  returngah.oldcurrentwells=oldcurrentwells;
  returngah.currentwells=currentwells;
  returngah.shutdownwells=shutdownwells;
  returngah.totalwells=totalwells;
  returngah.oldtotalwells=oldtotalwells;
  returngah.cumm_prod=cumm_prod;
  returngah.indisruption=indisruption;
  returngah.oldindisruption=oldindisruption;
  returngah.whichdisruption=whichdisruption;
  returngah.backtonormal=backtonormal;
  returngah.predisruptionwells=predisruptionwells;
  returngah.cummwellsshutdown=cummwellsshutdown;
  returngah.oldcummwellsshutdown=oldcummwellsshutdown;
  returngah.basinlifechecker=basinlifechecker;
  returngah.maxoffline=maxoffline;
  returngah.oldcumm_prod=oldcumm_prod;
  returngah.wellsy=wellsy;
  returngah.stupid=stupid;
  returngah.supply=supply;
  returngah.countingwells=countingwells;
  returngah.fixer=fixer;
  returngah.oldcountingwells=oldcountingwells;
  returngah.oldwellsURR=oldwellsURR;
  return returngah;
};


wellpainfulfields fieldsmodel(int& yearfind, int& timedelay,vector<double> & yearlybasinprodmod, vector<vector<cwells> >& currentwells,  vector<vector<cwells> > & oldcurrentwells, double & URRwtoURRr, double & URRwtoR0,  double& shutoffpercent, double& rampup_time, int i, vector<double>& totalwells, vector<double>& oldtotalwells, vector<vector<cwells> > &shutdownwells,vector<double> & maxprod, vector<double> & maybemaxprod, double max_capacity , vector<int> & oldcountingwells, vector<int> & countingwells, vector<double> & oldcummwellsshutdown, vector<double> & cummwellsshutdown, vector<double> & maxoffline, vector<int> &indisruption, vector<int> & oldindisruption, vector<disr>& disruptions, vector<double>& whichdisruption, vector<int>& backtonormal, vector<double>& predisruptionwells, vector<double>& cumm_prod, vector<double> & wellsy, double & numberwells, bool & gonk, vector<double> & oldwellsonlinerate, vector<double> & wellsonlinerate, vector<double> & oldcumm_prod, double & realnumwells, bool & basinlifechecker, double & URR_basin, double & powernum, double & whencross, double & oldfieldstotal, double & fieldstotal, double & fieldsCP, double & totalfields, vector<double> & URR_fields,double & fieldsrate, vector<int> & yearfieldfound, vector<int> & fieldlifechecker, vector<vector<double> > & fieldproduction, vector<double> & fieldtime, double & fieldsy ,double k2gap, double k3smallgap, vector<double> & howmanywells, double & whenparity, vector<int> & fixer, vector<double> & stupid, double & maximwell, vector<double> & oldwellsURR, bool & tripped, double abort)
{
  // this calculates the oil or gas production from a country that has multiple oil or gas regions (e.g. USA)
  wellpainfulfields icky;
  wellpainful icky1;
  int futuretime, j, k,b;
  vector<int> early, late;
  int kk,c;
  double supply, tempers;
  vector<double> temp;
  bool yup, ended;
  double temper, temper2, fieldstotaler;
  vector<cwells> tempclear;
  futuretime=yearfind+timedelay;
  ended=true;
  if (gonk)
  {
    for (j=0;j<oldfieldstotal;j++)
    {
      oldwellsonlinerate.at(j)=wellsonlinerate.at(j);
      wellsonlinerate.at(j)=(howmanywells.at(j)-1)/(whenparity);
    }
  }
  for (j=(int)oldfieldstotal+1;j<=fieldstotal;j++)
  {
    temper=URR_basin*(1-exp(-fieldsrate*(pow(j/totalfields,2))))/(1-exp(-fieldsrate));
    temper2=URR_basin*(1-exp(-fieldsrate*(pow((j-1)/totalfields,2))))/(1-exp(-fieldsrate));
    URR_fields.push_back(temper-temper2);
    yearfieldfound.push_back(i-1);
    oldcurrentwells.push_back(tempclear);
    oldcurrentwells.back().clear();
    currentwells.push_back(tempclear);
    oldcurrentwells.back().clear();
    shutdownwells.push_back(tempclear);
    shutdownwells.back().clear();
    totalwells.push_back(1);
    oldtotalwells.push_back(0);
    wellsy.push_back(1); // maybe 0...
    oldcountingwells.push_back(0);
    countingwells.push_back(0);
    cumm_prod.push_back(0);
    oldcumm_prod.push_back(0);
    maxoffline.push_back(0);
    oldcummwellsshutdown.push_back(0);
    cummwellsshutdown.push_back(0);
    oldindisruption.push_back(false);
    maxprod.push_back(0);
    maybemaxprod.push_back(0);
    fieldlifechecker.push_back(true);
    fieldtime.push_back(yearfieldfound.back());
    temp.clear();
    temp.push_back(0);
    fieldproduction.push_back(temp);
    oldwellsURR.push_back(0);
    fixer.push_back(false);
    tempers=ceil(realnumwells*(URR_fields.at(j-1)/URR_basin));
    if (URR_fields.at(j-1)/maximwell<tempers)
    {
      howmanywells.push_back(tempers);
    }
    else
    {
      cout<<"I have had to change the number of wells by, "<<tempers<<" "<< ceil(URR_fields.at(j-1)/maximwell)<<" Maximwells too low or numberwells too low"<<endl;
      howmanywells.push_back(ceil(URR_fields.at(j-1)/maximwell));
    }
    wellsonlinerate.push_back((howmanywells.back()-1)/(whenparity));
    oldwellsonlinerate.push_back(wellsonlinerate.back());
    yup=true;
    if (!disruptions.empty())
    {
      for (kk=1;kk<=disruptions.size();kk++)
      {
        if ((disruptions.at(kk-1).startdisr<=i-1)&&(disruptions.at(kk-1).enddisr>i-1))
        {
          indisruption.push_back(true);
          backtonormal.push_back(false);
          predisruptionwells.push_back(totalwells.back());
          whichdisruption.push_back(kk);
          yup=false;
        }
      }
    }
    if (yup)
    {
      indisruption.push_back(false);
      backtonormal.push_back(true);
      predisruptionwells.push_back(totalwells.back());
      whichdisruption.push_back(0);
    }
  }
  supply=0;
  for (j=1;j<=fieldstotal;j++)
  {
    if (fieldlifechecker.at(j-1))
    {
      ended=false;
      icky1=wellmodelproc(yearfieldfound.at(j-1),timedelay,fieldtime.at(j-1),fieldproduction.at(j-1),currentwells.at(j-1),oldcurrentwells.at(j-1),URRwtoURRr,URRwtoR0,shutoffpercent,rampup_time,i-yearfieldfound.at(j-1)-timedelay,totalwells.at(j-1),oldtotalwells.at(j-1),shutdownwells.at(j-1),maxprod.at(j-1),maybemaxprod.at(j-1),max_capacity,oldcountingwells.at(j-1),countingwells.at(j-1),oldcummwellsshutdown.at(j-1),cummwellsshutdown.at(j-1),maxoffline.at(j-1),indisruption[j-1],oldindisruption.at(j-1),disruptions,whichdisruption.at(j-1),backtonormal.at(j-1),predisruptionwells.at(j-1),cumm_prod.at(j-1),wellsy.at(j-1),howmanywells.at(j-1),gonk,oldwellsonlinerate.at(j-1),wellsonlinerate.at(j-1),oldcumm_prod.at(j-1),howmanywells.at(j-1),fieldlifechecker.at(j-1),URR_fields.at(j-1),powernum,whencross,k2gap,supply,fixer.at(j-1),stupid,yearfind,maximwell,oldwellsURR.at(j-1));
      stupid=icky1.stupid;
      oldcurrentwells.at(j-1)=icky1.oldcurrentwells;
      currentwells.at(j-1)=icky1.currentwells;
      shutdownwells.at(j-1)=icky1.shutdownwells;
      totalwells.at(j-1)=icky1.totalwells;
      oldtotalwells.at(j-1)=icky1.oldtotalwells;
      wellsy.at(j-1)=icky1.wellsy;
      countingwells.at(j-1)=icky1.countingwells;
      oldcountingwells.at(j-1)=icky1.oldcountingwells;
      cumm_prod.at(j-1)=icky1.cumm_prod;
      oldcumm_prod.at(j-1)=icky1.oldcumm_prod;
      maxoffline.at(j-1)=icky1.maxoffline;
      supply=supply+icky1.supply;
      oldcummwellsshutdown.at(j-1)=icky1.oldcummwellsshutdown;
      cummwellsshutdown.at(j-1)=icky1.cummwellsshutdown;
      indisruption.at(j-1)=icky1.indisruption;
      backtonormal.at(j-1)=icky1.backtonormal;
      predisruptionwells.at(j-1)=icky1.predisruptionwells;
      oldindisruption.at(j-1)=icky1.oldindisruption;
      whichdisruption.at(j-1)=icky1.whichdisruption;
      maxprod.at(j-1)=icky1.maxprod;
      oldwellsURR.at(j-1)=icky1.oldwellsURR;
      maybemaxprod.at(j-1)=icky1.maybemaxprod;
      fieldlifechecker.at(j-1)=icky1.basinlifechecker;
      fixer.at(j-1)=icky1.fixer;
      fieldtime.at(j-1)=(double)icky1.futuretime;
      fieldproduction.at(j-1)=icky1.yearlybasinprodmod;
    }
  }
  yearlybasinprodmod.push_back(supply);
  fieldsCP=fieldsCP+supply;
  if (oldfieldstotal==0)
  {
    fieldsy=min(supply/URR_basin,1.0);
  }
  oldfieldstotal=fieldstotal;
  if ((!indisruption.back())&&(!tripped))
  {
    fieldstotaler=min( ceil(fieldsy*(sqrt(1+((supply/URR_basin)/(pow(fieldsy/totalfields,2))))+k3smallgap)) ,totalfields);
    if (fieldstotaler>=fieldstotal)
    {
      fieldstotal=fieldstotaler;
      fieldsy=fieldsy*(sqrt(1+((supply/URR_basin)/(pow(fieldsy/totalfields,2))))+k3smallgap) ;
    }
    else
    {
    fieldstotal=fieldstotal;
    fieldsy=fieldsy;
    }

  }
  else
  {
    if (!tripped)
    {
      fieldstotal=min( ceil(fieldsy*(sqrt(1+((supply/URR_basin)/(pow(fieldsy/totalfields,2)))))) ,totalfields);
      fieldsy=fieldsy*(sqrt(1+((supply/URR_basin)/(pow(fieldsy/totalfields,2))))) ;
    }
  }

  basinlifechecker=true;
  if ((ended)&&(fieldstotal==totalfields)&&(supply==0))
  {
    basinlifechecker=false;
  }
  if ((ended)&&(fieldstotal!=totalfields))
  {
    fieldstotal=totalfields;
    tripped=true;
  }
  if ((i >= abort)&&(abort!=-1))
  {
    basinlifechecker = false;
    cout<<i<<" "<<abort<<" "<<yearlybasinprodmod.size()<<endl;
    for (b=(int)(i-yearfind-timedelay);b<yearlybasinprodmod.size();b++)
    {
      yearlybasinprodmod.at(b) = 0;
    }
    //if (yearfind+timedelay > abort)
    //{
    //  for (b=0;b<yearlybasinprodmod.size();b++)
    //  {
    //  yearlybasinprodmod.at(b)= 0;
    //  }
    //}
  }
  icky.fieldsy=fieldsy;
  icky.yearlybasinprodmod=yearlybasinprodmod;
  icky.basinlifechecker=basinlifechecker;
  icky.fieldlifechecker=fieldlifechecker;
  icky.yearfieldfound=yearfieldfound;
  icky.oldfieldstotal=oldfieldstotal;
  icky.fieldstotal=fieldstotal;
  icky.fieldsCP=fieldsCP;
  icky.URR_fields=URR_fields;
  icky.oldwellsURR=oldwellsURR;
  icky.fieldtime=fieldtime;
  icky.fieldproduction=fieldproduction;
  icky.oldcurrentwells=oldcurrentwells;
  icky.currentwells=currentwells;
  icky.shutdownwells=shutdownwells;
  icky.totalwells=totalwells;
  icky.oldtotalwells=oldtotalwells;
  icky.wellsy=wellsy;
  icky.countingwells=countingwells;
  icky.oldcountingwells=oldcountingwells;
  icky.cumm_prod=cumm_prod;
  icky.oldcumm_prod=oldcumm_prod;
  icky.maxoffline=maxoffline;
  icky.supply=supply;
  icky.cummwellsshutdown=cummwellsshutdown;
  icky.oldcummwellsshutdown=oldcummwellsshutdown;
  icky.indisruption=indisruption;
  icky.backtonormal=backtonormal;
  icky.predisruptionwells=predisruptionwells;
  icky.oldindisruption=oldindisruption;
  icky.whichdisruption=whichdisruption;
  icky.maxprod=maxprod;
  icky.maybemaxprod=maybemaxprod;
  icky.howmanywells=howmanywells;
  icky.wellsonlinerate=wellsonlinerate;
  icky.oldwellsonlinerate=oldwellsonlinerate;
  icky.stupid=stupid;
  icky.fixer=fixer;
  icky.tripped=tripped;
  return icky;
};







double cumm_mine(double URR, double Max_production, double ramping_time, double start_year, double current_year, vector<double> overrider)
{
  double rampingdown_year, rpt, beginplateau;
  rampingdown_year=(URR/(Max_production))+start_year;
  if (start_year+ramping_time>rampingdown_year)
  {
    if (overrider.empty())
    {
      rpt=sqrt(URR*ramping_time/(Max_production));
      if (current_year<start_year)
      {
        return 0;
      }
      if ((current_year>=start_year) && (current_year<rpt+start_year))
      {
        return (Max_production/(2.0*ramping_time))*(pow((current_year-start_year),2));
      }
      if ((current_year>=start_year+rpt) && (current_year<start_year+2.0*rpt))
      {
        return URR-(Max_production/(2.0*ramping_time))*(pow((current_year-start_year-2.0*rpt),2.0));
      }
      if (current_year>=start_year+2.0*rpt)
      {
        return URR;
      }
    }
    if (!overrider.empty())
    {
      beginplateau=(1.0/2.0)*sqrt(pow(overrider.front(),2)+(4.0*URR*ramping_time)/(Max_production))-(1.0/2.0)*overrider.front()+start_year;
      if (current_year<start_year)
      {
        return 0;
      }
      if ((current_year>=start_year) && (current_year<beginplateau))
      {
        return (Max_production/(2.0*ramping_time))*(pow((current_year-start_year),2.0));
      }
      if ((current_year>=beginplateau) && (current_year<beginplateau+overrider.front()))
      {
        return ((pow((sqrt((pow(overrider.front(),2))+(4.0*URR*ramping_time)/(Max_production))-overrider.front()),2))*Max_production)/(8.0*ramping_time)+((Max_production)*(sqrt((pow(overrider.front(),2))+(4.0*URR*ramping_time)/(Max_production))-overrider.front())*(current_year-beginplateau))/(2.0*ramping_time);
      }
      if ((current_year>=beginplateau+overrider.front()) && (current_year<beginplateau+overrider.front()+beginplateau-start_year))
      {
        return URR-((Max_production*(pow((current_year-2.0*beginplateau-overrider.front()+start_year),2)))/(2.0*ramping_time));
      }
      if (current_year>=beginplateau+overrider.front()+beginplateau-start_year)
      {
        return URR;
      }
    }
  }
  if (start_year+ramping_time<=rampingdown_year)
  {
    if (overrider.empty())
    {
      if (current_year<start_year)
      {
        return 0;
      }
      if ((current_year>=start_year) && (current_year<start_year+ramping_time))
      {
        return ((Max_production*(pow((current_year-start_year),2)))/(2.0*ramping_time));
      }
      if ((current_year>=start_year+ramping_time) && (current_year<rampingdown_year))
      {
        return (ramping_time*Max_production/2.0+Max_production*(current_year-start_year-ramping_time));
      }
      if ((current_year>=rampingdown_year) && (current_year<rampingdown_year+ramping_time))
      {
        return URR-(ramping_time*Max_production/2.0)+(Max_production)*(current_year-rampingdown_year)*(1.0-(current_year-rampingdown_year)/(2.0*ramping_time));
      }
      if (current_year>=rampingdown_year+ramping_time)
      {
        return URR;
      }
    }
    if (!overrider.empty())
    {
      if (overrider.front()<=rampingdown_year-start_year-ramping_time)
      {
        if (current_year<start_year)
        {
          return 0;
        }
        if ((current_year>=start_year) && (current_year<start_year+ramping_time))
        {
          return Max_production*(pow((current_year-start_year),2))/(2.0*ramping_time);
        }
        if ((current_year>=start_year+ramping_time) && (current_year<rampingdown_year))
        {
          return ramping_time*Max_production/2.0+Max_production*(current_year-start_year-ramping_time);
        }
        if ((current_year>=rampingdown_year) && (current_year<rampingdown_year+ramping_time))
        {
          return URR-(ramping_time*Max_production/2.0)+Max_production*(current_year-rampingdown_year)*(1.0-(current_year-rampingdown_year)/(2.0*ramping_time));
        }
        if (current_year>=rampingdown_year+ramping_time)
        {
          return URR;
        }
      }
      if (overrider.front()>rampingdown_year-start_year-ramping_time)
      {
        beginplateau= sqrt((pow(overrider.front(),2))+(4.0*URR*ramping_time)/(Max_production))/2.0-overrider.front()/2.0+start_year;
        if (current_year<start_year)
        {
          return 0;
        }
        if ((current_year>=start_year) && (current_year<beginplateau))
        {
          return (Max_production*(pow((current_year-start_year),2)))/(2.0*ramping_time);
        }
        if ((current_year>=beginplateau) && (current_year<beginplateau+overrider.front()))
        {
          return ((Max_production*(pow(sqrt((pow(overrider.front(),2))+((4.0*URR*ramping_time)/(Max_production)))-overrider.front(),2)))/(8.0*ramping_time))+((Max_production*(current_year-beginplateau)*(sqrt((pow(overrider.front(),2))+((4.0*URR*ramping_time)/(Max_production)))-overrider.front()))/(2.0*ramping_time));
        }
        if ((current_year>=beginplateau+overrider.front()) && (current_year<beginplateau+overrider.front()+beginplateau-start_year))
        {
          return URR - ((Max_production*(pow(current_year-2.0*beginplateau-overrider.front()+start_year,2)))/(2.0*ramping_time));
        }
        if (current_year>=beginplateau+overrider.front()+beginplateau-start_year)
        {
          return URR;
        }
      }
    }
  }
};



double minelife(double URR, double Max_production, double ramping_time, double start_year, vector<double> overrider)
{
  double rampingdown_year, cumm_prod, rpt, beginplateau;
  rampingdown_year=((URR)/(Max_production))+start_year;
  if (start_year+ramping_time>rampingdown_year)
  {
    if (overrider.empty())
    {
      rpt=sqrt((URR*ramping_time)/(Max_production));
      return ceil(start_year+2*rpt+1);
    }
    if (!overrider.empty())
    {
      beginplateau=(1.0/2.0)*sqrt((pow(overrider.at(0),2.0))+((4.0*URR*ramping_time)/(Max_production)))-(1.0/2.0)*overrider.at(0)+start_year;
      return ceil(beginplateau+overrider.at(0)+beginplateau-start_year+1);
    }
  }
  if (start_year+ramping_time<=rampingdown_year)
  {
    if (overrider.empty())
    {
      return ceil(rampingdown_year+ramping_time+1);
    }
    if (!overrider.empty())
    {
      if (overrider.at(0)<=rampingdown_year-start_year-ramping_time)
      {
        return ceil(rampingdown_year+ramping_time+1);
      }
      if (overrider.at(0)>rampingdown_year-start_year-ramping_time)
      {
        beginplateau=(1.0/2.0)*sqrt((pow(overrider.at(0),2.0))+((4.0*URR*ramping_time)/(Max_production)))-(1.0/2.0)*overrider.at(0)+start_year;
        return ceil(beginplateau+overrider.at(0)+beginplateau-start_year+1);
      }
    }
  }
};









vector<double> prodminemodel(double URR, double Max_production, double ramping_time, double start_year, vector<double> overrider)
{
  bool stoptimechecker;
  vector<double> mineproduction;
  double end_year, mineprod,i;
  stoptimechecker=true;
  end_year=minelife(URR,Max_production,ramping_time,start_year,overrider);
  i=start_year;
  while (stoptimechecker)
  {
    if (i-0.5>end_year)
    {
      stoptimechecker=false;
    }
    mineprod=cumm_mine(URR,Max_production,ramping_time,start_year,i+0.5,overrider)-cumm_mine(URR,Max_production,ramping_time,start_year,i-0.5,overrider);
    mineproduction.push_back(mineprod);
    i++;
  }
  return mineproduction;
};



double prodmineattimet(double URR, double Max_production, double ramping_time, double start_year, double t, vector<double> overrider)
{
  double mineprod;
  mineprod=cumm_mine(URR,Max_production,ramping_time,start_year,t+0.5,overrider)-cumm_mine(URR,Max_production,ramping_time,start_year,t-0.5,overrider);
  return mineprod;
};






double numberminesreally_ds(double numbermines, double minesonlinerate)
{
  return ceil(numbermines-(numbermines-1)*exp(-minesonlinerate));
};

double numberminesonline_ds(double cumm_prod,double numbermines, double minesonlinerate, double URR_basin)
{
  return ceil(numbermines+(1.0-numbermines)*exp(-minesonlinerate*(cumm_prod/URR_basin)));
};








bool splitteronline(const cmines& elem1, const cmines& elem2)
{
  return elem1.startyear<elem2.startyear;
};







bool splitterremain(const cmines& elem1, const cmines& elem2)
{
  return elem1.remainres<elem2.remainres;
};




double howmanyminestoremove(vector<cmines> currentmines, double rampingtime, double currentyear, double removeURR, vector<double> overrider)
{
  int i;
  vector<cmines> shutdownmines, minedata, temper;
  double howmanymines, minesshutsofar, howmanyshutdown,URR;
  bool stillmoretoshutdown, keepgoing, moretosearch;
  shutdownmines.clear();
  howmanymines=0;
  minedata=currentmines;
  howmanymines=currentmines.size();
  stillmoretoshutdown=true;
  moretosearch=true;
  minesshutsofar=0;
  sort(minedata.begin(),minedata.end(),splitteronline);
  i=minedata.size();
  URR=0;
  while ((stillmoretoshutdown)&&(moretosearch))
  {
    if ((minedata.at(i-1).startyear+rampingtime>currentyear)&&(minedata.at(i-1).endyear>currentyear))
    {
      minesshutsofar++;
      URR=URR+minedata.at(i-1).mdata.URR;
      if (URR>removeURR)
      {
        stillmoretoshutdown=false;
      }
    }
    else
    {
      temper.push_back(minedata.at(i-1));
    }
    if (i==1)
    {
      moretosearch=false;
    }
    i--;
  }
  minedata=temper;
  if ((stillmoretoshutdown)&&(minedata.size()>0))
  {
    temper.clear();
    keepgoing=true;
    sort(minedata.begin(),minedata.end(),splitterremain);
    i=1;
    while (keepgoing)
    {
      if ((minedata.at(i-1).endyear>currentyear)&&(minedata.at(i-1).remainres>0))
      {
        minesshutsofar++;
        URR=URR+minedata.at(i-1).mdata.URR;
        if (URR>removeURR)
        {
          keepgoing=false;
        }
      }
      if (i==minedata.size())
      {
        keepgoing=false;
      }
      i++;
    }
  }
  if (minesshutsofar==currentmines.size())
  {
    minesshutsofar=minesshutsofar-1;
  }
  if (minesshutsofar>currentmines.size())
  {
  cout<<"this shouldn't be possible ";
  }
  return minesshutsofar;
};










shutty shuttingmines(vector<cmines> currentmines, double rampingtime, double currentyear, double howmanyshutdowna, vector<double> overrider)
{
  int i, j, k;
  cmines temp, lastone;
  shutty tempy;
  vector<cmines> shutdownmines, minedata, temper;
  double howmanymines, minesshutsofar, interim, fixit, howmanyshutdown,URR;
  bool stillmoretoshutdown, oops, keepgoing;
  shutdownmines.clear();
  howmanymines=0;
  oops=false;
  howmanyshutdown=howmanyshutdowna;
  minedata=currentmines;
  howmanymines=currentmines.size();
  if (oops==false)
  {
    stillmoretoshutdown=true;
    minesshutsofar=0;
    sort(minedata.begin(),minedata.end(),splitteronline);
    i=minedata.size();
    while (stillmoretoshutdown)
    {

      if ((minedata.at(i-1).startyear+rampingtime>currentyear)&&(minedata.at(i-1).endyear>currentyear)&&(minesshutsofar<howmanyshutdown))
      {
        minesshutsofar++;
        shutdownmines.push_back(minedata.at(i-1));
      }
      else
      {
        temper.push_back(minedata.at(i-1));
      }
      if (i==1)
      {
        stillmoretoshutdown=false;
      }
      i--;
    }
    minedata=temper;
    if ((minesshutsofar<howmanyshutdown)&&(minedata.size()>0))
    {
      temper.clear();
      keepgoing=true;
      sort(minedata.begin(),minedata.end(),splitterremain);
      i=1;
      while (keepgoing)
      {
        if ((minedata.at(i-1).endyear>currentyear)&&(minedata.at(i-1).remainres>0)&&(minesshutsofar<howmanyshutdown))
        {
          minesshutsofar++;
          shutdownmines.push_back(minedata.at(i-1));
        }
        else
        {
          temper.push_back(minedata.at(i-1));
        }
        if (i==minedata.size())
        {
          keepgoing=false;
        }
        i++;
      }
      minedata=temper;
    }
  }
  else
  {
    cout<<"there are problems with the mining data"<<endl;
  }
  if (howmanyshutdown>howmanymines)
  {
    cout<<"too many mines shutting down"<<endl;
  }
  if (minesshutsofar<howmanyshutdown)
  {
    cout<<"warning too few mines removed "<<minesshutsofar<<" "<<howmanyshutdown<<" "<<currentmines.size()<<endl;
  }
  if (shutdownmines.size()>0)
  {
    lastone=shutdownmines.back();
    shutdownmines.pop_back();
    minedata.push_back(lastone);
    if (lastone.upgrade==-1)
    {
      URR=lastone.remainres+prodmineattimet(lastone.mdata.URR, lastone.mdata.maximprod, rampingtime,lastone.startyear, currentyear, overrider);
    }
    else
    {
      URR=lastone.remainres+upgradprodattimet(lastone.mdata.URR,lastone.mdata.wpremainingres,lastone.mdata.maximprod,rampingtime,lastone.startyear, currentyear, overrider, lastone.mdata.wptime,lastone.endyear);
    }
  }
  else
  {
    URR=0;
  }
  fixit=howmanyshutdown-minesshutsofar;
  tempy.fixit=fixit;
  tempy.shutdown=shutdownmines;
  tempy.URR=URR;
  tempy.mines=minedata;
  return tempy;
};











double upgradprodattimet(double URR, double remainingres,double Max_production,double ramping_time,double start_year, double t, vector<double> overrider, double whenupgrade, double runningtime)
{
  double a, b;
  double proda, prodb, prod;
  if (whenupgrade!=0)
  {
    a=(0.5)*Max_production*ramping_time;
    b=(0.5)*(remainingres-5*a);
    if (b<0)
    {
      cout<<"error remaining reserves too low "<<b<<endl;
    }
    proda=prodmineattimet(URR-2*a-b,Max_production,ramping_time,start_year,t,overrider);
    prodb=prodmineattimet(2*a+b,Max_production,ramping_time,start_year+whenupgrade,t,overrider);
    prod=proda+prodb;
  }
  else
  {
    prod=prodmineattimet(URR, 2*Max_production, ramping_time, start_year, t,overrider);
  }
  return prod;
};








painful painfulmodelproc(double & maxprod, double & maybemaxprod, vector<double> yearlybasinprodamod, int & futuretime, vector<cmines> & oldcurrentmines, vector<cmines> & currentmines, vector<cmines> & shutdownmines, double & totalmines, double & oldtotalmines, double & cumm_prod, int & indisruption, bool & oldindisruption, double & whichdisruption, bool & backtonormal, double & predisruptionURRs, double & predisruptionmines, double & cummminesshutdown, double & oldcummminesshutdown,  double & minesonlinerate, double ramping_time, double URR_basin, int timedelay, int yearfind,   double max_capacity, vector<disr> & disruptions, vector<double> overrider, double i, bool & basinlifechecker, double & lastdisruptionend, double & maxoffline, double oldminesonlineratea, double & oldcumm_prod, double & wellsy, double mintime, double k3, double smallergap,  double oldminesonlinerateaa, bool & gonk ,int & countingmines ,double k2gap, double & mineURR, double & mineMP, double Max_prodLOW, double Max_prodHIGH, double Max_prodCY, double Max_prodRATE, double ML_LOW, double ML_HIGH, double & upperURR, double & lowerURR, bool & fixer,double PP, double & cminesize ,bool ARGH, double abort)
{
  vector<cmines> upgradable, removedmines, oldremovedmines;
  double oldminesonlinerate, oldminesonlinerateb;
  vector<cmines> minestoupgrade,oldtempmineset , tempmineset, newminestoupgrade,   oldy, temporaryshutdownmines, temporarycurrentmines;
  bool resetcumm, goingon, grr, goop;
  double mineLIFE, removeURR, fixtotalmines, minres, oldupperURR, cutters, totmin, oldtotmin, lifemine, itnum, lowURR;
  vector<double> maybeprod, tempy2,yearlybasinprod, reallyoldedata, yearlybasinprodmod;
  vector<int> shutplaces;
  int a, kk, mazer, iii, ii, indexer, j,kkk,tt,b,jj,yy;
  cmines dataofmine, temper;
  painful returngah;
  double lifeofmine, deltacumm_prod, supply,minernum, tempdob, tempblob;
  double tempmines, tempcount, tempnumber,upa, upb, upc, upghowmany, upgsofar;
  shutty shutter;
  vector<vector<double> >  tempy1;
  tempy2.push_back(0);
  tempy1.push_back(tempy2);
  cutters=0;
  removeURR=0;
  yearlybasinprod=yearlybasinprodamod;
  oldminesonlinerate=oldminesonlineratea;
  oldminesonlinerateb=oldminesonlinerateaa;



// code here upgrades some mines
  upghowmany=ceil(k3*smallergap*(countingmines-shutdownmines.size()));
  if (upghowmany>0)
  {
    if (!currentmines.empty())
    {
      temporarycurrentmines.clear();
      upgsofar=0;
      minestoupgrade.clear();
      for (j=currentmines.size()-1;j>=0;j--)
      {
        if ((currentmines.at(j).endyear>i)&&(currentmines.at(j).upgrade==-1))
        {
          upa=5.0*ramping_time*currentmines.at(j).mdata.maximprod/2.0;
          upb=2.0*currentmines.at(j).mdata.maximprod*mintime;
          minres=upa+upb;
          if (currentmines.at(j).remainres>minres)
          {
            minestoupgrade.push_back(currentmines.at(j));
          }
          else
          {
            temporarycurrentmines.push_back(currentmines.at(j));
          }
        }
        else
        {
          temporarycurrentmines.push_back(currentmines.at(j));
        }
      }
      if (!minestoupgrade.empty())
      {
        sort(minestoupgrade.begin(),minestoupgrade.end(),splitterremain);
        for (j=minestoupgrade.size()-1;j>=0;j--)
        {
          if (upgsofar<upghowmany)
          {
            upgsofar++;
            if (max_capacity!=-1)
            {
              if (maybeprod.size()<=minestoupgrade.at(j).endyear-1)
              {
                itnum=minestoupgrade.at(j).endyear-1-maybeprod.size();
                for (b=0;b<=itnum;b++)
                {
                  maybeprod.push_back(0);
                }
              }
              for (b=(int)(i-minestoupgrade.at(j).startyear+1);b<=(int)(minestoupgrade.at(j).endyear-minestoupgrade.at(j).startyear+1);b++) //i - minestoupgrade[iii]+1
              {
                maybeprod.at((int)(b+minestoupgrade.at(j).startyear-2))=yearlybasinprod.at((int)(b+minestoupgrade.at(j).startyear-2))-prodmineattimet(minestoupgrade.at(j).mdata.URR, minestoupgrade.at(j).mdata.maximprod, ramping_time,minestoupgrade.at(j).startyear, (int)(b+minestoupgrade.at(j).startyear-1), overrider)+upgradprodattimet(minestoupgrade.at(j).mdata.URR,minestoupgrade.at(j).remainres,minestoupgrade.at(j).mdata.maximprod,ramping_time,minestoupgrade.at(j).startyear, (int)(b+minestoupgrade.at(j).startyear-1), overrider, i-minestoupgrade.at(j).startyear+1,minestoupgrade.at(j).endyear);
                if (maybeprod.at((int)(b+minestoupgrade.at(j).startyear-2))>maybemaxprod)
                {
                  maybemaxprod=maybeprod.at((int)(b+minestoupgrade.at(j).startyear-2));
                }
              }
              if (maybemaxprod<=max_capacity)
              {
                maxprod=maybemaxprod;
                for (b=(int)(i-minestoupgrade.at(j).startyear+1);b<=(int)(minestoupgrade.at(j).endyear-minestoupgrade.at(j).startyear+1);b++) //i - minestoupgrade[iii]+1
                {
                  yearlybasinprod.at((int)(b+minestoupgrade.at(j).startyear-2))=yearlybasinprod.at((int)(b+minestoupgrade.at(j).startyear-2))-prodmineattimet(minestoupgrade.at(j).mdata.URR, minestoupgrade.at(j).mdata.maximprod, ramping_time,minestoupgrade.at(j).startyear, (int)(b+minestoupgrade.at(j).startyear-1), overrider)+upgradprodattimet(minestoupgrade.at(j).mdata.URR,minestoupgrade.at(j).remainres,minestoupgrade.at(j).mdata.maximprod,ramping_time,minestoupgrade.at(j).startyear, (int)(b+minestoupgrade.at(j).startyear-1), overrider, i-minestoupgrade.at(j).startyear+1,minestoupgrade.at(j).endyear);
                }
                temper.startyear=minestoupgrade.at(j).startyear;
                temper.mdata.maximprod=minestoupgrade.at(j).mdata.maximprod;
                temper.mdata.URR=minestoupgrade.at(j).mdata.URR;
                temper.mdata.minelife=minestoupgrade.at(j).mdata.minelife;
                temper.mdata.wpremainingres=minestoupgrade.at(j).remainres;
                temper.mdata.wptime=i-minestoupgrade.at(j).startyear+1;
                temper.mdata.lowURRdeterminor=minestoupgrade.at(j).mdata.lowURRdeterminor;
                temper.endyear=minestoupgrade.at(j).endyear;
                temper.remainres=minestoupgrade.at(j).remainres;
                temper.upgrade=(int)(i-minestoupgrade.at(j).startyear+1);
                temporarycurrentmines.push_back(temper);
              }
              else
              {
                temporarycurrentmines.push_back(minestoupgrade.at(j));
              }
            }
            else
            {
              for (b=(int)(i-minestoupgrade.at(j).startyear+1);b<=(int)(minestoupgrade.at(j).endyear-minestoupgrade.at(j).startyear+1);b++) //i - minestoupgrade[iii]+1
              {
                yearlybasinprod.at((int)(b+minestoupgrade.at(j).startyear-2))=yearlybasinprod.at((int)(b+minestoupgrade.at(j).startyear-2))-prodmineattimet(minestoupgrade.at(j).mdata.URR, minestoupgrade.at(j).mdata.maximprod, ramping_time,minestoupgrade.at(j).startyear, (int)(b+minestoupgrade.at(j).startyear-1), overrider)+upgradprodattimet(minestoupgrade.at(j).mdata.URR,minestoupgrade.at(j).remainres,minestoupgrade.at(j).mdata.maximprod,ramping_time,minestoupgrade.at(j).startyear, (int)(b+minestoupgrade.at(j).startyear-1), overrider, i-minestoupgrade.at(j).startyear+1,minestoupgrade.at(j).endyear);
              }
              temper.startyear=minestoupgrade.at(j).startyear;
              temper.mdata.maximprod=minestoupgrade.at(j).mdata.maximprod;
              temper.mdata.URR=minestoupgrade.at(j).mdata.URR;
              temper.mdata.minelife=minestoupgrade.at(j).mdata.minelife;
              temper.mdata.wpremainingres=minestoupgrade.at(j).remainres;
              temper.mdata.wptime=i-minestoupgrade.at(j).startyear+1;
              temper.mdata.lowURRdeterminor=minestoupgrade.at(j).mdata.lowURRdeterminor;
              temper.endyear=minestoupgrade.at(j).endyear;
              temper.remainres=minestoupgrade.at(j).remainres;
              temper.upgrade=(int)(i-minestoupgrade.at(j).startyear+1);
              temporarycurrentmines.push_back(temper);
            }
          }
          else
          {
            temporarycurrentmines.push_back(minestoupgrade.at(j));
          }
        }
      }
      currentmines=temporarycurrentmines;
    }
  }


// updating currentmines
  if (!currentmines.empty())
  {
    oldcurrentmines.clear();
    oldcurrentmines=currentmines;
    currentmines.clear();
    for (iii=1;iii<=oldcurrentmines.size();iii++)
    {
      if ((i<oldcurrentmines.at(iii-1).endyear+1)&&(oldcurrentmines.at(iii-1).remainres>0))
      {
        if (oldcurrentmines.at(iii-1).upgrade==-1)
        {
          temper.startyear=oldcurrentmines.at(iii-1).startyear;
          temper.mdata.maximprod=oldcurrentmines.at(iii-1).mdata.maximprod;
          temper.mdata.URR=oldcurrentmines.at(iii-1).mdata.URR;
          temper.mdata.minelife=oldcurrentmines.at(iii-1).mdata.minelife;
          temper.mdata.wpremainingres=oldcurrentmines.at(iii-1).mdata.wpremainingres;
          temper.mdata.wptime=oldcurrentmines.at(iii-1).mdata.wptime;
          temper.mdata.lowURRdeterminor=oldcurrentmines.at(iii-1).mdata.lowURRdeterminor;
          temper.endyear=oldcurrentmines.at(iii-1).endyear;
          temper.upgrade=oldcurrentmines.at(iii-1).upgrade;
          temper.remainres=oldcurrentmines.at(iii-1).remainres-prodmineattimet(oldcurrentmines.at(iii-1).mdata.URR, oldcurrentmines.at(iii-1).mdata.maximprod, ramping_time,oldcurrentmines.at(iii-1).startyear, (int)(i), overrider);
          currentmines.push_back(temper);
        }
        else
        {
          temper.startyear=oldcurrentmines.at(iii-1).startyear;
          temper.mdata.maximprod=oldcurrentmines.at(iii-1).mdata.maximprod;
          temper.mdata.URR=oldcurrentmines.at(iii-1).mdata.URR;
          temper.mdata.minelife=oldcurrentmines.at(iii-1).mdata.minelife;
          temper.mdata.wpremainingres=oldcurrentmines.at(iii-1).mdata.wpremainingres;
          temper.mdata.wptime=oldcurrentmines.at(iii-1).mdata.wptime;
          temper.mdata.lowURRdeterminor=oldcurrentmines.at(iii-1).mdata.lowURRdeterminor;
          temper.endyear=oldcurrentmines.at(iii-1).endyear;
          temper.upgrade=oldcurrentmines.at(iii-1).upgrade;
          temper.remainres=oldcurrentmines.at(iii-1).remainres-upgradprodattimet(oldcurrentmines.at(iii-1).mdata.URR,oldcurrentmines.at(iii-1).mdata.wpremainingres,oldcurrentmines.at(iii-1).mdata.maximprod,ramping_time,oldcurrentmines.at(iii-1).startyear, i, overrider, oldcurrentmines.at(iii-1).mdata.wptime,oldcurrentmines.at(iii-1).endyear);
          currentmines.push_back(temper);
        }
      }
    }
  }

// returning shutdown mines component


  if (totalmines>oldtotalmines)
  {
    totmin=totalmines;
    oldtotmin=oldtotalmines;
    if (!shutdownmines.empty())
    {
      if (totmin-oldtotmin<shutdownmines.size())
      {
        minernum=totmin-oldtotmin;
      }
      else
      {
        minernum=shutdownmines.size();
      }
      temporaryshutdownmines.clear();
      for (jj=0;jj<shutdownmines.size()-minernum;jj++)
      {
        temporaryshutdownmines.push_back(shutdownmines.at(jj));
      }
      shutplaces.clear();
      for (jj=1;jj<=(int)(minernum);jj++)
      {
        dataofmine=shutdownmines.at((int)(shutdownmines.size()-jj));
        if (dataofmine.remainres<0)
        {
          cout<<"warning remaining reserves are negative, panic if the following is smaller than -1 "<<dataofmine.remainres<<endl;
          dataofmine.remainres=0;
        }
        if (dataofmine.upgrade==-1)
        {
          lifemine=minelife(dataofmine.remainres,dataofmine.mdata.maximprod,ramping_time, yearfind+timedelay+i-1,overrider);
        }
        else
        {
          lifemine=minelife(dataofmine.remainres,2*dataofmine.mdata.maximprod,ramping_time,yearfind+timedelay+i-1,overrider);
        }
        if (lifemine>futuretime)
        {
          for (a=futuretime+1; a<=lifemine;a++)
          {
            yearlybasinprod.push_back(0);
          }
          futuretime=(int)lifemine;
        }
        if (dataofmine.upgrade==-1)
        {
          if (maybeprod.size()<=lifemine-yearfind-timedelay)
          {
            itnum=lifemine-yearfind-timedelay-maybeprod.size()+1;
            for (b=0;b<itnum;b++)
            {
              maybeprod.push_back(0);
            }
          }
          if (max_capacity!=-1)
          {
            for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifemine);b++)
            {
              maybeprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+prodmineattimet(dataofmine.mdata.URR, dataofmine.mdata.maximprod, ramping_time,dataofmine.startyear, b-yearfind-timedelay-i+1+dataofmine.startyear, overrider);
              if (maybeprod.at((int)(b-yearfind-timedelay))>maybemaxprod)
              {
                maybemaxprod=maybeprod.at((int)(b-yearfind-timedelay));
              }
            }
            if (maybemaxprod<=max_capacity)
            {
              maxprod=maybemaxprod;
              for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifemine);b++)
              {
                yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+prodmineattimet(dataofmine.mdata.URR, dataofmine.mdata.maximprod, ramping_time,dataofmine.startyear, b-yearfind-timedelay-i+1+dataofmine.startyear, overrider);
              }
              temper.startyear=i;
              temper.mdata.maximprod=dataofmine.mdata.maximprod;
              temper.mdata.URR=dataofmine.mdata.URR;
              temper.mdata.minelife=lifemine;
              temper.mdata.wpremainingres=0;
              temper.mdata.wptime=0;
              temper.mdata.lowURRdeterminor=dataofmine.mdata.lowURRdeterminor;
              temper.endyear=lifemine-yearfind-timedelay+1;
              temper.remainres=dataofmine.remainres-prodmineattimet(dataofmine.mdata.URR, dataofmine.mdata.maximprod, ramping_time,dataofmine.startyear,dataofmine.startyear, overrider);
              temper.upgrade=dataofmine.upgrade;
              currentmines.push_back(temper);
            }
            else
            {
              maybemaxprod=maxprod;
              cutters=cutters+1;
              removeURR=removeURR+dataofmine.mdata.URR;
              shutplaces.push_back(shutdownmines.size()-jj);
            }
          }
          else
          {
            for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifemine);b++)
            {
              yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+prodmineattimet(dataofmine.mdata.URR, dataofmine.mdata.maximprod, ramping_time,dataofmine.startyear, b-yearfind-timedelay-i+1+dataofmine.startyear, overrider);
            }
            temper.startyear=i;
            temper.mdata.maximprod=dataofmine.mdata.maximprod;
            temper.mdata.URR=dataofmine.mdata.URR;
            temper.mdata.minelife=lifemine;
            temper.mdata.wpremainingres=0;
            temper.mdata.wptime=0;
            temper.mdata.lowURRdeterminor=dataofmine.mdata.lowURRdeterminor;
            temper.endyear=lifemine-yearfind-timedelay+1;
            temper.remainres=dataofmine.remainres-prodmineattimet(dataofmine.mdata.URR, dataofmine.mdata.maximprod, ramping_time,dataofmine.startyear,dataofmine.startyear, overrider);
            temper.upgrade=dataofmine.upgrade;
            currentmines.push_back(temper);
          }
        }
        else
        {
          if (maybeprod.size()<=lifemine-yearfind-timedelay)
          {
            itnum=lifemine-yearfind-timedelay-maybeprod.size()+1;
            for (b=0;b<itnum;b++)
            {
              maybeprod.push_back(0);
            }
          }
          if (max_capacity!=-1)
          {
            for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifemine);b++)
            {
              maybeprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at(b-yearfind-timedelay)+upgradprodattimet(dataofmine.mdata.URR,dataofmine.mdata.URR,dataofmine.mdata.maximprod,ramping_time,i, b-yearfind-timedelay+1, overrider, 0,dataofmine.endyear);
              if (maybeprod.at((int)(b-yearfind-timedelay))>maybemaxprod)
              {
                maybemaxprod=maybeprod.at((int)(b-yearfind-timedelay));
              }
            }
            if (maybemaxprod<=max_capacity)
            {
              maxprod=maybemaxprod;
              for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifemine);b++)
              {
                yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+upgradprodattimet(dataofmine.mdata.URR,dataofmine.mdata.URR,dataofmine.mdata.maximprod,ramping_time,i, b-yearfind-timedelay+1, overrider, 0,dataofmine.endyear);
              }
              temper.startyear=i;
              temper.mdata.maximprod=dataofmine.mdata.maximprod;
              temper.mdata.URR=dataofmine.mdata.URR;
              temper.mdata.minelife=lifemine;
              temper.mdata.wpremainingres=dataofmine.mdata.URR;
              temper.mdata.wptime=0;
              temper.mdata.lowURRdeterminor=dataofmine.mdata.lowURRdeterminor;
              temper.endyear=lifemine-yearfind-timedelay+1;
              temper.remainres=dataofmine.remainres-upgradprodattimet(dataofmine.mdata.URR,dataofmine.mdata.URR,dataofmine.mdata.maximprod,ramping_time,i, i, overrider, 0,dataofmine.endyear);
              temper.upgrade=dataofmine.upgrade;
              currentmines.push_back(temper);
            }
            else
            {
              maybemaxprod=maxprod;
              cutters=cutters+1;
              removeURR=removeURR+dataofmine.mdata.URR;
              shutplaces.push_back(shutdownmines.size()-jj);
            }
          }
          else
          {
            for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifemine);b++)
            {
              yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+upgradprodattimet(dataofmine.mdata.URR,dataofmine.mdata.URR,dataofmine.mdata.maximprod,ramping_time,i, b-yearfind-timedelay+1, overrider, 0,dataofmine.endyear);
            }
            temper.startyear=i;
            temper.mdata.maximprod=dataofmine.mdata.maximprod;
            temper.mdata.URR=dataofmine.mdata.URR;
            temper.mdata.minelife=lifemine;
            temper.mdata.wpremainingres=dataofmine.mdata.URR;
            temper.mdata.wptime=0;
            temper.mdata.lowURRdeterminor=dataofmine.mdata.lowURRdeterminor;
            temper.endyear=lifemine-yearfind-timedelay+1;
            temper.remainres=dataofmine.remainres-upgradprodattimet(dataofmine.mdata.URR,dataofmine.mdata.URR,dataofmine.mdata.maximprod,ramping_time,i, i, overrider, 0,dataofmine.endyear);
            temper.upgrade=dataofmine.upgrade;
            currentmines.push_back(temper);
          }
        }
      }
      for (jj=shutplaces.size()-1;jj>=0;jj--)
      {
        temporaryshutdownmines.push_back(shutdownmines.at(shutplaces.at(jj)));
      }
      if (totmin<shutdownmines.size()+oldtotmin)
      {
        oldtotmin=totmin;
      }
      else
      {
        oldtotmin=shutdownmines.size()+oldtotmin;
      }
      shutdownmines.clear();
      shutdownmines=temporaryshutdownmines;
    }
// if there aren't any(more) shutdown mines, then this adds new mines



    if (totmin>oldtotmin)
    {
      lifeofmine=minelife(mineURR , mineMP, ramping_time, yearfind+timedelay+i-1, overrider);
      if (lifeofmine>futuretime)
      {
        for (a=futuretime+1; a<=(int)(lifeofmine);a++)
        {
          yearlybasinprod.push_back(0);
        }
        futuretime=(int)lifeofmine;
      }
      if (max_capacity!=-1)
      {
        for (jj=(int)(oldtotmin+1);jj<=(int)(totmin);jj++)
        {
          if (maybeprod.size()<=lifeofmine-yearfind-timedelay)
          {
            itnum=lifeofmine-yearfind-timedelay-maybeprod.size()+1;
            for (b=0;b<=itnum;b++)
            {
              maybeprod.push_back(0);
            }
          }
          for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifeofmine);b++)
          {
            maybeprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+prodmineattimet(mineURR, mineMP, ramping_time,i, b-yearfind-timedelay+1, overrider);
            if (maybeprod.at((int)(b-yearfind-timedelay))>maybemaxprod)
            {
              maybemaxprod=maybeprod.at((int)(b-yearfind-timedelay));
            }
          }
          if (maybemaxprod<=max_capacity)
          {
            maxprod=maybemaxprod;
            for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifeofmine);b++)
            {
              yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+prodmineattimet(mineURR, mineMP, ramping_time,i, b-yearfind-timedelay+1, overrider);
            }
            temper.startyear=i;
            temper.mdata.maximprod=mineMP;
            temper.mdata.URR=mineURR;
            temper.mdata.minelife=lifeofmine;
            temper.mdata.wpremainingres=0;
            temper.mdata.wptime=0;
            temper.mdata.lowURRdeterminor=mineURR;
            temper.endyear=lifeofmine-yearfind-timedelay+1;
            temper.remainres=mineURR-prodmineattimet(mineURR, mineMP, ramping_time,i, i, overrider);
            temper.upgrade=-1;
            currentmines.push_back(temper);
            countingmines++;
          }
          else
          {
            maybemaxprod=maxprod;
            temper.startyear=i;
            temper.mdata.maximprod=mineMP;
            temper.mdata.URR=mineURR;
            temper.mdata.minelife=lifeofmine;
            temper.mdata.wpremainingres=0;
            temper.mdata.wptime=0;
            temper.mdata.lowURRdeterminor=mineURR;
            temper.endyear=lifeofmine-yearfind-timedelay+1;
            temper.remainres=mineURR;
            temper.upgrade=-1;
            shutdownmines.push_back(temper);
            cutters=cutters+1;
            removeURR=removeURR+mineURR;
            countingmines++;
          }
        }
      }
      else
      {
        for (b=(int)(yearfind+timedelay+i-1);b<=(int)(lifeofmine);b++)
        {
          yearlybasinprod.at((int)(b-yearfind-timedelay))=yearlybasinprod.at((int)(b-yearfind-timedelay))+(totmin-oldtotmin)*(prodmineattimet(mineURR, mineMP, ramping_time,i, b-yearfind-timedelay+1, overrider));
        }
        temper.startyear=i;
        temper.mdata.maximprod=mineMP;
        temper.mdata.URR=mineURR;
        temper.mdata.minelife=lifeofmine;
        temper.mdata.wpremainingres=0;
        temper.mdata.wptime=0;
        temper.mdata.lowURRdeterminor=mineURR;
        temper.endyear=lifeofmine-yearfind-timedelay+1;
        temper.remainres=mineURR-prodmineattimet(temper.mdata.URR, temper.mdata.maximprod, ramping_time,temper.startyear, temper.startyear, overrider);
        temper.upgrade=-1;
        countingmines=countingmines+(int)(totmin-oldtotmin);
        for (b=1;b<=(int)(totmin-oldtotmin);b++)
        {
          currentmines.push_back(temper);
        }
      }
    }
  }


// This bit removes some currentmines to shutdown mines
  if (totalmines<oldtotalmines)
  {
    oldcummminesshutdown=cummminesshutdown;
    cummminesshutdown=cummminesshutdown+(oldtotalmines-totalmines);
    shutter=shuttingmines(currentmines,ramping_time,i,oldtotalmines-totalmines,overrider);
    removedmines=shutter.shutdown;
    totalmines=totalmines+shutter.fixit;
    cummminesshutdown=cummminesshutdown-shutter.fixit;
    currentmines=shutter.mines;
    tempnumber=shutter.URR;
    lowerURR=upperURR-tempnumber;
    wellsy=upperURR-tempnumber;
    oldremovedmines=removedmines;
    removedmines.clear();
    reallyoldedata.clear();
    oldy.clear();
    for (iii=1;iii<=oldremovedmines.size();iii++)
    {
      oldy.push_back(oldremovedmines.at(iii-1));
      if (oldremovedmines.at(iii-1).upgrade==-1)
      {
        temper.startyear=oldremovedmines.at(iii-1).startyear;
        temper.mdata.maximprod=oldremovedmines.at(iii-1).mdata.maximprod;
        temper.mdata.URR=oldremovedmines.at(iii-1).remainres+prodmineattimet(oldy.at(iii-1).mdata.URR, oldy.at(iii-1).mdata.maximprod, ramping_time,oldy.at(iii-1).startyear, i, overrider);
        upperURR=upperURR-temper.mdata.URR;
        wellsy=wellsy-temper.mdata.URR;
        lowerURR=lowerURR-temper.mdata.URR;
        temper.mdata.minelife=oldremovedmines.at(iii-1).mdata.minelife;
        temper.mdata.wpremainingres=oldremovedmines.at(iii-1).mdata.wpremainingres;
        temper.mdata.wptime=oldremovedmines.at(iii-1).mdata.wptime;
        temper.mdata.lowURRdeterminor=oldremovedmines.at(iii-1).mdata.lowURRdeterminor;
        temper.endyear=oldremovedmines.at(iii-1).endyear;
        temper.upgrade=oldremovedmines.at(iii-1).upgrade;
        temper.remainres=oldremovedmines.at(iii-1).remainres+prodmineattimet(oldy.at(iii-1).mdata.URR, oldy.at(iii-1).mdata.maximprod, ramping_time,oldy.at(iii-1).startyear, i, overrider);
        removedmines.push_back(temper);
      }
      else
      {
        temper.startyear=oldremovedmines.at(iii-1).startyear;
        temper.mdata.maximprod=oldremovedmines.at(iii-1).mdata.maximprod;
        temper.mdata.URR=oldremovedmines.at(iii-1).remainres+upgradprodattimet(oldremovedmines.at(iii-1).mdata.URR,oldremovedmines.at(iii-1).mdata.wpremainingres,oldremovedmines.at(iii-1).mdata.maximprod,ramping_time,oldremovedmines.at(iii-1).startyear, i, overrider, oldremovedmines.at(iii-1).mdata.wptime,oldremovedmines.at(iii-1).endyear);
        upperURR=upperURR-temper.mdata.URR;
        wellsy=wellsy-temper.mdata.URR;
        lowerURR=lowerURR-temper.mdata.URR;
        temper.mdata.minelife=oldremovedmines.at(iii-1).mdata.minelife;
        temper.mdata.wpremainingres=oldremovedmines.at(iii-1).mdata.wpremainingres;
        temper.mdata.wptime=oldremovedmines.at(iii-1).mdata.wptime;
        temper.mdata.lowURRdeterminor=oldremovedmines.at(iii-1).mdata.lowURRdeterminor;
        temper.endyear=oldremovedmines.at(iii-1).endyear;
        temper.upgrade=oldremovedmines.at(iii-1).upgrade;
        temper.remainres=oldremovedmines.at(iii-1).remainres+upgradprodattimet(oldremovedmines.at(iii-1).mdata.URR,oldremovedmines.at(iii-1).mdata.wpremainingres,oldremovedmines.at(iii-1).mdata.maximprod,ramping_time,oldremovedmines.at(iii-1).startyear, i, overrider, oldremovedmines.at(iii-1).mdata.wptime,oldremovedmines.at(iii-1).endyear);
        removedmines.push_back(temper);
      }
    }
    for (b=1;b<=(int)(removedmines.size());b++)
    {
      shutdownmines.push_back(removedmines.at(b-1));
    }
    maxoffline=maxoffline+removedmines.size();
    for (iii=1;iii<=removedmines.size();iii++)
    {
      if (oldremovedmines.at(iii-1).upgrade==-1)
      {
        for (b=(int)(i-removedmines.at(iii-1).startyear+1);b<=(int)(removedmines.at(iii-1).endyear-removedmines.at(iii-1).startyear+1);b++)
        {
          yearlybasinprod.at(int(b+removedmines.at(iii-1).startyear-2))=yearlybasinprod.at(int(b+removedmines.at(iii-1).startyear-2))-prodmineattimet(oldy.at(iii-1).mdata.URR, oldy.at(iii-1).mdata.maximprod, ramping_time,oldy.at(iii-1).startyear, b-1+oldy.at(iii-1).startyear, overrider);
        }
      }
      else
      {
        for (b=(int)(i-removedmines.at(iii-1).startyear+1);b<=(int)(removedmines.at(iii-1).endyear-removedmines.at(iii-1).startyear+1);b++)
        {
          yearlybasinprod.at((int)(b+removedmines.at(iii-1).startyear-2))=yearlybasinprod.at((int)(b+removedmines.at(iii-1).startyear-2))-upgradprodattimet(oldy.at(iii-1).mdata.URR,oldy.at(iii-1).mdata.wpremainingres,oldy.at(iii-1).mdata.maximprod,ramping_time,oldy.at(iii-1).startyear, b+removedmines.at(iii-1).startyear-1, overrider, oldy.at(iii-1).mdata.wptime,oldy.at(iii-1).endyear);
        }
      }
    }
  }








  oldtotalmines=totalmines;
// has the disruption ended?
  oldindisruption=indisruption;
  if (indisruption)
  {
    if (disruptions.at((int)(whichdisruption-1)).enddisr==yearfind+i-2)
    {
      indisruption=false;
    }
  }
// are we in a disruption?
  if (!disruptions.empty())
  {
    for (kk=1;kk<=disruptions.size();kk++)
    {
      if (disruptions.at(kk-1).startdisr==yearfind+i-1)
      {
        indisruption=true;
        backtonormal=false;
        predisruptionURRs=wellsy;
        predisruptionmines=totalmines;
        whichdisruption=kk;
        cminesize=currentmines.size();
      }
    }
  }
//this bit fixes the cumulative production for anomalies

  resetcumm=false;
  if (indisruption)
  {
    if (disruptions.at((int)(whichdisruption-1)).enddisr==yearfind+i-2)
    {
      resetcumm=true;
    }
  }
  if (i==1)
  {
    cumm_prod=0;
  }
  else
  {
    cumm_prod=cumm_prod+yearlybasinprod.at((int)(i-2));
  }
  if (cutters>0)
  {
    totalmines=totalmines-cutters;
    oldtotalmines=oldtotalmines-cutters;
    resetcumm=true;
  }
  if (resetcumm)
  {
    wellsy=wellsy-removeURR;
    lowerURR=wellsy;
    upperURR=upperURR-removeURR;
  }
  if (gonk)
  {
    cumm_prod=oldminesonlinerateb*cumm_prod/minesonlinerate;
    oldcumm_prod=cumm_prod-yearlybasinprod.at((int)(i-2));
  }




oldupperURR=upperURR;


// ending program stuff
  deltacumm_prod=cumm_prod-oldcumm_prod;
  oldcumm_prod=cumm_prod;
  fixtotalmines=0;
  if (!fixer)
  {
    tempblob=wellsy*(exp(-minesonlinerate*(deltacumm_prod/URR_basin))+(PP-PP*exp(-minesonlinerate*(deltacumm_prod/URR_basin)))/wellsy+k2gap); // removed *wellsy on k2gap
    if (!indisruption)
    {
      if ((tempblob<lowerURR)||(tempblob>upperURR))
      {
        if (tempblob<lowerURR)
        {
          tempmineset=currentmines;
          if (!tempmineset.empty())
          {
            oldtempmineset.clear();
            oldtempmineset=tempmineset;
            tempmineset.clear();
            for (iii=1;iii<=oldtempmineset.size();iii++)
            {
              if ((i+1<oldtempmineset.at(iii-1).endyear+1)&&(oldtempmineset.at(iii-1).remainres>0))
              {
                if (oldtempmineset.at(iii-1).upgrade==-1)
                {
                  temper.startyear=oldtempmineset.at(iii-1).startyear;
                  temper.mdata.maximprod=oldtempmineset.at(iii-1).mdata.maximprod;
                  temper.mdata.URR=oldtempmineset.at(iii-1).mdata.URR;
                  temper.mdata.minelife=oldtempmineset.at(iii-1).mdata.minelife;
                  temper.mdata.wpremainingres=oldtempmineset.at(iii-1).mdata.wpremainingres;
                  temper.mdata.wptime=oldtempmineset.at(iii-1).mdata.wptime;
                  temper.mdata.lowURRdeterminor=oldtempmineset.at(iii-1).mdata.lowURRdeterminor;
                  temper.endyear=oldtempmineset.at(iii-1).endyear;
                  temper.upgrade=oldtempmineset.at(iii-1).upgrade;
                  temper.remainres=oldtempmineset.at(iii-1).remainres-prodmineattimet(oldtempmineset.at(iii-1).mdata.URR, oldtempmineset.at(iii-1).mdata.maximprod, ramping_time,oldtempmineset.at(iii-1).startyear, (int)(i+1), overrider);
                  tempmineset.push_back(temper);
                }
                else
                {
                  temper.startyear=oldtempmineset.at(iii-1).startyear;
                  temper.mdata.maximprod=oldtempmineset.at(iii-1).mdata.maximprod;
                  temper.mdata.URR=oldtempmineset.at(iii-1).mdata.URR;
                  temper.mdata.minelife=oldtempmineset.at(iii-1).mdata.minelife;
                  temper.mdata.wpremainingres=oldtempmineset.at(iii-1).mdata.wpremainingres;
                  temper.mdata.wptime=oldtempmineset.at(iii-1).mdata.wptime;
                  temper.mdata.lowURRdeterminor=oldtempmineset.at(iii-1).mdata.lowURRdeterminor;
                  temper.endyear=oldtempmineset.at(iii-1).endyear;
                  temper.upgrade=oldtempmineset.at(iii-1).upgrade;
                  temper.remainres=oldtempmineset.at(iii-1).remainres-upgradprodattimet(oldtempmineset.at(iii-1).mdata.URR,oldtempmineset.at(iii-1).mdata.wpremainingres,oldtempmineset.at(iii-1).mdata.maximprod,ramping_time,oldtempmineset.at(iii-1).startyear, i+1, overrider, oldtempmineset.at(iii-1).mdata.wptime,oldtempmineset.at(iii-1).endyear);
                  tempmineset.push_back(temper);
                }
              }
            }
          }
          if (tempmineset.size()>0)
          {
            totalmines=totalmines-howmanyminestoremove(tempmineset,ramping_time,i+1,lowerURR-tempblob,overrider);
          }
          else
          {
            totalmines=totalmines;
          }
          wellsy=wellsy;
          lowerURR=lowerURR;
          upperURR=upperURR;
        }
        if ((tempblob>upperURR)&&(upperURR!=URR_basin))
        {
          if (tempblob>URR_basin)
          {
            tempblob=URR_basin;
          }
          if (!shutdownmines.empty())
          {
            goingon=true;
            indexer=shutdownmines.size()-1;
            while(goingon)
            {
              upperURR=upperURR+shutdownmines.at(indexer).mdata.URR;
              totalmines++;
              fixtotalmines++;
              if ((indexer==0)||(tempblob<=upperURR))
              {
                goingon=false;
              }
              indexer--;
            }
            if (tempblob<=upperURR)
            {
              wellsy=tempblob;
              lowerURR=wellsy;
            }
          }
          if ((tempblob>upperURR)&&(upperURR!=URR_basin))
          {
            mineMP=(Max_prodLOW+Max_prodHIGH)/2+((Max_prodHIGH-Max_prodLOW)/2)*(tanh(Max_prodRATE*(yearfind+i-1-Max_prodCY)));
            //mineLIFE=(ML_LOW+ML_HIGH)/2+((ML_HIGH-ML_LOW)/2)*(tanh(Max_prodRATE*(yearfind+i-1-Max_prodCY)));
            if (Max_prodLOW!=Max_prodHIGH)
            {
              mineLIFE=ML_HIGH+(ML_LOW-ML_HIGH)*((log10(mineMP/Max_prodHIGH))/(log10(Max_prodLOW/Max_prodHIGH)));
            }
            else
            {
              mineLIFE=(ML_LOW+ML_HIGH)/2;
            }
            if (mineLIFE>2*ramping_time)
            {
              mineURR=(mineMP*(mineLIFE-ramping_time));
            }
            else
            {
              mineURR=(mineMP*mineLIFE)/(2*ramping_time);
            }
            if (mineURR>URR_basin-upperURR)
            {
              mineURR=URR_basin-upperURR;
            }
            tempmines=ceil((tempblob-upperURR)/(mineURR))+totalmines;
            if ((tempmines-totalmines)*mineURR+upperURR>URR_basin)
            {
              grr=false;
              tempcount=0;
              for (iii=(int)totalmines+1;iii<=tempmines;iii++)
              {
                tempcount++;
                if (grr==false)
                {
                  if (tempcount*(mineURR)+upperURR>URR_basin)
                  {
                    totalmines=totalmines+tempcount;
                    mineURR=(URR_basin-upperURR)/(tempcount);
                    grr=true;
                  }
                }
              }
            }
            else
            {
              totalmines=tempmines;
            }
            wellsy=tempblob;
            lowerURR=wellsy;
            upperURR=upperURR+(totalmines-oldtotalmines-fixtotalmines)*mineURR;
          }
        }
        if (upperURR==URR_basin)
        {
          wellsy=wellsy;
          totalmines=totalmines;
          lowerURR=wellsy;
          upperURR=upperURR;
        }
      }
      else
      {
        wellsy=tempblob;
        totalmines=totalmines;
        lowerURR=wellsy;
        upperURR=upperURR;
      }
    }
  }
  if (indisruption)
  {
    tempblob=(predisruptionURRs*(((disruptions.at((int)(whichdisruption-1)).endmines-disruptions.at((int)(whichdisruption-1)).intmines)*(yearfind+i-1-disruptions.at((int)(whichdisruption-1)).startdisr))/(disruptions.at((int)(whichdisruption-1)).enddisr-disruptions.at((int)(whichdisruption-1)).startdisr)+disruptions.at((int)(whichdisruption-1)).intmines));
    if ((tempblob<lowerURR)||(tempblob>upperURR))
    {
      if (tempblob<lowerURR)
      {
        totalmines=predisruptionmines-cminesize+ceil(cminesize*(((disruptions.at((int)(whichdisruption-1)).endmines-disruptions.at((int)(whichdisruption-1)).intmines)*(yearfind+i-1-disruptions.at((int)(whichdisruption-1)).startdisr))/(disruptions.at((int)(whichdisruption-1)).enddisr-disruptions.at((int)(whichdisruption-1)).startdisr)+disruptions.at((int)(whichdisruption-1)).intmines));
      }
      if ((tempblob>upperURR)&&(upperURR!=URR_basin))
      {
        if (tempblob>URR_basin)
        {
          tempblob=URR_basin;
        }
        if (!shutdownmines.empty())
        {
          goingon=true;
          indexer=shutdownmines.size()-1;
          while(goingon)
          {
            upperURR=upperURR+shutdownmines.at(indexer).mdata.URR;
            totalmines++;
            fixtotalmines++;
            if ((indexer==0)||(tempblob<=upperURR))
            {
              goingon=false;
            }
            indexer--;
          }
          if (tempblob<=upperURR)
          {
            wellsy=tempblob;
            lowerURR=wellsy;
          }
        }
        if ((tempblob>upperURR)&&(upperURR!=URR_basin))
        {
          mineMP=(Max_prodLOW+Max_prodHIGH)/2+((Max_prodHIGH-Max_prodLOW)/2)*(tanh(Max_prodRATE*(yearfind+i-1-Max_prodCY)));
          if (Max_prodLOW!=Max_prodHIGH)
            {
              mineLIFE=ML_HIGH+(ML_LOW-ML_HIGH)*((log10(mineMP/Max_prodHIGH))/(log10(Max_prodLOW/Max_prodHIGH)));
            }
            else
            {
              mineLIFE=(ML_LOW+ML_HIGH)/2;
            }



          if (mineLIFE>2*ramping_time)
          {
            mineURR=(mineMP*(mineLIFE-ramping_time));
          }
          else
          {
            mineURR=(mineMP*mineLIFE)/(2*ramping_time);
          }
          if (mineURR>URR_basin-upperURR)
          {
            mineURR=URR_basin-upperURR;
          }
          tempmines=ceil((tempblob-upperURR)/(mineURR))+totalmines;
          if ((tempmines-totalmines)*mineURR+upperURR>URR_basin)
          {
            grr=false;
            tempcount=0;
            for (iii=(int)totalmines+1;iii<=tempmines;iii++)
            {
              tempcount++;
              if (grr==false)
              {
                if (tempcount*(mineURR)+upperURR>URR_basin)
                {
                  totalmines=totalmines+tempcount;
                  mineURR=(URR_basin-upperURR)/(tempcount);
                  grr=true;
                }
              }
            }
          }
          else
          {
            totalmines=tempmines;
          }
          wellsy=tempblob;
          lowerURR=wellsy;
          upperURR=upperURR+(totalmines-oldtotalmines-fixtotalmines)*mineURR;
        }
      }
      if (upperURR==URR_basin)
      {
        wellsy=wellsy;
        totalmines=totalmines;
        lowerURR=wellsy;
        upperURR=upperURR;
      }
    }
    else
    {
      wellsy=tempblob;
      totalmines=totalmines;
      lowerURR=wellsy;
      upperURR=upperURR;
    }
  }
  goop=false;
  if ((yearlybasinprod.at((int)(i))<pow(10,-7))&&(totalmines<=oldtotalmines))
  {
    if ((URR_basin-upperURR<pow(10,-7)))
    {
      basinlifechecker=false;
    }
    else
    {
      wellsy = URR_basin;
      lowerURR=URR_basin;
      fixer=true;
      goop=true;
    }
  }
  if (goop==true)
  {
    totalmines=oldtotalmines;
    if (!shutdownmines.empty())
    {
      goingon=true;
      indexer=shutdownmines.size()-1;
      while(goingon)
      {
        upperURR=upperURR+shutdownmines.at(indexer).mdata.URR;
        totalmines++;
        fixtotalmines++;
        if ((indexer==0))
        {
          goingon=false;
        }
        indexer--;
      }
    }
    mineMP=(Max_prodLOW+Max_prodHIGH)/2+((Max_prodHIGH-Max_prodLOW)/2)*(tanh(Max_prodRATE*(yearfind+i-1-Max_prodCY)));
    if (Max_prodLOW!=Max_prodHIGH)
    {
      mineLIFE=ML_HIGH+(ML_LOW-ML_HIGH)*((log10(mineMP/Max_prodHIGH))/(log10(Max_prodLOW/Max_prodHIGH)));
    }
    else
    {
      mineLIFE=(ML_LOW+ML_HIGH)/2;
    }
    if (mineLIFE>2*ramping_time)
    {
      mineURR=(mineMP*(mineLIFE-ramping_time));
    }
    else
    {
      mineURR=(mineMP*mineLIFE)/(2*ramping_time);
    }
    grr=false;
    tempcount=0;
    while (grr==false)
    {
      tempcount++;
      if (tempcount*(mineURR)+upperURR>URR_basin)
      {
        totalmines=totalmines+tempcount;
        mineURR=(URR_basin-upperURR)/(tempcount);
        grr=true;
        upperURR=URR_basin;
      }
    }
  }
  if ((yearfind+timedelay+i-1 >= abort)&&(abort!=-1))
  {
    basinlifechecker = false;
    for (b=(int)(i);b<yearlybasinprod.size();b++)
    {
      yearlybasinprod.at(b) = 0;
    }
    if (yearfind+timedelay>=abort)
    {
      for (b=0;b<yearlybasinprod.size();b++)
      {
        yearlybasinprod.at((int)(i-1)) = 0;
      }
    }
  }
  supply=yearlybasinprod.at((int)i-1);
  returngah.maxprod=maxprod;
  returngah.maybemaxprod=maybemaxprod;
  returngah.yearlybasinprodmod=yearlybasinprod;
  returngah.futuretime=futuretime;
  returngah.oldcurrentmines=oldcurrentmines;
  returngah.currentmines=currentmines;
  returngah.shutdownmines=shutdownmines;
  returngah.totalmines=totalmines;
  returngah.oldtotalmines=oldtotalmines;
  returngah.cumm_prod=cumm_prod;
  returngah.indisruption=indisruption;
  returngah.oldindisruption=oldindisruption;
  returngah.whichdisruption=whichdisruption;
  returngah.backtonormal=backtonormal;
  returngah.predisruptionURRs=predisruptionURRs;
  returngah.predisruptionmines=predisruptionmines;
  returngah.cminesize=cminesize;
  returngah.cummminesshutdown=cummminesshutdown;
  returngah.oldcummminesshutdown=oldcummminesshutdown;
  returngah.basinlifechecker=basinlifechecker;
  returngah.maxoffline=maxoffline;
  returngah.oldcumm_prod=oldcumm_prod;
  returngah.wellsy=wellsy;
  returngah.supply=supply;
  returngah.countingmines=countingmines;
  returngah.mineURR=mineURR;
  returngah.mineMP=mineMP;
  returngah.upperURR=upperURR;
  returngah.lowerURR=lowerURR;
  returngah.fixer=fixer;
  return returngah;
};











vector<returningdata> completemodel(vector<reservwelldata> reswelldata, vector<reservdata> resminedata, double shutoffpercent, int timedelay, double initdemand, double kDD,double maxdemand, double k1, double k2, double k3, double k4, double whendisc, double k5, double whenupgrade, double gapdelay, double foil, double fcoal, double fgas  ,double maxpop, double popinit, double poprate, double popmidyear, double popB, double popGamma, double coalmax, double coalmin, double coalrate, double coalmidyear, double coalB, double coalGamma, double gasmax, double gasmin, double gasrate, double gasmidyear, string whichoption  ,  vector<changer> demandchanger ,vector<double> recycler)
{
  returningdata tempery;
  vector<returningdata> prodder;
  vector<vector<cwells> > currentwells[(int)reswelldata.size()+1];
  vector<vector<cwells> > oldcurrentwells[(int)reswelldata.size()+1];
  vector<vector<cwells> > shutdownwells[(int)reswelldata.size()+1];
  vector<cmines> currentmines[(int)resminedata.size()+1];
  vector<cmines> oldcurrentmines[(int)resminedata.size()+1];
  vector<cmines> shutdownmines[(int)resminedata.size()+1];
  double kD, lowyear, lowyeartester, population, temp, demandall,demandoil,demandcoal;
  double demandgas, supplyall, supplyoil,supplycoal,supplygas, Gapinuse, Gapall, Gapoil, Gapcoal, Gapgas;
  double fracoil, fracgas, fraccoal, smallergapinuseupgrade, smallergapallupgrade, smallergapoilupgrade;
  double smallergapgasupgrade, smallergapcoalupgrade, smallergapinusedisc, smallergapalldisc, smallergapoildisc;
  double smallergapgasdisc, smallergapcoaldisc;
  double cminesize[(int)resminedata.size()+1];
  double cummminesshutdown[(int)resminedata.size()+1];
  double minecumm_prod[(int)resminedata.size()+1];
  double fmine[(int)resminedata.size()+1];
  double fwell[(int)reswelldata.size()+1];
  double fieldstotal[(int)reswelldata.size()+1];
  double fieldsCP[(int)reswelldata.size()+1];
  double fieldsrate[(int)reswelldata.size()+1];
  double fieldsy[(int)reswelldata.size()+1];
  double founditwhenmines[(int)resminedata.size()+1];
  double founditwhenwells[(int)reswelldata.size()+1];
  double lastminedisruptionend[(int)resminedata.size()+1];
  double lastwelldisruptionend[(int)reswelldata.size()+1];
  double lowerURR[(int)resminedata.size()+1];
  double minemaxprod[(int)resminedata.size()+1];
  double Max_prodLOW[(int)resminedata.size()+1];
  double Max_prodHIGH[(int)resminedata.size()+1];
  double Max_prodCY[(int)resminedata.size()+1];
  double Max_prodRATE[(int)resminedata.size()+1];
  double Max_prodinit[(int)resminedata.size()+1];
  double Max_prod[(int)resminedata.size()+1];
  double minemaxoffline[(int)resminedata.size()+1];
  double maybeminemaxprod[(int)resminedata.size()+1];
  double mineMP[(int)resminedata.size()+1];
  double minesonlinerate[(int)resminedata.size()+1];
  double mineURR[(int)resminedata.size()+1];
  double mineURR_basin[(int)resminedata.size()+1];
  double minesupplier[(int)resminedata.size()+1];
  double mineabort[(int)resminedata.size()+1];
  double minemax_capacity[(int)resminedata.size()+1];
  double mintime[(int)resminedata.size()+1];
  double ML_LOW[(int)resminedata.size()+1];
  double ML_HIGH[(int)resminedata.size()+1];
  double MLinit[(int)resminedata.size()+1];
  double ML[(int)resminedata.size()+1];
  double numberwells[(int)reswelldata.size()+1];
  double oldminecumm_prod[(int)resminedata.size()+1];
  double oldcummminesshutdown[(int)resminedata.size()+1];
  double oldfieldstotal[(int)reswelldata.size()+1];
  double oldminesonlinerate[(int)resminedata.size()+1];
  double oldtotalmines[(int)resminedata.size()+1];
  double powernum[(int)reswelldata.size()+1];
  double maximwell[(int)reswelldata.size()+1];
  double PP[(int)resminedata.size()+1];
  double predisruptionURRs[(int)resminedata.size()+1];
  double predisruptionmines[(int)resminedata.size()+1];
  double ramping_time[(int)resminedata.size()+1];
  double rampup_time[(int)reswelldata.size()+1];
  double realnumwells[(int)reswelldata.size()+1];
  double totalmines[(int)resminedata.size()+1];
  double totalfields[(int)reswelldata.size()+1];
  double upperURR[(int)resminedata.size()+1];
  double URRinit[(int)resminedata.size()+1];
  double URRwtoR0[(int)reswelldata.size()+1];
  double URRwtoURRr[(int)reswelldata.size()+1];
  double minewellsy[(int)resminedata.size()+1];
  double wellsupplier[(int)reswelldata.size()+1];
  double wellURR_basin[(int)reswelldata.size()+1];
  double wellmax_capacity[(int)reswelldata.size()+1];
  double wellabort[(int)reswelldata.size()+1];
  double wellwhenparity[(int)reswelldata.size()+1];
  double whencross[(int)reswelldata.size()+1];
  double whichminedisruption[(int)resminedata.size()+1];
  double mineyearfind[(int)resminedata.size()+1];
  vector<double> mineyearlybasinprod[(int)resminedata.size()+1];
  vector<double> wellyearlybasinprod[(int)reswelldata.size()+1];
  vector<vector<double> > overrider;
  vector<vector<double> > mineprods[(int)resminedata.size()+1];
  vector<vector<double> > mineprodupgrades[(int)resminedata.size()+1];
  vector<double> wellsonlinerate[(int)reswelldata.size()+1];
  vector<double> oldwellsonlinerate[(int)reswelldata.size()+1];
  vector<double> stupid[(int)reswelldata.size()+1];
  vector<double> totsupply;
  vector<double> fieldtime[(int)reswelldata.size()+1];
  vector<double> URR_fields[(int)reswelldata.size()+1];
  vector<double> wellcumm_prod[(int)reswelldata.size()+1];
  vector<double> oldwellsURR[(int)reswelldata.size()+1];
  vector<double> cummwellsshutdown[(int)reswelldata.size()+1];
  vector<double> wellmaxprod[(int)reswelldata.size()+1];
  vector<double> maybewellmaxprod[(int)reswelldata.size()+1];
  vector<double> oldwellcumm_prod[(int)reswelldata.size()+1];
  vector<double> oldtotalwells[(int)reswelldata.size()+1];
  vector<double> howmanywells[(int)reswelldata.size()+1];
  vector<double> totalwells[(int)reswelldata.size()+1];
  vector<double> wellwellsy[(int)reswelldata.size()+1];
  vector<double> wellmaxoffline[(int)reswelldata.size()+1];
  vector<double> oldcummwellsshutdown[int(reswelldata.size()+1)];
  vector<double> whichwelldisruption[(int)reswelldata.size()+1];
  vector<double> predisruptionwells[(int)reswelldata.size()+1];
  vector<vector<double> > fieldproduction[(int)reswelldata.size()+1];
  int z, kk, c, i;
  int countingmines[(int)resminedata.size()+1];
  int minefuturetime[(int)resminedata.size()+1];
  int wellfuturetime[(int)reswelldata.size()+1];
  int wellyearfind[(int)reswelldata.size()+1];
  vector<int> countingwells[(int)reswelldata.size()+1];
  vector<int> oldcountingwells[(int)reswelldata.size()+1];
  vector<int> yearfieldfound[(int)reswelldata.size()+1];
  bool minealterpreferences[(int)resminedata.size()+1];
  bool wellalterpreferences[(int)reswelldata.size()+1];
  bool basinender;
  bool minebasinlifechecker[(int)resminedata.size()+1];
  bool wellbasinlifechecker[(int)reswelldata.size()+1];
  bool minebacktonormal[(int)resminedata.size()+1];
  bool minecummswitcher[(int)resminedata.size()+1];
  bool wellcummswitcher[(int)reswelldata.size()+1];
  bool minefixer[(int)resminedata.size()+1];
  bool minegonk[(int)resminedata.size()+1];
  bool wellgonk[(int)reswelldata.size()+1];
  bool tripped[(int)reswelldata.size()+1];
  int mineindisruption[(int)resminedata.size()+1];
  bool ARGH;
  bool oldmineindisruption[(int)resminedata.size()+1];
  vector<int> wellbacktonormal[(int)reswelldata.size()+1];
  vector<int> fieldlifechecker[(int)reswelldata.size()+1];
  vector<int> wellfixer[(int)reswelldata.size()+1];
  vector<int> wellindisruption[(int)reswelldata.size()+1];
  vector<int> oldwellindisruption[(int)reswelldata.size()+1];
  string minetitle[(int)resminedata.size()+1];
  string welltitle[(int)reswelldata.size()+1];
  string minetype[(int)resminedata.size()+1];
  string welltype[(int)reswelldata.size()+1];
  vector<vector<disr> > minedisruptions;
  vector<vector<disr> > welldisruptions;
  vector<chpref> minechangedpreferences[(int)resminedata.size()+1];
  vector<chprefwell> wellchangedpreferences[(int)reswelldata.size()+1];
  production temp4, temper;
  vector<production> basin_prod, demanderall, demanderoil, recycle, demandergas, demandercoal;
  production atemp;
  wellpainfulfields wellicky;
  painful mineicky;
  kD=kDD;
  for (z=1;z<=reswelldata.size();z++)
  {
    lowyeartester=reswelldata.at(z-1).founditwhen;
    if (z==1)
    {
      lowyear=lowyeartester;
    }
    if (lowyeartester<lowyear)
    {
      lowyear=lowyeartester;
    }
  }
  for (z=1;z<=resminedata.size();z++)
  {
    lowyeartester=resminedata.at(z-1).founditwhen;
    if ((reswelldata.empty())&&(z==1))
    {
      lowyear=lowyeartester;
    }
    if (lowyeartester<lowyear)
    {
      lowyear=lowyeartester;
    }
  }
  for (z=1; z<=reswelldata.size();z++)
  {
    wellalterpreferences[z]=false;
    wellURR_basin[z]=reswelldata.at(z-1).URR_basin;
    founditwhenwells[z]=reswelldata.at(z-1).founditwhen;
    wellwhenparity[z]=reswelldata.at(z-1).whenparity;
    numberwells[z]=reswelldata.at(z-1).numberwells;
    rampup_time[z]=reswelldata.at(z-1).rampup_time;
    wellmax_capacity[z]=reswelldata.at(z-1).max_capacity;
    URRwtoR0[z]=reswelldata.at(z-1).URRwtoR0;
    URRwtoURRr[z]=reswelldata.at(z-1).URRwtoURRr;
    powernum[z]=reswelldata.at(z-1).powernum;
    maximwell[z]=reswelldata.at(z-1).maximwell;
    whencross[z]=reswelldata.at(z-1).whencross;
    totalfields[z]=reswelldata.at(z-1).howmanyfields;
    fieldsrate[z]=reswelldata.at(z-1).fieldsrate;
    welltitle[z]=reswelldata.at(z-1).title;
    welltype[z]=reswelldata.at(z-1).type;
    wellabort[z] = reswelldata.at(z-1).abort;
    welldisruptions.push_back(reswelldata.at(z-1).disruptions);
    wellchangedpreferences[z]=reswelldata.at(z-1).changedpreferences;
    if ((reswelldata.at(z-1).type=="Oil")||(reswelldata.at(z-1).type=="Coal")||(reswelldata.at(z-1).type=="Gas"))
    {
      if (reswelldata.at(z-1).type=="Oil")
      {
        fwell[z]=foil;
      }
      if (reswelldata.at(z-1).type=="Coal")
      {
        fwell[z]=fcoal;
      }
      if (reswelldata.at(z-1).type=="Gas")
      {
        fwell[z]=fgas;
      }
    }
    else
    {
      //cout<<"oi what the fuel type "<<reswelldata.at(z-1).type<<endl;
      fwell[z]=1;
    }
    if (!wellchangedpreferences[z].empty())
    {
      wellalterpreferences[z]=true;
    }
    wellyearfind[z]=(int)founditwhenwells[z]+(int)timedelay;
    wellbasinlifechecker[z]=true;
    wellcummswitcher[z]=false;
    lastwelldisruptionend[z]=0;
    tripped[z]=false;
    for (kk=0;kk<welldisruptions.at(z-1).size();kk++)
    {
      if (welldisruptions.at(z-1).at(kk).enddisr>lastwelldisruptionend[z])
      {
        lastwelldisruptionend[z]=welldisruptions.at(z-1).at(kk).enddisr;
      }
      if (welldisruptions.at(z-1).at(kk).enddisr<=welldisruptions.at(z-1).at(kk).startdisr)
      {
        cout<<"your disruptions make no sense"<<endl;
      }
    }
    for (kk=0;kk<(int)(welldisruptions.at(z-1).size())-1;kk++)
    {
      if (welldisruptions.at(z-1).at(kk).enddisr>welldisruptions.at(z-1).at(kk+1).startdisr)
      {
        cout<<"the disruptions overlap incorrectly "<<z<<" "<<welldisruptions.at(z-1).at(kk).enddisr<<" "<<welldisruptions.at(z-1).at(kk+1).startdisr<<endl;
      }
    }
    oldfieldstotal[z]=0;
    fieldstotal[z]=1;
    fieldsCP[z]=0;
    realnumwells[z]=numberwells[z];
    wellfuturetime[z]=(int)ceil(wellyearfind[z]+timedelay);
  }
  for (z=1; z<=resminedata.size();z++)
  {
    minealterpreferences[z]=false;
    mineURR_basin[z]=resminedata.at(z-1).URR_basin;
    founditwhenmines[z]=resminedata.at(z-1).founditwhen;
    Max_prodLOW[z]=resminedata.at(z-1).Max_prodLOW;
    Max_prodHIGH[z]=resminedata.at(z-1).Max_prodHIGH;
    Max_prodCY[z]=resminedata.at(z-1).Max_prodCY;
    Max_prodRATE[z]=resminedata.at(z-1).Max_prodRATE;
    ML_LOW[z]=resminedata.at(z-1).MinelifeLOW;
    ML_HIGH[z]=resminedata.at(z-1).MinelifeHIGH;
    minesonlinerate[z]=resminedata.at(z-1).minesonlinerate;
    oldminesonlinerate[z]=minesonlinerate[z];
    cminesize[z]=0;
    predisruptionURRs[z]=0;
    predisruptionmines[z]=0;
    whichminedisruption[z]=0;
    ramping_time[z]=resminedata.at(z-1).ramping_time;
    minemax_capacity[z]=resminedata.at(z-1).max_capacity;
    mineabort[z] = resminedata.at(z-1).abort;
    minetitle[z]=resminedata.at(z-1).title;
    minetype[z]=resminedata.at(z-1).type;
    minedisruptions.push_back(resminedata.at(z-1).disruptions);
    overrider.push_back(resminedata.at(z-1).overrider);
    mintime[z]=resminedata.at(z-1).mintime;
    minefixer[z]=false;
    minemaxoffline[z]=0;
    minechangedpreferences[z]=resminedata.at(z-1).changedpreferences;
    if ((resminedata.at(z-1).type=="Oil")||(resminedata.at(z-1).type=="Coal")||(resminedata.at(z-1).type=="Gas"))
    {
      if (resminedata.at(z-1).type=="Oil")
      {
        fmine[z]=foil;
      }
      if (resminedata.at(z-1).type=="Coal")
      {
        fmine[z]=fcoal;
      }
      if (resminedata.at(z-1).type=="Gas")
      {
        fmine[z]=fgas;
      }
    }
    else
    {
      //cout<<"oi what the fuel type "<<resminedata.at(z-1).type<<endl;
      fmine[z]=1;
    }
    if (!minechangedpreferences[z].empty())
    {
      minealterpreferences[z]=true;
    }
    mineyearfind[z]=founditwhenmines[z]+timedelay;
    minecumm_prod[z]=0;
    mineindisruption[z]=false;
    cummminesshutdown[z]=0;
    oldcummminesshutdown[z]=0;
    minecummswitcher[z]=false;
    minebacktonormal[z]=true;
    lastminedisruptionend[z]=0;
    for (kk=0;kk<minedisruptions.at(z-1).size();kk++)
    {
      if (minedisruptions.at(z-1).at(kk).enddisr>lastminedisruptionend[z])
      {
        lastminedisruptionend[z]=minedisruptions.at(z-1).at(kk).enddisr;
      }
      if (minedisruptions.at(z-1).at(kk).enddisr<=minedisruptions.at(z-1).at(kk).startdisr)
      {
        cout<<"your disruptions make no sense"<<endl;
      }
    }
    for (kk=0;kk<(int)(minedisruptions.at(z-1).size())-1;kk++)
    {
      if (minedisruptions.at(z-1).at(kk).enddisr>minedisruptions.at(z-1).at(kk+1).startdisr)
      {
        cout<<"the disruptions overlap incorrectly "<<z<<" "<<minedisruptions.at(z-1).at(kk).enddisr<<" "<<minedisruptions.at(z-1).at(kk+1).startdisr<<endl;
      }
    }
    minemaxprod[z]=0;
    maybeminemaxprod[z]=0;
    oldminecumm_prod[z]=0;
    oldtotalmines[z]=0;
    countingmines[z]=0;
    totalmines[z]=1;
    mineMP[z]=(Max_prodLOW[z]+Max_prodHIGH[z])/2+((Max_prodHIGH[z]-Max_prodLOW[z])/2)*(tanh(Max_prodRATE[z]*(mineyearfind[z]-Max_prodCY[z])));
    if (Max_prodLOW[z]!=Max_prodHIGH[z])
    {
      MLinit[z]=ML_HIGH[z]+(ML_LOW[z]-ML_HIGH[z])*((log10(mineMP[z]/Max_prodHIGH[z]))/(log10(Max_prodLOW[z]/Max_prodHIGH[z])));
    }
    else
    {
      MLinit[z]=(ML_LOW[z]+ML_HIGH[z])/2;
    }
    if (MLinit[z]>2*ramping_time[z])
    {
      mineURR[z]=(mineMP[z]*(MLinit[z]-ramping_time[z]));
    }
    else
    {
      mineURR[z]=(mineMP[z]*MLinit[z])/(2*ramping_time[z]);
    }
    if (mineURR[z]>mineURR_basin[z])
    {
      mineURR[z]=mineURR_basin[z];
    }
    lowerURR[z]=mineURR[z];
    upperURR[z]=mineURR[z];
    minewellsy[z]=mineURR[z];
    PP[z]=(-mineURR_basin[z]+lowerURR[z]*exp(-minesonlinerate[z]))/(exp(-minesonlinerate[z])-1);
    minebasinlifechecker[z]=true;
    mineyearlybasinprod[z].push_back(0);
    minefuturetime[z]=(int)ceil(mineyearfind[z]+timedelay);
  }
  basinender=true;
  Gapall=0;
  Gapoil=0;
  Gapcoal=0;
  Gapgas=0;
  demandall=initdemand;
  demandoil=initdemand;
  demandcoal=initdemand;
  demandgas=initdemand;
  //population=((maxpop-popinit)/2)*(tanh(poprate*(lowyear-popmidyear)))+(maxpop+popinit)/2;
  population=(maxpop-popinit)/(pow(1+popB*exp(-poprate*popGamma*(lowyear-popmidyear)),1/popGamma))+popinit;
  //above is all just initiating things
  if ((whichoption=="all")||(whichoption=="components"))
  {
    if (whichoption=="all")
    {
      temp4.year=lowyear;
      temp4.amount=demandall*population;
      demanderall.push_back(temp4);
    }
    else
    {
      temp4.year=lowyear;
      fraccoal=coalmax-(coalmax-coalmin)/(pow(1+coalB*exp(-coalrate*coalGamma*(lowyear-coalmidyear)),(1/coalGamma)));
      if ((fraccoal>100)||(fraccoal<0))
      {
        cout<<"shoot fraccoal is wrong "<<fraccoal<<endl;
        if (fraccoal>100)
        {
          fraccoal=100;
        }
        else
        {
          fraccoal=0;
        }
      }
      temp4.amount=fraccoal*demandcoal*population/100;
      demandercoal.push_back(temp4);
      temp4.year=lowyear;
      fracgas=((gasmax-gasmin)/2)*tanh(gasrate*(lowyear-gasmidyear))+((gasmax+gasmin)/2);
      if ((fracgas>100)||(fracgas<0))
      {
        cout<<"shoot fracgas is wrong "<<fracgas<<endl;
        if (fracgas>100)
        {
          fracgas=100;
        }
        else
        {
          fracgas=0;
        }
      }
      temp4.amount=fracgas*demandgas*population/100;
      demandergas.push_back(temp4);
      temp4.year=lowyear;
      fracoil=100-fraccoal-fracgas;
      if ((fracoil>100)||(fracoil<0))
      {
        cout<<"shoot fracoil is wrong "<<fracoil<<endl;
        if (fracoil>100)
        {
          fracoil=100;
        }
        else
        {
          fracoil=0;
        }
      }
      temp4.amount=fracoil*demandoil*population/100;
      demanderoil.push_back(temp4);
      temp4.year=lowyear;
      temp4.amount=demandercoal.back().amount+demandergas.back().amount+demanderoil.back().amount;
      demanderall.push_back(temp4);
    }
  }
  else
  {
    cout<<"yo what demand type 1 ?? "<<whichoption<<endl;
  }
  i=1;
  while (basinender)
  {
    basinender=false;
    //population=((maxpop-popinit)/2)*(tanh(poprate*(lowyear+i-popmidyear)))+(maxpop+popinit)/2;
    population=(maxpop-popinit)/(pow(1+popB*exp(-poprate*popGamma*(lowyear+i-popmidyear)),1/popGamma))+popinit;
    temp=demandall*(exp(kD)-k1*Gapall);
    if (temp>maxdemand)
    {
      //demandall=demandall*(1-k1*Gapall);
      if (demandall>maxdemand)
      {
        demandall=demandall-demandall*k1*Gapall;
      }
      else
      {
        demandall=maxdemand-demandall*k1*Gapall;
      }
    }
    else
    {
      if (temp>0)
      {
      demandall=temp;
      }
      else
      {
      demandall=0;
      }
    }
    temp=demandoil*(exp(kD)-k1*Gapoil);
    if (temp>maxdemand)
    {
      if (demandoil>maxdemand)
      {
        demandoil=demandoil-demandoil*k1*Gapoil;
      }
      else
      {
        demandoil=maxdemand-demandoil*k1*Gapoil;
      }
    }
    else
    {
      if (temp>0)
      {
      demandoil=temp;
      }
      else
      {
      demandoil=0;
      }
    }
    temp=demandgas*(exp(kD)-k1*Gapgas);
    if (temp>maxdemand)
    {
      if (demandgas>maxdemand)
      {
        demandgas=demandgas-demandgas*k1*Gapgas;
      }
      else
      {
        demandgas=maxdemand-demandgas*k1*Gapgas;
      }
    }
    else
    {
      if (temp>0)
      {
      demandgas=temp;
      }
      else
      {
      demandgas=0;
      }
    }
    temp=demandcoal*(exp(kD)-k1*Gapcoal);
    if (temp>maxdemand)
    {
      if (demandcoal>maxdemand)
      {
        demandcoal=demandcoal-demandcoal*k1*Gapcoal;
      }
      else
      {
        demandcoal=maxdemand-demandcoal*k1*Gapcoal;
      }
    }
    else
    {
      if (temp>0)
      {
      demandcoal=temp;
      }
      else
      {
      demandcoal=0;
      }
    }
    if ((whichoption=="all")||(whichoption=="components"))
    {
      if (whichoption=="all")
      {
        temp4.year=lowyear+i;
        temp4.amount=demandall*population;
        demanderall.push_back(temp4);
      }
      else
      {
        temp4.year=lowyear+i;
        fraccoal=coalmax-(coalmax-coalmin)/(pow(1+coalB*exp(-coalrate*coalGamma*(lowyear+i-coalmidyear)),(1/coalGamma)));
        if ((fraccoal>100)||(fraccoal<0))
        {
          cout<<"shoot fraccoal is wrong "<<fraccoal<<endl;
          if (fraccoal>100)
          {
            fraccoal=100;
          }
          else
          {
            fraccoal=0;
          }
        }
        temp4.amount=fraccoal*demandcoal*population/100;
        demandercoal.push_back(temp4);
        temp4.year=lowyear+i;
        fracgas=((gasmax-gasmin)/2)*tanh(gasrate*(lowyear+i-gasmidyear))+((gasmax+gasmin)/2);
        if ((fracgas>100)||(fracgas<0))
        {
          cout<<"shoot fracgas is wrong "<<fracgas<<endl;
          if (fracgas>100)
          {
            fracgas=100;
          }
          else
          {
            fracgas=0;
          }
        }
        temp4.amount=fracgas*demandgas*population/100;
        demandergas.push_back(temp4);
        temp4.year=lowyear+i;
        fracoil=100-fraccoal-fracgas;
        if ((fracoil>100)||(fracoil<0))
        {
          cout<<"shoot fracoil is wrong "<<fracoil<<endl;
          if (fracoil>100)
          {
            fracoil=100;
          }
          else
          {
            fracoil=0;
          }
        }
        temp4.amount=fracoil*demandoil*population/100;
        demanderoil.push_back(temp4);
        temp4.year=lowyear+i;
        temp4.amount=demandercoal.back().amount+demandergas.back().amount+demanderoil.back().amount;
        demanderall.push_back(temp4);
      }
    }
    else
    {
      cout<<"yo what demand type 2 ?? "<<whichoption<<endl;
    }
    supplyall=0;
    supplyoil=0;
    supplygas=0;
    supplycoal=0;
    if ((whichoption=="all")||(whichoption=="components"))
    {
      if (whichoption=="all")
      {
        if (Gapall>0)
        {
          if (Gapall-whendisc>0)
          {
            smallergapalldisc=Gapall-whendisc;
          }
          else
          {
            smallergapalldisc=0;
          }
        }
        else
        {
          if (Gapall+whendisc<0)
          {
            smallergapalldisc=Gapall+whendisc;
          }
          else
          {
            smallergapalldisc=0;
          }
        }
        if (Gapall-whenupgrade>0)
        {
          smallergapallupgrade=Gapall-whenupgrade;
        }
        else
        {
          smallergapallupgrade=0;
        }
      }
      else
      {
        if (Gapoil>0)
        {
          if (Gapoil-whendisc>0)
          {
            smallergapalldisc=Gapoil-whendisc;
          }
          else
          {
            smallergapoildisc=0;
          }
        }
        else
        {
          if (Gapoil+whendisc<0)
          {
            smallergapoildisc=Gapoil+whendisc;
          }
          else
          {
            smallergapoildisc=0;
          }
        }
        if (Gapoil-whenupgrade>0)
        {
          smallergapoilupgrade=Gapoil-whenupgrade;
        }
        else
        {
          smallergapoilupgrade=0;
        }
        if (Gapgas>0)
        {
          if (Gapgas-whendisc>0)
          {
            smallergapgasdisc=Gapgas-whendisc;
          }
          else
          {
            smallergapgasdisc=0;
          }
        }
        else
        {
          if (Gapgas+whendisc<0)
          {
            smallergapgasdisc=Gapgas+whendisc;
          }
          else
          {
            smallergapgasdisc=0;
          }
        }
        if (Gapgas-whenupgrade>0)
        {
          smallergapgasupgrade=Gapgas-whenupgrade;
        }
        else
        {
          smallergapgasupgrade=0;
        }
        if (Gapcoal>0)
        {
          if (Gapcoal-whendisc>0)
          {
            smallergapcoaldisc=Gapcoal-whendisc;
          }
          else
          {
            smallergapcoaldisc=0;
          }
        }
        else
        {
          if (Gapcoal+whendisc<0)
          {
            smallergapcoaldisc=Gapcoal+whendisc;
          }
          else
          {
            smallergapcoaldisc=0;
          }
        }
        if (Gapcoal-whenupgrade>0)
        {
          smallergapcoalupgrade=Gapcoal-whenupgrade;
        }
        else
        {
          smallergapcoalupgrade=0;
        }
      }
    }
    else
    {
      cout<<"yo what demand type 3 ?? "<<whichoption<<endl;
    }
    for (z=1;z<=reswelldata.size();z++)
    {
      wellgonk[z]=false;
      if (wellalterpreferences[z])
      {
        if (wellchangedpreferences[z].at(0).year==lowyear+i-1)
        {
          wellwhenparity[z]=wellchangedpreferences[z].at(0).wellsonlinerate;
          wellmax_capacity[z] = wellchangedpreferences[z].at(0).max_capacity;
          wellgonk[z]=true;
        }
      }
      if (!demandchanger.empty())
      {
        if (demandchanger.front().year==lowyear+i-1)
        {
          kD=demandchanger.front().amount;
        }
      }
      if (i+lowyear-1<wellyearfind[z]+timedelay)
      {
        basinender=true;
      }
      if ((i+lowyear-1>=wellyearfind[z]+timedelay) && (wellbasinlifechecker[z]==true))
      {
        basinender=true;
        if ((whichoption=="all")||(whichoption=="components"))
        {
          if (whichoption=="all")
          {
             Gapinuse=Gapall;
             smallergapinuseupgrade=smallergapallupgrade;
             smallergapinusedisc=smallergapalldisc;
          }
          else
          {
            if (welltype[z]=="Oil")
            {
              Gapinuse=Gapoil;
              smallergapinuseupgrade=smallergapoilupgrade;
              smallergapinusedisc=smallergapoildisc;
            }
            if (welltype[z]=="Gas")
            {
              Gapinuse=Gapgas;
              smallergapinuseupgrade=smallergapgasupgrade;
              smallergapinusedisc=smallergapgasdisc;
            }
            if (welltype[z]=="Coal")
            {
              Gapinuse=Gapcoal;
              smallergapinuseupgrade=smallergapcoalupgrade;
              smallergapinusedisc=smallergapcoaldisc;
            }
          }
        }
        else
        {
          cout<<"yo what demand type 4 ?? "<<whichoption<<endl;
        }
        wellicky=fieldsmodel(wellyearfind[z], timedelay,wellyearlybasinprod[z],currentwells[z],oldcurrentwells[z],URRwtoURRr[z],URRwtoR0[z],shutoffpercent,rampup_time[z],(int)(i+lowyear) ,totalwells[z],oldtotalwells[z],shutdownwells[z], wellmaxprod[z]    ,maybewellmaxprod[z],wellmax_capacity[z]  ,oldcountingwells[z] ,countingwells[z], oldcummwellsshutdown[z], cummwellsshutdown[z], wellmaxoffline[z], wellindisruption[z], oldwellindisruption[z], welldisruptions.at(z-1), whichwelldisruption[z], wellbacktonormal[z] , predisruptionwells[z], wellcumm_prod[z]     , wellwellsy[z]     , numberwells[z]     , wellgonk[z]   , oldwellsonlinerate[z]         ,  wellsonlinerate[z] ,oldwellcumm_prod[z]      , realnumwells[z]     , wellbasinlifechecker[z]   , wellURR_basin[z], powernum[z], whencross[z], oldfieldstotal[z], fieldstotal[z], fieldsCP[z], totalfields[z], URR_fields[z],fieldsrate[z],yearfieldfound[z], fieldlifechecker[z],fieldproduction[z],fieldtime[z],fieldsy[z], k2*Gapinuse*fwell[z], k4*smallergapinusedisc*fwell[z], howmanywells[z],wellwhenparity[z], wellfixer[z], stupid[z] ,maximwell[z], oldwellsURR[z], tripped[z],wellabort[z]);
        stupid[z]=wellicky.stupid;
        fieldsy[z]=wellicky.fieldsy;
        tripped[z]=wellicky.tripped;
        howmanywells[z]=wellicky.howmanywells;
        fieldproduction[z]=wellicky.fieldproduction;
        fieldtime[z]=wellicky.fieldtime;
        fieldlifechecker[z]=wellicky.fieldlifechecker;
        oldfieldstotal[z]=wellicky.oldfieldstotal;
        fieldstotal[z]=wellicky.fieldstotal;
        fieldsCP[z]=wellicky.fieldsCP;
        oldwellsURR[z]=wellicky.oldwellsURR;
        yearfieldfound[z]=wellicky.yearfieldfound;
        wellsonlinerate[z]=wellicky.wellsonlinerate;
        oldwellsonlinerate[z]=wellicky.oldwellsonlinerate;
        URR_fields[z]=wellicky.URR_fields;
        wellfixer[z]=wellicky.fixer;
        wellmaxprod[z]=wellicky.maxprod;
        maybewellmaxprod[z]=wellicky.maybemaxprod;
        wellyearlybasinprod[z]=wellicky.yearlybasinprodmod;
        oldcurrentwells[z]=wellicky.oldcurrentwells;
        currentwells[z]=wellicky.currentwells;
        shutdownwells[z]=wellicky.shutdownwells;
        totalwells[z]=wellicky.totalwells;
        oldtotalwells[z]=wellicky.oldtotalwells;
        wellcumm_prod[z]=wellicky.cumm_prod;
        wellindisruption[z]=wellicky.indisruption;
        oldwellindisruption[z]=wellicky.oldindisruption;
        whichwelldisruption[z]=wellicky.whichdisruption;
        wellbacktonormal[z]=wellicky.backtonormal;
        predisruptionwells[z]=wellicky.predisruptionwells;
        cummwellsshutdown[z]=wellicky.cummwellsshutdown;
        oldcummwellsshutdown[z]=wellicky.oldcummwellsshutdown;
        wellbasinlifechecker[z]=wellicky.basinlifechecker;
        countingwells[z]=wellicky.countingwells;
        oldcountingwells[z]=wellicky.oldcountingwells;
        wellmaxoffline[z]=wellicky.maxoffline;
        oldwellcumm_prod[z]=wellicky.oldcumm_prod;
        wellwellsy[z]=wellicky.wellsy;
        wellsupplier[z]=wellicky.supply;
      }
      else
      {
        if (i+lowyear-1<wellyearfind[z]+timedelay)
        {
          wellsupplier[z]=0;
        }
        else
        {
          if (i+lowyear-wellyearfind[z]-timedelay<=wellyearlybasinprod[z].size())
          {
            wellsupplier[z]=wellyearlybasinprod[z].at((int)(i+lowyear-wellyearfind[z]-timedelay-1));
          }
          else
          {
            wellsupplier[z]=0;
          }
        }
      }
      if ((whichoption=="all")||(whichoption=="components"))
      {
        if (whichoption=="all")
        {
          supplyall=supplyall+wellsupplier[z];
        }
        else
        {
          if (welltype[z]=="Oil")
          {
            supplyoil=supplyoil+wellsupplier[z];
          }
          if (welltype[z]=="Gas")
          {
            supplygas=supplygas+wellsupplier[z];
          }
          if (welltype[z]=="Coal")
          {
            supplycoal=supplycoal+wellsupplier[z];
          }
        }
      }
      else
      {
        cout<<"yo what demand type 5 ?? "<<whichoption<<endl;
      }
    }
    for (z=1;z<=resminedata.size();z++)
    {
      minegonk[z]=false;
      if (minealterpreferences[z])
      {
        if (minechangedpreferences[z].at(0).year==lowyear+i-1)
        {
          oldminesonlinerate[z]=minesonlinerate[z];
          minesonlinerate[z]=minechangedpreferences[z].at(0).minesonlinerate;
          minemax_capacity[z]=minechangedpreferences[z].at(0).max_capacity;
          minegonk[z]=true;
        }
      }
      if (!demandchanger.empty())
      {
        if (demandchanger.front().year==lowyear+i-1)
        {
          kD=demandchanger.front().amount;
        }
      }
      if (i+lowyear-1<mineyearfind[z]+timedelay)
      {
        basinender=true;
      }
      if ((i+lowyear-1>=mineyearfind[z]+timedelay) && (minebasinlifechecker[z]==true))
      {
        basinender=true;
        if ((whichoption=="all")||(whichoption=="components"))
        {
          if (whichoption=="all")
          {
             Gapinuse=Gapall;
             smallergapinuseupgrade=smallergapallupgrade;
             smallergapinusedisc=smallergapallupgrade;
          }
          else
          {
            if (minetype[z]=="Oil")
            {
              Gapinuse=Gapoil;
              smallergapinuseupgrade=smallergapoilupgrade;
              smallergapinusedisc=smallergapoilupgrade;
            }
            if (minetype[z]=="Gas")
            {
              Gapinuse=Gapgas;
              smallergapinuseupgrade=smallergapgasupgrade;
              smallergapinusedisc=smallergapgasupgrade;
            }
            if (minetype[z]=="Coal")
            {
              Gapinuse=Gapcoal;
              smallergapinuseupgrade=smallergapcoalupgrade;
              smallergapinusedisc=smallergapcoalupgrade;
            }
          }
        }
        else
        {
          cout<<"yo what demand type 6 ?? "<<whichoption<<endl;
        }
        mineicky=painfulmodelproc(minemaxprod[z],maybeminemaxprod[z],mineyearlybasinprod[z],minefuturetime[z],oldcurrentmines[z],currentmines[z],shutdownmines[z],totalmines[z],oldtotalmines[z],minecumm_prod[z],mineindisruption[z],oldmineindisruption[z],whichminedisruption[z],minebacktonormal[z],predisruptionURRs[z], predisruptionmines[z],cummminesshutdown[z],oldcummminesshutdown[z],minesonlinerate[z],ramping_time[z],mineURR_basin[z],(int)timedelay,(int)mineyearfind[z],minemax_capacity[z],minedisruptions.at(z-1),overrider.at(z-1),i+lowyear-mineyearfind[z]-timedelay,minebasinlifechecker[z],lastminedisruptionend[z],minemaxoffline[z],minesonlinerate[z],oldminecumm_prod[z],minewellsy[z],mintime[z],k5,smallergapinuseupgrade*fmine[z],oldminesonlinerate[z],minegonk[z],countingmines[z],k3*Gapinuse*fmine[z],mineURR[z],mineMP[z], Max_prodLOW[z],Max_prodHIGH[z],Max_prodCY[z],  Max_prodRATE[z],  ML_LOW[z],  ML_HIGH[z], upperURR[z], lowerURR[z], minefixer[z],PP[z], cminesize[z],ARGH,mineabort[z]);
        minemaxprod[z]=mineicky.maxprod;
        maybeminemaxprod[z]=mineicky.maybemaxprod;
        mineyearlybasinprod[z]=mineicky.yearlybasinprodmod;
        minefuturetime[z]=(int)mineicky.futuretime;
        oldcurrentmines[z]=mineicky.oldcurrentmines;
        currentmines[z]=mineicky.currentmines;
        minefixer[z]=mineicky.fixer;
        cminesize[z]=mineicky.cminesize;
        shutdownmines[z]=mineicky.shutdownmines;
        totalmines[z]=mineicky.totalmines;
        oldtotalmines[z]=mineicky.oldtotalmines;
        minecumm_prod[z]=mineicky.cumm_prod;
        mineindisruption[z]=mineicky.indisruption;
        oldmineindisruption[z]=mineicky.oldindisruption;
        whichminedisruption[z]=mineicky.whichdisruption;
        minebacktonormal[z]=mineicky.backtonormal;
        predisruptionURRs[z]=mineicky.predisruptionURRs;
        predisruptionmines[z]=mineicky.predisruptionmines;
        cummminesshutdown[z]=mineicky.cummminesshutdown;
        oldcummminesshutdown[z]=mineicky.oldcummminesshutdown;
        minebasinlifechecker[z]=mineicky.basinlifechecker;
        countingmines[z]=mineicky.countingmines;
        minemaxoffline[z]=mineicky.maxoffline;
        oldminecumm_prod[z]=mineicky.oldcumm_prod;
        minewellsy[z]=mineicky.wellsy;
        minesupplier[z]=mineicky.supply;
        upperURR[z]=mineicky.upperURR;
        lowerURR[z]=mineicky.lowerURR;
        mineURR[z]=mineicky.mineURR;
        mineMP[z]=mineicky.mineMP;
      }
      else
      {
        if (i+lowyear-1<mineyearfind[z]+timedelay)
        {
          minesupplier[z]=0;
        }
        else
        {
          if (i+lowyear-mineyearfind[z]-timedelay<=mineyearlybasinprod[z].size())
          {
            minesupplier[z]=mineyearlybasinprod[z].at((int)(i+lowyear-mineyearfind[z]-timedelay-1));
          }
          else
          {
            minesupplier[z]=0;
          }
        }
      }
      if ((whichoption=="all")||(whichoption=="components"))
      {
        if (whichoption=="all")
        {
          supplyall=supplyall+minesupplier[z];
        }
        else
        {
          if (minetype[z]=="Oil")
          {
            supplyoil=supplyoil+minesupplier[z];
          }
          if (minetype[z]=="Gas")
          {
            supplygas=supplygas+minesupplier[z];
          }
          if (minetype[z]=="Coal")
          {
            supplycoal=supplycoal+minesupplier[z];
          }
          supplyall=supplyall+minesupplier[z];
        }
      }
      else
      {
        cout<<"yo what demand type 7 ?? "<<whichoption<<endl;
      }
    }
    if (totsupply.size()>=recycler.at(1))
    {
      if (recycler.at(1)!=0)
      {
      atemp.year=i+lowyear-1;
      atemp.amount=totsupply.at((int)(totsupply.size()-recycler.at(1)))*((recycler.at(3)-recycler.at(2))/2.0+((recycler.at(3)+recycler.at(2))/2.0)*tanhl(recycler.at(4)*(i+lowyear-1-recycler.at(5))));
      supplyall=supplyall+atemp.amount;
      recycle.push_back(atemp);
      }
    }
    else
    {
      atemp.year=i+lowyear-1;
      atemp.amount=0;
      recycle.push_back(atemp);
    }
    totsupply.push_back(supplyall);
    if ((whichoption=="all")||(whichoption=="components"))
    {
      if (whichoption=="all")
      {
        if (supplyall>0)
        {
          Gapall=(demandall*population-supplyall)/supplyall;
          if (i<=gapdelay)
          {
            Gapall=0;
          }
        }
      }
      else
      {
        if (supplyall>0)
        {
          Gapall=(demandall*population-supplyall)/supplyall;
          if (i<=gapdelay)
          {
            Gapall=0;
          }
        }

        if (supplyoil>0)
        {
          Gapoil=(fracoil*demandoil*population/100-supplyoil)/supplyoil;
          if (i<=gapdelay)
          {
            Gapoil=0;
          }
        }
        if (supplygas>0)
        {
          Gapgas=(fracgas*demandgas*population/100-supplygas)/supplygas;
          if (i<=gapdelay)
          {
            Gapgas=0;
          }
        }
        if (supplycoal>0)
        {
          Gapcoal=(fraccoal*demandcoal*population/100-supplycoal)/supplycoal;
          if (i<=gapdelay)
          {
            Gapcoal=0;
          }
        }
      }
    }
    else
    {
      cout<<"yo what demand type 8 ?? "<<whichoption<<endl;
    }
    //cout<<i+lowyear-1<<endl;
    i++;
  }
  for (z=1;z<=reswelldata.size();z++)
  {
    basin_prod.clear();
    for (c=0;c<wellyearlybasinprod[z].size();c++)
    {
      temper.year=wellyearfind[z]+timedelay+c;
      temper.amount=wellyearlybasinprod[z].at((int)(c));
      basin_prod.push_back(temper);
    }
    tempery.title=welltitle[z];
    tempery.prod=basin_prod;
    prodder.push_back(tempery);
  }
  for (z=1;z<=resminedata.size();z++)
  {
    basin_prod.clear();
    for (c=(int)(mineyearfind[z]+timedelay);c<=(int)minefuturetime[z];c++)
    {
      temper.year=c;
      temper.amount=mineyearlybasinprod[z].at((int)(c-mineyearfind[z]-timedelay));
      basin_prod.push_back(temper);
    }
    tempery.title=minetitle[z];
    tempery.prod=basin_prod;
    prodder.push_back(tempery);
  }
  if ((whichoption=="all")||(whichoption=="components"))
  {
    if (whichoption=="all")
    {
      tempery.title="demandall+demandall+demandall+demandall+demandall+demandall";
      tempery.prod=demanderall;
      prodder.push_back(tempery);
      if (recycler.at(1)!=0)
      {
      tempery.title="recycle+recycle+recycle+recycle+recycle+recycle";
      tempery.prod=recycle;
      prodder.push_back(tempery);
      }
    }
    else
    {
      tempery.title="demandall+demandall+demandall+demandall+demandall+demandall";
      tempery.prod=demanderall;
      prodder.push_back(tempery);
      tempery.title="demandoil+demandoil+demandoil+demandoil+demandoil+demandoil";
      tempery.prod=demanderoil;
      prodder.push_back(tempery);
      tempery.title="demandgas+demandgas+demandgas+demandgas+demandgas+demandgas";
      tempery.prod=demandergas;
      prodder.push_back(tempery);
      tempery.title="demandcoal+demandcoal+demandcoal+demandcoal+demandcoal+demandcoal";
      tempery.prod=demandercoal;
      prodder.push_back(tempery);
      if (recycler.at(1)!=0)
      {
      tempery.title="recycle+recycle+recycle+recycle+recycle+recycle";
      tempery.prod=recycle;
      prodder.push_back(tempery);
      }
    }
  }
  else
  {
    cout<<"yo what demand type 9 ?? "<<whichoption<<endl;
  }
  return prodder;
}
