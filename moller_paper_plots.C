///////////////////////////////////////////////////////////////////////////////
// MOLLER POLARIMETER PREX PAPER PLOTS
// Use: root -l -q moller_paper_plots.C
// Note: Canvases deleted after print.
//
// --Eric King
//////////////////////////////////////////////////////////////////////////////

#include <TROOT.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLine.h>
#include <TString.h>
#include <TText.h>
#include "MolpolStyle.h"

Bool_t deleteAfterPrint(false);

void PlotMollerVsCompton();
void PlotAsymAndRateCurves();

void moller_paper_plots(){
  PlotMollerVsCompton();
  PlotAsymAndRateCurves();
}

void PlotMollerVsCompton(){
  gROOT->SetStyle("Plain");
  static TStyle * molpolStyle = 0;
  molpolStyle = MolpolStyle_4x3();
  gROOT->SetStyle("MOLPOL_4X3");
  gROOT->ForceStyle();

  // STYLE OVERRIDE -- WILL BE USING TITLES
  molpolStyle->SetPadTopMargin(0.1);

  // COLOR AND MARKER OPTIONS
  Int_t  com  = kBlue+2;    //Compton Color
  Int_t  mol  = kOrange+10; //Moller Color
  Int_t  ro   = 20;         //Right-out Marker Style
  Int_t  ri   = 21;         //Right-in Marker Style
  Int_t  lo   = 20;         //Left-out Marker Style
  Int_t  li   = 21;         //Left-in Marker Style

  // ATTRIBUTES
  Double_t gap = 1.4;       // Y Axis Gap From Minimum
  Double_t ymin1= 86.1;     // Y Axis Minimum
  Double_t ymax1= ymin1+gap;// Y Axis Maximum
  Double_t ymin2= 85.9;     // Y Axis Minimum
  Double_t ymax2= ymin2+gap;// Y Axis Maximum
  Double_t ymin3= 86.5;     // Y Axis Minimum
  Double_t ymax3= ymin3+gap;// Y Axis Maximum
  Double_t ymin4= 86.9;     // Y Axis Minimum
  Double_t ymax4= ymin4+gap;// Y Axis Maximum
  Double_t ymin5= 86.9;     // Y Axis Minimum
  Double_t ymax5= ymin5+gap;// Y Axis Maximum
  Double_t ymin6= 86.5;     // Y Axis Minimum
  Double_t ymax6= ymin6+gap;// Y Axis Maximum
  Double_t xmin = 0.0;   // X Axis Minimum
  Double_t xmax = 5.0;   // X Axis Maximum
  Double_t yLbPs= 85.32; // Text Label Position (User Y Axis)
  Double_t lbsz = 0.035; // Text Label Size
  Int_t    lbtxt= 42;    // Text Label Text Style
  Double_t legx1= 0.575; // Legend X1
  Double_t legy1= 0.65;  // Legend Y1
  Double_t legx2= 0.945; // Legend X2
  Double_t legy2= 0.894; // Legend Y2
  Int_t    cw1  = 1200;  // Canvas Width 3 columns x 400
  Int_t    ch1  = 600;   // Canvas Height 2 rows x 300
  Double_t szxlab=0;     // NO X-LABELS

  // DUMMY -- X axis not setting properly with SetRangeUser(), added white point dummies as hotfix
  // This keeps axes consistent for all plots
  Double_t dummyX[2] = {0.25,4.75};
  Double_t dummyY[2] = {87.5,87.5};
  TGraph * dummyPoints = new TGraph(2,dummyX,dummyY);
  dummyPoints->SetMarkerColor(0);
  dummyPoints->SetMarkerStyle(1);

  // DATA
  // 2-8-2020
  Double_t 	com_0208_ro_x[1]={	1	};
  Double_t 	com_0208_ro_p[1]={	86.89	};
  Double_t 	com_0208_ro_e[1]={	0.22	};
  Double_t 	mol_0208_ro_x[1]={	2	};
  Double_t 	mol_0208_ro_p[1]={	86.98	};
  Double_t 	mol_0208_ro_e[1]={	0.20	};
  Double_t 	mol_0208_ri_x[1]={	3	};
  Double_t 	mol_0208_ri_p[1]={	86.83	};
  Double_t 	mol_0208_ri_e[1]={	0.20	};
  Double_t 	com_0208_ri_x[1]={	4	};
  Double_t 	com_0208_ri_p[1]={	86.45	};
  Double_t 	com_0208_ri_e[1]={	0.22	};
  // 2-24-2020
  Double_t 	com_0224_lo_x[1]={	1	};
  Double_t 	com_0224_lo_p[1]={	86.65	};
  Double_t 	com_0224_lo_e[1]={	0.07	};
  Double_t 	mol_0224_lo_x[1]={	2	};
  Double_t 	mol_0224_lo_p[1]={	86.79	};
  Double_t 	mol_0224_lo_e[1]={	0.16	};
  Double_t 	mol_0224_li_x[1]={	3	};
  Double_t 	mol_0224_li_p[1]={	86.23	};
  Double_t 	mol_0224_li_e[1]={	0.16	};
  Double_t 	com_0224_li_x[1]={	4	};
  Double_t 	com_0224_li_p[1]={	86.48	};
  Double_t 	com_0224_li_e[1]={	0.09	};
  // 3-18-2020
  Double_t 	com_0318_lo_x[1]={	1.5	};
  Double_t 	com_0318_lo_p[1]={	86.80	};
  Double_t 	com_0318_lo_e[1]={	0.07	};
  Double_t 	mol_0318_lo_x[1]={	3.5	};
  Double_t 	mol_0318_lo_p[1]={	87.08	};
  Double_t 	mol_0318_lo_e[1]={	0.23	};
  // 8-19-2020
  Double_t 	com_0819_ro_x[1]={	1	};
  Double_t 	com_0819_ro_p[1]={	87.77	};
  Double_t 	com_0819_ro_e[1]={	0.10	};
  Double_t 	mol_0819_ro_x[1]={	2	};
  Double_t 	mol_0819_ro_p[1]={	87.68	};
  Double_t 	mol_0819_ro_e[1]={	0.20	};
  Double_t 	mol_0819_ri_x[1]={	3	};
  Double_t 	mol_0819_ri_p[1]={	87.43	};
  Double_t 	mol_0819_ri_e[1]={	0.20	};
  Double_t 	com_0819_ri_x[1]={	4	};
  Double_t 	com_0819_ri_p[1]={	87.29	};
  Double_t 	com_0819_ri_e[1]={	0.15	};
  // 9-4-2020
  Double_t 	com_0904_ro_x[1]={	1	};
  Double_t 	com_0904_ro_p[1]={	87.72	};
  Double_t 	com_0904_ro_e[1]={	0.10	};
  Double_t 	mol_0904_ro_x[1]={	2	};
  Double_t 	mol_0904_ro_p[1]={	87.45	};
  Double_t 	mol_0904_ro_e[1]={	0.16	};
  Double_t 	mol_0904_ri_x[1]={	3	};
  Double_t 	mol_0904_ri_p[1]={	87.49	};
  Double_t 	mol_0904_ri_e[1]={	0.17	};
  Double_t 	com_0904_ri_x[1]={	4	};
  Double_t 	com_0904_ri_p[1]={	87.15	};
  Double_t 	com_0904_ri_e[1]={	0.11	};
  // 9-16-2020
  Double_t 	com_0916_ri_x[1]={	1.5	};
  Double_t 	com_0916_ri_p[1]={	87.12	};
  Double_t 	com_0916_ri_e[1]={	0.42	};
  Double_t 	mol_0916_ri_x[1]={	3.5	};
  Double_t 	mol_0916_ri_p[1]={	87.11	};
  Double_t 	mol_0916_ri_e[1]={	0.18	};

  // GRAPHS
  // 02-08
  TGraphErrors * grmol0208ro = new TGraphErrors(1,mol_0208_ro_x,mol_0208_ro_p,0,mol_0208_ro_e);
  TGraphErrors * grmol0208ri = new TGraphErrors(1,mol_0208_ri_x,mol_0208_ri_p,0,mol_0208_ri_e);
  TGraphErrors * grcom0208ro = new TGraphErrors(1,com_0208_ro_x,com_0208_ro_p,0,com_0208_ro_e);
  TGraphErrors * grcom0208ri = new TGraphErrors(1,com_0208_ri_x,com_0208_ri_p,0,com_0208_ri_e);
  grmol0208ro->SetMarkerStyle(ro);
  grmol0208ri->SetMarkerStyle(ri);
  grcom0208ro->SetMarkerStyle(ro);
  grcom0208ri->SetMarkerStyle(ri);
  grmol0208ro->SetMarkerColor(mol);
  grmol0208ri->SetMarkerColor(mol);
  grcom0208ro->SetMarkerColor(com);
  grcom0208ri->SetMarkerColor(com);
  // 02-24
  TGraphErrors * grmol0224lo = new TGraphErrors(1,mol_0224_lo_x,mol_0224_lo_p,0,mol_0224_lo_e);
  TGraphErrors * grmol0224li = new TGraphErrors(1,mol_0224_li_x,mol_0224_li_p,0,mol_0224_li_e);
  TGraphErrors * grcom0224lo = new TGraphErrors(1,com_0224_lo_x,com_0224_lo_p,0,com_0224_lo_e);
  TGraphErrors * grcom0224li = new TGraphErrors(1,com_0224_li_x,com_0224_li_p,0,com_0224_li_e);
  grmol0224lo->SetMarkerStyle(lo);
  grmol0224li->SetMarkerStyle(li);
  grcom0224lo->SetMarkerStyle(lo);
  grcom0224li->SetMarkerStyle(li);
  grmol0224lo->SetMarkerColor(mol);
  grmol0224li->SetMarkerColor(mol);
  grcom0224lo->SetMarkerColor(com);
  grcom0224li->SetMarkerColor(com);
  // 03-18
  TGraphErrors * grmol0318lo = new TGraphErrors(1,mol_0318_lo_x,mol_0318_lo_p,0,mol_0318_lo_e);
  TGraphErrors * grcom0318lo = new TGraphErrors(1,com_0318_lo_x,com_0318_lo_p,0,com_0318_lo_e);
  grmol0318lo->SetMarkerStyle(lo);
  grcom0318lo->SetMarkerStyle(lo);
  grmol0318lo->SetMarkerColor(mol);
  grcom0318lo->SetMarkerColor(com);
  // 08-19
  TGraphErrors * grmol0819ro = new TGraphErrors(1,mol_0819_ro_x,mol_0819_ro_p,0,mol_0819_ro_e);
  TGraphErrors * grmol0819ri = new TGraphErrors(1,mol_0819_ri_x,mol_0819_ri_p,0,mol_0819_ri_e);
  TGraphErrors * grcom0819ro = new TGraphErrors(1,com_0819_ro_x,com_0819_ro_p,0,com_0819_ro_e);
  TGraphErrors * grcom0819ri = new TGraphErrors(1,com_0819_ri_x,com_0819_ri_p,0,com_0819_ri_e);
  grmol0819ro->SetMarkerStyle(ro);
  grmol0819ri->SetMarkerStyle(ri);
  grcom0819ro->SetMarkerStyle(ro);
  grcom0819ri->SetMarkerStyle(ri);
  grmol0819ro->SetMarkerColor(mol);
  grmol0819ri->SetMarkerColor(mol);
  grcom0819ro->SetMarkerColor(com);
  grcom0819ri->SetMarkerColor(com);
  // 09-04
  TGraphErrors * grmol0904ro = new TGraphErrors(1,mol_0904_ro_x,mol_0904_ro_p,0,mol_0904_ro_e);
  TGraphErrors * grmol0904ri = new TGraphErrors(1,mol_0904_ri_x,mol_0904_ri_p,0,mol_0904_ri_e);
  TGraphErrors * grcom0904ro = new TGraphErrors(1,com_0904_ro_x,com_0904_ro_p,0,com_0904_ro_e);
  TGraphErrors * grcom0904ri = new TGraphErrors(1,com_0904_ri_x,com_0904_ri_p,0,com_0904_ri_e);
  grmol0904ro->SetMarkerStyle(ro);
  grmol0904ri->SetMarkerStyle(ri);
  grcom0904ro->SetMarkerStyle(ro);
  grcom0904ri->SetMarkerStyle(ri);
  grmol0904ro->SetMarkerColor(mol);
  grmol0904ri->SetMarkerColor(mol);
  grcom0904ro->SetMarkerColor(com);
  grcom0904ri->SetMarkerColor(com);
  // 09-16
  TGraphErrors * grmol0916ri = new TGraphErrors(1,mol_0916_ri_x,mol_0916_ri_p,0,mol_0916_ri_e);
  TGraphErrors * grcom0916ri = new TGraphErrors(1,com_0916_ri_x,com_0916_ri_p,0,com_0916_ri_e);
  grmol0916ri->SetMarkerStyle(ri);
  grcom0916ri->SetMarkerStyle(ri);
  grmol0916ri->SetMarkerColor(mol);
  grcom0916ri->SetMarkerColor(com);

  // LEGENDS
  // 2In/2Out
  TLegend * leg = new TLegend(legx1,legy1,legx2,legy2);
  leg->AddEntry(grcom0208ro,"Compton HWP-Out","p");
  leg->AddEntry(grmol0208ro,"Moller HWP-Out","p");
  leg->AddEntry(grmol0208ri,"Moller HWP-In","p");
  leg->AddEntry(grcom0208ri,"Compton HWP-In","p");
  // Out only
  TLegend * legout = new TLegend(legx1,legy1+0.5*(legy2-legy1),legx2,legy2);
  legout->AddEntry(grcom0208ro,"Compton HWP-Out","p");
  legout->AddEntry(grmol0208ro,"Moller HWP-Out","p");
  // In only
  Double_t  fudge = 0.01; // hotfix: auto text sizing too large for leg box, alter box ever so slightly.
  TLegend * legin = new TLegend(legx1,legy1+0.5*(legy2-legy1)+fudge,legx2,legy2);
  legin->AddEntry(grcom0208ri,"Compton HWP-In","p");
  legin->AddEntry(grmol0208ri,"Moller HWP-In","p");

  // MULTIGRAPHS
  // First panel
  TMultiGraph * mgr1 = new TMultiGraph();
  mgr1->SetTitle("02-08-2020 | Wein: Flip-Right;;Polarization [%]");
  mgr1->Add(grmol0208ro);
  mgr1->Add(grmol0208ri);
  mgr1->Add(grcom0208ro);
  mgr1->Add(grcom0208ri);
  mgr1->Add(dummyPoints);
  // Second panel
  TMultiGraph * mgr2 = new TMultiGraph();
  mgr2->SetTitle("02-24-2020 | Wein: Flip-Left;;Polarization [%]");
  mgr2->Add(grmol0224lo);
  mgr2->Add(grmol0224li);
  mgr2->Add(grcom0224lo);
  mgr2->Add(grcom0224li);
  mgr2->Add(dummyPoints);
  // Third panel
  TMultiGraph * mgr3 = new TMultiGraph();
  mgr3->SetTitle("03-18-2020 | Wein: Flip Left;;Polarization [%]");
  mgr3->Add(grmol0318lo);
  mgr3->Add(grcom0318lo);
  mgr3->Add(dummyPoints);
  // Fourth panel
  TMultiGraph * mgr4 = new TMultiGraph();
  mgr4->SetTitle("08-19-2020 | Wein: Flip-Right;;Polarization [%]");
  mgr4->Add(grmol0819ro);
  mgr4->Add(grmol0819ri);
  mgr4->Add(grcom0819ro);
  mgr4->Add(grcom0819ri);
  mgr4->Add(dummyPoints);
  // Fifth panel
  TMultiGraph * mgr5 = new TMultiGraph();
  mgr5->SetTitle("09-04-2020 | Wein: Flip-Right;;Polarization [%]");
  mgr5->Add(grmol0904ro);
  mgr5->Add(grmol0904ri);
  mgr5->Add(grcom0904ro);
  mgr5->Add(grcom0904ri);
  mgr5->Add(dummyPoints);
  // Sixth panel
  TMultiGraph * mgr6 = new TMultiGraph();
  mgr6->SetTitle("09-16-2020 | Wein: Flip-Right;;Polarization [%]");
  mgr6->Add(grmol0916ri);
  mgr6->Add(grcom0916ri);
  mgr6->Add(dummyPoints);

  // CANVAS
  TCanvas * A = new TCanvas("A","A",cw1,ch1);
  A->Divide(3,2);
  A->cd(1);
  mgr1->GetXaxis()->SetTickLength(0.);
  mgr1->GetXaxis()->SetLabelSize(szxlab);
  mgr1->Draw("AP");
  mgr1->GetXaxis()->SetRangeUser(xmin,xmax);
  mgr1->GetYaxis()->SetRangeUser(ymin1,ymax1);
  mgr1->GetYaxis()->SetDecimals(1);
  gPad->SetGridy();
  leg->Draw();
  A->cd(2);
  mgr2->GetXaxis()->SetTickLength(0.);
  mgr2->GetXaxis()->SetLabelSize(szxlab);
  mgr2->Draw("AP");
  mgr2->GetXaxis()->SetRangeUser(xmin,xmax);
  mgr2->GetYaxis()->SetRangeUser(ymin2,ymax2);
  mgr2->GetYaxis()->SetDecimals(1);
  gPad->SetGridy();
  leg->Draw();
  A->cd(3);
  mgr3->GetXaxis()->SetTickLength(0.);
  mgr3->GetXaxis()->SetLabelSize(szxlab);
  mgr3->Draw("AP");
  mgr3->GetXaxis()->SetRangeUser(xmin,xmax);
  mgr3->GetYaxis()->SetRangeUser(ymin3,ymax3);
  mgr3->GetYaxis()->SetDecimals(1);
  gPad->SetGridy();
  legout->Draw();
  A->cd(4);
  mgr4->GetXaxis()->SetTickLength(0.);
  mgr4->GetXaxis()->SetLabelSize(szxlab);
  mgr4->Draw("AP");
  mgr4->GetXaxis()->SetRangeUser(xmin,xmax);
  mgr4->GetYaxis()->SetRangeUser(ymin4,ymax4);
  mgr4->GetYaxis()->SetDecimals(1);
  gPad->SetGridy();
  leg->Draw();
  A->cd(5);
  mgr5->GetXaxis()->SetTickLength(0.);
  mgr5->GetXaxis()->SetLabelSize(szxlab);
  mgr5->Draw("AP");
  mgr5->GetXaxis()->SetRangeUser(xmin,xmax);
  mgr5->GetYaxis()->SetRangeUser(ymin5,ymax5);
  mgr5->GetYaxis()->SetDecimals(1);
  gPad->SetGridy();
  leg->Draw();
  A->cd(6);
  mgr6->GetXaxis()->SetTickLength(0.);
  mgr6->GetXaxis()->SetLabelSize(szxlab);
  mgr6->Draw("AP");
  mgr6->GetXaxis()->SetRangeUser(xmin,xmax);
  mgr6->GetYaxis()->SetRangeUser(ymin6,ymax6);
  mgr6->GetYaxis()->SetDecimals(1);
  gPad->SetGridy();
  legin->Draw();

  A->Print("plot_mollerComptonMulti_standard.pdf");

  if(deleteAfterPrint) delete A; //Close histogram after draw/print

}

