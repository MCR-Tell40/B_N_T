--=================================================================================================--
--##################################   Module Information   #######################################--
--=================================================================================================--
--                                                                                         
-- Company:               CERN (PH-ESE-BE)                                                         
-- Engineer:              Manoel Barros Marin (manoel.barros.marin@cern.ch) (m.barros.marin@ieee.org)
--                                                                                                 
-- Project Name:          GWT-FPGA                                                                
-- Module Name:           GWT RX descrambler 30bit
--                                                                                                 
-- Language:              VHDL'93                                                              
--                                                                                                   
-- Target Device:         Vendor agnostic                                                      
-- Tool version:                                                                             
--                                                                                                   
-- Version:               4.0                                                                      
--
-- Description:            
--
-- Versions history:      DATE         VERSION   AUTHOR                               DESCRIPTION
--                
--                        06/10/2008   0.1       F. Marin (CPPM)                      First .bdf entity definition.
--                
--                        02/11/2009   0.2       S. Muschter (Stockholm University)   Translate from .bdf to .vhd.
--
--                        13/06/2013   3.0       M. Barros Marin                      Cosmetic and minor modifications.                                                                                  
--
--                        05/06/2015   4.0       K. Hennessy                          modified for GWT
--                                                                                    Removed Widebus and 8b10b 
-- Additional Comments:                                                                               
--
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! IMPORTANT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
-- !!                                                                                           !!
-- !! * The different parameters of the gwt Bank are set through:                               !!  
-- !!   (Note!! These parameters are vendor specific)                                           !!                    
-- !!                                                                                           !!
-- !!   - The MGT control ports of the gwt Bank module (these ports are listed in the records   !!
-- !!     of the file "<vendor>_<device>_gwt_bank_package.vhd").                                !! 
-- !!     (e.g. xlx_v6_gwt_bank_package.vhd)                                                    !!
-- !!                                                                                           !!  
-- !!   - By modifying the content of the file "<vendor>_<device>_gwt_bank_user_setup.vhd".     !!
-- !!     (e.g. xlx_v6_gwt_bank_user_setup.vhd)                                                 !! 
-- !!                                                                                           !! 
-- !! * The "<vendor>_<device>_gwt_bank_user_setup.vhd" is the only file of the gwt Bank that   !!
-- !!   may be modified by the user. The rest of the files MUST be used as is.                  !!
-- !!                                                                                           !!  
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
-- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
--                                                                                                   
--=================================================================================================--
--#################################################################################################--
--=================================================================================================--

-- IEEE VHDL standard library:
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

--=================================================================================================--
--#######################################   Entity   ##############################################--
--=================================================================================================--



entity gwt_rx_descrambler_30bit_new is
  port (
    
    --===============--
    -- Reset & Clock --
    --===============--    
    
    -- Reset:
    ---------
    RX_RESET_I                : in  std_logic;
    
    -- Clock:
    ---------
    RX_FRAMECLK_I             : in  std_logic;
    
    --==============--           
    -- Frame & Data --           
    --==============--              
    
    -- Common frame:
    ----------------
    RX_COMMON_FRAME_I         : in  std_logic_vector(29 downto 0);
    
    -- Data:
    --------
    rx_data_out         : out std_logic_vector(29 downto 0)
    

    );
end gwt_rx_descrambler_30bit_new;

--=================================================================================================--
--####################################   Architecture   ###########################################-- 
--=================================================================================================--

architecture behavioral of gwt_rx_descrambler_30bit_new is 

  --================================ Signal Declarations ================================--
  
  signal feedbackRegister       : std_logic_vector(29 downto 0);
  signal rx_data_temp           : std_logic_vector(29 downto 0);
  --=====================================================================================--
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

