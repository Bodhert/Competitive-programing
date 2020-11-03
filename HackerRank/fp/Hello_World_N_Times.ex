defmodule Solution do
  def print_recursive(number, msg)  do
      if number === 1 do
          IO.puts msg
      else
          IO.puts msg
          print_recursive(number-1,msg)
      end

  end

  def main() do
      lines =  IO.read(:stdio, :all) |> String.split # lines
      [num] = lines
      String.to_integer(num)
      |> print_recursive("Hello World")
  end
end

Solution.main()
