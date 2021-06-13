defmodule MatchingBrackets do
  @doc """
  Checks that all the brackets and braces in the string are matched correctly, and nested correctly
  """

  @spec check_brackets(String.t()) :: boolean
  def check_brackets(str) do
    result = check_str(str,[])
    if result === [] do
      true
    else
      false
    end
  end

  def check_str("", stack) do
    stack
  end

  def check_str(<<?[, rest::binary>>, stack) do
    check_str(rest, [?[ | stack])
  end

  def check_str(<<?], rest_str::binary>>, [?[ | rest_stack]) do
    check_str(rest_str, rest_stack)
  end

  def check_str(<<?], _rest_str::binary>>, _stack) do
    [:error_parsing]
  end

  def check_str(<<?{, rest::binary>>, stack) do
    check_str(rest, [?{ | stack])
  end

  def check_str(<<?}, rest_str::binary>>, [?{ | rest_stack]) do
    check_str(rest_str, rest_stack)
  end

  def check_str(<<?}, _rest_str::binary>>, _stack) do
    [:error_parsing]
  end

  def check_str(<<?(, rest::binary>>, stack) do
    check_str(rest, [?( | stack])
  end

  def check_str(<<?), rest_str::binary>>, [?( | rest_stack]) do
    check_str(rest_str, rest_stack)
  end

  def check_str(<<?), _rest_str::binary>>, _stack) do
    [:error_parsing]
  end

  def check_str(<<_any_char, rest_str::binary>>, stack) do
    check_str(rest_str, stack)
  end

end
