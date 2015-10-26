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
int    transition_count       (chunk DATA);
packet str_to_packet          (string signal);
chunk  packet_to_chunk        (packet, int);
packet attach_chunk_to_packet (packet,chunk,int); //WRITE THIS FUNCTION
chunk  new_scramble           (chunk);
chunk  new_unscramble         (chunk);
chunk  old_scramble           (chunk DATA_IN);


int main(int argc, const char * argv[])
{
  if (argc != 5)
    {
      cerr << "Incorrect arguments, please specify input and output file" << endl;
      cerr << "e.g. $: scramble_analysis <input_file> <old_scramble_output> <new_scramble_output> <analysis_output>" << endl;
      return 1;
    }
   
  fstream in_file         (argv[1],ios::in);
  fstream new_scramble_out(argv[2],fstream::out | fstream::trunc);
  fstream old_scramble_out(argv[3],fstream::out | fstream::trunc);
  fstream analysis_out    (argv[4],fstream::out | fstream::trunc);

  while(!in_file.eof())
    {
      //read in one 128bit packet from file
      char buff[128];
      in_file.get(buff,128);
      packet packet_in = str_to_packet(buff);

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
      for (int i(120); i<128; i++)
    {
      new_packet_out[i] = packet_in[i];
      old_packet_out[i] = packet_in[i];
    }

      //compute scramble algorithums for all spp chunks
      for (int i(0); i>=0; i--) //TO BE EXPANDED FOR ALL 4 CHUNKS TO SIMULATE PARALLEL GWT'S
    {
      unscrambled_chunk[i] = packet_to_chunk(packet_in,i); //create chunk from packet

      //scramble chunk with both alg's
      new_scrambled_chunk[i] = new_scramble(unscrambled_chunk[i]);
      old_scrambled_chunk[i] = old_scramble(unscrambled_chunk[i]);

      //count transitions
      un_transition_count[i] = transition_count(unscrambled_chunk[i]);
      new_transition_count[i] = transition_count(new_scrambled_chunk[i]);
      old_transition_count[i] = transition_count(old_scrambled_chunk[i]);

      //check scramble is reversable
      new_success[i] = unscrambled_chunk[i] == new_unscramble(new_scrambled_chunk[i]);
      old_success[i] = unscrambled_chunk[i] == old_scramble(old_scrambled_chunk[i]);

      //attach chunk to out_file
      new_packet_out = attach_chunk_to_packet(new_packet_out,new_scrambled_chunk[i],i);
      old_packet_out = attach_chunk_to_packet(old_packet_out,old_scrambled_chunk[i],i);

    analysis_out
      << "chunk" << i << ",\t" << un_transition_count[i] << ",\t"
      << new_transition_count[i] << ",\t" << new_success[i] << ",\t"
      << old_transition_count[i] << ",\t" << old_success[i] << ",\t";
    }

      //write to out files
      new_scramble_out << new_packet_out << endl;
      old_scramble_out << old_packet_out << endl;
      analysis_out << endl;
    } //while !eof




}




#endif
