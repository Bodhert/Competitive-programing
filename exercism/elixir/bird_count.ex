defmodule BirdCount do
  @spec today([non_neg_integer()] | []) :: non_neg_integer() | nil
  def today([]), do: nil
  def today([head | _tail]), do: head

  @spec increment_day_count([number]) :: [number]
  def increment_day_count([]), do: [1]
  def increment_day_count([head | tail]), do: [head + 1 | tail]

  @spec has_day_without_birds?(list) :: boolean
  def has_day_without_birds?([]), do: false

  def has_day_without_birds?([head | tail]) do
    head == 0 or has_day_without_birds?(tail)
  end

  @spec total([number]) :: number
  def total(list), do: total(list, 0)

  @spec total([number], number) :: number
  defp total([], acc), do: acc
  defp total([head | tail], acc), do: total(tail, acc + head)

  @spec busy_days(list) :: non_neg_integer
  def busy_days(list), do: busy_days(list, 0)

  @spec busy_days(list, number) :: number
  defp busy_days([], acc), do: acc
  defp busy_days([head | tail], acc) when head >= 5, do: busy_days(tail, acc + 1)
  defp busy_days([_head | tail], acc), do: busy_days(tail, acc)
end
