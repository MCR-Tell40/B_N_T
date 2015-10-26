#ifndef __scramble_analysis_h__
#define __scramble_analysis_h__

#include <bitset>
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

typedef bitset<1>   bit;
typedef bitset<30>  chunk;
typedef bitset<128> packet;

//functions coded
int    transition_count       (chunk)             ;
int    transition_count       (packet);
packet str_to_packet          (string)            ;
chunk  packet_to_chunk        (packet, int)       ;
packet attach_chunk_to_packet (packet,chunk,int)  ;
chunk  new_scramble_TX        (chunk, int)        ;
chunk  new_scramble_RX        (chunk, int)        ;
chunk  old_scramble_TX        (chunk, int)        ;
chunk  old_scramble_RX        (chunk, int)        ;

int main(int argc, const char * argv[])
{
  if (argc != 5)
    {
      cerr << "Incorrect arguments, please specify input and output files" << endl;
      cerr << "e.g. $: scramble_analysis <input_file> <old_scramble_output> <new_scramble_output> <analysis_output>" << endl;
      return 1;
    }
    
  fstream in_file         (argv[1],ios::in);
  fstream input_check_file("in_check_file.txt", fstream::out | fstream::trunc);
  fstream new_scramble_out(argv[2],fstream::out | fstream::trunc);
  fstream old_scramble_out(argv[3],fstream::out | fstream::trunc);
  fstream analysis_out    (argv[4],fstream::out | fstream::trunc);

  //analysis header
//  analysis_out
//    << "chunk i,\tun_transition_count[i],\tnew_transition_count[i],\tnew_success[i],\told_transition_count[i],\told_success[i]" << endl;


//  int itt_count(0);
  int itt_count(0);
  while(!in_file.eof())
  //while(itt_count < itterations && !in_file.eof())
    {

      // ---- debugging ----
      itt_count++;
      if (itt_count % 1000 == 0)cout << itt_count << endl;


      //read in one 128bit packet from file
      char buff[128];
      in_file >> buff;
      packet packet_in = str_to_packet(buff);
      input_check_file << packet_in << endl;
      
      chunk unscrambled_chunk[4];   //chunks from packet
      chunk new_scrambled_chunk[4]; //chunks scrambled by new alg
      chunk old_scrambled_chunk[4]; //chunks scrambled by old alg

      int un_transition_count[4];   //transitions in unscrambled chunks
      int new_transition_count[4];  //transitions in new alg scrambled chunks
      int old_transition_count[4];  //transitions in old alg scrambled chunks

      bool new_success[4]; //descramble successful with new alg
      bool old_success[4]; //descramble successful with old alg

      //scrambled packets for writing to file
      packet new_packet_out;
      packet old_packet_out;

      //attach header and parity to outfiles 
      for (int i(127); i>=120; i--)
      {
        new_packet_out[i] = packet_in[i];
        old_packet_out[i] = packet_in[i];
      }

      //compute scramble algorithums for all spp chunks
      for (int i(3); i>=0; i--)
	{
	  unscrambled_chunk[i] = packet_to_chunk(packet_in,i); //create chunk from packet

	  //scramble chunk with both alg's
	  new_scrambled_chunk[i] = new_scramble_TX(unscrambled_chunk[i],i);
	  old_scrambled_chunk[i] = old_scramble_TX(unscrambled_chunk[i],i);

	  //count transitions
	  un_transition_count[i] = transition_count(unscrambled_chunk[i]);
	  new_transition_count[i] = transition_count(new_scrambled_chunk[i]);
	  old_transition_count[i] = transition_count(old_scrambled_chunk[i]);

	  //check scramble is reversable
//	  new_success[i] = unscrambled_chunk[i] == new_scramble_RX(new_scrambled_chunk[i],i);
//	  old_success[i] = unscrambled_chunk[i] == old_scramble_RX(old_scrambled_chunk[i],i);
      if (unscrambled_chunk[i] != new_scramble_RX(new_scrambled_chunk[i],i) )
          cout << "new_scrambler_error line: " << itt_count << endl;
      if (unscrambled_chunk[i] != old_scramble_RX(old_scrambled_chunk[i],i) )
          cout << "old_scrambler_error line: " << itt_count << endl;

	  //attach chunk to out_file
	  new_packet_out = attach_chunk_to_packet(new_packet_out,new_scrambled_chunk[i],i);
	  old_packet_out = attach_chunk_to_packet(old_packet_out,old_scrambled_chunk[i],i);

	  analysis_out
	    << "chunk" << i << "\t" << un_transition_count[i] << "\t"
	    << new_transition_count[i] << "\t";// << new_success[i] << ",\t";
	  analysis_out  << old_transition_count[i] << "\t";// << old_success[i] << ",\t";
	}

      //write to out files
      new_scramble_out << new_packet_out << endl;
      old_scramble_out << old_packet_out << endl;
      analysis_out << "Total\t" << transition_count(packet_in) << "\t" << transition_count(new_packet_out) << "\t" << transition_count(old_packet_out) << endl;
    


    } //while !eof
  
  cout << itt_count << endl;
}

#endif
