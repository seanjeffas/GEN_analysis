

TChain *C = new TChain("T");
TCut globalcut="";
double Ebeam;
double bbtheta;
double sbstheta;
double sbsdist;
double hcaldist;
double sbsfieldscale;
double px_mean;
double px_sigma;
double nx_mean;
double nx_sigma;
double py_mean;
double py_sigma;
double ny_mean;
double ny_sigma;
int nsigma;

TChain *E = new TChain("E");

void LoadConfig(TString cfg);
