defmodule Bob do
  def hey(input) do
    cond do
      String.match?(input, ~r{^[[:upper:]\s|\'|?]+$}u) and String.ends_with?(input,"?") -> "Calm down, I know what I'm doing!"
      String.match?(input, ~r{\?[[:blank:]]*$}) -> "Sure."
      String.contains?(input,"!") and String.match?(input, ~r{\b[[:upper:]]+\b}) -> "Whoa, chill out!"
      String.match?(input, ~r{^[[:blank:]|[:cntrl:]]*$}) -> "Fine. Be that way!"
      String.match?(input, ~r{^[[:upper:]]+$}u) or String.match?(input, ~r{^[[:upper:]\s]+$})   -> "Whoa, chill out!"
      true -> "Whatever."
    end
  end
end
