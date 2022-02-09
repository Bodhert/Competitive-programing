defmodule LibraryFees do

  @spec datetime_from_string(String.t()) :: NaiveDateTime.t() 
  def datetime_from_string(string) do
    {:ok, date} = NaiveDateTime.from_iso8601(string)
    date
  end

  @spec before_noon?(NaiveDateTime.t()) :: boolean()
  def before_noon?(datetime) do
    datetime.hour < 12
  end

  @spec return_date(NaiveDateTime.t()) :: Date.t()
  def return_date(checkout_datetime) do
    datetime = NaiveDateTime.to_date(checkout_datetime)
    if before_noon?(checkout_datetime) do
      datetime
      |> Date.add(28)
    else
      datetime
      |> Date.add(29)
    end
      
  end

  @spec days_late(Date.t(), NaiveDateTime.t()) :: integer
  def days_late(planned_return_date, actual_return_datetime) do
    result = Date.compare(actual_return_datetime, planned_return_date) 
    if result == :lt or result == :eq  do
      0
    else
      Date.diff(actual_return_datetime, planned_return_date)
    end
  end

  def monday?(datetime) do
    Date.day_of_week(datetime) == 1
  end

  @spec calculate_late_fee(String.t(), String.t(), number) :: integer()
  def calculate_late_fee(checkout, return, rate) do
    checkout_date = datetime_from_string(checkout)
    return_date = datetime_from_string(return)

    raw_fee = days_late(return_date(checkout_date), return_date) * rate
    if monday?(return_date) do
      raw_fee * 0.5 |> trunc
    else
      raw_fee
    end
  end

end
