/////////////////////////////////////////////////////////////////
// USAGE                                                       //
//  gRoot->SetStyle("Plain");                                  //
//  static TStyle * molpolStyle = 0;                           //
//  molpolStyle = MolpolStyle_4x3();                           //
//  gROOT->SetStyle("MOLPOL_4X3");                             //
//  gROOT->ForceStyle();                                       //
//                                                             //
// --Eric King                                                 //
/////////////////////////////////////////////////////////////////

#include "TStyle.h"

TStyle* MolpolStyle_4x3();
TStyle* MolpolStyle_16x9();

TStyle * MolpolStyle_4x3()
{
  // Note: Designed for 400x300 plots. Works fine with 400x400 plots.
  // Note: Yaxis title offset default assumes two digit labels, ajust as needed with override
  // Note: No main title space allocated. If title desired override in script with molpolStyle->SetPadTopMargin(0.1);

  TStyle *molpolStyle = new TStyle("MOLPOL_4X3","MolPol Style Square");

  Float_t topMargin(0.05);  // No title space
  Float_t botMargin(0.1);   // Standard space enough for labels and title
  Float_t leftMargin(0.15); // Widened left margin
  Float_t rghtMargin(0.05); // Narrowed right margin

  Int_t whiteColor=0;
  molpolStyle->SetFrameBorderMode(whiteColor);
  molpolStyle->SetFrameFillColor(whiteColor);
  molpolStyle->SetCanvasBorderMode(whiteColor);
  molpolStyle->SetCanvasColor(whiteColor);
  molpolStyle->SetPadBorderMode(whiteColor);
  molpolStyle->SetPadColor(whiteColor);
  molpolStyle->SetStatColor(whiteColor);

  // set margin sizes
  molpolStyle->SetPadTopMargin(topMargin);
  molpolStyle->SetPadRightMargin(rghtMargin);
  molpolStyle->SetPadBottomMargin(botMargin);
  molpolStyle->SetPadLeftMargin(leftMargin);

  // set title offsets (for axis label)
  molpolStyle->SetTitleOffset(1.7,"y");
  molpolStyle->SetLabelOffset(0.005,"y");
  molpolStyle->SetTitleOffset(1.0,"x"); //X will need to be revisted
  molpolStyle->SetLabelOffset(0.005,"x"); //X will need to be revisted

  // main title
  molpolStyle->SetTitleX(0.5*leftMargin-0.5*rghtMargin+0.5);
  molpolStyle->SetTitleY(0.950);
  molpolStyle->SetTitleAlign(22); // center-center from set point

  // font settings
  Int_t     font  = 42;
  Double_t  tsize = 0.045;
  molpolStyle->SetTextFont(font);

  molpolStyle->SetTextSize(tsize);
  molpolStyle->SetLabelFont(font,"x");
  molpolStyle->SetTitleFont(font,"x");
  molpolStyle->SetLabelFont(font,"y");
  molpolStyle->SetTitleFont(font,"y");
  molpolStyle->SetLabelFont(font,"z");
  molpolStyle->SetTitleFont(font,"z");

  molpolStyle->SetLabelSize(tsize,"x");
  molpolStyle->SetTitleSize(tsize,"x");
  molpolStyle->SetLabelSize(tsize,"y");
  molpolStyle->SetTitleSize(tsize,"y");
  molpolStyle->SetLabelSize(tsize,"z");
  molpolStyle->SetTitleSize(tsize,"z");

  // use bold lines and markers
  molpolStyle->SetMarkerStyle(20);
  molpolStyle->SetMarkerSize(1.2);
  molpolStyle->SetHistLineWidth(2.);
  molpolStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  molpolStyle->SetOptTitle(1);
  molpolStyle->SetTitleBorderSize(0);
  molpolStyle->SetTitleFillColor(0);
  molpolStyle->SetOptStat(0);
  molpolStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  molpolStyle->SetPadTickX(0);
  molpolStyle->SetPadTickY(0);

  // default marker size
  molpolStyle->SetMarkerSize(1.5);

  // legend
  molpolStyle->SetLegendBorderSize(1);

  return molpolStyle;
}

TStyle * MolpolStyle_16x9()
{
  // Style for 16:9 ratio plots. Default size at the moment should be 533 x 300
  // Note: Yaxis title offset default assumes two digit labels, ajust as needed with override
  // Note: No main title space allocated. If title desired override in script with molpolStyle->SetPadTopMargin(0.1);

  TStyle *molpolStyle = new TStyle("MOLPOL_16X9","MolPol Style Rectangular");

  // use plain black on white colors
  Int_t whiteColor=0; // WHITE
  molpolStyle->SetFrameBorderMode(whiteColor);
  molpolStyle->SetFrameFillColor(whiteColor);
  molpolStyle->SetCanvasBorderMode(whiteColor);
  molpolStyle->SetCanvasColor(whiteColor);
  molpolStyle->SetPadBorderMode(whiteColor);
  molpolStyle->SetPadColor(whiteColor);
  molpolStyle->SetStatColor(whiteColor);

  // set margin sizes
  molpolStyle->SetPadTopMargin(0.05);   // No main title space
  molpolStyle->SetPadRightMargin(0.05); // Right margin narrowed
  molpolStyle->SetPadBottomMargin(0.1); // Bottom margin standard
  molpolStyle->SetPadLeftMargin(0.1);   // Left margin standard

  // set title offsets (for axis label)
  molpolStyle->SetTitleOffset(1.0,"y");
  molpolStyle->SetLabelOffset(0.005,"y");
  molpolStyle->SetTitleOffset(1.0,"x");   // X will need to be revisted
  molpolStyle->SetLabelOffset(0.005,"x"); // X will need to be revisted

  // main title
  molpolStyle->SetTitleX(0.545);
  molpolStyle->SetTitleY(0.950);
  molpolStyle->SetTitleAlign(22);         // center-center from set point

  // font settings
  Int_t     font  = 42;
  Double_t  tsize = 0.045;
  molpolStyle->SetTextFont(font);

  molpolStyle->SetTextSize(tsize);
  molpolStyle->SetLabelFont(font,"x");
  molpolStyle->SetTitleFont(font,"x");
  molpolStyle->SetLabelFont(font,"y");
  molpolStyle->SetTitleFont(font,"y");
  molpolStyle->SetLabelFont(font,"z");
  molpolStyle->SetTitleFont(font,"z");

  molpolStyle->SetLabelSize(tsize,"x");
  molpolStyle->SetTitleSize(tsize,"x");
  molpolStyle->SetLabelSize(tsize,"y");
  molpolStyle->SetTitleSize(tsize,"y");
  molpolStyle->SetLabelSize(tsize,"z");
  molpolStyle->SetTitleSize(tsize,"z");

  // use bold lines and markers
  molpolStyle->SetMarkerStyle(20);
  molpolStyle->SetMarkerSize(1.0);
  molpolStyle->SetHistLineWidth(2.);
  molpolStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  molpolStyle->SetOptTitle(1);
  molpolStyle->SetTitleBorderSize(0);
  molpolStyle->SetTitleFillColor(0);
  molpolStyle->SetOptStat(0);
  molpolStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  molpolStyle->SetPadTickX(0);
  molpolStyle->SetPadTickY(0);

  // default marker size
  molpolStyle->SetMarkerSize(1);

  // legend
  molpolStyle->SetLegendBorderSize(1);

  return molpolStyle;
}
