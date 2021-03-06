void draw_transition_graph_short()
{
  TFile *f = new TFile("root_transition_analysis_short.root");
    
  // TGraph *un_scramble = (TGraph*)f->Get("Un_Scramble");
  // TGraph *new_scramble = (TGraph*)f->Get("New_Scramble");
  // TGraph *old_scramble = (TGraph*)f->Get("Old_Scramble");
    
  // TCanvas *c1 = new TCanvas("c1","",900,400);
  // c1->Divide(3,1);
  // c1->cd(1);
  // un_scramble->Draw("AC*");
  // c1->cd(2);
  // new_scramble->Draw("AC*");
  // c1->cd(3);
  // old_scramble->Draw("AP");
  // //c1->Draw();
    
  // c1->SaveAs("test.pdf");

  TH1F *pre_scramble_hist = (TH1F*)f->Get("pre_scramble_hist");
  TH1F *new_scramble_hist = (TH1F*)f->Get("new_scramble_hist");
  TH1F *old_scramble_hist = (TH1F*)f->Get("old_scramble_hist");

  gStyle->SetOptStat(1000000001);
  gStyle->SetOptFit(11);
  gStyle->SetStatW(0.12);                
  gStyle->SetStatH(0.12);                

  TCanvas *c1 = new TCanvas("c1","Transitions Per Packet",900,600);

  // New Scramble
  new_scramble_hist->Draw("");
  new_scramble_hist->SetLineColor(2);
  new_scramble_hist->SetLineStyle(1);
  new_scramble_hist->Fit("gaus"); 
  new_scramble_hist->GetFunction("gaus")->SetLineColor(2);
  new_scramble_hist->SetTitle("Comparison of the Number of Transitions");
  new_scramble_hist->GetXaxis()->SetTitle("Number of Transitions");
  new_scramble_hist->GetYaxis()->SetTitle("Count");
  new_scramble_hist->GetYaxis()->SetRangeUser(0,1100);
  
  // Pre Scramble
  pre_scramble_hist->Draw("sames");
  pre_scramble_hist->SetLineColor(1);
  pre_scramble_hist->SetLineStyle(1);
  pre_scramble_hist->Fit("gaus");
  pre_scramble_hist->GetFunction("gaus")->SetLineColor(1); 
 
  // Old Scramble
  old_scramble_hist->Draw("sames");
  old_scramble_hist->SetLineColor(4);
  old_scramble_hist->SetLineStyle(1);
  old_scramble_hist->Fit("gaus"); 
  old_scramble_hist->GetFunction("gaus")->SetLineColor(4); 

  //    old_scramble_hist->GetYaxis()->SetRangeUser(0,1100);

  c1->Update();
}
