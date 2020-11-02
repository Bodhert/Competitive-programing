defmodule RunLengthEncoder do
  @doc """
  Generates a string where consecutive elements are represented as a data value and count.
  "AABBBCCCC" => "2A3B4C"
  For this example, assume all input are strings, that are all uppercase letters.
  It should also be able to reconstruct the data into its original form.
  "2A3B4C" => "AABBBCCCC"
  """
  @spec encode(String.t()) :: String.t()
  def encode(string) do
    string
    |> String.graphemes
    |> Enum.chunk_by(fn char -> char end)
    |> Enum.map_join(
      fn [char | _ ] = list ->
        cond do
          length(list) == 1 -> "#{char}"
          true -> "#{length(list)}#{char}"
        end
      end)

    # |> Enum.map(fn {str} ->  str end)
    # |> List.to_string
    # |> Enum.flat_map(fn {str} -> str end)
  end

  @spec decode(String.t()) :: String.t()
  def decode(string) do
    string
    |> String.split(~r{[1-9]+.}, trim: true , include_captures: true)
    |> Enum.map_join(
      fn str ->
        {num, rest} = String.split_at(str,-1)
        cond do
          Regex.match?(~r{[1-9]+}, num) -> String.duplicate(rest, String.to_integer(num))
          true -> num <> rest
        end
      end
    )
  end

end
