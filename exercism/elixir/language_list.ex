defmodule LanguageList do
  @spec new :: []
  def new(), do: []

  @spec add(list(), String.t()) :: list(String.t())
  def add(list, language), do: [language | list]

  @spec remove(list()) :: list()
  def remove([_head | tail]), do: tail

  @spec first(list()) :: String.t()
  def first([head | _tail]), do: head

  @spec count(list()) :: non_neg_integer
  def count(list), do: length(list)

  @spec exciting_list?(list) :: boolean
  def exciting_list?(list), do: "Elixir" in list
end
