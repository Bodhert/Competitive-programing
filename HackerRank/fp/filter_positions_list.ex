defmodule Solution do
  def main() do
    lines = IO.read(:stdio, :all)
    |> String.split

    ans =
      lines
      |> Enum.with_index
      |> Enum.filter(fn {_num, pos} -> rem(pos, 2) == 1 end)

    Enum.map(ans, fn {num, _pos} -> IO.puts num end)

  end
end

Solution.main()
