defmodule Solution do
  def main() do
      n = IO.gets("") |> String.to_integer
      IO.inspect(Enum.to_list(1..n), limit: :infinity)
  end
end

Solution.main
