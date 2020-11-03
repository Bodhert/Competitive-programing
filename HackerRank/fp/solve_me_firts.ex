defmodule Solution do
  IO.read(:stdio, :all)
    |> String.split
    |> Enum.map(&String.to_integer(&1))
    |> Enum.sum
    |> IO.puts
end
