defmodule FreelancerRates do

  @spec daily_rate(integer) :: float
  def daily_rate(hourly_rate), do: (hourly_rate * 8) / 1

  @spec apply_discount(number, number) :: float
  def apply_discount(before_discount, discount) do
    discount = before_discount * (discount / 100)
    before_discount - discount
  end

  @spec monthly_rate(number, number) :: number
  def monthly_rate(hourly_rate, discount) do
    raw_price = daily_rate(hourly_rate) * 22
    discount = ceil(apply_discount(raw_price, discount))
    discount
  end

  @spec days_in_budget(number, number, number) :: float
  def days_in_budget(budget, hourly_rate, discount) do
    raw_price = daily_rate(hourly_rate)
    discount = apply_discount(raw_price, discount)
    final_budget = Float.ceil(budget / discount,4) / 1
    parse_number(final_budget)
  end

  @spec parse_number(float) :: float
  defp parse_number(number) do
    stringify = Float.to_string(number)
    ans = String.split(stringify, ".", parts: 2)
    [real_part, decimal] = ans
    full_ans = "#{real_part}.#{String.at(decimal,0)}"
    answer = String.to_float(full_ans)
    answer
  end
end
