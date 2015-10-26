void draw_transition_graph_full()
{
  TFile *f = new TFile("root_transition_analysis_full.root");

  TH1F *pre_scramble_hist = (TH1F*)f->Get("pre_scramble_hist");
  TH1F *new_scramble_hist = (TH1F*)f->Get("new_scramble_hist");
  TH1F *old_scramble_hist = (TH1F*)f->Get("old_scramble_hist");

  TCanvas *c1 = new TCanvas("c1","Transitions Per Packet",900,600);

  // New Scramble
  new_scramble_hist->Draw("");
  new_scramble_hist->SetLineColor(2);
  new_scramble_hist->SetLineStyle(1);
  new_scramble_hist->Fit("gaus"); 
  new_scramble_hist->GetFunction("gaus")->SetLineColor(2);
  new_scramble_hist->SetTitle("Comparison of the Number of Transitions");
  new_scramble_hist->GetXaxis()->SetTitle("Number of Transitions");
  new_scramble_hist->GetYaxis()->SetTitle("Entries");
  new_scramble_hist->GetYaxis()->SetRangeUser(0,25000);
  new_scramble_hist->GetYaxis()->SetLabelSize(0.02);
  new_scramble_hist->SetStats(0);
  
  // Pre Scramble
  pre_scramble_hist->Draw("sames");
  pre_scramble_hist->SetLineColor(1);
  pre_scramble_hist->SetLineStyle(1);
  pre_scramble_hist->Fit("gaus");
  pre_scramble_hist->GetFunction("gaus")->SetLineColor(1); 
  pre_scramble_hist->SetStats(0);
   
  // Old Scramble
  old_scramble_hist->Draw("sames");
  old_scramble_hist->SetLineColor(4);
  old_scramble_hist->SetLineStyle(1);
  old_scramble_hist->Fit("gaus"); 
  old_scramble_hist->GetFunction("gaus")->SetLineColor(4); 
  old_scramble_hist->SetStats(0);
  
  // Legend
  //pre stats
  stringstream pre_scramble_mean_ss;
  pre_scramble_mean_ss.precision(3);
  pre_scramble_mean_ss << "mean: " << pre_scramble_hist->GetFunction("gaus")->GetParameter(1);
  string pre_scramble_mean = pre_scramble_mean_ss.str();

  stringstream pre_scramble_sigma_ss;
  pre_scramble_sigma_ss.precision(3);
  pre_scramble_sigma_ss << "#sigma: " << pre_scramble_hist->GetFunction("gaus")->GetParameter(2);
  string pre_scramble_sigma = pre_scramble_sigma_ss.str();

  //new stats
  stringstream new_scramble_mean_ss;
  new_scramble_mean_ss.precision(3);
  new_scramble_mean_ss << "mean: " << new_scramble_hist->GetFunction("gaus")->GetParameter(1);
  string new_scramble_mean = new_scramble_mean_ss.str();

  stringstream new_scramble_sigma_ss;
  new_scramble_sigma_ss.precision(3);
  new_scramble_sigma_ss << "#sigma: " << new_scramble_hist->GetFunction("gaus")->GetParameter(2);
  string new_scramble_sigma = new_scramble_sigma_ss.str();

  //old stats
  stringstream old_scramble_mean_ss;
  old_scramble_mean_ss.precision(3);
  old_scramble_mean_ss << "mean: " << old_scramble_hist->GetFunction("gaus")->GetParameter(1);
  string old_scramble_mean = old_scramble_mean_ss.str();

  stringstream old_scramble_sigma_ss;
  old_scramble_sigma_ss.precision(3);
  old_scramble_sigma_ss << "#sigma: " << old_scramble_hist->GetFunction("gaus")->GetParameter(2);
  string old_scramble_sigma = old_scramble_sigma_ss.str();

  leg = new TLegend(0.65,0.6,0.9,0.9);
  leg->AddEntry(pre_scramble_hist,"Pre Scrambler","l");
  leg->AddEntry(pre_scramble_hist,pre_scramble_mean.c_str(),"");
  leg->AddEntry(pre_scramble_hist,pre_scramble_sigma.c_str(),"");
  leg->AddEntry(new_scramble_hist,"New Scrambler","l");
  leg->AddEntry(new_scramble_hist,new_scramble_mean.c_str(),"");
  leg->AddEntry(new_scramble_hist,new_scramble_sigma.c_str(),"");
  leg->AddEntry(old_scramble_hist,"Old Scrambler","l");
  leg->AddEntry(old_scramble_hist,old_scramble_mean.c_str(),"");
  leg->AddEntry(old_scramble_hist,old_scramble_sigma.c_str(),"");
  leg->Draw();

  c1->Update();

  c1->SaveAs("Transition_Histogram_update.pdf");
}
