defmodule Raindrops do
  @doc """
  Returns a string based on raindrop factors.

  - If the number contains 3 as a prime factor, output 'Pling'.
  - If the number contains 5 as a prime factor, output 'Plang'.
  - If the number contains 7 as a prime factor, output 'Plong'.
  - If the number does not contain 3, 5, or 7 as a prime factor,
    just pass the number's digits straight through.
  """
  @spec convert(pos_integer) :: String.t()
  def convert(number) do
    "#{is_multiple_of(number)}"
  end

  def is_multiple_of(number) do
    cond do
      rem(number , 3) == 0 -> "Pling#{is_multiple_of_5(number)}"
      "#{is_multiple_of_5(number)}" == "" -> number
      true -> "#{is_multiple_of_5(number)}"
    end
  end

  def is_multiple_of_5(number) do
    cond do
      rem(number , 5) == 0 -> "Plang#{is_multiple_of_7(number)}"
      true -> "#{is_multiple_of_7(number)}"
    end
  end

  def is_multiple_of_7(number) do
    cond do
      rem(number , 7) == 0 -> "Plong"
      true -> ""
    end
  end
end
