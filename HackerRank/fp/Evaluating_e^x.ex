defmodule Solution do


  def factorial(n) do
      Enum.reduce(1..n, fn(num, acc) -> num * acc end)
  end

  def expansion_10(x) do
   1 + x + Enum.reduce(2..9, 0, fn(num, acc) -> (:math.pow(x,num)/ factorial(num)) + acc end)
  end

  def read_data() do
      IO.read(:stdio, :all)
      |> String.split
      |> Enum.map(&Float.parse(&1))
  end

  def main() do
      [_|ans] = Enum.map(read_data(), fn {float,_} -> expansion_10(float) end)
      Enum.map(ans, &IO.puts(&1))
  end
end

Solution.main()