--=================================================================================================--
begin                 --========####   Architecture Body   ####========-- 
--=================================================================================================--

  --==================================== User Logic =====================================--
  
  descrambler30bit_new: process(RX_RESET_I, RX_FRAMECLK_I)
  begin
    
    if RX_RESET_I = '1' then
      
      feedbackRegister  <= (others => '0');
      rx_data_out	<= (others => '0');
      rx_data_temp      <= (others => '0');
      report "========== Reset asserted (RX_descrambler) ===================";
      
    elsif RISING_EDGE(RX_FRAMECLK_I) then

      rx_data_out <= rx_data_temp;
      
      report "rx_data_temp = " & stdvec_to_str(rx_data_temp);
      -----------------------------------------------------------------------------------------         
      feedbackRegister  <= RX_COMMON_FRAME_I;      
      
    elsif FALLING_EDGE(RX_FRAMECLK_I) then

      rx_data_temp( 0) <= RX_COMMON_FRAME_I( 0) xor feedbackRegister( 0) xor feedbackRegister( 2);
      rx_data_temp( 1) <= RX_COMMON_FRAME_I( 1) xor feedbackRegister( 1) xor feedbackRegister( 3);
      rx_data_temp( 2) <= RX_COMMON_FRAME_I( 2) xor feedbackRegister( 2) xor feedbackRegister( 4);
      rx_data_temp( 3) <= RX_COMMON_FRAME_I( 3) xor feedbackRegister( 3) xor feedbackRegister( 5);
      rx_data_temp( 4) <= RX_COMMON_FRAME_I( 4) xor feedbackRegister( 4) xor feedbackRegister( 6);
      rx_data_temp( 5) <= RX_COMMON_FRAME_I( 5) xor feedbackRegister( 5) xor feedbackRegister( 7);
      rx_data_temp( 6) <= RX_COMMON_FRAME_I( 6) xor feedbackRegister( 6) xor feedbackRegister( 8);
      rx_data_temp( 7) <= RX_COMMON_FRAME_I( 7) xor feedbackRegister( 7) xor feedbackRegister( 9);
      rx_data_temp( 8) <= RX_COMMON_FRAME_I( 8) xor feedbackRegister( 8) xor feedbackRegister(10);
      rx_data_temp( 9) <= RX_COMMON_FRAME_I( 9) xor feedbackRegister( 9) xor feedbackRegister(11);
      rx_data_temp(10) <= RX_COMMON_FRAME_I(10) xor feedbackRegister(10) xor feedbackRegister(12);
      rx_data_temp(11) <= RX_COMMON_FRAME_I(11) xor feedbackRegister(11) xor feedbackRegister(13);
      rx_data_temp(12) <= RX_COMMON_FRAME_I(12) xor feedbackRegister(12) xor feedbackRegister(14);
      rx_data_temp(13) <= RX_COMMON_FRAME_I(13) xor feedbackRegister(13) xor feedbackRegister(15);
      rx_data_temp(14) <= RX_COMMON_FRAME_I(14) xor feedbackRegister(14) xor feedbackRegister(16);
      rx_data_temp(15) <= RX_COMMON_FRAME_I(15) xor feedbackRegister(15) xor feedbackRegister(17);
      rx_data_temp(16) <= RX_COMMON_FRAME_I(16) xor feedbackRegister(16) xor feedbackRegister(18);
      rx_data_temp(17) <= RX_COMMON_FRAME_I(17) xor feedbackRegister(17) xor feedbackRegister(19);
      rx_data_temp(18) <= RX_COMMON_FRAME_I(18) xor feedbackRegister(18) xor feedbackRegister(20);
      rx_data_temp(19) <= RX_COMMON_FRAME_I(19) xor feedbackRegister(19) xor feedbackRegister(21);
      rx_data_temp(20) <= RX_COMMON_FRAME_I(20) xor feedbackRegister(20) xor feedbackRegister(22);
      rx_data_temp(21) <= RX_COMMON_FRAME_I(21) xor feedbackRegister(21) xor feedbackRegister(23);
      rx_data_temp(22) <= RX_COMMON_FRAME_I(22) xor feedbackRegister(22) xor feedbackRegister(24);
      rx_data_temp(23) <= RX_COMMON_FRAME_I(23) xor feedbackRegister(23) xor feedbackRegister(25);
      rx_data_temp(24) <= RX_COMMON_FRAME_I(24) xor feedbackRegister(24) xor feedbackRegister(26);
      rx_data_temp(25) <= RX_COMMON_FRAME_I(25) xor feedbackRegister(25) xor feedbackRegister(27);
      rx_data_temp(26) <= RX_COMMON_FRAME_I(26) xor feedbackRegister(26) xor feedbackRegister(28);
      rx_data_temp(27) <= RX_COMMON_FRAME_I(27) xor feedbackRegister(27) xor feedbackRegister(29);
      rx_data_temp(28) <= RX_COMMON_FRAME_I(28) xor feedbackRegister(28) xor RX_COMMON_FRAME_I( 0);
      rx_data_temp(29) <= RX_COMMON_FRAME_I(29) xor feedbackRegister(29) xor RX_COMMON_FRAME_I( 1);

    end if;
    
  end process;
  
--=====================================================================================--   
end behavioral;
--=================================================================================================--
--#################################################################################################--
--=================================================================================================--
