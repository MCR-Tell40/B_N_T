-- Top Level Entity
-- old_scrambler_top
-- Author: BNT Collaberation Group
-- Date Created: 06/10/15

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity old_scrambler_top is
  port(
    
    rsi_Reset		        : IN    std_logic;
    csi_Clock_160MHz	     : IN    std_logic
    
    );
end old_scrambler_top;

architecture a of old_scrambler_top is
  
  
  
  --COMPONENT gwt_tx_scrambler_30bit_new IS 
  --  PORT (
  --    TX_RESET_I              : in  std_logic;
  --    RESET_PATTERN_I         : in  std_logic_vector(29 downto 0);      
  --    TX_FRAMECLK_I           : in  std_logic;
  --    TX_DATA_I               : in  std_logic_vector(29 downto 0);  
  --    TX_COMMON_FRAME_O       : out std_logic_vector(29 downto 0)
  --    );
  --END COMPONENT;
  
  
  
  COMPONENT scrambler is
    port(      
      rst,clk_160MHz:IN std_logic;
      data_in:IN std_logic_vector(29 downto 0);
      data_out:OUT std_logic_vector(29 downto 0)
      );
  END COMPONENT;
  
  COMPONENT the_reader is
    
    port(
      clk_40MHz  : in  std_logic;
      rst  : in  std_logic;
      pixel_read : out  std_logic_vector(29 downto 0)
      );
  end COMPONENT ;

  
  COMPONENT the_writer IS
    port( 
      pixel_write : IN std_logic_vector(29 downto 0) ;
      rst, clk_40MHz: IN std_logic
      ) ;
  end COMPONENT ;
  
  
  --constant reset_pattern_reg	   : std_logic_vector(29 downto 0) := "00" & X"0000000";
  --constant reset_pattern_reg	   : std_logic_vector(29 downto 0) := (others => '0');
  --constant data_reg              : std_logic_vector(29 downto 0) := "00" & X"f0f0f0f";
  --constant data_reg              : std_logic_vector(29 downto 0) := "00" & X"1234567";
  SIGNAL reset_reg, clock160_reg	: std_logic;
  SIGNAL common_frame_output_reg : std_logic_vector(29 downto 0);
  SIGNAL data_output_reg	    	: std_logic_vector(29 downto 0);
  SIGNAL read_to_descramble		: std_logic_vector(29 downto 0);
  SIGNAL descramble_to_write		: std_logic_vector(29 downto 0);
  
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
  
  
  --TX : gwt_tx_scrambler_30bit_new
  --  PORT MAP (
  --    TX_DATA_I => data_reg,
  --    TX_RESET_I => reset_reg,
  --    TX_FRAMECLK_I => clock160_reg,
  --    TX_COMMON_FRAME_O => common_frame_output_reg,
  --    RESET_PATTERN_I => reset_pattern_reg 
  --    );
  --
  
  read_inst1 : the_reader
    PORT MAP (
      clk_40MHz         => clock160_reg,
      rst	        => reset_reg,
      pixel_read 	=> read_to_descramble
      );
  
  
  RX_inst1 : scrambler
    PORT MAP (
      rst 	        => reset_reg,
      clk_160MHz 	=> clock160_reg,
      data_in           => read_to_descramble,
      data_out  	=> descramble_to_write
      );		
  
  write_inst1 : the_writer
    PORT MAP (
      pixel_write       => descramble_to_write,
      rst	        => reset_reg,
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
