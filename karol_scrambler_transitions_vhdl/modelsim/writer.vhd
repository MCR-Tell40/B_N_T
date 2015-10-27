
-- Name : writer
-- Entity name : the_writer
-- Author : B.Jeffrey
-- Modified By: Nicholas Mead, Ben Jeffrey
-- Modified Date: 06/10/15
-- Date created : 15/6/2015
-- Description : Writes out a super pixel packet 30 bit to a txt file
-- MODIFIED BY BEN FOR WORKING OUT TRANSTITIONS OF 1 SPP 13/10/15
-- MODIFIED BY BEN FOR WORKING OUT TRANSTITIONS OF ALL 4 SPP 13/10/15


LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
use STD.textio.all;

--------- entity declaration ---
ENTITY the_writer IS
  port( 
    pixel_write1, pixel_write2, pixel_write3, pixel_write4 : IN std_logic_vector(29 downto 0) ;
    file_name    : in string(20 downto 1);
    rst, clk_40MHz: IN std_logic;
    file_name2 : in string(19 downto 1)
    
    ) ;
end ENTITY ;

ARCHITECTURE w OF the_writer IS 

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
  process(rst, clk_40MHz)
    ------- declare all variables ---------		
    file file_pointer, file_pointer2 : text;
    variable line_content : string ( 1 to 128 );
    variable line_num : line;
    variable i,j : integer := 0;
    variable char : std_logic :='0';
    variable full_file_path : string(87 downto 1);
    variable full_file_path2: string(86 downto 1);
    variable transitions : integer := 0;
    variable full_pixel : std_logic_vector(119 downto 0);


    
  begin
    full_file_path := "/home/velo/Documents/B_N_T/new_scrambler_transitions_vhdl/modelsim/" & file_name;
    full_file_path2:="/home/velo/Documents/B_N_T/new_scrambler_transitions_vhdl/modelsim/" & file_name2;
    
    file_open(file_pointer,full_file_path,WRITE_MODE);
    file_open(file_pointer2,full_file_path2,WRITE_MODE);
    
    ------------- reset ------------		   
    ------------- reset ------------		
    
    if rst = '1' then
      
      for j in 1 to 128 loop
        line_content(129-j) := '0';
      end loop;
      ----------- write the lines ------------
      write(line_num,line_content);
      writeline (file_pointer,line_num);
      
    elsif(rising_edge(clk_40MHz)) then
      transitions := 0;
      line_content := "0101XXXX"& stdvec_to_str(pixel_write1) & stdvec_to_str(pixel_write2) & stdvec_to_str(pixel_write3) & stdvec_to_str(pixel_write4);

      write(line_num,line_content);
      writeline (file_pointer,line_num);
      full_pixel := pixel_write1 & pixel_write2 & pixel_write3 & pixel_write4;
      for i in 1 to 119 loop
        if ((full_pixel(i) XOR full_pixel(i-1)) = '1') then
          transitions := transitions + 1;
        end if;
      end loop;
       
      write(line_num, transitions);
      writeline(file_pointer2, line_num);
    end if;


  end process;
END  w ;
