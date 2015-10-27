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
      
      RX_RESET_I                                : in  std_logic;
      
      -- Clock:
      ---------
      
      RX_FRAMECLK_I                             : in  std_logic;
      
      --==============--           
      -- Frame & Data --           
      --==============--              
      
      -- Common frame:
      ----------------
      
      RX_COMMON_FRAME_I                         : in  std_logic_vector(29 downto 0);
      
      -- Data:
      --------
      
      RX_DATA_O                                 : out std_logic_vector(29 downto 0)
      
   );
end gwt_rx_descrambler_30bit_new;

--=================================================================================================--
--####################################   Architecture   ###########################################-- 
--=================================================================================================--

architecture behavioral of gwt_rx_descrambler_30bit_new is 

   --================================ Signal Declarations ================================--
 
   signal feedbackRegister                      : std_logic_vector(29 downto 0);
   
   --=====================================================================================--

--=================================================================================================--
begin                 --========####   Architecture Body   ####========-- 
--=================================================================================================--

   --==================================== User Logic =====================================--
  
   descrambler30bit_new: process(RX_RESET_I, RX_FRAMECLK_I)
   begin
      if RX_RESET_I = '1' then
         feedbackRegister                       <= (others => '0');
      elsif RISING_EDGE(RX_FRAMECLK_I) then

         RX_DATA_O( 0) <= RX_COMMON_FRAME_I( 0) xor feedbackRegister( 0) xor feedbackRegister ( 2);
         RX_DATA_O( 1) <= RX_COMMON_FRAME_I( 1) xor feedbackRegister( 1) xor feedbackRegister ( 3);
         RX_DATA_O( 2) <= RX_COMMON_FRAME_I( 2) xor feedbackRegister( 2) xor feedbackRegister ( 4);
         RX_DATA_O( 3) <= RX_COMMON_FRAME_I( 3) xor feedbackRegister( 3) xor feedbackRegister ( 5);
         RX_DATA_O( 4) <= RX_COMMON_FRAME_I( 4) xor feedbackRegister( 4) xor feedbackRegister ( 6);
         RX_DATA_O( 5) <= RX_COMMON_FRAME_I( 5) xor feedbackRegister( 5) xor feedbackRegister ( 7);
         RX_DATA_O( 6) <= RX_COMMON_FRAME_I( 6) xor feedbackRegister( 6) xor feedbackRegister ( 8);
         RX_DATA_O( 7) <= RX_COMMON_FRAME_I( 7) xor feedbackRegister( 7) xor feedbackRegister ( 9);
         RX_DATA_O( 8) <= RX_COMMON_FRAME_I( 8) xor feedbackRegister( 8) xor feedbackRegister (10);
         RX_DATA_O( 9) <= RX_COMMON_FRAME_I( 9) xor feedbackRegister( 9) xor feedbackRegister (11);
         RX_DATA_O(10) <= RX_COMMON_FRAME_I(10) xor feedbackRegister(10) xor feedbackRegister (12);
         RX_DATA_O(11) <= RX_COMMON_FRAME_I(11) xor feedbackRegister(11) xor feedbackRegister (13);
         RX_DATA_O(12) <= RX_COMMON_FRAME_I(12) xor feedbackRegister(12) xor feedbackRegister (14);
         RX_DATA_O(13) <= RX_COMMON_FRAME_I(13) xor feedbackRegister(13) xor feedbackRegister (15);
         RX_DATA_O(14) <= RX_COMMON_FRAME_I(14) xor feedbackRegister(14) xor feedbackRegister (16);
         RX_DATA_O(15) <= RX_COMMON_FRAME_I(15) xor feedbackRegister(15) xor feedbackRegister (17);
         RX_DATA_O(16) <= RX_COMMON_FRAME_I(16) xor feedbackRegister(16) xor feedbackRegister (18);
         RX_DATA_O(17) <= RX_COMMON_FRAME_I(17) xor feedbackRegister(17) xor feedbackRegister (19);
         RX_DATA_O(18) <= RX_COMMON_FRAME_I(18) xor feedbackRegister(18) xor feedbackRegister (20);
         RX_DATA_O(19) <= RX_COMMON_FRAME_I(19) xor feedbackRegister(19) xor feedbackRegister (21);
         RX_DATA_O(20) <= RX_COMMON_FRAME_I(20) xor feedbackRegister(20) xor feedbackRegister (22);
         RX_DATA_O(21) <= RX_COMMON_FRAME_I(21) xor feedbackRegister(21) xor feedbackRegister (23);
         RX_DATA_O(22) <= RX_COMMON_FRAME_I(22) xor feedbackRegister(22) xor feedbackRegister (24);
         RX_DATA_O(23) <= RX_COMMON_FRAME_I(23) xor feedbackRegister(23) xor feedbackRegister (25);
         RX_DATA_O(24) <= RX_COMMON_FRAME_I(24) xor feedbackRegister(24) xor feedbackRegister (26);
         RX_DATA_O(25) <= RX_COMMON_FRAME_I(25) xor feedbackRegister(25) xor feedbackRegister (27);
         RX_DATA_O(26) <= RX_COMMON_FRAME_I(26) xor feedbackRegister(26) xor feedbackRegister (28);
         RX_DATA_O(27) <= RX_COMMON_FRAME_I(27) xor feedbackRegister(27) xor feedbackRegister (29);
         RX_DATA_O(28) <= RX_COMMON_FRAME_I(28) xor feedbackRegister(28) xor RX_COMMON_FRAME_I( 0);
         RX_DATA_O(29) <= RX_COMMON_FRAME_I(29) xor feedbackRegister(29) xor RX_COMMON_FRAME_I( 1);
         -----------------------------------------------------------------------------------------         
         feedbackRegister                       <= RX_COMMON_FRAME_I;      
         
      end if;
   end process;
  
   --=====================================================================================--   
end behavioral;
--=================================================================================================--
--#################################################################################################--
--=================================================================================================--
