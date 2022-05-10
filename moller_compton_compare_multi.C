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

void moller_compton_compare_multi(){
static TStyle * molpolStyle = 0;
molpolStyle = MolpolStyle_4x3();
gROOT->SetStyle("MOLPOL_4X3");
gROOT->ForceStyle();

// Styling options
Int_t  com  = kBlue+2;    //Compton Color
Int_t  mol  = kOrange+10; //Moller Color
Int_t  ro   = 20; //Right-out Marker Style
Int_t  ri   = 21; //Right-in Marker Style
Int_t  lo   = 20; //Left-out Marker Style
Int_t  li   = 21; //Left-in Marker Style
Int_t  lnst = 7;  //Separating Line Style

// Attributes
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
Double_t xmin1= 0.0;   // X Axis Minimum
Double_t xmax1= 5.0;   // X Axis Maximum
Double_t xmin2= 5.0;   // X Axis Minimum
Double_t xmax2= 10.0;  // X Axis Maximum
Double_t xmin3= 10.0;  // X Axis Minimum
Double_t xmax3= 13.0;  // X Axis Maximum
Double_t xmin4= 13.0;  // X Axis Minimum
Double_t xmax4= 18.0;  // X Axis Maximum
Double_t xmin5= 18.0;  // X Axis Minimum
Double_t xmax5= 23.0;  // X Axis Maximum
Double_t xmin6= 23.0;  // X Axis Minimum
Double_t xmax6= 26.0;  // X Axis Maximum
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

// Dummy -- X axis not setting properly even with SetRangeUser(), added white point dummies as hotfix
Double_t        dummyX[2] = {0.25,4.75};
Double_t        dummyY[2] = {87.5,87.5};
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

// Graphs 02-08
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
// Graphs 02-24
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
// Graphs 03-18
TGraphErrors * grmol0318lo = new TGraphErrors(1,mol_0318_lo_x,mol_0318_lo_p,0,mol_0318_lo_e);
TGraphErrors * grcom0318lo = new TGraphErrors(1,com_0318_lo_x,com_0318_lo_p,0,com_0318_lo_e);
grmol0318lo->SetMarkerStyle(lo);
grcom0318lo->SetMarkerStyle(lo);
grmol0318lo->SetMarkerColor(mol);
grcom0318lo->SetMarkerColor(com);
// Graphs 08-19
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
// Graphs 09-04
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
// Graphs 09-16
TGraphErrors * grmol0916ri = new TGraphErrors(1,mol_0916_ri_x,mol_0916_ri_p,0,mol_0916_ri_e);
TGraphErrors * grcom0916ri = new TGraphErrors(1,com_0916_ri_x,com_0916_ri_p,0,com_0916_ri_e);
grmol0916ri->SetMarkerStyle(ri);
grcom0916ri->SetMarkerStyle(ri);
grmol0916ri->SetMarkerColor(mol);
grcom0916ri->SetMarkerColor(com);

// Legend -- 2In/2Out
TLegend * leg = new TLegend(legx1,legy1,legx2,legy2);
leg->AddEntry(grcom0208ro,"Compton HWP-Out","p");
leg->AddEntry(grmol0208ro,"Moller HWP-Out","p");
leg->AddEntry(grmol0208ri,"Moller HWP-In","p");
leg->AddEntry(grcom0208ri,"Compton HWP-In","p");
// Legend -- Out only
TLegend * legout = new TLegend(legx1,legy1+0.5*(legy2-legy1),legx2,legy2);
legout->AddEntry(grcom0208ro,"Compton HWP-Out","p");
legout->AddEntry(grmol0208ro,"Moller HWP-Out","p");
// Legend -- In only
TLegend * legin  = new TLegend(legx1,legy1+0.5*(legy2-legy1),legx2,legy2);
legin->AddEntry(grcom0208ri,"Compton HWP-In","p");
legin->AddEntry(grmol0208ri,"Moller HWP-In","p");

// Multigraphs
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

// Canvas
TCanvas * C1 = new TCanvas("C1","C1",cw1,ch1);
C1->Divide(3,2);
C1->cd(1);
mgr1->GetXaxis()->SetTickLength(0.);
mgr1->GetXaxis()->SetLabelSize(szxlab);
mgr1->Draw("AP");
mgr1->GetXaxis()->SetRangeUser(xmin,xmax);
mgr1->GetYaxis()->SetRangeUser(ymin1,ymax1);
mgr1->GetYaxis()->SetDecimals(1);
gPad->SetGridy();
leg->Draw();
C1->cd(2);
mgr2->GetXaxis()->SetTickLength(0.);
mgr2->GetXaxis()->SetLabelSize(szxlab);
mgr2->Draw("AP");
mgr2->GetXaxis()->SetRangeUser(xmin,xmax);
mgr2->GetYaxis()->SetRangeUser(ymin2,ymax2);
mgr2->GetYaxis()->SetDecimals(1);
gPad->SetGridy();
leg->Draw();
C1->cd(3);
mgr3->GetXaxis()->SetTickLength(0.);
mgr3->GetXaxis()->SetLabelSize(szxlab);
mgr3->Draw("AP");
mgr3->GetXaxis()->SetRangeUser(xmin,xmax);
mgr3->GetYaxis()->SetRangeUser(ymin3,ymax3);
mgr3->GetYaxis()->SetDecimals(1);
gPad->SetGridy();
legout->Draw();
C1->cd(4);
mgr4->GetXaxis()->SetTickLength(0.);
mgr4->GetXaxis()->SetLabelSize(szxlab);
mgr4->Draw("AP");
mgr4->GetXaxis()->SetRangeUser(xmin,xmax);
mgr4->GetYaxis()->SetRangeUser(ymin4,ymax4);
mgr4->GetYaxis()->SetDecimals(1);
gPad->SetGridy();
leg->Draw();
C1->cd(5);
mgr5->GetXaxis()->SetTickLength(0.);
mgr5->GetXaxis()->SetLabelSize(szxlab);
mgr5->Draw("AP");
mgr5->GetXaxis()->SetRangeUser(xmin,xmax);
mgr5->GetYaxis()->SetRangeUser(ymin5,ymax5);
mgr5->GetYaxis()->SetDecimals(1);
gPad->SetGridy();
leg->Draw();
C1->cd(6);
mgr6->GetXaxis()->SetTickLength(0.);
mgr6->GetXaxis()->SetLabelSize(szxlab);
mgr6->Draw("AP");
mgr6->GetXaxis()->SetRangeUser(xmin,xmax);
mgr6->GetYaxis()->SetRangeUser(ymin6,ymax6);
mgr6->GetYaxis()->SetDecimals(1);
gPad->SetGridy();
legin->Draw();

C1->Print("plot_mollerComptonComparisonWide.pdf");

}
