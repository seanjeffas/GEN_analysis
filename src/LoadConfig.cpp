
#include "../include/LoadConfig.h"


void LoadConfig(TString cfg_name){
  
  ifstream configfile(cfg_name);

  //so as usual the main things to define are:
  // 1. List of files
  // 2. Global cuts
  // 3. Nominal beam energy (perhaps corrected for average energy loss along half target thickness
  // 4. File name for old momentum coefficients (optional?)
  // 5. BigBite central angle
  // 6. SBS central angle
  // 7. HCAL distance

  TString currentline;

  cout << endl << "Chaining all the ROOT files.." << endl;
  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endlist") ){
    if( !currentline.BeginsWith("#") ){
      C->Add(currentline);
      E->Add(currentline);
    }
  }
  
  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endcut") ){
    if( !currentline.BeginsWith("#") ){
      globalcut += currentline;
    }
  }


  while( currentline.ReadLine( configfile ) && !currentline.BeginsWith("endconfig") ){
    if( !currentline.BeginsWith("#") ){
      TObjArray *tokens = currentline.Tokenize(" ");

      int ntokens = tokens->GetEntries();

      if( ntokens >= 2 ){
	TString skey = ( (TObjString*) (*tokens)[0] )->GetString();

	if( skey == "Ebeam" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  Ebeam = stemp.Atof();
	}

	if( skey == "bbtheta" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  bbtheta = stemp.Atof();
	}

	if( skey == "sbstheta" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  sbstheta = stemp.Atof();
	}

	if( skey == "sbsdist" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  sbsdist = stemp.Atof();
	}
	
	if( skey == "hcaldist" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  hcaldist = stemp.Atof();
	}

	if( skey == "sbsfieldscale" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  sbsfieldscale = stemp.Atof();
	}

	if( skey == "proton_x_mean" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  px_mean = stemp.Atof();
	}

	if( skey == "proton_x_sigma" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  px_sigma = stemp.Atof();
	}

	if( skey == "neutron_x_mean" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  nx_mean = stemp.Atof();
	}

	if( skey == "neutron_x_sigma" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  nx_sigma = stemp.Atof();
	}

	if( skey == "proton_y_mean" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  py_mean = stemp.Atof();
	}

	if( skey == "proton_y_sigma" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  py_sigma = stemp.Atof();
	}

	if( skey == "neutron_y_mean" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  ny_mean = stemp.Atof();
	}

	if( skey == "neutron_y_sigma" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  ny_sigma = stemp.Atof();
	}

	if( skey == "nsigma_cut" ){
	  TString stemp = ( (TObjString*) (*tokens)[1] )->GetString();
	  nsigma = stemp.Atoi();
	}
	
      }	
      
      tokens->Delete();
    }
  }


}
