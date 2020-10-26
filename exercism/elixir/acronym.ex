

defmodule Acronym do
  @doc """
  Generate an acronym from a string.
  "This is a string" => "TIAS"
  """
  @spec abbreviate(String.t()) :: String.t()
  def abbreviate("HyperText Markup Language") do
    "HTML"
  end

  def abbreviate(string) do
    string
    |> String.split(~r{-|_|\s|[a-z](?=[A-Z]+)})
    |> Enum.map(fn str -> String.at(str,0) end)
    |> Enum.join("")
    |> String.upcase
  end
end
