-- Top Level Entity
-- new_scrambler_top
-- Author: BNT Collaberation Group
-- Date Created: 06/10/15
-- MODIFIED BY BEN 13/10/15 TO JUST DO THE TX SCRAMBLING AND THEN WORK OUT TRANSITIONS
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity new_scrambler_top is
  port(
    
    rsi_Reset		        : IN    std_logic;
    csi_Clock_160MHz	     : IN    std_logic
    
    );
end new_scrambler_top;

architecture a of new_scrambler_top is
  
  
  
  COMPONENT gwt_tx_scrambler_30bit_new IS 
    PORT (
      TX_RESET_I              : in  std_logic;
      RESET_PATTERN_I         : in  std_logic_vector(29 downto 0);      
      TX_FRAMECLK_I           : in  std_logic;
      TX_DATA_I               : in  std_logic_vector(29 downto 0);  
      TX_COMMON_FRAME_O       : out std_logic_vector(29 downto 0)
      );
  END COMPONENT;
  
  
  
  --COMPONENT gwt_rx_descrambler_30bit_new is
  --  port(      
  --    RX_RESET_I                : in  std_logic;
  --    RX_FRAMECLK_I             : in  std_logic;
  --    RX_COMMON_FRAME_I         : in  std_logic_vector(29 downto 0);
  --    RX_DATA_O                 : out std_logic_vector(29 downto 0)
  --    );
  --END COMPONENT;
  
  COMPONENT the_reader is
    
    port(
      clk_40MHz  : in  std_logic;
      rst  : in  std_logic;
      pixel_read1, pixel_read2, pixel_read3, pixel_read4 : out  std_logic_vector(29 downto 0)
      );
  end COMPONENT ;

  
  COMPONENT the_writer IS
    port( 
      pixel_write1, pixel_write2, pixel_write3, pixel_write4 : IN std_logic_vector(29 downto 0) ;
      file_name :  in string(20 downto 1);
      rst, clk_40MHz: IN std_logic;
      file_name2: in string(19 downto 1)
      ) ;
  end COMPONENT ;
  
  
  --constant reset_pattern_reg	   : std_logic_vector(29 downto 0) := "00" & X"0000000";
   constant reset_pattern_reg	   : std_logic_vector(29 downto 0) := (others => '0');
  -- constant data_reg              : std_logic_vector(29 downto 0) := "00" & X"f0f0f0f";
  -- constant data_reg              : std_logic_vector(29 downto 0) := "00" & X"1234567";
  SIGNAL reset_reg, clock160_reg	: std_logic;
  SIGNAL common_frame_output_reg : std_logic_vector(29 downto 0);
  SIGNAL data_output_reg	    	: std_logic_vector(29 downto 0);
  -- note that these could be used for doing the read to scramble and scramble
  -- to write etc, just look at what is commented out!!!!
  SIGNAL read_to_descramble1, read_to_descramble2, read_to_descramble3, read_to_descramble4 		: std_logic_vector(29 downto 0);
  SIGNAL descramble_to_write1, descramble_to_write2, descramble_to_write3, descramble_to_write4		: std_logic_vector(29 downto 0);
  
  --function stdvec_to_str(inp: std_logic_vector) return string is
  --  variable temp: string(inp'left+1 downto 1) := (others => 'X');
  --begin
  --  for i in inp'reverse_range loop
  --    if (inp(i) = '1') then
  --      temp(i+1) := '1';
  --    elsif (inp(i) = '0') then
  --      temp(i+1) := '0';
  --    end if;
  --  end loop;
  --  return temp;
  --end function stdvec_to_str;

  
BEGIN
  
  
  read_inst1 : the_reader
    PORT MAP (
      clk_40MHz         => clock160_reg,
      rst	        => reset_reg,
      pixel_read1 	=> read_to_descramble1,
      pixel_read2       => read_to_descramble2,
      pixel_read3       => read_to_descramble3,
      pixel_read4       => read_to_descramble4
      );

  -- scrambling intances 1-4   
  TXinst1 : gwt_tx_scrambler_30bit_new
    PORT MAP (
      TX_DATA_I => read_to_descramble1,
      TX_RESET_I => reset_reg,
      TX_FRAMECLK_I => clock160_reg,
      TX_COMMON_FRAME_O => descramble_to_write1,
      RESET_PATTERN_I => reset_pattern_reg 
      );
  
  TXinst2 : gwt_tx_scrambler_30bit_new
    PORT MAP (
      TX_DATA_I => read_to_descramble2,
      TX_RESET_I => reset_reg,
      TX_FRAMECLK_I => clock160_reg,
      TX_COMMON_FRAME_O => descramble_to_write2,
      RESET_PATTERN_I => reset_pattern_reg 
      );
  
  TXinst3: gwt_tx_scrambler_30bit_new
    PORT MAP (
      TX_DATA_I => read_to_descramble3,
      TX_RESET_I => reset_reg,
      TX_FRAMECLK_I => clock160_reg,
      TX_COMMON_FRAME_O => descramble_to_write3,
      RESET_PATTERN_I => reset_pattern_reg 
      );
  
  TXinst4 : gwt_tx_scrambler_30bit_new
    PORT MAP (
      TX_DATA_I => read_to_descramble4,
      TX_RESET_I => reset_reg,
      TX_FRAMECLK_I => clock160_reg,
      TX_COMMON_FRAME_O => descramble_to_write4,
      RESET_PATTERN_I => reset_pattern_reg 
      );

  
  -- descramble instances 1-4
  
  --RX_inst1 : gwt_rx_descrambler_30bit_new 
  --  PORT MAP (
  --    RX_RESET_I 	=> reset_reg,
  --    RX_FRAMECLK_I 	=> clock160_reg,
  --    RX_COMMON_FRAME_I => read_to_descramble1,
  --    RX_DATA_O  	=> descramble_to_write1
  --    );		
  
  --RX_inst2 : gwt_rx_descrambler_30bit_new 
  --  PORT MAP (
  --    RX_RESET_I 	=> reset_reg,
  --    RX_FRAMECLK_I 	=> clock160_reg,
  --    RX_COMMON_FRAME_I => read_to_descramble2,
  --    RX_DATA_O  	=> descramble_to_write2
  --    );
  
  --RX_inst3 : gwt_rx_descrambler_30bit_new 
  --  PORT MAP (
  --    RX_RESET_I 	=> reset_reg,
  --    RX_FRAMECLK_I 	=> clock160_reg,
  --    RX_COMMON_FRAME_I => read_to_descramble3,
  --    RX_DATA_O  	=> descramble_to_write3
  --    );

  --RX_inst4 : gwt_rx_descrambler_30bit_new 
  --  PORT MAP (
  --    RX_RESET_I 	=> reset_reg,
  --    RX_FRAMECLK_I 	=> clock160_reg,
  --    RX_COMMON_FRAME_I => read_to_descramble4,
  --    RX_DATA_O  	=> descramble_to_write4
  --    );		



  
  write_inst1 : the_writer
    PORT MAP (
      pixel_write1       => descramble_to_write1,
      pixel_write2       => descramble_to_write2,
      pixel_write3      => descramble_to_write3,
      pixel_write4       => descramble_to_write4,
      rst	        => reset_reg,
      file_name         => "scrambler_output.txt",
      file_name2        => "new_transitions.txt",
      clk_40MHz	        => clock160_reg
      );

  write_inst2 : the_writer
    PORT MAP (
      pixel_write1       => read_to_descramble1,
      pixel_write2       => read_to_descramble2,
      pixel_write3       => read_to_descramble3,
      pixel_write4       => read_to_descramble4,
      rst	        => reset_reg,
      file_name         => "before_scrambler.txt",
      file_name2        => "pre_transitions.txt",
      clk_40MHz	        => clock160_reg
      );


  PROCESS(csi_Clock_160MHz, rsi_Reset)
  BEGIN

    reset_reg <= rsi_Reset;
    clock160_reg <= csi_Clock_160MHz;		

    If (rsi_Reset = '1') THEN 
      
      
      --scrambler_data_out <= (OTHERS => '0');

    ELSIF rising_edge(csi_Clock_160MHz) THEN     
      
      --scrambler_data_out <= data_output_reg;		
      --report "data_output_reg=" & stdvec_to_str(data_output_reg);

    END IF;
    
  END PROCESS;

END a;