void PlotAsymAndRateCurves(){
  Int_t cw1 = 533;
  Int_t ch1 = 300;

  // Simulations Magnet Current
  Double_t simMagcurr[41]={72.01,74.03,76.06,78.08,80.10,82.12,84.15,86.17,88.19,90.22,92.24,94.26,96.29,98.31,100.33,102.36,104.38,106.40,108.43,110.45,112.47,114.50,116.52,118.54,120.57,122.59,124.61,126.64,128.66,130.68,132.71,134.73,136.75,138.78,140.80,142.82,144.84,146.87,148.89,150.91,152.94};
  // Modified-hydrogen wavefunction results
  Double_t simAnpowMH[41]={0.58147,0.59684,0.62761,0.67483,0.72529,0.76029,0.77670,0.77958,0.77608,0.77014,0.76579,0.76260,0.76005,0.75779,0.75580,0.75488,0.75446,0.75427,0.75403,0.75378,0.75342,0.75356,0.75378,0.75381,0.75374,0.75401,0.75419,0.75480,0.75510,0.75578,0.75632,0.75699,0.75789,0.75827,0.75939,0.76051,0.76167,0.76303,0.76432,0.76602,0.76772};
  // Hartree-Fock wavefunction results
  Double_t simAnpowHF[41]={0.55820,0.57108,0.59788,0.64635,0.70904,0.76380,0.78709,0.78595,0.77890,0.77207,0.76819,0.76432,0.76091,0.75795,0.75604,0.75449,0.75405,0.75388,0.75373,0.75366,0.75371,0.75378,0.75366,0.75365,0.75370,0.75393,0.75404,0.75461,0.75489,0.75534,0.75610,0.75710,0.75775,0.75895,0.75973,0.76112,0.76223,0.76334,0.76474,0.76664,0.76813};
  // Normaized predicted coincidence rates; these were effectively the same for MH and HF models
  Double_t simMolratenorm[41]={0.112,0.141,0.181,0.241,0.332,0.462,0.618,0.762,0.862,0.924,0.962,0.986,0.997,1.000,0.999,0.995,0.991,0.986,0.980,0.975,0.969,0.964,0.958,0.952,0.946,0.940,0.933,0.926,0.918,0.909,0.899,0.888,0.876,0.862,0.847,0.831,0.813,0.793,0.772,0.749,0.724};
  // (If needed) Analyzing power errors; again, these were effectively the same for the MH and HF models
  Double_t simAnpowErr[41]={0.00078,0.00073,0.00066,0.00059,0.00060,0.00054,0.00051,0.00048,0.00045,0.00045,0.00044,0.00043,0.00043,0.00043,0.00042,0.00044,0.00042,0.00043,0.00043,0.00044,0.00044,0.00043,0.00045,0.00042,0.00044,0.00044,0.00045,0.00044,0.00045,0.00044,0.00044,0.00045,0.00046,0.00046,0.00046,0.00047,0.00046,0.00049,0.00050,0.00051,0.00051};
  // Adjusted asymmetry scan currents (moved ~1.5%)
  Double_t dataAscanfield[9]={81.09,82.09,83.08,87.05,93.01,102.95,114,126.86,142.93};
  // Asymmetries of the scan points converted to analyzing powers
  Double_t dataAscanasym[9]={0.75686,0.77142,0.77835,0.78512,0.76955,0.75643,0.75441,0.75268,0.76205};
  // 0.2% bars would probably be sufficient here. I put numbers that were in original spreadsheet.
  // These are the statistical error of the measurements and do not include the error for the 'free parameter' (polarization)
  // used to convert from asymmetry to analyzing power.
  Double_t dataAsymErr[9]={0.00197,0.00180,0.00176,0.00172,0.00168,0.00169,0.00174,0.00171,0.00170};
  // Spin dance moller coincidence scan currents
  Double_t dataSpinDanceField[13]={140,135,130,125,120,115,110,105,100,95,90,85,80};
  // We will shift these by 1.5
  // Quadrupole characterisations are accurate to within 1% so having used three (3) quads this shift is consistent with known errors.
  Double_t dataSpinDanceFieldShifted[13];
  for(Int_t i=0;i<13;i++) dataSpinDanceFieldShifted[i]=dataSpinDanceField[i]*1.015;
  // Normalized moller rates from spin dance.
  Double_t dataSpinDanceRateScan[13]={0.845,0.881,0.905,0.927,0.946,0.954,0.976,0.988,0.996,1.000,0.964,0.825,0.502};

  // GRAPHS
  // Normalized rates
  TGraph * grRateNorm = new TGraph(13,dataSpinDanceField,dataSpinDanceRateScan);
  grRateNorm->SetLineColor(kBlack);
  grRateNorm->SetMarkerColor(kBlack);
  grRateNorm->SetMarkerStyle(24);
  // (Shifted) Normalized rates
  TGraph * grRateNormShifted = new TGraph(13,dataSpinDanceFieldShifted,dataSpinDanceRateScan);
  grRateNormShifted->SetLineColor(kBlack);
  grRateNormShifted->SetMarkerColor(kBlack);
  grRateNormShifted->SetMarkerStyle(20);
  // MolPol predicted coincidence
  TGraph * grSimRateCurve = new TGraph(41,simMagcurr,simMolratenorm);
  grSimRateCurve->SetLineColor(kBlack);
  grSimRateCurve->SetLineWidth(2.0);
  grSimRateCurve->SetLineStyle(2);
  // Modified Hydrogen analyzing power
  TGraph * grSimAzzMH = new TGraph(41,simMagcurr,simAnpowMH);
  grSimAzzMH->SetLineColor(kBlack);
  grSimAzzMH->SetMarkerStyle(1);
  grSimAzzMH->SetMarkerColor(kBlack);
  grSimAzzMH->SetLineWidth(2);
  grSimAzzMH->SetLineStyle(7);
  // Hartree-Fock analyzing powers
  TGraph * grSimAzzHF = new TGraph(41,simMagcurr,simAnpowHF);
  grSimAzzHF->SetLineColor(kBlack);
  grSimAzzHF->SetMarkerStyle(1);
  grSimAzzHF->SetMarkerColor(kBlack);
  grSimAzzHF->SetLineWidth(2);
  grSimAzzHF->SetLineStyle(1);
  // Moller rate
  TGraph * grSimMolRt = new TGraph(41,simMagcurr,simMolratenorm);
  // Asymmetry scan data points
  TGraphErrors * grAsymScan = new TGraphErrors(9,dataAscanfield,dataAscanasym,0,dataAsymErr);
  grAsymScan->SetMarkerStyle(20);
  grAsymScan->SetMarkerColor(kRed); // Red markers
  grAsymScan->SetLineColor(kBlack); // Black error bars
  grAsymScan->SetLineWidth(2);      // Accentuate the error bars
  grAsymScan->SetMarkerSize(1);     // Override the marker size

  // MULTIGRAPHS
  // Analyzing powers
  TMultiGraph * mgrAzzs = new TMultiGraph();
  mgrAzzs->Add(grSimAzzMH);
  mgrAzzs->Add(grSimAzzHF);
  mgrAzzs->SetTitle(";Moller Quadrupole 1 Current [A];Analyzing Power");

  // LEGENDS
  // Legend for canvas C
  auto legC = new TLegend(0.375,0.75,0.94,0.935);
  legC->AddEntry(grSimAzzMH,"Predicted Corrected Asymmetry MH","l");
  legC->AddEntry(grSimAzzHF,"Predicted Corrected Asymmetry HF","l");
  legC->AddEntry(grAsymScan,"Asymmetry Measurements","p");
  // Legend for canvas D
  auto legD = new TLegend(0.43,0.425,0.94,0.625);
  legD->AddEntry(grSimRateCurve,"Predicted Moller Rate Curve","l");
  legD->AddEntry(grRateNorm,"Measured Moller Rates","p");
  legD->AddEntry(grRateNormShifted,"(Shifted) Measured Moller Rate","p");

  // Set style MolPol Wide
  static TStyle * molpolStyle = 0;
  molpolStyle = MolpolStyle_16x9();
  gROOT->SetStyle("MOLPOL_16X9");
  gROOT->ForceStyle();

  // CANVASES
  TCanvas * C = new TCanvas("C","C",cw1,ch1);
  mgrAzzs->Draw("ACP");
  mgrAzzs->GetHistogram()->SetMinimum(0.75);
  mgrAzzs->GetHistogram()->SetMaximum(0.79);
  mgrAzzs->GetXaxis()->SetRangeUser(78,152);
  mgrAzzs->GetYaxis()->SetDecimals(3);
  mgrAzzs->GetYaxis()->SetTitleOffset(1.15); //Four digits, need to offset title.
  grAsymScan->Draw("P");
  legC->Draw();
  C->Modified();
  C->Update();
  C->Print("plot_AnalyzingPowerCurvesAndData_wider.pdf");

  TCanvas * D = new TCanvas("D","D",cw1,ch1);
  grSimRateCurve->SetTitle(";Moller Quadrupole 1 Current [A]; Fraction of Maximum Rate");
  grSimRateCurve->Draw("AC");
  grSimRateCurve->GetHistogram()->SetMinimum(0.2);
  grSimRateCurve->GetHistogram()->SetMaximum(1.0);
  grSimRateCurve->GetXaxis()->SetRangeUser(78,152);
  grRateNormShifted->Draw("P");
  grRateNorm->Draw("P");
  legD->Draw();
  D->Print("plot_CoincidenceRateQ3Scan_wider.pdf");

  if(deleteAfterPrint) delete C; // Close histogram after draw/print
  if(deleteAfterPrint) delete D; // Close histogram after draw/print

  //////////////////////////////////////////////////////////////////
  // Alternate smaller plots if needed for two column.
  //////////////////////////////////////////////////////////////////

  // LEGENDS
  // Legend for Canvas Calt
  auto legCalt = new TLegend(0.425,0.725,0.94,0.885);
  legCalt->AddEntry(grSimAzzMH,"Predicted Corrected Asymmetry MH","l");
  legCalt->AddEntry(grSimAzzHF,"Predicted Corrected Asymmetry HF","l");
  legCalt->AddEntry(grAsymScan,"Asymmetry Measurements","p");
  // Legend for Canvas Dalt
  auto legDalt = new TLegend(0.40,0.425,0.94,0.575);
  legDalt->AddEntry(grSimRateCurve,"Predicted Moller Rate Curve","l");
  legDalt->AddEntry(grRateNorm,"Measured Moller Rates","p");
  legDalt->AddEntry(grRateNormShifted,"(Shifted) Moller Rate","p");

  // Set new styling
  gROOT->SetStyle("Plain"); //Effectively a reset.
  molpolStyle = 0;
  molpolStyle = MolpolStyle_4x3();
  gROOT->SetStyle("MOLPOL_4X3");
  gROOT->ForceStyle();

  //Style Overrides
  molpolStyle->SetMarkerSize(1);  //Lots of points, make them smaller.

  // CANVASES
  TCanvas * Calt = new TCanvas("Calt","Calt",400,300);
  mgrAzzs->Draw("AC");
  mgrAzzs->GetHistogram()->SetMinimum(0.75);
  mgrAzzs->GetHistogram()->SetMaximum(0.79);
  mgrAzzs->GetXaxis()->SetRangeUser(78,152);
  mgrAzzs->GetYaxis()->SetDecimals(3);
  mgrAzzs->GetYaxis()->SetTitleOffset(1.5);
  grAsymScan->Draw("P");
  legCalt->Draw();
  Calt->Modified();
  Calt->Update();
  Calt->Print("plot_AnalyzingPowerCurvesAndData_standard.pdf");

  TCanvas * Dalt = new TCanvas("Dalt","Dalt",400,300);
  grSimRateCurve->Draw("AC");
  grSimRateCurve->GetHistogram()->SetMinimum(0.2);
  grSimRateCurve->GetHistogram()->SetMaximum(1.0);
  grSimRateCurve->GetXaxis()->SetRangeUser(78,152);
  grSimRateCurve->GetYaxis()->SetDecimals(1);
  grSimRateCurve->GetYaxis()->SetTitleOffset(1.2);
  grRateNormShifted->Draw("P");
  grRateNorm->Draw("P");
  legDalt->Draw();
  Dalt->Print("plot_CoincidenceRateQ3Scan_standard.pdf");

  if(deleteAfterPrint) delete Calt; // Close histogram after draw/print
  if(deleteAfterPrint) delete Dalt; // Close histogram after draw/print

}
