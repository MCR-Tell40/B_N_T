void draw_balance_graphs()
{
  TFile* f = new TFile("balance_analysis_full.root");

  TGraph* pre_graph = (TGraph*)f->Get("Un_Scramble");
  TGraph* new_graph = (TGraph*)f->Get("New_Scramble");
  TGraph* old_graph = (TGraph*)f->Get("Old_Scramble");

  TCanvas* c1 = new TCanvas("Evolution in the Balance of 1s and 0s",
			    "Evolution in the Balance of 1s and 0s",
			    900,600);

  old_graph->Draw("AL");
  old_graph->SetLineColor(4);
  old_graph->SetLineWidth(2);
  old_graph->GetXaxis()->SetTitle("Frame #");
  old_graph->GetYaxis()->SetTitle("(#1 - #0)");
  old_graph->SetTitle("Evolution in the Balance of 1s and 0s");

  new_graph->Draw("same");
  new_graph->SetLineColor(2);
  new_graph->SetLineWidth(2);
  new_graph->SetMarkerStyle(0);

  pre_graph->Draw("same");
  pre_graph->SetLineColor(6);
  pre_graph->SetLineWidth(2);
  
  TLegend* leg = new TLegend(0.7,0.8,0.9,0.9);
  leg->AddEntry(pre_graph,"Dysync 9X","l");
  leg->AddEntry(new_graph,"Markov Scrambler","l");
  leg->AddEntry(old_graph,"Additive Scrambler","l");
  leg->Draw();
  c1->Update();
  c1->SaveAs("Evolution_in_the_Balance_of_1s_and_0s.pdf");
}
