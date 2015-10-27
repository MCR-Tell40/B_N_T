
-- Name : writer
-- Entity name : the_writer
-- Author : B.Jeffrey
-- Modified By: Nicholas Mead, Ben Jeffrey
-- Modified Date: 06/10/15
-- Date created : 15/6/2015
-- Description : Writes out a super pixel packet 30 bit to a txt file

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
use STD.textio.all;

--------- entity declaration -------
ENTITY the_writer IS
  port( 
    pixel_write : IN std_logic_vector(29 downto 0) ;
    file_name    : in string(20 downto 1);
    rst, clk_40MHz: IN std_logic
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
    file file_pointer: text;
    variable line_content : string ( 1 to 30 );
    variable line_num : line;
    variable i,j : integer := 0;
    variable char : std_logic :='0';
    variable full_file_path : string(88 downto 1);



    
  begin
    full_file_path := "./" & file_name;
    
    file_open(file_pointer,full_file_path,WRITE_MODE);
     ------------- reset ------------		   
    ------------- reset ------------		
    if rst = '1' then
      
      for j in 1 to 30 loop
        line_content(31-j) := '0';
      end loop;
      ----------- write the lines ------------
      write(line_num,line_content);
      writeline (file_pointer,line_num);
      
    elsif(rising_edge(clk_40MHz)) then

      line_content := stdvec_to_str(pixel_write);

      write(line_num,line_content);
      writeline (file_pointer,line_num);
      
    end if;

  end process;
END  w ;
