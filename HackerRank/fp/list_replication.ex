defmodule Solution do
  def main() do
    input = IO.read(:stdio, :all)
    |> String.split
    |> Enum.map(&String.to_integer(&1))

    [x | s] = input

     Enum.map(s, fn si ->
      for i <- 1..x do
          IO.puts si
      end
     end)

  end
end

Solution.main()
