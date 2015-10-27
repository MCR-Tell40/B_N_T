-- Name: read_in_30_bit
-- Author: Ben Jeffrey
-- Modified By: Nicholas Mead, Ben Jeffrey
-- Modified Date 
-- Entity name: the_reader
-- Description: Reads in 30 bit std_logic_vector from a txt file

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use STD.textio.all;


entity the_reader is
  
  port(
    clk_40MHz  : in  std_logic;
    rst  : in  std_logic;
    pixel_read : out  std_logic_vector(29 downto 0)
    );
end the_reader ;


architecture r of the_reader is

  function str_to_stdvec(inp: string) return std_logic_vector is
    variable temp: std_logic_vector(inp'range) := (others => 'X');
  begin
    for i in inp'range loop
      if (inp(i) = '1') then
        temp(i) := '1';
      elsif (inp(i) = '0') then
        temp(i) := '0';
      end if;
    end loop;
    return temp;
  end function str_to_stdvec;

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

begin
  process (clk_40MHz, rst)
    
    file file_pointer : text;
    variable line_content : string(1 to 128);
    variable line_num : line;
    variable j : integer := 0;
    variable char : character:='0'; 
    variable bin : std_logic_vector(127 downto 0);
    
    
  begin
    file_open(file_pointer,"/home/velo/Documents/B_N_T/new_scrambler_resource_analysis/modelsim/desyncFilter.txt"   ,READ_MODE);
    if rst = '1' then
      pixel_read<= ( others => '0' ) ;

    elsif rising_edge(clk_40MHz) then	
      
      if (not endfile(file_pointer)) then  
        readline (file_pointer,line_num);
        read (line_num,line_content);
	report "line_content =" & line_content;
        bin := str_to_stdvec(line_content);
	--report "bin" & stdvec_to_str(bin) & "    --->   " & stdvec_to_str(bin(29 downto 0));
        pixel_read <= bin(29 downto 0);
      end if;
      				

    end if;
   

  end process ; 
END r ;
