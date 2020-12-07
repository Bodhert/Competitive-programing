defmodule SumOfMultiples do
  @doc """
  Adds up all numbers from 1 to a given end number that are multiples of the factors provided.
  """
  def is_multiple(num, factors) do
    Enum.any?(factors, fn(factor) -> rem(num, factor) == 0 end)
  end

  @spec to(non_neg_integer, [non_neg_integer]) :: non_neg_integer
  def to(limit, factors) do
    Enum.filter(0..limit-1, fn(num) -> is_multiple(num, factors) end )
    |> Enum.sum
  end
end
