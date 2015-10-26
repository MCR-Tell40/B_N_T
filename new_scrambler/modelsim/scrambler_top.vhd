library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;


--FH comments:
-- FH add "coe_Rx_Ready"
-- ready is a flag from transceiver : when ready = '0' => transceiver is not ready => system must be reset
--                                    when ready = '1' => transceiver is     ready => system can run

entity scrambler_top is
  port(
    
    rsi_Reset		        : IN    std_logic;
    csi_Clock_160MHz	        : IN    std_logic;
    scrambler_data_out       	: OUT std_logic_vector(29 downto 0)

    );
end scrambler_top;

architecture a of scrambler_top is
  
  COMPONENT gwt_tx_scrambler_30bit_new IS 
    PORT (
      TX_RESET_I              : in  std_logic;
      RESET_PATTERN_I         : in  std_logic_vector(29 downto 0);      
      TX_FRAMECLK_I           : in  std_logic;
      TX_DATA_I               : in  std_logic_vector(29 downto 0);  
      TX_COMMON_FRAME_O       : out std_logic_vector(29 downto 0)
      );
  END COMPONENT;
  
  COMPONENT gwt_rx_descrambler_30bit_new is
    port(      
      RX_RESET_I                : in  std_logic;
      RX_FRAMECLK_I             : in  std_logic;
      RX_COMMON_FRAME_I         : in  std_logic_vector(29 downto 0);
      rx_data_out               : out std_logic_vector(29 downto 0)
      );
  END COMPONENT;
  
  
  constant reset_pattern_reg	    	: std_logic_vector(29 downto 0) := "00" & X"0000000";
  --constant data_reg                     : std_logic_vector(29 downto 0) := "00" & X"f0f0f0f";
  constant data_reg                     : std_logic_vector(29 downto 0) := "00" & X"1234567";
  SIGNAL reset_reg, clock160_reg	: std_logic;
  SIGNAL common_frame_output_reg 	: std_logic_vector(29 downto 0);
  SIGNAL data_output_reg	    	: std_logic_vector(29 downto 0);

  function stdvec_to_str(inp: std_logic_vector) return string is
    variable temp: string(inp'left+1 downto 1) := (others => 'X');
  begin
    for i in inp'reverse_range loop
      if (inp(i) = '1') then
        temp(i+1) := '1';
      elsif (inp(i) = '0') then
        temp(i+1) := '0';
      end if;
    end loop;
    return temp;
  end function stdvec_to_str;

  
BEGIN
  
  
  TX : gwt_tx_scrambler_30bit_new
    PORT MAP (
      TX_DATA_I => data_reg,
      TX_RESET_I => reset_reg,
      TX_FRAMECLK_I => clock160_reg,
      TX_COMMON_FRAME_O => common_frame_output_reg,
      RESET_PATTERN_I => reset_pattern_reg 
      );
  
  RX : gwt_rx_descrambler_30bit_new 
    PORT MAP (
      RX_RESET_I => reset_reg,
      RX_FRAMECLK_I => clock160_reg,
      RX_COMMON_FRAME_I => common_frame_output_reg, 
      rx_data_out => data_output_reg
      );		
  


  PROCESS(csi_Clock_160MHz, rsi_Reset)
    
  BEGIN

    reset_reg <= rsi_Reset;
    clock160_reg <= csi_Clock_160MHz;		

    If (rsi_Reset = '1') THEN 
      
      
      scrambler_data_out <= (OTHERS => '0');

    ELSIF rising_edge(csi_Clock_160MHz) THEN     
      
      scrambler_data_out <= data_output_reg;		
      report "data_output_reg=" & stdvec_to_str(data_output_reg);

    END IF;
    
  END PROCESS;

END a;
