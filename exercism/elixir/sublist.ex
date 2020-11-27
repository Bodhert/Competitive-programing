defmodule Sublist do
  @doc """
  Returns whether the first list is a sublist or a superlist of the second list
  and if not whether it is equal or unequal to the second list.
  """
  def sublist?([], _), do: true

  def sublist?(a, [head | tail]) do
    new_list = [head | Enum.slice(tail, 0, length(a)-1)]
    cond do
      length(a) == length([head]) -> a === head
      a === new_list -> true
      length(new_list) < length(a) -> false
      true -> sublist?(a, tail)
    end
  end

  def compare(a, b) do
    # List.to_string(a)
    cond do
      a === b -> :equal
      a === [nil] -> :superlist
      sublist?(a,b) -> :sublist
      sublist?(b,a) -> :superlist
      true -> :unequal
    end
  end

end
