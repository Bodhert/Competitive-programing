defmodule DateParser do
  use TypeCheck

  @spec! day :: String.t()
  def day(), do: "(0?[1-9]|[12]\d|3[01])"

  @spec! month :: String.t()
  def month(), do: "(0?[1-9]|[1-12])"

  @spec! year :: String.t()
  def year(), do: "[0-9]{4}"

  @spec! day_names :: String.t()
  def day_names(), do: "(Monday|Tuesday|Wednesday|Thursday|Friday|Saturday|Sunday)"

  @spec! month_names :: String.t()
  def month_names(),
    do: "(January|February|March|April|May|June|July|August|September|October|November|December)"

  @spec! capture_day :: String.t()
  def capture_day(), do: "(?<day>#{day()})"

  @spec! capture_month :: String.t()
  def capture_month(), do: "(?<month>#{month()})"

  @spec! capture_year :: String.t()
  def capture_year(), do: "(?<year>#{year()})"

  @spec! capture_day_name :: String.t()
  def capture_day_name(), do: "(?<day_name>#{day_names()})"

  @spec! capture_month_name :: String.t()
  def capture_month_name(), do: "(?<month_name>#{month_names()})"

  @spec! capture_numeric_date :: String.t()
  def capture_numeric_date(), do: "#{capture_day()}\/#{capture_month()}\/#{capture_year()}"

  @spec! capture_month_name_date :: String.t()
  def capture_month_name_date(),
    do: "#{capture_month_name()} #{capture_day()}\, #{capture_year()}"

  @spec! capture_day_month_name_date :: String.t()
  def capture_day_month_name_date(), do: "#{capture_day_name()}, #{capture_month_name_date()}"

  @spec! match_numeric_date :: Regex.t()
  def match_numeric_date(), do: ~r/^#{capture_numeric_date()}$/

  @spec! match_month_name_date :: Regex.t()
  def match_month_name_date(), do: ~r/^#{capture_month_name_date()}$/

  @spec! match_day_month_name_date :: Regex.t()
  def match_day_month_name_date(), do: ~r/^#{capture_day_month_name_date()}$/

end
