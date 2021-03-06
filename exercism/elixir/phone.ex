defmodule Phone do
  @doc """
  Remove formatting from a phone number.

  Returns "0000000000" if phone number is not valid
  (10 digits or "1" followed by 10 digits)

  ## Examples

  iex> Phone.number("212-555-0100")
  "2125550100"

  iex> Phone.number("+1 (212) 555-0100")
  "2125550100"

  iex> Phone.number("+1 (212) 055-0100")
  "0000000000"

  iex> Phone.number("(212) 555-0100")
  "2125550100"

  iex> Phone.number("867.5309")
  "0000000000"
  """
  @spec number(String.t()) :: String.t()
  def number(raw) do
    raw
    |> clean_number
    |> validate_number
  end

  @doc """
  Extract the area code from a phone number

  Returns the first three digits from a phone number,
  ignoring long distance indicator

  ## Examples

  iex> Phone.area_code("212-555-0100")
  "212"

  iex> Phone.area_code("+1 (212) 555-0100")
  "212"

  iex> Phone.area_code("+1 (012) 555-0100")
  "000"

  iex> Phone.area_code("867.5309")
  "000"
  """
  @spec area_code(String.t()) :: String.t()
  def area_code(raw) do
    raw
    |> number
    |> to_string
    |> get_area_code
  end

  @spec get_area_code(<<_::24, _::_*8>>) :: <<_::24>>
  def get_area_code(<< area_code, rest_area_code::binary-size(2),_rest::binary >>) do
      << area_code, rest_area_code::binary-size(2) >>
  end


  @doc """
  Pretty print a phone number

  Wraps the area code in parentheses and separates
  exchange and subscriber number with a dash.

  ## Examples

  iex> Phone.pretty("212-555-0100")
  "(212) 555-0100"

  iex> Phone.pretty("212-155-0100")
  "(000) 000-0000"

  iex> Phone.pretty("+1 (303) 555-1212")
  "(303) 555-1212"

  iex> Phone.pretty("867.5309")
  "(000) 000-0000"
  """
  @spec pretty(String.t()) :: String.t()
  def pretty(raw) do
    raw
    |> number
    |> to_string
    |> format
  end

  def format(<< first_part::binary-size(3), second_part::binary-size(3), last_part::binary >>) do
    "(#{first_part}) #{second_part}-#{last_part}"
  end


  @spec clean_number(String.t()) :: String.t()
  def clean_number(str) do
    String.replace(str, ["(", ")", "-", ".", "+", " "], "")
  end

  def validate_number(<<head, rest::binary-size(10)>>) when head == ?1 do
    rest
  end

  def validate_number(<<head, head_rest::binary-size(2), exchange_code,  exchange_code_rest::binary-size(6)>>)
  when head != ?1 and head != ?0 and exchange_code != ?1 and exchange_code != ?0
   do
    str = <<head, head_rest::binary-size(2), exchange_code,  exchange_code_rest::binary-size(6)>>
    try do
      String.to_integer(str)
      str
    rescue
      _e in ArgumentError -> "0000000000"
    end
  end

  def validate_number(_str) do
   "0000000000"
  end

end
