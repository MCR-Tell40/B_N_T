void draw_chain_graph_full()
{
  TFile *f = new TFile("root_longest_chain_full.root");

  TH1F *un_scramble_hist = (TH1F*)f->Get("Un_Scramble_Longest_Chain");
  TH1F *new_scramble_hist = (TH1F*)f->Get("New_Scramble_Longest_Chain");
  TH1F *old_scramble_hist = (TH1F*)f->Get("Old_Scramble_Longest_Chain");

  // gStyle->SetOptStat(0000000000);
  // gStyle->SetOptFit(11);
  // gStyle->SetStatW(0.12);                
  // gStyle->SetStatH(0.12);  
  
  TCanvas *c1 = new TCanvas("c1","Chain Length",900,800);

  c1->Divide(1,2,0.01,0.01);

  c1->cd(1);
  
  // Pre Scramble

  un_scramble_hist->Draw("");
  un_scramble_hist->SetLineColor(1);
  un_scramble_hist->SetLineStyle(1);
  un_scramble_hist->SetLineWidth(3);
  //un_scramble_hist->Fit("gaus");
  //un_scramble_hist->GetFunction("gaus")->SetLineColor(1); 
  un_scramble_hist->SetStats(0);
  un_scramble_hist->GetYaxis()->SetLabelSize(0.06);
  un_scramble_hist->GetXaxis()->SetLabelSize(0.06);
  un_scramble_hist->GetYaxis()->SetTitleSize(0.052);
  un_scramble_hist->GetXaxis()->SetTitleSize(0.052);

  un_scramble_hist->SetTitle(0);
  un_scramble_hist->GetXaxis()->SetTitle("Chain Length");
  un_scramble_hist->GetYaxis()->SetTitle("Entries");

  un_scramble_hist->GetXaxis()->SetRangeUser(1,35);

  // New Scramble
  new_scramble_hist->Draw("sames");
  new_scramble_hist->SetTitle(0);
  new_scramble_hist->SetLineColor(2);
  new_scramble_hist->SetLineStyle(1);
  new_scramble_hist->SetLineWidth(3);
  //new_scramble_hist->Fit("gaus"); 
  //new_scramble_hist->GetFunction("gaus")->SetLineColor(2);
 
  //new_scramble_hist->GetYaxis()->SetRangeUser(5000);
  

  new_scramble_hist->SetStats(0);




   
  // Old Scramble
  old_scramble_hist->Draw("sames");
  old_scramble_hist->SetLineColor(4);
  old_scramble_hist->SetLineStyle(7);
  old_scramble_hist->SetLineWidth(3);
  //old_scramble_hist->Fit("gaus"); 
  //old_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  old_scramble_hist->SetStats(0);
  
  // Legend
  leg_top = new TLegend(0.65,0.6,0.9,0.9);
  leg_top->AddEntry(un_scramble_hist,"Pre Scrambler","l");
  leg_top->AddEntry(new_scramble_hist,"New Scrambler","l");
  leg_top->AddEntry(old_scramble_hist,"Old Scrambler","l");
  leg_top->Draw();


 c1->Pad()->SetGridy();

  //----------------------Bottom graph-------------//
  c1->cd(2);
  



  // Pre Scramble
  un_scramble_hist->Draw("");
  un_scramble_hist->SetLineColor(1);
  un_scramble_hist->SetLineStyle(1);
  //un_scramble_hist->Fit("gaus");
  //un_scramble_hist->GetFunction("gaus")->SetLineColor(1);
  un_scramble_hist->SetTitle(0);
  un_scramble_hist->GetXaxis()->SetTitle("Chain Length");
  un_scramble_hist->GetYaxis()->SetTitle("Entries");
 
  un_scramble_hist->SetStats(0);
   

  // New Scramble
  new_scramble_hist->Draw("sames");
  new_scramble_hist->SetLineColor(2);
  new_scramble_hist->SetLineStyle(1);
  //new_scramble_hist->Fit("gaus"); 
  //new_scramble_hist->GetFunction("gaus")->SetLineColor(2);

  //new_scramble_hist->GetYaxis()->SetLabelSize(0.02);
  new_scramble_hist->SetStats(0);
  
  
  // Old Scramble
  old_scramble_hist->Draw("sames");
  old_scramble_hist->SetLineColor(4);
  old_scramble_hist->SetLineStyle(7);
  //old_scramble_hist->Fit("gaus"); 
  //old_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  old_scramble_hist->SetStats(0);
  
  // Legend
  leg_top = new TLegend(0.65,0.6,0.9,0.9);
  leg_top->AddEntry(un_scramble_hist,"Pre Scrambler","l");
  leg_top->AddEntry(new_scramble_hist,"New Scrambler","l");
  leg_top->AddEntry(old_scramble_hist,"Old Scrambler","l");
  leg_top->Draw();
  
  c1->Pad()->SetLogy();
  c1->Pad()->SetGridy();

  
  //c1->SaveAs("Chain_Length_Full_Hist_Update.pdf");
}
