#ifndef __root_graph_transitions_h__
#define __root_graph_transitions_h__

#include <iostream>
#include <fstream>
#include <TFile.h>
#include <TGraph.h>
#include <TH1.h>
#include <string>
#include <bitset>

using namespace std;

//typedef
typedef bitset<128> packet;

//files
fstream * un_scrambled_datafile;
fstream * new_scrambled_datafile;
fstream * old_scrambled_datafile;
TFile   * output_file;

//graphs
TGraph * un_scrambled_graph;
TGraph * new_scrambled_graph;
TGraph * old_scrambled_graph;

//hists
TH1F * pre_scramble_hist;
TH1F * new_scramble_hist;
TH1F * old_scramble_hist;

//funcitons
int count_data_points();
void graph_init(int);
void draw_graphs(int);
int transition_count(packet);
packet str_to_packet(string);
void save_graphs();
            
int main(int argc, const char ** argv)
{
    if (argc != 5)
    {
        cout << "Invalid arguments, please use form: $ <executable> <unscrambled> <new_scrambled> <old_scrambled> <output_file>" << endl;
        return 1;
    }
    else
    {
        //open files
        un_scrambled_datafile  = new fstream(argv[1],fstream::in);
        new_scrambled_datafile = new fstream(argv[2],fstream::in);
        old_scrambled_datafile = new fstream(argv[3],fstream::in);
        output_file            = new TFile(argv[4], "RECREATE");
    }
    
    int data_points(count_data_points());
    cout << data_points << " data_points" << endl;
    
    //reopen un_scrambled_datafile as its used for counting
    un_scrambled_datafile -> close();   
    un_scrambled_datafile -> open(argv[1]);
    
    graph_init(data_points);
    
    draw_graphs(data_points);

    save_graphs();
    
    return 0;
}

#endif
