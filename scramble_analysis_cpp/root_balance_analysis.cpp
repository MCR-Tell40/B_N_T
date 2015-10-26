#include "root_balance_analysis.h"

void fillVector(fstream* file, vector<int>& balance)
{
  long count(0);

  while (!file->eof())
  //for (int j(0); j < 20; j++)
    {
      string temp;
      *file >> temp;
      packet line = str_to_packet(temp);

      for (int i(0); i<120; i++)
	{
	  if (line[i] == 1) count++;
	  else count--; 

	} 
	balance.push_back(count);	
    }
}

void draw_graphs(TGraph& graph, vector<int> datay)
{
  int* y = &datay[0];

  int* x = new int[datay.size()];
  
  for (int i(0); i < datay.size(); i++)
    x[i] = i;
  
  //TVectorF _datax(datax.size(),datax[0]);
  //TVectorF _datay(datay.size(),datay[0]);
  //TVectorT<long>* _datax;
  // for (int i(0); i < datax.size(); i++)
  //_datax[i] = datax[i];

  //TVectorD* _datay = new TVectorD((Int_t)datay.size());
  //for (int i(0); i < datay.size(); i++)
  //_datay[i] = datay[i];
  graph = TGraph(datay.size(),x,y);  
}

packet str_to_packet(string signal)
{
  packet _packet = 0;
    
  for (int index(1); index <= 128; index++)
    if (signal[128-index] == '1')
      _packet[index-1] = 1;
    
  return _packet;
}

void save_graphs()
{
  output_file -> cd();
  un_scrambled_graph.Write("Un_Scramble");
  new_scrambled_graph.Write("New_Scramble");
  old_scrambled_graph.Write("Old_Scramble");
  output_file->Close();
}
