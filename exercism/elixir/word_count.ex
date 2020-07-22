defmodule WordCount do
  @doc """
  Count the number of words in the sentence.

  Words are compared case-insensitively.
  """
  @spec count(String.t()) :: map
  def count(sentence) do
    words = sentence |> String.downcase |> String.split(~r/[^[:alnum:]\-]/u, trim: true)
    Enum.group_by(words,&(&1)) |>
    Enum.reduce(%{}, fn {k,v}, acc -> Map.put(acc, k, Enum.count(v)) end)
  end
end
