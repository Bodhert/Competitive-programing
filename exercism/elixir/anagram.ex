defmodule Anagram do
  @doc """
  Returns all candidates that are anagrams of, but not equal to, 'base'.
  """


  def compare(base, candidate) do
    base -- candidate === [] and length(base) == length(candidate) and base != candidate
  end

  @spec match(String.t(), [String.t()]) :: [String.t()]
  def match(base, candidates) do
    Enum.filter(
      candidates,
      fn(candidate) ->
        compare(
          base |> String.downcase |> String.graphemes,
          candidate |> String.downcase |> String.graphemes
        )
      end
    )
  end
end
