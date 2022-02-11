defmodule BoutiqueInventory do
  
  @spec sort_by_price(list) :: list
  def sort_by_price(inventory) do
    inventory
    |> Enum.sort_by(fn inv -> inv.price end)
  end

	@spec with_missing_price(list) :: list
  def with_missing_price(inventory) do
    inventory
    |> Enum.filter(fn inv -> inv.price == nil end)
  end

	@spec increase_quantity(map, integer) :: map
  def increase_quantity(item, count) do
    quantity_by_size = item.quantity_by_size
    |> Enum.into(%{}, fn {k, v} -> {k, v + count} end)
    
    %{item | quantity_by_size: quantity_by_size}

  end

	@spec total_quantity(map) :: integer
  def total_quantity(item) do
    item.quantity_by_size
    |> Enum.reduce(0, fn {_k, v}, acc -> v + acc end)
  end
end
