#include "root_longest_chain.h"

int count_data_points()
{
  int count(0);
  while(!un_scrambled_datafile->eof())
    {
      string temp;
      *un_scrambled_datafile >> temp;
      count++;
    }
  return count;
}

void graph_init(int data_point)
{
  un_scrambled_hist = new TH1F("Un_Scramble_Longest_Chain","Un_Scramble_Longest_Chain",35,0,35);
  new_scrambled_hist = new TH1F("New_Scramble_Longest_Chain","New_Scramble_Longest_Chain",35,0,35);
  old_scrambled_hist = new TH1F("Old_Scramble_Longest_Chain","Old_Scramble_Longest_Chain",35,0,35);
}

void draw_graphs(int data_points)
{
  for (int i(0); i < data_points-1; i++)
    {

      string temp;
      *un_scrambled_datafile >> temp;
      longest_chain_count(str_to_packet(temp),un_scrambled_hist);
      *new_scrambled_datafile >> temp;
      longest_chain_count(str_to_packet(temp),new_scrambled_hist);
      *old_scrambled_datafile >> temp;
      longest_chain_count(str_to_packet(temp),old_scrambled_hist);

      //    string temp;
      //    *un_scrambled_datafile >> temp;
      //    if (longest_chain_count(str_to_packet(temp)!=0))
      //	un_scrambled_hist -> Fill(longest_chain_count(str_to_packet(temp)));
      //    *new_scrambled_datafile >> temp;
      //    if (longest_chain_count(str_to_packet(temp)!=0))
      //	new_scrambled_hist -> Fill(longest_chain_count(str_to_packet(temp)));
      //    *old_scrambled_datafile >> temp;
      //    if (longest_chain_count(str_to_packet(temp)!=0))
      //	old_scrambled_hist -> Fill(longest_chain_count(str_to_packet(temp)));
    }
}

packet str_to_packet(string signal)
{
  packet _packet = 0;
    
  for (int index(1); index <= 128; index++)
    if (signal[128-index] == '1')
      _packet[index-1] = 1;
    
  return _packet;
}




int longest_chain_count(packet DATA, TH1F* histogram) //IN PROGRESS
{ 
  int a(1);
  // int b(1);
  //int longest_chain(1);
  for (int i(1); i < 120 ; i++)
    {
      if (DATA[i] == DATA[i-1] && DATA[i] == 0)
	{
	  a = a+1;	 
	}
      // else if (DATA[i] == DATA[i-1] && DATA[i] == 1)
      //{
      // b=b+1;
      //}
      else
	{
	 histogram -> Fill(a);	  
	  a = 1;
	  // b = 1;
	  // cout << b << endl;
	}         
      //b = a;
      //if (b > longest_chain)
      //longest_chain = b;
    }
  return 0;
}





void save_graphs()
{
  output_file -> cd();
  un_scrambled_hist -> Write("Un_Scramble_Longest_Chain");
  new_scrambled_hist -> Write("New_Scramble_Longest_Chain");
  old_scrambled_hist -> Write("Old_Scramble_Longest_Chain");
  output_file->Close();
}
