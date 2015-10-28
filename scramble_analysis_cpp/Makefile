ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --libs)
ROOTDIR = root_files
ROOTMAC = root_macros
SCRAMBLE = scramble_outputs

all: scramble_sim root_transition_analysis root_longest_chain root_balance_analysis

scramble_sim: scramble_sim.cpp scramble_sim.h
	g++ -o $@ scramble_sim.cpp

root_transition_analysis: root_transition_analysis.cpp root_transition_analysis.h
	g++ -o $@ root_transition_analysis.cpp $(ROOTFLAGS) $(ROOTLIBS)

root_longest_chain: root_longest_chain.cpp root_longest_chain.h
	g++ -o $@ root_longest_chain.cpp $(ROOTFLAGS) $(ROOTLIBS)

root_balance_analysis: root_balance_analysis.cpp root_balance_analysis.h
	g++ -o $@ root_balance_analysis.cpp $(ROOTFLAGS) $(ROOTLIBS)

run_short: scramble_sim root_transition_analysis root_longest_chain root_balance_analysis
	./scramble_sim desyncFilter.txt $(SCRAMBLE)Karol_scramble_output.txt $(SCRAMBLE)additive_scramble_output.txt $(SCRAMBLE)VeloPix_scramble_output.txt
	./root_transition_analysis desyncFilter.txt $(SCRAMBLE)Karol_scramble_output.txt $(SCRAMBLE)additive_scramble_output.txt  $(ROOTDIR)transition_analysis_short.root $(SCRAMBLE)VeloPix_scramble_output.txt
	./root_longest_chain desyncFilter.txt $(SCRAMBLE)Karol_scramble_output.txt $(SCRAMBLE)additive_scramble_output.txt  $(ROOTDIR)longest_chain_short.root $(SCRAMBLE)VeloPix_scramble_output.txt
	./root_balance_analysis desyncFilter.txt $(SCRAMBLE)Karol_scramble_output.txt $(SCRAMBLE)additive_scramble_output.txt  $(ROOTDIR)balance_analysis_short.root  $(SCRAMBLE)VeloPix_scramble_output.txt

run_full: scramble_sim root_transition_analysis root_longest_chain root_balance_analysis
	./scramble_sim desync9X.txt $(SCRAMBLE)Karol_scramble_output.txt $(SCRAMBLE)additive_scramble_output.txt  $(SCRAMBLE)VeloPix_scramble_output.txt
	./root_transition_analysis desync9X.txt $(SCRAMBLE)Karol_scramble_output.txt $(SCRAMBLE)additive_scramble_output.txt  $(ROOTDIR)transition_analysis_full.root $(SCRAMBLE)VeloPix_scramble_output.txt
	./root_longest_chain desync9X.txt $(SCRAMBLE)Karol_scramble_output.txt $(SCRAMBLE)additive_scramble_output.txt $(ROOTDIR)longest_chain_full.root $(SCRAMBLE)VeloPix_scramble_output.txt
	./root_balance_analysis desyncFilter.txt $(SCRAMBLE)Karol_scramble_output.txt $(SCRAMBLE)additive_scramble_output.txt $(ROOTDIR)balance_analysis_full.root $(SCRAMBLE)VeloPix_scramble_output.txt

clean:
	rm -f scramble_sim
	rm -f root_transition_analysis
	rm -f root_longest_chain
