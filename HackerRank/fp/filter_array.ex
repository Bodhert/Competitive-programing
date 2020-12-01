defmodule Solution do

  defp filter(_,[],acc) do
      acc
  end

  defp filter(func, [head | tail], acc) do
      cond do
           func.(head) -> filter(func, tail, [head | acc])
           func.(head) == false -> filter(func, tail, acc)
      end
  end

  def main() do
    lines = IO.read(:stdio, :all)
    |> String.split
    |> Enum.map(&String.to_integer(&1))
    [b | array] = lines
    ans = Enum.reverse(filter(fn x -> x < b end, array, []))
    Enum.map(ans, &IO.puts(&1))
  end
end

Solution.main()
